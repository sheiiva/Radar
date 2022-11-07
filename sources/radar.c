/*
** Description:
** Radar Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "macro.h"
#include "event.h"
#include "graphic.h"
#include "system.h"
#include "my.h"

#include <stdio.h>

int gameLoop(t_system *system, t_graphic *graphics)
{
    printf("%ld\n", system->aircrafts[0]->speed);
    /* Start the game loop */
    while (sfRenderWindow_isOpen(graphics->window->window)) {
        // /* Manage Event */
        eventManager(graphics);
        if (graphics->state == QUIT) {
            return (SUCCESS);
        }
        /* Clear the screen */
        clearWindow(graphics->window->window);
        // /* Process Event */
        // process(system, scenes);
        /* Display Screen */
        displayWindow(graphics->window->window, system);
    }
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