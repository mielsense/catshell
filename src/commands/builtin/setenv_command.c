/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../../includes/lib.h"
#include "../../../includes/minishell.h"

char *format_env(shell_t *shell)
{
    int i = shell->i;
    int t_len = my_strlen(shell->commands[i][1])
        + my_strlen(shell->commands[i][2]);
    char *formated_env = malloc(sizeof(char) * t_len + 1);

    formated_env = my_strcpy(formated_env, shell->commands[i][1]);
    formated_env[my_strlen(shell->commands[i][1])] = '=';
    formated_env[my_strlen(shell->commands[i][1]) + 1] = '\0';

    if (shell->commands[i][2] != NULL)
        formated_env = my_strcat(formated_env, shell->commands[i][2]);

    return formated_env;
}

int setenv_command(shell_t *shell)
{
    char **temp_env = NULL;
    char *added_env = format_env(shell);
    int len = my_strlen(shell->commands[shell->i][1]);
    int i = 0;

    for (; shell->env[i] != NULL; i++)
        if (!my_strncmp(shell->commands[shell->i][1], shell->env[i], len - 1)) {
            free(shell->env[i]);
            shell->env[i] = added_env;
            return 0;
        }

    temp_env = copy_array(shell->env);
    free_array(shell->env);
    shell->env = temp_env;
    shell->env[i] = added_env;
    shell->env[i + 1] = NULL;
    return 0;
}

int setenv_handler(shell_t *shell)
{
    if (get_arr_len(shell->commands[shell->i]) == 1) {
        env_command(shell);
        return 0;
    }

    if (error_handler(shell, 3) == 84)
        return 1;

    return setenv_command(shell);
}
