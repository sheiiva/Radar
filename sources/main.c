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
#include "graphic.h"

int radar()
{
    t_graphic *graphics = initgraphics();

    if (!graphics)
        return (FAILURE);
    while (1){}
    // game loop
    // destroygraphics(graphics);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    size_t result = 0;
    t_system *system = NULL;
    int argsValidation = checkInputArgs(ac, av);

    if (argsValidation != SUCCESS)
        return (argsValidation == HELP ? SUCCESS : FAILURE);
    if (!(system = parsing(av[1])))
        return (FAILURE);
    result = radar();
    deleteSystem(system);
    return (result);
}