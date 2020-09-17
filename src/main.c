/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    basic all;

    fill_struct(&all);
    loop(&all, env);
    return (0);
}

void fill_struct(basic *all)
{
    all->line = NULL;
    all->cenv = NULL;
    all->arr = NULL;
}

char *space_tab(char *str)
{
    char *new = NULL;
    int len = my_strlen(str);
    int check = 0;
    int x = 0;

    new = malloc(sizeof(char) * 1000000);
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ' && str[i] != '\t')
            check = 1;
        if (str[i+1] != '\t' && str[i] == ' '
            && str[i+1] != ' ' && str[i+1] != '\0'
            && check == 1 && str[i+1] != '\n'
            || str[i] != ' '
            && str[i] != '\t') {
            new[x] = str[i];
            x++;
        }
    }
    new[len] = '\0';
    return (new);
}

int lines_cenv(basic *all)
{
    int i = 0;

    while (all->cenv[i] != NULL)
        i++;
    return (i);
}

int lines_arr(basic *all)
{
    int i = 0;

    while (all->arr[i] != NULL)
        i++;
    return (i);
}
