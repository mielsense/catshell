/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int get_art(shell_t *shell)
{
    int i = 0;
    char **art = NULL;

    while (shell->config[i] != NULL) {
        if (my_strncmp(shell->config[i], "startup_art", 11) == 0) {
            art = malloc(sizeof(char *) * (my_strlen(shell->config[i]) + 1));
            art = my_str_to_word_array(shell->config[i], '=');
        }
        i++;
    }

    if (read_file(art[1]) == NULL)
        return 1;

    shell->art = art[1];
    return 0;
}

int parse_config(shell_t *shell, char *path)
{
    char *config_input = read_file(path);
    int i = 0;

    shell->config = malloc(sizeof(char *) * my_strlen(config_input) + 1);
    shell->config = my_str_to_word_array(config_input, '\n');

    while (shell->config[i]) {
        if (my_strcmp(shell->config[i], "use_aliases=1") == 0) {
            shell->use_aliases = 1;
            break;
        } else
            shell->use_aliases = 0;
        i++;
    }

    if (get_art(shell) == 1)
        shell->art = "ressources/startup_art";
    return 0;
}
