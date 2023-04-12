/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int get_ignores(char *string)
{
    int i = 0;
    int res = 0;

    while (string[i]) {
        if (string[i] == '\t' || string[i] == ' ')
            res++;
        i++;
    }

    return res;
}

int get_word_number(char *string)
{
    int res = 0;
    int i = get_ignores(string);

    for (; string[i] != '\0'; i++)
        if (check_up(string, i) == 1)
            res++;
    return (res + 1);
}

int get_arr_len(char **arr)
{
    int res = 0;

    while (*arr) {
        res++;
        arr++;
    }

    return res;
}

char *get_env_var(shell_t *shell, char *var)
{
    char *res_var;
    int len = my_strlen(var) + 1;
    int i = 0;

    for (; shell->env[i]; i++)
        if (my_strncmp(shell->env[i], var, my_strlen(var)) == 0)
            break;

    res_var = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 1));
    res_var = my_strcpy(res_var, shell->env[i]);

    for (; len > 0; len--)
        res_var++;
    return (res_var);
}

int get_env(shell_t *shell, char **env)
{
    int i = 0;
    shell->env_lenght = get_arr_len(env);

    if (env == NULL)
        return 84;

    shell->env = malloc(sizeof(char *) * (shell->env_lenght + 10));
    if (shell->env == NULL)
        return 84;

    while (env[i]) {
        shell->env[i] = my_strdup(env[i]);
        i++;
    }

    shell->env[i] = NULL;
    return 0;
}
