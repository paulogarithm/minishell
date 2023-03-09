/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_putstr
*/

#include <unistd.h>

int my_countstr(char *str);

void my_putstr(char *str)
{
    write(1, str, my_countstr(str));
}
