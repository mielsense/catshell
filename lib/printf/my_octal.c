/*
** EPITECH PROJECT, 2022
** my_octal
** File description:
** my_octal
*/

void my_putchar(char c);
int my_error_output(char const *str);

void my_octal(int n)
{
    int res;

    if (n == 0)
        my_putchar(48);
    if (n >= 8) {
        res = n % 8;
        n = n / 8;
        my_octal(n);
    } else if (n > 0) {
        res = n % 8;
        n = n / 8;
    }
    my_putchar(res + 48);
}
