/*
** EPITECH PROJECT, 2021
** tree
** File description:
** path_compare
*/

#include "./include/my.h"

int str_compare2(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (big_letter(str1[i]) != big_letter(str2[i]))
            return (0);
    return (1);
}

char *my_strdup(char *str)
{
    char *returned = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (returned == NULL)
        return (NULL);
    returned[my_strlen(str)] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
        returned[i] = str[i];
    return (returned);
}

void get_path(char *path, int *flags)
{
    int nb_files = cont_files(path);
    char **table = malloc(sizeof(char *) * (nb_files + 1));
    DIR *folder = NULL;
    struct dirent *entry = NULL;
    int i = 0;

    table[nb_files] = NULL;
    folder = opendir(path);
    while ( (entry = readdir(folder)) ) { 
        table[i] = my_strdup(entry->d_name);
        i++;
    }
    sort_table(table);
    closedir(folder);
    print_tree(flags, path, table);
    for (int i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
}