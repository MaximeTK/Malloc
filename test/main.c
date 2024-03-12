/*
** EPITECH PROJECT, 2021
** a
** File description:
** a
*/

#include <unistd.h>
#include "malloc.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    int z = 0;

    while (str != NULL && str[z] != '\0') {
        my_putchar(str[z]);
        z++;
    }
}

char *copy(char *str, char *tmp)
{
    int x = 0;

    for (; tmp[x] != '\0'; str[x] = tmp[x], x++);
    str[x] = '\0';
    return (str);
}

int main(void)
{
    char *str = calloc(15, sizeof(char));

    my_putstr(str);
    my_putstr("\n");
    str = copy(str, "HELLO WORLD");
    my_putstr(str);
    my_putstr("\n");
    free(str);
    return (0);
}
