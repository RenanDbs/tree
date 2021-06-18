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

    // printf("%s %s\n", str, path);
    for (int i = pos; str[i] != '\0'; i++, pos++)
        returned[i] = str[i];
    // printf("pos: %i\n", pos);
    for (int i = pos; path[j] != '\0'; i++, pos++, j++) {
        returned[i] = path[i - my_strlen(str)];
        // printf("passed %c %c\n", path[i - my_strlen(str) - 1], returned[i]);
        // printf("+%s+\n", returned);
    }
    // printf("pos2: %i\n", pos);
    // for (int i = 0; returned[i] != '\0'; i++)
    //     printf("%c", returned[i]);
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
                // free(tmp);
            }
    }

    // for (int i = 1; i < nb_files; i++)
    //     for (int j = 0; j < nb_files - i; j++) {
    //         if (strcmp(table[i], table[i + 1]) > 0) {
    //             tmp = strdup(table[i]);
    //             // printf("BEFORE = %s\n", table[i]);
    //             table[i] = strdup(table[i + 1]);
    //             table[i] = strdup(tmp);
    //             // printf("AFTER= %s\n", table[i]);
    //         }
    //     }
    return (table);
}

void get_path(int depth, char *path)
{
    int nb_files = cont_files(path);
    char **table = malloc(sizeof(char *) * (nb_files + 1));
    char *test_path = NULL;
    DIR *folder = NULL;
    struct dirent *entry = NULL;
    int files = 0;
    int nb_folders = 0;
    char *prev_folder = NULL;
    int i = 0;

    table[nb_files] = NULL;
    folder = opendir(path);
    // printf("STR = %s\n", str);
    while ( (entry = readdir(folder)) )
    { 
        table[i] = strdup(entry->d_name);
        i++;
        // printf("THE PLACE TO BE = %s\n", table[i]);
        // if (entry->d_type == DT_DIR && (table[i][1] != '\0' && table[i][0] != '.')) {
        //     i++;
        //     str = strdup(entry->d_name);
        //     printf("FOLDERS_NAME = %s\n", str);
        //     infos->pos_folder[j] = i;
        //     j++;
        //     get_path(infos, table, i, j, str);
        //     nb_folders++;
        // }
        // free(buf);
    }
    sort_table(table, nb_files);
    for (int i = 0; table[i] != NULL; i++) {
        printf("%i %s\n", depth, table[i]);
        test_path = add_path(path, table[i]);
        if (opendir(test_path) != NULL && table[i][0] != '.') {
            // printf("str: +%s+\n", test_path);
            get_path(depth + 1, test_path);
        }
    }
    for (int i = 0; table[i] != NULL; i++)
        free(table[i]);
    free(table);
    closedir(folder);
}

int main()
{
    // int nb_files = cont_files();
    int nb_folders = 0;
    int i = 0;
    int j = 0;
    char *str = "./";
    // char **table = malloc(sizeof(char *) * 50);
    // info *infos = malloc(sizeof(info));

    // infos->pos_folder = malloc(sizeof(int) * 50);
    get_path(0, str);
    // printf("FILES = %d\nFOLDERS = %d\n", nb_files, nb_folders);
    // printf(".\n");
    // for(int i = 0; i < nb_files; i++){
    //     if(table[i][0] != '.')
    //         if (infos->pos_folder[0] == i + 1){
    //             printf("|-- %s\n|   `--%s \n", table[i], table[i + 1]);
    //             i++;
    //         } else {
    //             printf("|-- %s\n",table[i]);
    //         }
    // }
}