/*
** EPITECH PROJECT, 2020
** gest_env
** File description:
** gest_env
*/

#include "my.h"

char *add_last(char *str)
{
    int len = my_strlen(str);
    char *new = malloc(sizeof(char) * len+2);

    for (int i = 0; str[i] != '\0'; i++)
        new[i] = str[i];
    new[len] = 61;
    new[len+1] = '\0';
    return (new);
}

int pos_line(basic *all, char *str)
{
    char *tmp = NULL;
    int len = 0;

    str = add_last(str);
    len = my_strlen(str);
    tmp = malloc(sizeof(char) * len+1);
    tmp[len] = '\0';
    for (int y = 0; all->cenv[y] != NULL; y++) {
        for (int x = 0; all->cenv[y][x] != '\0'; x++) {
            if (x < len)
                tmp[x] = all->cenv[y][x];
            if (my_strcmp(tmp, str) == true)
                return (y);
        }
    }
    return (0);
}

void unset_env(basic *all, char *str)
{
    int line = pos_line(all, str);

    if (line == 0)
        return;
    all->cenv[line] = " ";
}

bool check_senv(basic *all)
{
    if (count_rows(all->line, ' ') > 3) {
        my_putstr("setenv: Too many arguments.\n");
        return (true);
    } else if (count_rows(all->line, ' ') == 3) {
        set_env(all, all->arr[1], all->arr[2]);
        return (true);
    }
}

void set_env(basic *all, char *arg1, char *arg2)
{
    char **tab = NULL;
    int pos = pos_line(all, arg1);
    int lines = lines_cenv(all);
    int size1 = my_strlen(arg1);
    int size2 = my_strlen(arg2);

    if (pos > 0) {
        all->cenv[pos] = NULL;
        all->cenv[pos] = malloc(sizeof(char) * (size1+size2+2));
        all->cenv[pos] = my_strcat(all->cenv[pos], arg1);
        all->cenv[pos] = my_strcat(all->cenv[pos], "=");
        all->cenv[pos] = my_strcat(all->cenv[pos], arg2);
    }
}
