/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** task 02, pool day 4
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
