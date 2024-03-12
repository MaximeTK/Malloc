/*
** EPITECH PROJECT, 2021
** calloc
** File description:
** calloc
*/

#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

extern struct t_data *data;

void *calloc(size_t elementCount, size_t elementSize)
{
    char *address = NULL;

    if (elementCount * elementSize == 0) return (NULL);
    address = malloc(elementCount * elementSize);
    for (int a = 0; a < elementCount * elementSize; address[a] = 0, a++);
    return ((void *)address);
}
