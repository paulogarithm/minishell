/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** vaguelette
*/

#include <unistd.h>

char *my_addstr(char *str1, char *str2);
char *my_addchar(char *str, char c);

char *env_get(char **env, char *value);
int error(char *str);

char *replace_vaguelette(char *str, char **env)
{
    char *new_str = "";
    int n = 1;
    char *home = env_get(env, "HOME");
    if (home == NULL)
        error("Could not find HOME env.");
    new_str = my_addchar(new_str, str[0]);
    while (str[n]) {
        if (str[n] == '~' && str[n - 1] == ' ') {
            new_str = my_addstr(my_addstr(new_str, "/"), home);
            ++ n;
        }
        new_str = my_addchar(new_str, str[n]);
        ++ n;
    }
    return new_str;
}
