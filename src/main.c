/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** main
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

char *my_scanf(char *type);
int my_printf(char *str, ...);
int my_compstr(char *str1, char *str2);
int my_countstr(char *str);
char *my_cutstr(char *str, int a, int b);

int custom_command(char *command, char ***env, char **old);
int check_command(char *args, char **env);
char *replace_vaguelette(char *str, char **env);
int pipe_bomb(char ***env, char **old);

int error(char *str)
{
    my_printf("%s\n", str);
    return 84;
}

void coucou2(int sig)
{
    (void) sig;
}

int process_normal(char *command, char ***env, char **old)
{
    command = replace_vaguelette(command, *env);
    if (my_compstr(command, "exit")) {
        my_printf("exit\n");
        return 1;
    }
    if (!my_countstr(command) || custom_command(command, env, old) != -1)
        return 0;
    check_command(command, *env);
    free(command);
    return 0;
}

char *other_scanf(char *show, int *status)
{
    long unsigned int size = 0;
    char *command = malloc(0);

    my_printf(show);
    *status = getline(&command, &size, stdin);
    if (*status == -1)
        return "";
    int count = my_countstr(command) - 1;
    char last = command[count];
    command = last == '\n' ? my_cutstr(command, 0, count) : command;

    return command;
}

int main(int ac, char **av, char **env)
{
    char *old = "";
    (void) ac;
    (void) av;

    signal(SIGINT, coucou2);
    if (!isatty(STDIN_FILENO))
        return pipe_bomb(&env, &old);
    while (1) {
        int status = 0;
        char *command = other_scanf("$> ", &status);
        if (status < 0) {
            my_printf("exit\n");
            break;
        }
        if (command == NULL || !my_countstr(command))
            continue;
        if (process_normal(command, &env, &old))
            break;
    }
    return 0;
}
