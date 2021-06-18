/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
*/

#include "./include/my.h"

int my_strlen(char *str)
{
    int returned = 0;

    for (int i = 0; str[i] != '\0'; i++)
        returned++;
    return (returned);
}

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
    while ( (entry = readdir(folder)) )
    {
        files++;
    }
    closedir(folder);
    return (files);
}

char *add_path(char *str, char *path)
{
    char *returned = malloc(sizeof(char) * (my_strlen(str) + my_strlen(path) + 2));
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

char **sort_table(char **table, int nb_files)
{
    char *tmp = NULL;
    int swapped = 0;

    while (swapped == 0) {
        swapped = 1;
        for (int i = 0; table[i + 1] != NULL; i++)
            if (strcmp(table[i], table[i + 1]) > 0) {
                swapped = 0;
                tmp = strdup(table[i]);
                table[i] = table[i + 1];
                table[i + 1] = tmp;
            }
    }
    return (table);
}

void get_path(int depth, char *path)
{
    int nb_files = cont_files(path);
    char **table = malloc(sizeof(char *) * (nb_files + 1));
    char *test_path = NULL;
    DIR *folder = NULL;
    struct dirent *entry = NULL;
    char *prev_folder = NULL;
    int i = 0;

    table[nb_files] = NULL;
    folder = opendir(path);
    while ( (entry = readdir(folder)) )
    { 
        table[i] = strdup(entry->d_name);
        i++;
    }
    sort_table(table, nb_files);
    closedir(folder);
    for (int i = 0; table[i] != NULL; i++) {
        printf("%i %s\n", depth, table[i]);
        test_path = add_path(path, table[i]);
        folder = opendir(test_path);
        if (folder != NULL && table[i][0] != '.') {
            get_path(depth + 1, test_path);
        }
        closedir(folder);
        free(test_path);
    }
    for (int i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
}

int main(int ac, char **av)
{
    int *flags = check_flags(ac, av);
    
    get_path(0, "./");
}