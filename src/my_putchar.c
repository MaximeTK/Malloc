/*
** EPITECH PROJECT, 2019
** putchar
** File description:
** putchar
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int x = 0;

    for (; str[x] != '\0'; x++);
    return (x);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_new_putchar(char const *str)
{
    write(1, &str, 1);
}
