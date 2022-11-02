/*
** Description:
** Print a string
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"

ssize_t my_putstr(const char *str, int fd)
{
    return (write(fd, str, my_strlen(str)));
}