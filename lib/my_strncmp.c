/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** shell
*/

#include "my.h"

int my_strncmp(char *str1, char *str2, int a)
{
    if (a < 0)
        return (1);
    for (int i = 0; a > 0; i++) {
        if (str1[i] != str2[i]
            || str1[i] == '\0'
            || str2[i] == '\0')
            return (1);
        a--;
    }
    return (0);
}

