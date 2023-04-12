/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int rd_start(int fd_file, int keep_fd)
{
    if (keep_fd == -1) {
        my_error_output(strerror(errno));
        return 1;
    }
    if (fd_file == -1) {
        my_error_output(strerror(errno));
        return 1;
    }
    if (dup2(fd_file, STDOUT_FILENO) == -1) {
        my_error_output(strerror(errno));
        return 1;
    }
    return 0;
}

int rd_end(int fd_file, int keep_fd)
{
    close(fd_file);
    if (dup2(keep_fd, STDOUT_FILENO) == -1) {
        my_error_output(strerror(errno));
        return 1;
    }
    close(keep_fd);
    return 0;
}

int redirection_errors(int fd_file, int keep_fd, int state)
{
    if (state == 1)
        return rd_start(fd_file, keep_fd);
    if (state == 2)
        return rd_end(fd_file, keep_fd);

    return 0;
}
