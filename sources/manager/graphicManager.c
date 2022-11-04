/*
** Description:
** Graphic Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stdlib.h>
#include "graphic.h"

void destroygraphics(t_graphic *graphics)
{
    sfClock_destroy(graphics->clock);
    if (!graphics)
        return;
    if (graphics->window)
        destroyWindow(graphics->window);
    free(graphics);
}

t_graphic *initgraphics()
{
    t_graphic *graphics = malloc(sizeof(t_graphic));

    if(!graphics)
        return (NULL);
    graphics->window = initWindow();
    if (!graphics->window) {
        destroygraphics(graphics);
        return (NULL);
    }
    sfRenderWindow_setFramerateLimit(graphics->window->window, 60);
    graphics->clock = sfClock_create();
    graphics->state = GAMESCENE;
    return (graphics);
}