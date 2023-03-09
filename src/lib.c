/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** lib
*/

#include <unistd.h>
#include <stdlib.h>

char *my_dupstr(char *str);
int my_countstr(char *str);
char *my_cutstr(char *str1, int beggin, int end);
int my_compstr(char *str1, char *str2);
int my_printf(char *str, ...);

int is_letter(char c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

int get_arraylen(char **array)
{
    int n = 0;
    while (array[n] != NULL)
        n += 1;
    return n;
}

char **remove_from_array(char **array, char *key)
{
    int array_len = get_arraylen(array);
    int key_len = my_countstr(key);
    char **new = malloc(sizeof(char *) * (array_len + 1));
    int n = 0;
    int i = 0;
    while (array[n] != NULL) {
        if (my_compstr(my_cutstr(array[n], 0, key_len), key)) {
            n += 1;
            continue;
        }
        new[i] = my_dupstr(array[n]);
        n += 1;
        i += 1;
    }
    new[i] = NULL;
    return new;
}
