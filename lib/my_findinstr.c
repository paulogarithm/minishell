/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** my_findinstr
*/

int my_countstr(char *str);

int my_findinstr(char *src, char *fnd)
{
    int s = 0;
    int f = 0;

    while (src[s] != '\0') {
        if (src[s] == fnd[f])
            f += 1;
        else
            f = 0;
        if (f >= my_countstr(fnd))
            return s;
        s += 1;
    }
    return -1;
}
