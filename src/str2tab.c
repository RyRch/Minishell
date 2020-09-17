/*
** EPITECH PROJECT, 2020
** str2tab
** File description:
** str2tab
*/

#include "my.h"

int count_rows(char *str, char c)
{
    int rows = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            rows++;
    }
    return (rows);
}

int *size_word(char *str, char c)
{
    int *size = NULL;
    int x = 0;

    size = malloc(sizeof(int) * (count_rows(str, c)+1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c)
            size[x]++;
        else if (str[i] == c)
            x++;
    }
    return (size);
}

char **malloc_tab(char *str, char c)
{
    int rows = count_rows(str, c);
    char **tab = NULL;
    int *cols = my_intdup(size_word(str, c), rows);

    tab = malloc(sizeof(char *) * rows+1);
    for (int i = 0; i < rows; i++)
        tab[i] = malloc(sizeof(char) * (cols[i]+1));
    return (tab);
}

char **str2tab(char *str, char c)
{
    char **tab = malloc_tab(str, c);
    int rows = count_rows(str, c);
    int *cols = my_intdup(size_word(str, c), rows);
    int i = 0;

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols[y]; x++) {
            if (str[i] != c && str[i] != '\n') {
                tab[y][x] = str[i];
                i++;
            }
            if (str[i] == c) {
                i++;
                break;
            }
        }

    }
    return (tab);
}
