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

static void System_ctor(__UNUSED__ SystemClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    this->state = GAMESCENE;

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
    .state = 0
    /* Methods definitions */
};

const Class *System = (const Class *)&_description;