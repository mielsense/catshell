/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../includes/lib.h"
#include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    shell_t *shell = malloc(sizeof(shell_t) + 1);
    parse_config(shell, ".config/init.txt");
    (void)av;

    if (ac != 1) {
        my_error_output("Error : no arguments are to be given !");
        exit(84);
    }

    if (get_env(shell, env) == 84)
        exit(84);

    if (error_handler(shell, 1)) {
        exit(84);
    }

     if (isatty(STDIN_FILENO))
        startup_art(shell->art);

    return shell_handler(shell);
}
