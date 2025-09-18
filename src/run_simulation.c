/*
** EPITECH PROJECT, 2024
** run_simulation.c
** File description:
** Panoramix
*/

#include "panoramix.h"

pthread_mutex_t mutexRefill;
pthread_cond_t condRefill;
pthread_mutex_t mutexCallDruid;
pthread_cond_t condCallDruid;
int nb_curr_servings;
bool druid_called;

static void handle_druid_call(int id)
{
    pthread_mutex_lock(&mutexCallDruid);
    pthread_mutex_lock(&mutexRefill);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    id, nb_curr_servings);
    if (nb_curr_servings == 0 && !druid_called) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
        druid_called = true;
        pthread_cond_signal(&condCallDruid);
    }
    pthread_mutex_unlock(&mutexCallDruid);
    while (nb_curr_servings == 0) {
        pthread_cond_wait(&condRefill, &mutexRefill);
    }
    pthread_mutex_unlock(&mutexRefill);
}

static void run_villager_fights(villager_info_t *info)
{
    while (info->remaining_fights > 0) {
        handle_druid_call(info->id);
        pthread_mutex_lock(&mutexRefill);
        if (nb_curr_servings > 0) {
            info->remaining_fights -= 1;
            nb_curr_servings -= (nb_curr_servings > 0);
            printf("Villager %d: Take that roman scum! Only %d left.\n",
            info->id, info->remaining_fights);
        }
        pthread_mutex_unlock(&mutexRefill);
    }
}

static void *run_villager(void *arg)
{
    villager_info_t *info = (villager_info_t *)arg;

    printf("Villager %d: Going into battle!\n", info->id);
    run_villager_fights(info);
    printf("Villager %d: I'm going to sleep now.\n", info->id);
    return NULL;
}

static void handle_refill_druid(sim_info_t *info)
{
    pthread_mutex_lock(&mutexRefill);
    if (nb_curr_servings == 0) {
        info->nb_refills -= 1;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! "
        "Beware I can only make %d more refills after this one.\n",
        info->nb_refills);
        nb_curr_servings = info->pot_size;
        pthread_cond_broadcast(&condRefill);
    }
    pthread_mutex_unlock(&mutexRefill);
}

static void *run_druid(void *arg)
{
    sim_info_t *info = (sim_info_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (info->nb_refills > 0) {
        pthread_mutex_lock(&mutexCallDruid);
        while (!druid_called) {
            pthread_cond_wait(&condCallDruid, &mutexCallDruid);
        }
        pthread_mutex_unlock(&mutexCallDruid);
        handle_refill_druid(info);
        pthread_mutex_lock(&mutexCallDruid);
        druid_called = false;
        pthread_mutex_unlock(&mutexCallDruid);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}

static int create_villagers_and_druid(sim_info_t *info, pthread_t *villagers,
    pthread_t *druid, villager_info_t *villagers_info)
{
    if (pthread_create(druid, NULL, run_druid, info) != 0) {
        return 0;
    }
    for (int n = 0; n < info->nb_villagers; n++) {
        villagers_info[n].id = n;
        villagers_info[n].remaining_fights = info->nb_fights;
        if (pthread_create(&villagers[n], NULL, run_villager,
        &villagers_info[n]) != 0) {
            return 0;
        }
    }
    if (pthread_join(*druid, NULL) != 0) {
        return 0;
    }
    for (int n = 0; n < info->nb_villagers; n++) {
        if (pthread_join(villagers[n], NULL) != 0) {
            return 0;
        }
    }
    return 1;
}

static void init_mutexes_and_cond_vars(void)
{
    pthread_mutex_init(&mutexRefill, NULL);
    pthread_cond_init(&condRefill, NULL);
    pthread_mutex_init(&mutexCallDruid, NULL);
    pthread_cond_init(&condCallDruid, NULL);
}

int run_simulation(sim_info_t *info)
{
    pthread_t villagers[info->nb_villagers];
    pthread_t druid;
    villager_info_t villagers_info[info->nb_villagers];

    nb_curr_servings = info->pot_size;
    druid_called = false;
    init_mutexes_and_cond_vars();
    if (!create_villagers_and_druid(info, villagers, &druid,
    villagers_info)) {
        return ERROR;
    }
    pthread_mutex_destroy(&mutexRefill);
    pthread_cond_destroy(&condRefill);
    pthread_mutex_destroy(&mutexCallDruid);
    pthread_cond_destroy(&condCallDruid);
    pthread_exit(NULL);
    return SUCCESS;
}
