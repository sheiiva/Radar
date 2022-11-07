/*
** Description:
** Window Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stdlib.h>
#include "graphic.h"
    
void displayWindow(sfRenderWindow* window, t_system *system)
{
    size_t i = 0;

    drawImage(window, system->background);
    while (system->aircrafts[i]) {
        drawImage(window, system->aircrafts[i]->image);
        i += 1;
    }
    i = 0;
    while (system->towers[i]) {
        drawImage(window, system->towers[i]->image);
        i += 1;
    }
    sfRenderWindow_display(window);
}

void clearWindow(sfRenderWindow* window)
{
    sfRenderWindow_clear(window, sfBlack);
}

sfRenderWindow *createWindow(sfVideoMode mode)
{
    return (sfRenderWindow_create(mode, "Radar", sfResize  | sfClose, NULL));
}

void destroyWindow(t_window *window)
{
    if (window)
        sfRenderWindow_destroy(window->window);
    free(window);
}

t_window *initWindow()
{
    t_window *window = malloc(sizeof(t_window));

    if (!window)
        return (NULL);
    window->mode = (sfVideoMode){1920, 1080, 32};
    if (!(window->window = createWindow(window->mode))) {
        destroyWindow(window);
        return (NULL);
    }
    sfRenderWindow_setMouseCursorVisible(window->window, sfFalse);
    return (window);
}