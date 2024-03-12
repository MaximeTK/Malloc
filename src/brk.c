/*
** EPITECH PROJECT, 2021
** brk
** File description:
** brk
*/

#include "malloc.h"

extern struct t_data *data;

size_t adapt_end(size_t size, void *new, void *end)
{
    size_t add = 0;
    size_t res = 0;
    size_t tmp = 0;
    int value = 2;

    if ((void *)new > end) {
        add = ((void *)new - end);
        if (add % (getpagesize() * value) != 0) {
            tmp = add / (getpagesize() * value);
            res = add - ((getpagesize() * 2) * tmp);
            add = add + ((getpagesize() * 2) - res);
        }
        add = add / (getpagesize() * value);
        add = add + 2;
        sbrk(add * (getpagesize() * value));
        end = sbrk(0);
    }
}
