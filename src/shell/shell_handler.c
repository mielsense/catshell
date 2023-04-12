/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int run_loop(shell_t *shell)
{
    if (shell->use_aliases == 1)
        is_alias(shell);

    shell->exit_state = command_handler(shell);

    if (shell->exit_state == 3)
        if (exec_handler(shell) == 1 && shell->state == 0)
            return 1;

    free_array(shell->commands[shell->i]);
    return shell->exit_state;
}

int shell_loop(shell_t *shell)
{
    if (shell->redirections == 0)
        redirection_getter(shell);

    while (shell->commands[shell->i] != NULL) {
        shell->exit_state = run_loop(shell);
        shell->u_command = 0;
        shell->i++;
    }

    free(shell->commands);
    return shell->exit_state;
}

int shell_handler(shell_t *shell)
{
    int state = 0;

    if (shell->use_aliases == 1)
        get_aliases(shell);

    shell->state = isatty(STDIN_FILENO);
    shell->exit_state = state;
    shell->redirections = 0;

    while (1) {
        if (shell->state == 1)
            show_prompt(shell);

        get_command(shell);
        shell->i = 0;

        if (shell_loop(shell) == 1)
            return EXIT_FAILURE;
    }
    state = shell->exit_state;

    free_all(shell);
    return state;
}
