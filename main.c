/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** .
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
                tmp = malloc(sizeof(char) * my_strlen(table[i]));
                swapped = 0;
                my_strcpy(tmp, table[i]);
                table[i] = malloc(sizeof(char) * my_strlen(table[i + 1]));
                my_strcpy(table[i], table[i + 1]);
                table[i + 1] = malloc(sizeof(char) * my_strlen(tmp));
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

int str_compare2(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
        if (big_letter(str1[i]) != big_letter(str2[i]))
            return (0);
    return (1);
}

void get_path(int depth, char *path, int last)
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
        if (last == 0)
            for (int i = 0; i < depth; i++)
                printf("%s", "|   ");
        if (table[i + 1] == NULL)
            printf("`");
        else 
            printf("%s", "|");
        printf("-- %s\n", table[i]);
        test_path = add_path(path, table[i]);
        folder = opendir(test_path);
        if (folder != NULL && table[i][0] != '.') {
            if (table[i + 1] == NULL)
                get_path(depth + 1, test_path, 1);
            else
                get_path(depth + 1, test_path, 0);
        }
        closedir(folder);
        free(test_path);
    }
    for (int i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
}

int main()
{
    get_path(0, "./", 0);
}