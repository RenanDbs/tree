/*
** EPITECH PROJECT, 2021
** tree
** File description:
** main_utils
*/

#include "./include/my.h"

int str_compare(char *str1, char *str2)
{
    if (str2 == NULL)
        return(1);
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int cont_files(char *path)
{
    DIR *folder;
    struct dirent *entry;
    int files = 0;

    folder = opendir(path);
    if (folder == NULL)
        return (-1);
    while ( (entry = readdir(folder)) ) {
        files++;
    }
    closedir(folder);
    return (files);
}

char *add_path(char *str, char *path)
{
    char *returned = malloc(sizeof(char) * (my_strlen(str) + \
    my_strlen(path) + 2));
    int pos = 0;
    int j = 0;

    for (int i = pos; str[i] != '\0'; i++, pos++)
        returned[i] = str[i];
    for (int i = pos; path[j] != '\0'; i++, pos++, j++)
        returned[i] = path[i - my_strlen(str)];
    returned[pos] = '/';
    returned[pos + 1] = '\0';
    return (returned);
}

char **sort_table(char **table)
{
    char *tmp = NULL;
    int swapped = 0;

    while (swapped == 0) {
        swapped = 1;
        for (int i = 0; table[i + 1] != NULL; i++)
            if (strcmp(table[i], table[i + 1]) > 0) {
                tmp = malloc(sizeof(char) * (my_strlen(table[i]) + 1));
                swapped = 0;
                my_strcpy(tmp, table[i]);
                free(table[i]);
                table[i] = malloc(sizeof(char) * (my_strlen(table[i + 1]) + 1));
                my_strcpy(table[i], table[i + 1]);
                free(table[i + 1]);
                table[i + 1] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
                my_strcpy(table[i + 1], tmp);
                free(tmp);
            }
    }
    return (table);
}

char big_letter(char c)
{
    if (c > 90)
        return (c - 32);
    return (c);
}
