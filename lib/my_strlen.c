/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i+1] == '\0')
            return (i+1);
    }
    return (0);
}
