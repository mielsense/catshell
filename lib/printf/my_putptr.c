/*
** EPITECH PROJECT, 2022
** my_putptr
** File description:
** my_putptr
*/

void my_low_hexa(int n);
int my_putstr(char const *str);

void my_putptr(int n)
{
    my_putstr("0x");
    my_low_hexa(n);
}
