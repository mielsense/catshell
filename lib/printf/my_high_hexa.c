/*
** EPITECH PROJECT, 2022
** my_high_hexa
** File description:
** my_high_hexa
*/

void my_putchar(char c);
int my_putstr(char const *str);
int my_error_output(char const *str);

void my_high_hexa(int n)
{
    int res;

    if (n >= 16) {
        res = n % 16;
        n = n / 16;
        my_high_hexa(n);
    } else if (n > 0) {
        res = n % 16;
        n = n / 16;
    }

    if (res > 9) {
        my_putchar(res + 55);
    } else
        my_putchar(res + 48);
}
