/*
** Description:
** Print a character
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    size_t i = 0;

    while (s1[i] && s2[i]) {
        if (s1[i] != s2[i])
            return (FAILURE);
        i += 1;
    }
    return (SUCCESS);
}