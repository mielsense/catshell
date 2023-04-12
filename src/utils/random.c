/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

char **copy_array(char **tab)
{
    int len = get_arr_len(tab);
    char **temp_array = malloc(sizeof(char *) * (len * 2));
    int i = 0;

    while (tab[i]) {
        temp_array[i] = my_strdup(tab[i]);
        i++;
    }
    temp_array[len] = NULL;

    return temp_array;
}

int is_last_char(char *string, int i)
{
    for (; string[i] != '\0'; i++)
        if (string[i] != '\t' && string[i] != '\n' && string[i] != ' ')
            return 0;

    return 1;
}

int new_command(char *string, int ext)
{
    int i = 0;
    for (; string[i] == ' ' || string[i] == '\t'; i++);

    for (; string[i] != '\0'; i++)
        if (check_up(string, i) == 1 && i == ext
                && is_last_char(string, i) == 0)
            return 1;

    return 0;
}

int check_up(char *string, int i)
{
    if (string[i] == '\t' || string[i] == ' ')
        if (string[i + 1] != '\t' && string[i + 1] != ' '
            && string[i + 1] != '\0')
            return 1;

    return 0;
}
