/*
** EPITECH PROJECT, 2023
** panoramix.h
** File description:
** Panoramix
*/

#ifndef PANORAMIX_H_
    #define PANORAMIX_H_
    #define SUCCESS 0
    #define ERROR 84
    #include <stdio.h>
    #include <stdlib.h>
    #include <pthread.h>
    #include <stdbool.h>

typedef struct sim_info_s {
    int nb_villagers;
    int pot_size;
    int nb_fights;
    int nb_refills;
} sim_info_t;

typedef struct villager_info_s {
    int id;
    int remaining_fights;
} villager_info_t;

int handle_errors(char **av);
int run_simulation(sim_info_t *info);

#endif
