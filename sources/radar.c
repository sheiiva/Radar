/*
** Description:
** Radar Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "macro.h"
#include "graphic.h"
#include "system.h"
#include "my.h"

int gameLoop(t_system *system, t_graphic *graphics)
{
    while (graphics->state != QUIT) {}
    (void)system;
    return (SUCCESS);
}

int radar(t_system *system)
{
    int result = 0;
    t_graphic *graphics = initgraphics();

    if (!graphics)
        return (FAILURE);
    result = gameLoop(system, graphics);
    destroygraphics(graphics);
    return (result);
}