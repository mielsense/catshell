/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-minishell1-mathis.rapaccioli
** File description:
** TODO: add description
*/

int my_isnum(const char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    return 1;
}

int my_str_is_num(const char *str)
{
    int i = 0;

    while (str[i]) {
        if (my_isnum(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}
