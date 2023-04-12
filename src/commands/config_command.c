/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

int use_aliases(shell_t *shell, char *arg_1, char *arg_2)
{
    if (my_strcmp(arg_1, "use_aliases") == 0) {
        if (my_strcmp(arg_2, "1") == 0) {
            shell->use_aliases = 1;
            get_aliases(shell);
            my_printf("succesfully turned on aliases\n");
            return 1;
        }
        if (my_strcmp(arg_2, "0") == 0) {
            shell->use_aliases = 0;
            my_printf("succesfully turned off aliases\n");
        } else {
            my_printf("error : wrong paramater for use_aliases\n");
            my_printf("\tplease only use [1] for ON & [2] for OFF\n");
        }
    } else {
        my_printf("error : wrong paramter for set\n");
        my_printf("\tplease only use : use_aliases");
    }
    return 0;
}

int config_commands(shell_t *shell)
{
    char *arg_1 = shell->commands[shell->i][1];
    char *arg_2 = shell->commands[shell->i][2];

    use_aliases(shell, arg_1, arg_2);
    shell->u_command = 1;

    return 0;
}
