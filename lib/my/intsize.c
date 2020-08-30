/*
** EPITECH PROJECT, 2019
** intsize.c
** File description:
** int size
*/

int intsize(int nb)
{
    int i = 0;
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return (i);
}
