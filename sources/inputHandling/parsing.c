/*
** Description:
** Parsing functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"
#include "parsing.h"
#include "system.h"
#include <stdio.h>

void shiftLeft(char *string)
{
    size_t i = 0;

    while (string[i + 1]) {
        string[i] = string[i + 1];
        i += 1;
    }
    string[i] = '\0';
}

void removeDuplicate(char *string, char c)
{
    size_t i = 0;

    while (string[i]) {
        while (string[i + 1] && string[i] == c && string[i + 1] == c) {
            shiftLeft(&string[i]);
            i += 1;
        }
        i += 1;
    }
}

void cleanString(char *string)
{
    size_t i = 0;

    while (string[i]) {
        if ((string[i] == '\t') || (string[i] == '\n') || (string[i] == '\r'))
            string[i] = ' ';
        i += 1;
    }
    removeDuplicate(string, ' ');
}

t_system *parsing(const char *path)
{
    char *content = getContentFromFile(path);
    char **array = NULL;

    if (!content)
        return (NULL);
    cleanString(content);

    array = my_strtowordarray(content, ' ');

    // while not \0
    //  while not \n
    //      word by word fill struct
    //      i += 1
    //  i += 1
    free(content);
    my_freeArray(array);
    return (NULL);
}