/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

char *parse_path(shell_t *shell, char *var)
{
    char *path;
    int i = 0;

    for (; shell->env[i]; i++)
        if (my_strncmp(shell->env[i], var, my_strlen(var)) == 0)
            break;

    path = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 1));
    path = my_strcpy(path, shell->env[i]);

    return path;
}

char *format_prompt(char *path)
{
    char **formated_path = my_str_to_word_array(path, '/');
    int len = get_arr_len(formated_path) - 1;
    formated_path[len][my_strlen(formated_path[len])] = '\0';

    return (formated_path[len]);
}

void show_prompt(shell_t *shell)
{
    char *path = parse_path(shell, "PWD");
    char *user_prompt = format_prompt(path);

    my_printf("\n");
    if (my_strcmp(user_prompt, "PWD=") != 0)
        my_printf("\033[35m~/%s\033[0m ", user_prompt);

    my_printf("\033[35mʕ\033[0m\033[33m•̀\033[0m\033[34mᴥ");
    my_printf("\033[0m\033[33m•̀\033[0m\033[35mʔっ\033[0m$ ");
}
