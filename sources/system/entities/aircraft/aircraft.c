/*
** Description:
** Aircraft's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stdlib.h>

#include "my.h"
#include "aircraft.h"

static void Aircraft_ctor(AircraftClass *this, va_list *args)
{
    char **data = strtowordarray(va_arg(*args, char*), ' ');

    // Check settins format
    size_t i = 0;
    while (data[i]) {i++;}
    if (i != 7)
        raise("Wrong Aircraft settings.");

    // Initialize internal resources
    this->_initPos = (sfVector2f){atof(data[1]), atof(data[2])};
    this->_landingPos = (sfVector2f){atof(data[3]), atof(data[4])};
    this->_pos = this->_initPos;
    this->_speed = atol(data[5]);
    this->_delay = atol(data[6]);

    freeArray(data);
    printf("Aircraft()\n");
}

static void Aircraft_dtor(__UNUSED__ AircraftClass *this)
{
    // Release internal resources

    printf("~Aircraft()\n");
}

static const AircraftClass _description = {
    { /* IEntity struct */
        {   /* Class struct */
        .__size__ = sizeof(AircraftClass),
        .__name__ = "Aircraft",
        .__ctor__ = (ctor_t)&Aircraft_ctor,
        .__dtor__ = (dtor_t)&Aircraft_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
        }
    },
    ._initPos = {0, 0},
    ._landingPos = {0, 0},
    ._pos = {0, 0},
    ._speed = 0,
    ._delay = 0
    /* Methods definitions */
};

const Class *Aircraft = (const Class *)&_description;