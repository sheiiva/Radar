/*
** Description:
** Print a character
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"

ssize_t my_putchar(char c, int fd)
{
    return (write(fd, &c, 1));
}