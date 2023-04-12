/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int redirection_handler(shell_t *shell)
{
    switch (shell->redirections) {
        case 1: return (simple_out(shell));
        case 2: return (simple_in(shell));
        default: return 0;
    }

    return 0;
}
