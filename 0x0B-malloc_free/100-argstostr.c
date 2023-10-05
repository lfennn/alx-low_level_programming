#include "holberton.h"
#include <stdlib.h>

/*
 * argstostr - concatenates all arguments to the program
 * @ac: argument count
 * @av: pointer to arguments
 * Return: pointer to new space in memory or null
 */
char *argstostr(int ac, char **av)
{
    char *strDup;
    int i, j, k, size;

    if (ac == 0 || av == NULL)
        return (NULL);

    size = 0;
    /* Count the number of characters in each string */
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j] != '\0'; j++)
            size++;
        size++;
    }
    size++;

    /* Allocate memory for the total number of characters and new line for each word */
    strDup = malloc(sizeof(char) * size);

    if (strDup == NULL)
        return (NULL);

    k = 0;
    for (i = 0; i < ac; i++)
    {
        for (j = 0; av[i][j] != '\0'; j++)
        {
            strDup[k++] = av[i][j];
        }
        strDup[k++] = '\n';
    }
    strDup[k] = '\0';
    return (strDup);
}
