/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** task03, pool day 6 - reverse a string
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    char temp_str[my_strlen(str) + 1];

    for (int i = 0; i <= my_strlen(str); i++)
        temp_str[i] = str[i];
    for (int i = 0; i < my_strlen(temp_str); i++)
        str[i] = temp_str[my_strlen(temp_str) - 1 - i];
    return str;
}
