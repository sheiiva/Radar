/*
** Description:
** Game's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "new.h"
#include "array.h"

#include "game.h"

#include "aircraft.h"
#include "tower.h"

static void Game_process(__UNUSED__ GameClass *this, SystemClass *system)
{
    for (size_t i = 0; i < len(system->_aircrafts); i++)
        moveAircraft(getitem(system->_aircrafts, i));
}

static void Game_display(GameClass *this, SystemClass *system)
{
    drawScene(this->_scene, this->_window);
    for (size_t i = 0; i < len(system->_aircrafts); i++)
        drawAircraft(getitem(system->_aircrafts, i), this->_window);
    for (size_t i = 0; i < len(system->_towers); i++)
        drawTower(getitem(system->_towers, i), this->_window);
    displayWindow(this->_window);
}

static void Game_run(GameClass *this, SystemClass *system)
{
    while (isWindowOpen(this->_window)) {
        clearWindow(this->_window);
        handleEvents(this->_scene->_eventManager, system);
        processGame(this, system);
        displayGame(this, system);
    }
}

static void Game_ctor(GameClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_scene = new(Scene);
    this->_window = new(Window);

    printf("Game()\n");
}

static void Game_dtor(__UNUSED__ GameClass *this)
{
    // Release internal resources
    delete(this->_scene);
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
    ._scene = NULL,
    ._window = NULL,
    /* Methods definitions */
    .__display__ = &Game_display,
    .__process__ = &Game_process,
    .__run__ = &Game_run
};

const Class *Game = (const Class *)&_description;