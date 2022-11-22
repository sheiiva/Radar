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

#include "errorHandling.h"
#include "parser.h"

static int System_run(__UNUSED__ SystemClass *this, int ac, char **av)
{
    //CHECK INPUT
    ErrorHandlingClass *errorHandling = new(ErrorHandling);

    errorHandling->__run__(errorHandling, ac, av);
    if (errorHandling->__getStatus__(errorHandling) != SUCCESS)
        return (errorHandling->__getStatus__(errorHandling) == ERROR ? ERROR : SUCCESS);

    delete(errorHandling);
    //PARSE
    ParserClass *parser = new(Parser);

    if (parser->__run__(parser, av[1]) == ERROR)
        return (ERROR);

    delete(parser);
    //GAME

    return (SUCCESS);
}

static void System_ctor(__UNUSED__ SystemClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources

    printf("System()\n");
}

static void System_dtor(__UNUSED__ SystemClass *this)
{
    // Release internal resources

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
    ._status = 0,
    /* Methods definitions */
    .__run__ = &System_run
};

const Class *System = (const Class *)&_description;