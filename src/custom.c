/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** custom_commands
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

char **my_conv_str_array(char *str);
char *my_addstr(char *str, char *str2);
int my_compstr(char *str1, char *str2);
char *my_cutstr(char *str, int a, int b);
int my_printf(char *str, ...);

char **env_write(char **env, char *key, char *value);
char *env_get(char **env, char *value);
int env_show(char **env);
int error(char *str);
int is_letter(char c);
char **remove_from_array(char **env, char *key);

int is_file(char *path)
{
    struct stat st;

    if (stat(path, &st) < 0)
        return 0;
    return S_ISREG(st.st_mode);
}

int change_directory(char *path, char **env, char **old)
{
    int size = 1024;
    char *cwd = malloc(sizeof(char) * size);

    getcwd(cwd, size);
    path = path == NULL ? env_get(env, "HOME") : path;
    if (path == NULL)
        return error("Weird Path.");
    if (my_compstr(path, "-"))
        path = *old;
    if (is_file(path))
        return error(my_addstr(path, ": Not a directory."));
    if (chdir(path))
        return error(my_addstr(path, ": No such file or directory."));
    *old = cwd;
    return 0;
}

int my_unsetenv(char ***env, char **command)
{
    if (command[1] == NULL)
        return error("unsetenv: Too few arguments.");
    int n = 1;
    while (command[n] != NULL) {
        *env = remove_from_array(*env, command[n]);
        n += 1;
    }
    return 0;
}

int my_setenv(char ***env, char **command)
{
    if (command[1] == NULL)
        return 0 * env_show(*env);
    if (!is_letter(command[1][0]))
        return error("setenv: Variable name must begin with a letter.");
    if (command[2] != NULL && command[3] != NULL)
        return error("setenv: Too many arguments.");

    char *second = command[2];
    *env = env_write(*env, command[1], second == NULL ? "" : second);
    return 0;
}

int custom_command(char *line, char ***env, char **old)
{
    char **command = my_conv_str_array(line);

    if (my_compstr(command[0], "cd"))
        return change_directory(command[1], *env, old);
    if (my_compstr(command[0], "env"))
        return env_show(*env);
    if (my_compstr(command[0], "setenv"))
        return my_setenv(env, command);
    if (my_compstr(command[0], "unsetenv"))
        return my_unsetenv(env, command);
    return -1;
}
