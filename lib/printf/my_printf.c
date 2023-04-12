/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** Recreating the "printf" function (w/romain)
*/

#include "../include/printf.h"

void hashtag_format(const char *format, va_list args, int i)
{
    int arg = va_arg(args, int);

    switch (format[i + 1]) {
        case 'o':
            if (arg != 0)
                my_octal(arg);
            break;
        case 'x':
            if (arg != 0)
                my_putstr("0x");
            my_low_hexa(arg);
            break;
        case 'X':
            if (arg != 0)
                my_putstr("0X");
            my_high_hexa(arg);
            break;
    }
}

void void_format(const char *format, va_list args, int i)
{
    switch (format[i + 1]) {
        case 'd':
        case 'i':
            my_putchar(' ');
            my_put_nbr(va_arg(args, int)); break;
    }
}

void case_handler(const char *flags, va_list args, int i)
{
    switch (flags[i + 1]) {
        case '%': my_putchar('%'); break;
        case 's': my_putstr(va_arg(args, char *)); break;
        case 'c': my_putchar(va_arg(args, int)); break;
        case 'd':
        case 'i': my_put_nbr(va_arg(args, int)); break;
        case 'n': my_put_nbr(my_strlen(flags)); break;
        case 'u': my_put_nbr(va_arg(args, unsigned int)); break;
        case 'o': my_octal(va_arg(args, int)); break;
        case 'X': my_high_hexa(va_arg(args, int)); break;
        case 'x': my_low_hexa(va_arg(args, int)); break;
        case 'f': my_putdouble(va_arg(args, double)); break;
        case 'l': my_putlong(va_arg(args, long)); break;
        case 'p': my_putptr(va_arg(args, int)); break;
        case 'b': my_binary(va_arg(args, unsigned int)); break;
        case 'S': my_nonprintable_char(va_arg(args, char *)); break;

        case '#' : hashtag_format(flags, args, i + 1); break;
        case ' ': void_format(flags, args, i + 1); break;
    }
}

int my_printf(const char *str, ...)
{
    va_list args;
    int i = 0;

    va_start(args, str);
    if (str[i] == '\0'){
        my_error_output("String is empty");
        return 84;
    }
    while (str[i] != '\0') {
        if (str[i] == '%') {
            case_handler(str, args, i);
            i += 1 + (str[i + 1] == '#') + (str[i + 1] == ' ');
        } else
            my_putchar(str[i]);
        i++;
    }
    va_end(args);
    return 0;
}
