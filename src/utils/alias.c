/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int is_alias(shell_t *shell)
{
    int i = 0;
    int len = 0;
    char **alias = NULL;

    while (shell->aliases[i] != NULL) {
        alias = malloc(sizeof(char *) * my_strlen(shell->aliases[0]) + 1);
        alias = my_str_to_word_array(shell->aliases[i], ':');

        if (my_strcmp(shell->commands[shell->i][0], alias[1]) == 0) {
            len = my_strlen(alias[2]);
            format(shell, alias[2], len, shell->i);
            return 1;
        }
        i++;
    }
    return 0;
}

int get_aliases(shell_t *shell)
{
    shell->aliases = malloc(sizeof(char *) * (1024 + 1));

    int i = 0, count = 0;

    while (shell->config[i] != NULL) {
        if (my_strncmp(shell->config[i], "alias", 5) == 0) {
            shell->aliases[count] = malloc(sizeof(char *) + 1);

            my_strcpy(shell->aliases[count], shell->config[i]);
            count++;
        }
        i++;
    }
    return 0;
}
