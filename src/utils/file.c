/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

char *read_file(char const *filepath)
{
    char *res;
    int fd, bs;
    struct stat *size = malloc(sizeof(struct stat));

    stat(filepath, size);
    if ((fd = open(filepath, O_RDONLY)) == -1) {
        return NULL;
    }

    res = malloc((size->st_size + 1) * sizeof(int));
    if ((bs = read(fd, res, size->st_size)) == -1) {
        return NULL;
    }
    close(fd);
    return res;
}
