/*
** EPITECH PROJECT, 2021
** bestfit
** File description:
** bestfit
*/

#include "malloc.h"

extern struct t_data *data;

int bestfit(size_t size)
{
    struct t_data *tmp = NULL;
    size_t tmp_min = 0;
    int page = 0;

    tmp = data;
    for (int x = 1; tmp != NULL; tmp = tmp->next, x++) {
        if (tmp->size >= size && tmp->status == 0) {
            page = x;
            tmp_min = tmp->size;
        }
    }
    tmp = data;
    for (int x = 1; tmp != NULL; tmp = tmp->next, x++) {
        if (tmp->size >= size && tmp->status == 0 && tmp->size <= tmp_min) {
            page = x;
            tmp_min = tmp->size;
        }
    }
    return (page);
}
