/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int exec_handler(shell_t *shell)
{
    if (error_handler(shell, 2) == 84)
        return 1;
    char **path = my_str_to_word_array(get_env_var(shell, "PATH"), ':');
    char *command = shell->commands[shell->i][0];
    int i = 0;

    if (my_strcmp(command, "") == 0)
        return 0;
    if (access(command, X_OK) == 0)
        return execute(shell, command);
    while (path[i]) {
        if (exec_launcher(shell, path[i], command) == 1)
            return shell->exit_state;
        i++;
    }
    if (!shell->u_command) {
        my_printf("%s: Command not found.\n", command);
        return 1;
    }
    return 0;
}
