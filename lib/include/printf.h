/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** bsprintf.h for my_printf
*/

#ifndef PRINTF_H_
    #define PRINTF_H_

    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>

    int my_put_nbr(int nb);
    void my_putchar(char c);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int	my_putdouble(int n);
    long my_putlong(long n);
    void my_binary(int n);
    void my_octal(int n);
    void my_high_hexa(int n);
    void my_low_hexa(int n);
    void my_putptr(int n);
    int my_error_output(char const *str);
    void error_print(char c);
    void my_nonprintable_char(char const *str);
    void convert_char(char c);
    void hashtag_format(const char *format, va_list args, int i);
    void void_format(const char *format, va_list args, int i);

#endif /* !PRINTF_H_ */
