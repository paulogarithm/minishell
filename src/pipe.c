/*
** EPITECH PROJECT, 2023
** sh_final
** File description:
** pipe
*/

#include <unistd.h>
#include <stdio.h>

int my_printf(char *format, ...);
int custom_command(char *command, char ***env, char **old);
char *my_addstr(char *str1, char *str2);
int my_countstr(char *str);
int check_command(char *args, char **env);
int my_compstr(char *str1, char *str2);
char *my_cutstr(char *str, int s, int e);

char *replace_vaguelette(char *str, char **env);
int error(char *str);

int process_pipe(char *command, char ***env, char **old)
{
    command = replace_vaguelette(command, *env);
    int iserror = custom_command(command, env, old);
    if (iserror != -1)
        return iserror;
    if (my_compstr(command, "exit"))
        return 0 * my_printf("exit\n");
    return check_command(command, *env);
}

int pipe_bomb(char ***env, char **old)
{
    long unsigned int size;
    char *buffer;
    int exit = 0;

    while (1) {
        int status = getline(&buffer, &size, stdin);
        if (status == -1)
            break;
        int count = my_countstr(buffer) - 1;
        char last = buffer[count];
        buffer = last == '\n' ? my_cutstr(buffer, 0, count) : buffer;
        if (buffer == NULL || !my_countstr(buffer))
            continue;
        if (status == -1)
            return 0;
        process_pipe(buffer, env, old);
    }
    return exit;
}
