/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int redirection_getter(shell_t *shell)
{
    int i = 0;

    while (shell->commands[shell->i][i]) {
        if (my_strcmp(shell->commands[shell->i][i], ">") == 0) {
            shell->redirections = 1;
            shell->filename = shell->commands[shell->i][i + 1];
            return (redirection_handler(shell));
        }
        if (my_strcmp(shell->commands[shell->i][i], "<") == 0) {
            shell->redirections = 2;
            shell->filename = shell->commands[shell->i][i + 1];
            return (redirection_handler(shell));
        }
        i++;
    }

    return 0;
}
