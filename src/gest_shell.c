/*
** EPITECH PROJECT, 2020
** shell
** File description:
** shell
*/

#include "my.h"

char *get_path(basic *all)
{
    char *path = NULL;
    int line = 0;
    int x = 5;
    int w = 0;

    path = malloc(sizeof(char) * 10000);
    for (int y = 0; all->cenv[y] != NULL; y++) {
        if (my_strncmp(all->cenv[y], "PATH=", 5) == 0) {
            line = y;
            break;
        }
    }
    for ( ; all->cenv[line][x] != '\0'; x++) {
        path[w] = all->cenv[line][x];
        w++;
    }
    return (path);
}

char *gest_path(basic *all, char *str)
{
    char *new = NULL;
    int len = my_strlen(str)+my_strlen(all->arr[0]);
    int x = 0;

    new = malloc(sizeof(char) * len+2);
    new = my_strcat(new, str);
    new = my_strcat(new, "/");
    new = my_strcat(new, all->arr[0]);
    new[len+1] = '\0';
    return (new);
}

char *check_access(basic *all)
{
    char **tab = str2tab(get_path(all), ':');

    for (int i = 0; i < 7; i++) {
        if (access(gest_path(all, tab[i]), F_OK) == 0
            && access(gest_path(all, tab[i]), X_OK) == 0) {
            return (gest_path(all, tab[i]));
        }
    }
    return (NULL);
}

void gest_shell(basic *all)
{
    char *path = check_access(all);
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(0);
    } else if (pid == 0) {
        if (path == NULL) {
            my_putstr(all->arr[0]);
            my_putstr(": Command not found.\n");
            exit(0);
        }
        execve(path, all->arr, all->cenv);
    } else if (pid > 0)
        wait(NULL);
}
