/*
** EPITECH PROJECT, 2023
** my_messaging
** File description:
** my_printf
*/

#include <stdarg.h>

char *my_addchar(char *str, char c);
char *my_addstr(char *str, char *str2);
int my_countstr(char *str);
void my_putstr(char *str);
char *my_conv_nb_str(int nb);

char *process_args(const char *format, int *n, va_list ap)
{
    *n += 1;
    switch (format[*n]) {
    case 'i':
    case 'd':
        return my_conv_nb_str(va_arg(ap, int));
    case 's':
        return va_arg(ap, char *);
    case 'c':
        return my_addchar("", (char) va_arg(ap, int));
    case '%':
        return "%";
    default:
        return my_addchar("%", format[*n]);
        break;
    }
}

int my_printf(const char *format, ...)
{
    int n = 0;
    int count = 0;
    char *str = "";
    va_list ap;

    va_start(ap, format);
    while (format[n] != '\0') {
        if (format[n] == '%') {
            str = my_addstr(str, process_args(format, &n, ap));
            n += 1;
        }
        if (format[n] == '\0')
            break;
        str = my_addchar(str, format[n ++]);
        count += 1;
    }
    my_putstr(str);
    return my_countstr(str);
}
