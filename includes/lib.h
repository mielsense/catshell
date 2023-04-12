/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#ifndef LIB_H
    #define LIB_H

    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <stdio.h>

    //  basic lib functions
    void my_putchar(char c);
    int my_put_nbr(int nb);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_error_output(char const *str);
    int my_printf(const char *str, ...);
    int	my_getnbr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strcat(char *dest, char *src);
    char *my_strncat(char *dest, char *src, int nb);
    char *my_revstr(char *str);
    char *my_strdup(char const *src);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char *s1, char *s2, int n);
    int my_str_is_num(const char *str);
    int my_isnum(const char c);
    char **my_str_to_word_array(char *str, char seperator);

#endif //LIB_H
