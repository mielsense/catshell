/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int error_handler(shell_t *shell, int type)
{
    if (type == 1)
        if (start_errors(shell) == 84)
            return 84;

    if (type == 2)
        if (exec_errors(shell) == 84)
            return 84;

    if (type == 3)
        if (env_errors(shell) == 84)
            return 84;

    return 0;
}
