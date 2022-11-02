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
#include "system.h"

int main(int ac, char **av)
{
    t_system *system = NULL;
    int argsValidation = checkInputArgs(ac, av);

    if (argsValidation != SUCCESS)
        return (argsValidation == HELP ? SUCCESS : FAILURE);
    if (!(system = parsing(av[1])))
        return (FAILURE);
    deleteSystem(system);
    return (SUCCESS);
}