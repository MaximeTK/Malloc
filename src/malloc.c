/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include "malloc.h"

struct t_data *data = NULL;

void init_struct(size_t size)
{
    size_t page_size = 2 * getpagesize();

    data = sbrk(0);
    brk(data + page_size);
    data->next = NULL;
    data->address_end = sbrk(0);
    data->size = page_size - sizeof(struct t_data);
    data->status = 0;
    data->end = data->address_end;
}

void *useback_data(struct t_data *tmp, size_t size)
{
    void *limit = NULL;

    limit = tmp->next;
    tmp->next = tmp + 100;
    tmp->next->status = 0;
    tmp->next->size = tmp->size - size;
    tmp->size = size;
    tmp->status = 1;
    tmp->next->next = limit;
    tmp->next->address_end = tmp->address_end;
    tmp->next->end = tmp->end;
    tmp->address_end = tmp->next;
    return ((tmp + sizeof(struct t_data *)));
}

void *linked_data(int page, size_t size)
{
    struct t_data *tmp = data;
    struct t_data *new = NULL;
    size_t add = 0;

    for (int x = 1; tmp->next != NULL && x != page; tmp = tmp->next, x++);
    if (tmp->next == NULL) {
        add = tmp->size;
        new = tmp + sizeof(struct t_data) + size;
        adapt_end(size, new, data->end);
        new->next = NULL;
        new->end = data->end;
        new->address_end = tmp->address_end;
        new->status = 0;
        new->size = tmp->size - size;
        tmp->next = new;
        tmp->address_end = new;
        tmp->status = 1;
        tmp->size = size;
        return ((tmp + sizeof(struct t_data)));
    }
    return (useback_data(tmp, size));
}

void *first_data(size_t size)
{
    struct t_data *tmp = data;
    struct t_data *new = NULL;
    size_t add = 0;

    if (tmp->next == NULL) {
        add = tmp->size;
        new = tmp + sizeof(struct t_data) + size;
        adapt_end(size, new, &data->end);
        new->next = NULL;
        new->address_end = tmp->address_end;
        new->status = 0;
        new->end = data->end;
        new->size = tmp->size - size;
        tmp->next = new;
        tmp->address_end = new;
        tmp->status = 1;
        tmp->size = size;
        return ((tmp + sizeof(struct t_data)));
    }
    return (linked_data(bestfit(size), size));
}

void *malloc(size_t size)
{
    static int access = 0;
    void *address = NULL;

    if (size == 0) return (NULL);
    if (access == 0) {
        init_struct(size);
        access = 1;
    }
    address = first_data(size);
    return (address);
}
