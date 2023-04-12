/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

char *get_unique_path(char *path, char *command)
{
    int len = my_strlen(path) + my_strlen(command);
    char *unique = malloc((sizeof(char) * len) + 1);

    unique = my_strcpy(unique, path);
    len = my_strlen(unique);

    if (unique[len - 1] != '/') {
        unique[len + 1] = '\0';
        unique[len] = '/';
    }

    unique = my_strcat(unique, command);
    return unique;
}
