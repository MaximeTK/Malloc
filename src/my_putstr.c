/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** str
*/

#include <stddef.h>

void my_new_putchar(char const *str);

void my_putchar(char c);

void my_putstr(char const *str)
{
    int z = 0;

    while (str != NULL && str[z] != '\0') {
        my_putchar(str[z]);
        z++;
    }
}
