/*
** Description:
** Event Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "system.h"
#include "event.h"

void onClose(t_graphic *graphics)
{
    /* Close window : exit */
    if (graphics->event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(graphics->window->window);
        graphics->state = QUIT;
    }
}

void (*checkEvent[NUMEVENT])(t_graphic*) = {
    onClose
};

void eventManager(t_graphic *graphics)
{
    int i = 0;

    /* Process events */
    while (sfRenderWindow_pollEvent(graphics->window->window, &(graphics->event))) {
        while (i < NUMEVENT) {
            checkEvent[i](graphics);
            i += 1;
        }
    }
}