/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** task 06, pool day 6 - reproduce the strcmp dunction
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    if (s1 == NULL || s2 == NULL) {
        return (-1);
    }
    while (s1[i] == s2[i] && s1[i] && s2[i]) {
        i++;
    }
    return (s1[i] - s2[i]);
}
