/*
** EPITECH PROJECT, 2021
** free
** File description:
** free
*/

#include "malloc.h"

extern struct t_data *data;

void free(void *ptr)
{
    struct t_data *tmp = data;
    int access = 0;
    int page = 0;

    for (int a = 0; tmp != NULL && access == 0; tmp = tmp->next, a++) {
        if (ptr == (tmp + sizeof(struct t_data *))) {
            tmp->status = 0;
            access = 1;
            page = a;
        }
    }
    tmp = data;
    while (tmp != NULL) {
        if (tmp->status == 0 && tmp->next != NULL && tmp->next->status == 0) {
            tmp->next = tmp->next->next;
            return;
        }
        tmp = tmp->next;
    }
}
