/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** task05, pool day 4
*/

int my_getnbr(char *str)
{
    int i = 0;
    int sign = 1;
    int nb = 0;

    if (str[i] == '-') {
        sign = -sign;
        i++;
    }

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (nb * 10) + str[i] - '0';
            i++;
        } else
            return (nb * sign);
    }
    return (nb * sign);
}
