/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** task03, pool day 4
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return 0;

    for (; str[len]; len++);

    return len;
}
