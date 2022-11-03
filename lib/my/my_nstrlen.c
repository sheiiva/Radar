/*
** Description:
** Count string characters until n
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stddef.h>

size_t my_nstrlen(const char *str, char n)
{
    size_t i = 0;

    while ((str[i]) && (str[i] != n))
        i += 1;
    return (i);
}