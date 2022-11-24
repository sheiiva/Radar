/*
** Description:
** System's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "new.h"
#include "system.h"

#include "game.h"
#include "errorHandling.h"
#include "parser.h"

#include "aircraft.h"
#include "array.h"

static int System_run(SystemClass *this, int ac, char **av)
{
    // INPUT CHECKING
    ErrorHandlingClass *errorHandling = new(ErrorHandling);

    errorHandling->__run__(errorHandling, ac, av);
    if (errorHandling->_status != SUCCESS)
        return (errorHandling->_status == ERROR ? ERROR : SUCCESS);

    delete(errorHandling);
    // PARSING
    ParserClass *parser = new(Parser);

    if (parser->__run__(parser, av[1], &this->_aircrafts, &this->_towers) == ERROR)
        return (ERROR);

    delete(parser);
    // GAME
    this->_game = new(Game);

    runGame(this->_game, this);

    delete(this->_game);
    return (SUCCESS);
}

static void System_ctor(__UNUSED__ SystemClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->_clock = new(Clock);

    printf("System()\n");
}

static void System_dtor(SystemClass *this)
{
    // Release internal resources
    delete(this->_aircrafts);
    delete(this->_towers);
    delete(this->_clock);

    printf("~System()\n");
}

static const SystemClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SystemClass),
        .__name__ = "System",
        .__ctor__ = (ctor_t)&System_ctor,
        .__dtor__ = (dtor_t)&System_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._aircrafts = NULL,
    ._towers = NULL,
    ._clock = NULL,
    ._game = NULL,
    /* Methods definitions */
    .__run__ = &System_run
};

const Class *System = (const Class *)&_description;