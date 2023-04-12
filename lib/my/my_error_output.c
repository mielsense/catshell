/*
** EPITECH PROJECT, 2022
** error_output
** File description:
** error_output
*/

#include <unistd.h>

void error_print(char c)
{
    write(2, &c, 1);
}

int my_error_output(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        error_print(str[i]);
        i++;
    }
    return 84;
}
