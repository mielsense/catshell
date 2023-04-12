/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../../includes/lib.h"
#include "../../../includes/minishell.h"

void change_pwd(shell_t *shell, int i)
{
    char *str = malloc(sizeof(char) * 1024);

    if (str == NULL)
        exit(84);
    if (getcwd(str, 1024) == NULL)
        return;
    if (shell->env[i] != NULL)
        free(shell->env[i]);
    else
        shell->env[i + 1] = NULL;
    shell->env[i] = malloc(sizeof(char) * (my_strlen(str) + 5));
    if (shell->env[i] == NULL)
        exit(84);
    shell->env[i] = my_strcpy(shell->env[i], "PWD=");
    shell->env[i] = my_strcat(shell->env[i], str);
    free(str);
    return;
}

void change_oldpwd(shell_t *shell)
{
    int i = 0, j = 0;

    for (; shell->env[i] != NULL; i++)
        if (my_strncmp(shell->env[i], "PWD", 3) == 0)
            break;
    for (; shell->env[j] != NULL; j++)
        if (my_strncmp(shell->env[j], "OLDPWD", 6) == 0)
            break;
    if (shell->env[i] == NULL) {
        change_pwd(shell, i);
        return;
    }
    if (shell->env[j] != NULL)
        free(shell->env[j]);

    shell->env[j] = malloc(sizeof(char) * (my_strlen(shell->env[i]) + 4));
    shell->env[j] = my_strcpy(shell->env[j], "OLD");
    shell->env[j] = my_strcat(shell->env[j], shell->env[i]);
    change_pwd(shell, i);
}

int cd_command(shell_t *shell)
{
    int special = 0;
    int i = shell->i;

    if (shell->commands[i][2]) {
        my_error_output("cd: Too many arguments.\n");
        return 1;
    }
    if (shell->commands[i][1] == NULL
            || my_strcmp(shell->commands[i][1], "~") == 0) {
        chdir(get_env_var(shell, "HOME"));
        special = 1;
    }
    if (chdir(shell->commands[i][1]) && special == 0) {
        my_printf("%s: ", shell->commands[i][1]);
        my_printf("%s.\n", strerror(errno));
        return 1;
    }
    change_oldpwd(shell);

    return 0;
}
