/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

int main(void)
{
    int n = 4, i, *p, s = 0;
    p = (int*) calloc(n, sizeof(int));
    if(p == NULL) {
        printf("\nError! memory not allocated.");
        exit(0);
    }
    printf("\nEnter elements of array : ");
    for(i = 0; i < n; ++i) {
        scanf("%d", p + i);
        s += *(p + i);
    }
    printf("\nSum : %d", s);
    p = (int*) realloc(p, 6);
    printf("\nEnter elements of array : ");
    for(i = 0; i < n; ++i) {
        scanf("%d", p + i);
        s += *(p + i);
    }
    printf("\nSum : %d", s);
    free(p);
    return 0;
}
