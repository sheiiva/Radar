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
#include "parsing.h"

int main(int ac, char **av)
{
    char *content = NULL;
    int argsValidation = checkInputArgs(ac, av);

    if (argsValidation != SUCCESS)
        return (argsValidation == HELP ? SUCCESS : FAILURE);
    if (!(content = parsing(av[1])))
        return (FAILURE);
    return (SUCCESS);
}