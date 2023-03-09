/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** my_dupstr
*/

#include <stdlib.h>

int my_countstr(char *str);

char *my_dupstr(char *src)
{
    int size = my_countstr(src);
    char *str = malloc(sizeof(char) * (size + 1));
    int n = 0;

    if (str == NULL)
        return NULL;
    while (src[n] != '\0') {
        str[n] = src[n];
        n += 1;
    }
    str[n] = '\0';
    return str;
}
