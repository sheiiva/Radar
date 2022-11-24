/*
** Description:
** Game's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "new.h"

#include "game.h"

static void Game_run(__UNUSED__ GameClass *this, __UNUSED__ SystemClass *system)
{
    while (1) {}
}

static void Game_ctor(GameClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_window = new(Window);

    // Initialize Scenes

    printf("Game()\n");
}

static void Game_dtor(__UNUSED__ GameClass *this)
{
    // Release internal resources
    delete(this->_window);

    printf("~Game()\n");
}

static const GameClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(GameClass),
        .__name__ = "Game",
        .__ctor__ = (ctor_t)&Game_ctor,
        .__dtor__ = (dtor_t)&Game_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._scenes = NULL,
    ._window = NULL,
    /* Methods definitions */
    .__run__ = &Game_run
};

const Class *Game = (const Class *)&_description;