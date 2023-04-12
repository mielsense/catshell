/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int personal_commands(shell_t *shell, char *command)
{
    if (my_strcmp(command, "art") == 0) {
        startup_art(shell->art);
        shell->u_command = 1;
        return 0;
    }
    if (my_strcmp(command, "set") == 0) {
        config_commands(shell);
        return 0;
    }

    return 3;
}

int env_commands(shell_t *shell, char *command)
{
    if (my_strcmp(command, "setenv") == 0)
        return setenv_handler(shell);

    if (my_strcmp(command, "unsetenv") == 0)
        return unsetenv_command(shell);

    if (my_strcmp(command, "env") == 0)
        return env_command(shell);

    if (my_strcmp(command, "mysh") == 0) {
        my_printf("mysh: Command not found.");
        return 1;
    }

    return personal_commands(shell, command);
}

int command_handler(shell_t *shell)
{
    char *command = malloc(sizeof(char *) + 1);
    command = shell->commands[shell->i][0];

    if (my_strcmp(command, "cd") == 0)
        return cd_command(shell);

    if (my_strcmp(command, "exit") == 0)
        return exit_command(shell);

    return env_commands(shell, command);
}
