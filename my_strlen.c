/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** print an integer;
*/

int my_strlen(char *str)
{
    int returned = 0;

    for (int i = 0; str[i] != '\0'; i++)
        returned++;
    return (returned);
}
