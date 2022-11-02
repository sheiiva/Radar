/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "macro.h"
#include "error.h"

int main(int ac, char **av)
{
    int argsValidation = checkInputArgs(ac, av);

    if (argsValidation != SUCCESS)
        return (argsValidation == HELP ? SUCCESS : FAILURE);
    return (SUCCESS);
}