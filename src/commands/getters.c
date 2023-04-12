/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

void format(shell_t *shell, char *commands, int len, int n)
{
    int line = 0, caracter = 0;

    for (int i = 0; commands[i] != '\0'; i++) {
        if (new_command(commands, i) == 1) {
            shell->commands[n][line][caracter] = '\0';
            caracter = 0;
            line++;
            shell->commands[n][line] = malloc(sizeof(char) * len + 1);
        }
        if (commands[i] != '\t' && commands[i] != '\n' && commands[i] !=
        ' ') {
            shell->commands[n][line][caracter] = commands[i];
            caracter++;
        }
    }
    if (shell->commands[n][0][0] == '\\')
        shell->commands[n][0]++;

    shell->commands[n][line][caracter] = '\0';
    shell->commands[n][line + 1] = NULL;
}

void format_commands(shell_t *shell, char *commands)
{
    int i = 0;
    int len = my_strlen(commands);
    char **temp = malloc(sizeof(char *) * (len + 1));
    shell->commands = malloc(sizeof(char **) * (len + 1));

    temp = my_str_to_word_array(commands, ';');

    while (temp[i] != NULL) {
        shell->commands[i] = malloc(sizeof(char *) * (len + 1));
        shell->commands[i][0] = malloc(sizeof(char) * (len + 1));
        format(shell, temp[i], len, i);
        i++;
    }

    shell->max = i;
}

int get_command(shell_t *shell)
{
    char *input_commands = NULL;
    size_t len = 0;

    if (getline(&input_commands, &len, stdin) == -1)
        exit(0);

    input_commands[len - 1] = '\0';
    format_commands(shell, input_commands);

    return 0;
}
