/*
** EPITECH PROJECT, 2022
** B-CPE-101-LYN-1-1-myprintf-romain.joanenc
** File description:
** my_nonprintable_char
*/

void my_putchar(char c);
int my_put_nbr(int nbr);

void convert_char(char c)
{
    my_putchar('\\');
    if (c < 10) {
        my_putchar('0');
        my_putchar('0');
    } else if (c >= 10)
        my_putchar('0');
    my_put_nbr(c);
}

void my_nonprintable_char(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127)
            convert_char(str[i]);
        else
            my_putchar(str[i]);
        i++;
    }
}
