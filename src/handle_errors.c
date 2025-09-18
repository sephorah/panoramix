/*
** EPITECH PROJECT, 2024
** handle_errors.c
** File description:
** Panoramix
*/

#include "panoramix.h"

int handle_errors(char **av)
{
    if (atoi(av[1]) <= 0 || atoi(av[2]) <= 0 || atoi(av[3]) <= 0
    || atoi(av[4]) <= 0) {
        return ERROR;
    }
    return SUCCESS;
}
