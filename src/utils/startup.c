/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include "../../includes/lib.h"
#include "../../includes/minishell.h"

void print_image(FILE *fptr)
{
    char read_string[128];

    my_printf("\n\n");
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        my_printf("\033[35m%s\033[0m", read_string);
    my_printf("\n\n");
}

int startup_art(char *filename)
{
    FILE *fptr = NULL;

    if ((fptr = fopen(filename,"r")) == NULL) {
        my_printf("error opening %s\n", filename);
        return 1;
    }

    print_image(fptr);
    fclose(fptr);
    return 0;
}
