/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int x = 0;

    while (src[x] != '\0') {
        dest[x] = src[x];
        x++;
    }
    dest[x] = '\0';
    return dest;
}