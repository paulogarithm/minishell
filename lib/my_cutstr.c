/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_cutstr
*/

char *my_addchar(char *str, char c);

char *my_cutstr(char *str, int beggin, int end)
{
    int n = beggin;
    char *new = "";

    while (str[n] && n < end)
        new = my_addchar(new, str[n++]);
    new = my_addchar(new, '\0');
    return new;
}
