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