/*
** EPITECH PROJECT, 2022
** my_putdouble
** File description:
** my_putdouble
*/

void my_putchar(char c);
int my_error_output(char const *str);

int	my_putdouble(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        double val = (n % 10);
        my_putdouble((n - val) / 10);
        my_putchar(48 + val);
    } else
        my_putchar((n % 10) + '0');
    return 0;
}
