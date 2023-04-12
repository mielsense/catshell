/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int start_errors(shell_t *shell)
{
    if (shell->env == NULL)
        return 84;

    return 0;
}

int env_errors(shell_t *shell)
{
    if (get_arr_len(shell->commands[shell->i]) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 84;
    }
    if (!my_isnum(shell->commands[shell->i][1][0])) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    if (!my_str_is_alpha_num(shell->commands[shell->i][1])) {
        my_printf("setenv: Variable name ");
        my_printf("must contain alphanumeric characters.\n");
        return 84;
    }

    return 0;
}

int exec_errors(shell_t *shell)
{
    int i = 0;

    while (shell->commands[shell->i][i]) {
        if (shell->commands[shell->i][i][0] == '.') {
            my_printf("%s: Command not found.\n", shell->commands[shell->i][i]);
            return 84;
        }
        i++;
    }
    return 0;
}

int launcher_errors(int status)
{
    if (WIFSIGNALED(status)) {
        int sig = WTERMSIG(status);
        switch (sig) {
            case 11: my_printf("Segmentation fault\n");
            case 8: my_printf("Floating exception\n");
            default: my_printf("%s", strerror(errno));
        }
        return 1;
    }
    return 0;
}

void permission_errors(shell_t *shell)
{
    my_printf("%s: ", shell->commands[shell->i][0]);

    if (errno == EACCES)
        my_printf("%s.\n", strerror(errno));
    if (errno == ENOEXEC) {
        my_printf("%s. Wrong Architecture.\n", strerror(errno));
    }
}
