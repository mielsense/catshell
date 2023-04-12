/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int simple_out(shell_t *shell)
{
    int fd_file = 0;
    int keep_fd = dup(STDOUT_FILENO);
    fd_file = open(shell->filename, O_CREAT | O_RDWR | O_TRUNC, 00664);

    if (redirection_errors(fd_file, keep_fd, 1) == 1)
        return 1;

    shell_loop(shell);

    if (redirection_errors(fd_file, keep_fd, 1) == 1)
        return 1;

    return 0;
}
