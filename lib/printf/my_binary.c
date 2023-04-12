/*
** EPITECH PROJECT, 2022
** my_binary
** File description:
** my_binary
*/

void my_putchar(char c);

void my_binary(int n)
{
    int res;

    if (n >= 2) {
        res = n % 2;
        n = n / 2;
        my_binary(n);
    } else if (n > 0) {
        res = n % 2;
        n = n / 2;
    }
    my_putchar(res + 48);
}
