/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <stdlib.h>

int my_printf(char *str, ...);
int my_countstr(char *str);
char *my_cutstr(char *str, int beggin, int end);
char *my_dupstr(char *str);

char **my_addin_array(char **array, char *str)
{
    char **new_array;
    int size = 0;
    int n = 0;

    if (!my_countstr(str))
        return array;

    while (array[size] != NULL)
        size ++;
    size += 1;

    new_array = malloc(sizeof(char *) * (size + 1));
    while (array[n] != NULL) {
        new_array[n] = array[n];
        n += 1;
    }
    new_array[n] = str;
    new_array[n + 1] = NULL;
    return new_array;
}

char **my_conv_str_array(char *src)
{
    char **array = malloc(sizeof(char *) * 2);
    int n = 0;
    int index = 0;
    char *cut;

    array[0] = NULL;
    while (1) {
        if (src[n] == ' ' || !src[n] || src[n] == '\t') {
            cut = my_cutstr(src, index, n);
            array = my_addin_array(array, cut);
            index = n + 1;
        }
        if (!src[n])
            break;
        n += 1;
    }
    return array;
}
