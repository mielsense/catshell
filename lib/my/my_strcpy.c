/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** task01, pool day 4
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int n = my_strlen(src);
    int i;

    for (i = 0; i <= n; i++)
        dest[i] = src[i];

    return dest;
}
