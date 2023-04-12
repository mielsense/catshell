/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

#include <stdlib.h>
#include <string.h>

int count_words(char *str, char sep)
{
    int words = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (in_word == 0 && str[i] != sep) {
            words++;
            in_word = 1;
        }
        if (str[i] == sep && in_word == 1)
            in_word = 0;
    }
    return words;
}

int word_length(char *str, int index, char sep)
{
    int i = index;
    int len;

    while (str[i] != '\0' && str[i] != sep)
        i++;
    len = i - index;

    return len;
}

char **verify_res(char **output)
{
    int i = 0;

    while (output[i] != NULL) {
        if (output[i][0] == output[i][1])
            output[i]++;
        i++;
    }

    return output;
}

char **my_str_to_word_array(char *str, char sep)
{
    char **output = malloc(sizeof(char *) * (count_words(str, sep) + 10));
    int in_word = 0, k = 0, j = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (in_word == 0 && str[i] != sep) {
            in_word = 1, k = 1;
            j++;
            output[j] = malloc(sizeof(char) * (word_length(str, i, sep) + 1));
            output[j][k - 1] = str[i];
        }
        if (in_word != 0 && str[i] != sep) {
            output[j][k] = str[i];
            output[j][k + 1] = NULL;
            k++;
        }
        output[j][k] = (in_word && str[i] == sep) ? '\0' : output[j][k];
        in_word = (in_word && str[i] == sep) ? 0 : in_word;
    }
    output[count_words(str, sep)] = NULL;
    return verify_res(output);
}
