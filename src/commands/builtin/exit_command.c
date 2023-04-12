/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../../includes/lib.h"
#include "../../../includes/minishell.h"

int exit_command(shell_t *shell)
{
    if (shell->i < shell->max - 1)
        return 0;

    if (get_arr_len(shell->commands[shell->i]) > 1) {
        if (my_str_is_num(shell->commands[shell->i][1])) {
            my_printf("exit: Expression Syntax.");
            return 1;
        }
        exit(my_getnbr(shell->commands[shell->i][1]));
    } else
        exit(0);

}
