/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../../includes/lib.h"
#include "../../../includes/minishell.h"

int env_command(shell_t *shell)
{
    int i = 0;

    while (shell->env[i]) {
        my_printf("%s\n", shell->env[i]);
        i++;
    }

    return 0;
}
