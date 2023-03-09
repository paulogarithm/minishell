/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** env
*/

#include <stdlib.h>

char *my_cutstr(char *str, int beggin, int end);
int my_compstr(char *str1, char *str2);
int my_countstr(char *str);
char *my_dupstr(char *src);
char *my_addstr(char *a, char *b);
char **my_addin_array(char **array, char *str);
int my_printf(char *str, ...);

int env_show(char **env)
{
    int n = 0;
    while (env[n] != NULL)
        my_printf("%s\n", env[n ++]);
    return 0;
}

char *env_get(char **env, char *key)
{
    int count = my_countstr(key);
    while (*env) {
        if (my_compstr(my_cutstr(*env, 0, count), key)) {
            char *str = my_dupstr(*env);
            return my_cutstr(str, count + 1, my_countstr(str));
        }
        env++;
    }
    return NULL;
}

char **env_write(char **env, char *key, char *value)
{
    int count = my_countstr(key);
    int n = 0;
    while (env[n] != NULL) {
        if (my_compstr(my_cutstr(env[n], 0, count), key)) {
            char *str = my_addstr(my_addstr(key, "="), value);
            env[n] = malloc(sizeof(char) * (my_countstr(str) + 1));
            env[n] = my_dupstr(str);
            return env;
        }
        n += 1;
    }
    char *new_line = my_addstr(my_addstr(key, "="), value);
    env = my_addin_array(env, new_line);
    return env;
}
