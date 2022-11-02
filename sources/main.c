/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "error.h"

int main(int ac, char **av)
{
    if (checkInputArgs(ac, av) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}