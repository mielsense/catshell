/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-minishell1-mathis.rapaccioli
** File description:
** TODO: add description
*/

#ifndef MINISHELL_H
    #define MINISHELL_H

    #include <string.h>
    #include <sys/types.h>
    #include <errno.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <stdlib.h>
    #include <stdio.h>

    typedef struct shell_s {
        char ***commands;
        char **env;
        char *filename;
        char **config;
        char **aliases;
        char *art;
        int u_command;
        int use_aliases;
        int redirections;
        int state;
        int i;
        int max;
        int exit_state;
        int env_lenght;
        int is_args;
    } shell_t;

    // shell
        int shell_handler(shell_t *shell);
        int shell_loop(shell_t *shell);

    // commands
        int get_command(shell_t *shell);
        void format_commands(shell_t *shell, char *commands);
        void format(shell_t *shell, char *commands, int len, int n);
        int command_handler(shell_t *shell);
        int config_commands(shell_t *shell);
        // implemented
            int cd_command(shell_t *shell);
            int env_command(shell_t *shell);
            int exit_command(shell_t *shell);
            int setenv_handler(shell_t *shell);
            int unsetenv_command(shell_t *shell);

    // exec
        int exec_handler(shell_t *shell);
        int exec_launcher(shell_t *shell, char *path, char *command);
        int execute(shell_t *shell, char *path);

        // getters
            char *get_unique_path(char *path, char *command);

    // redirections
        int redirection_getter(shell_t *shell);
        int redirection_handler(shell_t *shell);

        // errors
            int redirection_errors(int fd_file, int keep_fd, int state);

        // types
            int simple_out(shell_t *shell);
            int simple_in(shell_t *shell);

    // errors
        int error_handler(shell_t *shell, int type);
        int start_errors(shell_t *shell);
        int env_errors(shell_t *shell);
        int exec_errors(shell_t *shell);
        int launcher_errors(int status);
        void permission_errors(shell_t *shell);

        int my_str_is_alpha_num(char *str);
        int my_isnum(const char c);

    // utils
        // getters
            int get_arr_len(char **arr);
            int get_env(shell_t *shell, char **env);
            char *get_env_var(shell_t *shell, char *var);
            int get_word_number(char *string);

        // prompt
            void show_prompt(shell_t *shell);

        // random
            int check_up(char *string, int i);
            int new_command(char *string, int ext);
            void free_array(char **tab);
            char **copy_array(char **tab);

        // config / startup
            int parse_config(shell_t *shell, char *path);
            int startup_art(char *filename);
            // aliases
                int get_aliases(shell_t *shell);
                int is_alias(shell_t *shell);

        // free
            void free_array(char **tab);
            void free_commands(char ***tab);
            void free_all(shell_t *shell);

        // file
            char *read_file(char const *filepath);

#endif //MINISHELL_H
