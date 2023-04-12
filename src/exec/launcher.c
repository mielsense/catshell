/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int execute(shell_t *shell, char *path)
{
    pid_t pid = fork();
    int state = 0;

    if (pid == -1)
        exit(84);

    if (pid > 0) {
        waitpid(pid, &state, 0);
    } else {
        if (execve(path, shell->commands[shell->i], shell->env) == -1)
            permission_errors(shell);
        exit(1);
    }

    if (launcher_errors(state) == 1)
        return 1;

    shell->exit_state = WEXITSTATUS(state);
    return 0;
}

int exec_launcher(shell_t *shell, char *path, char *command)
{
    char *unique_path = get_unique_path(path, command);

    if (access(unique_path, X_OK) == 0) {
        execute(shell, unique_path);
        free(unique_path);
        return 1;
    }
    free(unique_path);
    return 0;

}
