/*
** EPITECH PROJECT, 2023
** project_template
** File description:
** TODO: add description
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    if (n == 0)
        return 0;

    while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
        i++;

    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return 0;

    if (s1[i] > s2[i])
        return 1;
    else
        return -1;
}
