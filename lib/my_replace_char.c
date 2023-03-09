/*
** EPITECH PROJECT, 2023
** sh_beggin
** File description:
** my_replaceallchars
*/

char *my_replace_char(char *str, char replace, char by)
{
    int n = 0;
    while (str[n]) {
        if (str[n] == replace)
            str[n] = by;
        n += 1;
    }
    return str;
}
