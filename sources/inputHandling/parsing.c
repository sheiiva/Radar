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

char *parsing(const char *path)
{
    char *content = getContentFromFile(path);

    if (!content)
        return (NULL);
    return (content);
}