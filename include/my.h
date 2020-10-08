/*
** EPITECH PROJECT, 2020
** include
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "struct.h"

void my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int my_putnbr(int nb);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

void fill_struct(basic *all);

void loop(basic *all, char **env);

void print_env(basic *all);

char *recup_path(char **env);

int count_rows(char *str, char c);

int *size_word(char *str, char c);

char **malloc_tab(char *str, char c);

char **str2tab(char *str, char c);

void print_tab(char **tab);

int *my_intdup(int *src, int len);

char *my_strdup(char const *src);

bool my_strcmp(char const *s1, char const *s2);

char *space_tab(char *str);

void copy_env(basic *all, char **env);

void unset_env(basic *all, char *str);

int pos_line(basic *all, char *str);

char *recup_line(basic *all, char *str);

bool gest_builtins(basic *all);

bool check_builtins(basic *all);

int lines_cenv(basic *all);

int lines_arr(basic *all);

void set_env(basic *all, char *arg1, char *arg2);

char *my_strcat(char *dest, char const *src);

char *get_path(basic *all);

int my_strncmp(char *str1, char *str2, int a);

char *gest_path(basic *all, char *str);

char *check_access(basic *all);

void gest_shell(basic *all);

bool check_senv(basic *all);
