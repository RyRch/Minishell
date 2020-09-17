/*
** EPITECH PROJECT, 2019
** CPOOL
** File description:
** DAY07
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    char *str = dest;

    while (*dest != '\0')
        dest++;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (str);
}
