/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** task02, pool day 6
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
