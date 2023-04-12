/*
** EPITECH PROJECT, 2022
** my_putlong
** File description:
** my_putlong
*/

void my_putchar(char c);

long my_putlong(long n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        long val = (n % 10);
        my_putlong((n - val) / 10);
        my_putchar(48 + val);
    } else
        my_putchar((n % 10) + '0');
    return 0;
}
