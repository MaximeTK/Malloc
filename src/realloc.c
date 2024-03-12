/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include "malloc.h"

extern struct t_data *data;


#include "malloc.h"

extern struct t_data *data;

void *realloc(void *ptr, size_t size)
{
    void *new = malloc(size);

    free(ptr);
    return (new);
}

void *reallocarray(void *ptr , size_t  nmemb , size_t  size)
{
    if (nmemb * size == 0) return (NULL);
    return (realloc(ptr, nmemb * size));
}
