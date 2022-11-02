/*
** Description:
** Duplicate a string (malloc)
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"

char *my_strcpy(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}