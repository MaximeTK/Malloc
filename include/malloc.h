/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef MALLOC_H_
#define MALLOC_H_

typedef struct t_data
{
    int status;
    size_t size;
    void *address_end;
    void *end;
    struct t_data *next;
} s_data;

void free_a_place(int x);

void my_putchar(char c);

void my_new_putchar(char const *str);

void my_putstr(char const *str);

void my_put_nbr(int nb);

int bestfit(size_t size);

size_t adapt_end(size_t size, void *new, void *end);

void verif_brk(void);

void *calloc(size_t elementCount, size_t elementSize);

#endif
