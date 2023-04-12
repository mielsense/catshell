/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

void free_all(shell_t *shell)
{
    free_array(shell->env);
    free_array(shell->aliases);
    free_array(shell->config);
    free(shell);
}

void free_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_commands(char ***tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free_array(tab[i]);
    free(tab);
}
