/*
** Description:
** Entity's interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "iEntity.h"

static const IEntityClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IEntityClass),
        .__name__ = "IEntity",
        .__ctor__ = NULL,
        .__dtor__ = NULL,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    }
    /* Methods definitions */
};

const Class *IEntity = (const Class *)&_description;