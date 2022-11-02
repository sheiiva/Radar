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

void cleanString(char *string)
{
    size_t i = 0;

    while (string[i]) {
        if (string[i] == '\t')
            string[i] = ' ';
        i += 1;
    }
}

t_system *parsing(const char *path)
{
    char *content = getContentFromFile(path);

    if (!content)
        return (NULL);
    cleanString(content);
    // str to word array

    // while not \0
    //  while not \n
    //      word by word fill struct
    //      i += 1
    //  i += 1
    return (NULL);
}