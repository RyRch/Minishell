/*
** EPITECH PROJECT, 2020
** loop
** File description:
** loop
*/

#include "my.h"

void loop(basic *all, char **env)
{
    copy_env(all, env);
    while (42) {
        my_putstr("$> ");
        if (getline(&all->line, &all->nb, stdin) == -1)
            break;
        all->line = space_tab(all->line);
        if (all->line[0] != '\n' && all->line[0] != ' ') {
            all->arr = str2tab(all->line, ' ');
            if (gest_builtins(all) == false)
                gest_shell(all);
        }
    }
}

cases gest_builtins(basic *all)
{
    if (my_strcmp(all->line, "exit\n") == true) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strncmp(all->arr[0], "./", 2) == 0) {
        execve(all->arr[0], all->arr, all->cenv);
        return (true);
    }
    return (check_builtins(all));
}

cases check_builtins(basic *all)
{
    if (my_strcmp(all->line, "env\n") == true
        || my_strcmp(all->line, "setenv\n") == true) {
        print_env(all);
        return (true);
    }
    if (my_strcmp(all->arr[0], "cd") == true) {
        chdir(all->arr[1]);
        return (true);
    }
    if (my_strcmp(all->arr[0], "setenv") == true)
        return (check_senv(all));
    if (my_strcmp(all->arr[0], "unsetenv") == true
        && lines_arr(all) >= 2) {
        unset_env(all, all->arr[1]);
        return (true);
    }
    return (false);
}

void print_env(basic *all)
{
    int lines = lines_cenv(all);

    for (int y = 0; y < lines; y++) {
        if (all->cenv[y][0] != ' ') {
            my_putstr(all->cenv[y]);
            my_putchar('\n');
        }
    }
}

void copy_env(basic *all, char **env)
{
    int lines = 0;

    for ( ; env[lines] != NULL; lines++);
    all->cenv = malloc(sizeof(char *) * lines+1);
    for (int i = 0; i < lines; i++)
        all->cenv[i] = my_strdup(env[i]);
}
