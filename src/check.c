/*
** EPITECH PROJECT, 2023
** sh_beggin
** File description:
** check
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

char *my_addstr(char *syr, char *bite);
int my_printf(char *str, ...);
char **my_conv_str_array(char *str);
int my_countstr(char *str);
char *my_replace_char(char *str, char replace, char by);

int error(char *str);
char *env_get(char **env, char *value);

void coucou(int sig)
{
    (void) sig;
    exit(0);
}

int execute(char *command, char **array, char **env)
{
    int status = 0;
    int pid = fork();

    if (pid == 0) {
        signal(SIGINT, coucou);
        execve(command, array, env);
    } else {
        wait(&status);
        return status ? 2 : 0;
    }
    return error(my_addstr(command, ": Command not found."));
}

char *check_all_paths(char *command, char *path_str)
{
    path_str = my_replace_char(path_str, ':', ' ');
    path_str[my_countstr(path_str)] = 0;

    char **array = my_conv_str_array(path_str);
    if (!access(command, X_OK))
        return command;
    while (*array) {
        char *str = my_addstr(my_addstr(*array, "/"), command);
        if (!access(str, X_OK))
            return str;
        array ++;
    }
    return NULL;
}

int check_command(char *args, char **env)
{
    char **array = my_conv_str_array(args);

    char *path_untreated = env_get(env, "PATH");
    if (path_untreated == NULL)
        return error("Could not find PATH env.");

    char *realcommand = check_all_paths(array[0], path_untreated);
    if (realcommand == NULL)
        return error(my_addstr(array[0], ": Command not found."));
    return execute(realcommand, array, env);
}
