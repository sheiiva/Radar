/*
** Description:
** Tower's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <string.h>

#include "new.h"

#include "my.h"
#include "tower.h"

static void Tower_draw(IEntityClass *this, WindowClass* window)
{
    drawImage(this->_image, window->_window);
}

static void Tower_ctor(TowerClass *this, va_list *args)
{
    char **data = strtowordarray(va_arg(*args, char*), ' ');

    // Check settins format
    size_t i = 0;
    while (data[i]) {i++;}
    if (i != 4)
        raise("Wrong Aircraft settings.");

    // Initialize internal resources
    this->_pos = (sfVector2f){atof(data[1]), atof(data[2])};
    this->_rad = atol(data[3]);

    this->base._image = new(Image, TOWER_IPATH, this->_pos, NULL);

    freeArray(data);
    printf("Tower()\n");
}

static void Tower_dtor(__UNUSED__ TowerClass *this)
{
    // Release internal resources
    delete(this->base._image);

    printf("~Tower()\n");
}

static const TowerClass _description = {
    { /* IEntity struct */
        {   /* Class struct */
        .__size__ = sizeof(TowerClass),
        .__name__ = "Tower",
        .__ctor__ = (ctor_t)&Tower_ctor,
        .__dtor__ = (dtor_t)&Tower_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
        },
        ._image = NULL,
        /* Methods */
        .__draw__ = &Tower_draw
    },
    ._pos = {0, 0},
    ._rad = 0
    /* Methods definitions */
};

const Class *Tower = (const Class *)&_description;