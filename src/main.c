/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Panoramix
*/

#include "panoramix.h"

int main(int ac, char **av)
{
    sim_info_t info;

    if (ac != 5 || handle_errors(av) == ERROR) {
        printf("USAGE: ./panoramix <nb_villagers> <pot_size> "
        "<nb_fights> <nb_refills>\nValues must be >0.\n");
        return ERROR;
    }
    info.nb_villagers = atoi(av[1]);
    info.pot_size = atoi(av[2]);
    info.nb_fights = atoi(av[3]);
    info.nb_refills = atoi(av[4]);
    return run_simulation(&info);
}
