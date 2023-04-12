/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int simple_in(shell_t *shell)
{
    int fd_file = 0;
    int keep_fd = dup(STDIN_FILENO);
    fd_file = open(shell->filename, O_RDONLY);

    if (redirection_errors(fd_file, keep_fd, 1) == 1)
        return 1;

    shell_loop(shell);

    if (redirection_errors(fd_file, keep_fd, 2) == 1)
        return 1;

    return 0;
}
