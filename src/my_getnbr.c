/*
** EPITECH PROJECT, 2019
** put
** File description:
** str
*/

void my_putchar(char c);

int my_suite(char const *str, int letter, int signe)
{
    int result = 0;
    int diz = 1;

    if (str[letter] < 47 || str[letter] > 58)
        return (0);
    while (str[letter] == 48)
        letter++;
    while (str[letter] >= 47 && str[letter] <= 58 )
        letter++;
    letter--;
    while (str[letter] >= 47 && str[letter] <= 58) {
        result = result + ((str[letter] - 48) * diz);
        letter--;
        diz = diz * 10;
    }
    if (signe < 0)
        result = result * -1;
    return (result);
}

int my_getnbr(char const *str)
{
    int letter = 0;
    int signe = 0;
    int up = 0;

    while (str[letter] > 42 && str[letter] < 46) {
        if (str[letter] == '+')
            signe++;
        if (str[letter] == '-') {
            signe = signe - 1;
            up++;
        }
        if (up == 2) {
            signe = signe + 2;
            up = 0;
        }
        letter++;
    }
    return (my_suite(str, letter, signe));
}
