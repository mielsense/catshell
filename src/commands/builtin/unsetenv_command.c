/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../../includes/lib.h"
#include "../../../includes/minishell.h"

int unsetenv_command(shell_t *shell)
{
    if (shell->commands[shell->i][1] == NULL) {
        my_error_output("unsetenv: Too few arguments.");
        return 1;
    }

    int state = 0;
    int len = my_strlen(shell->commands[shell->i][1]);

    for (int i = 0; shell->env[i]; i++) {
        if (!my_strncmp(shell->env[i], shell->commands[shell->i][1], len)) {
            free(shell->env[i]);
            state = 1;
        }
        if (state == 1)
            shell->env[i] = shell->env[i + 1];
    }
    return 0;
}
