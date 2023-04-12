/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include <unistd.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (dest == NULL)
        exit(84);
    return (my_strcpy(dest, src));
}
