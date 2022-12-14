/*
** Description:
** Aircraft's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stdlib.h>
#include <math.h>

#include "new.h"

#include "my.h"
#include "aircraft.h"

static void Aircraft_move(AircraftClass *this)
{
    if (this->_flying == false)
        return;
    // Update position
    this->_pos.x += this->_dir.x * this->_speed;
    this->_pos.y += this->_dir.y * this->_speed;

    // Check for landing
    int currentDist = sqrt(pow(this->_pos.x - this->_initPos.x, 2)  + pow(this->_pos.y - this->_initPos.y, 2));
    int landingDist = sqrt(pow(this->_landingPos.x - this->_initPos.x, 2)  + pow(this->_landingPos.y - this->_initPos.y, 2));
    if (currentDist > landingDist) {
        this->_flying = false;
        return;
    }

    // Update image position
    setImagePosition(this->base._image, this->_pos);
}

static void Aircraft_draw(IEntityClass *this, WindowClass* window)
{
    drawImage(this->_image, window->_window);
}

static void Aircraft_setOrientation(AircraftClass *this)
{
    sfVector2f d = {this->_landingPos.x - this->_initPos.x,
                    this->_landingPos.y - this->_initPos.y};
    double m = sqrt(pow(d.x, 2) + pow(d.y, 2));
    float rangle = 0;

    if (d.x == 0) {
        if (d.y > 0)
            rangle = M_PI_2;
        else
            rangle = 3*M_PI_2;
    } else if (d.x < 0)
        rangle = -M_PI - atan(d.y / -d.x);
    else
        rangle = atan(d.y / d.x);

    this->_dir = (sfVector2f){d.x / m, d.y / m};
    setImageRotation(this->base._image, radToDeg(rangle) - DEFAULT_ANGLE);
}

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
    this->_flying = true;
    // Compute direction
    this->base._image = new(Image, AIRCRAFT_IPATH, this->_initPos, NULL);
    this->__setOrientation__(this);

    freeArray(data);
    printf("Aircraft()\n");
}

static void Aircraft_dtor(__UNUSED__ AircraftClass *this)
{
    // Release internal resources
    delete(this->base._image);

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
        },
        ._image = NULL,
        /* Methods */
        .__draw__ = &Aircraft_draw
    },
    ._initPos = {0, 0},
    ._landingPos = {0, 0},
    ._pos = {0, 0},
    ._dir = {0, 0},
    ._speed = 0,
    ._delay = 0,
    ._flying = false,
    /* Methods definitions */
    .__move__ = &Aircraft_move,
    .__setOrientation__ = &Aircraft_setOrientation
};

const Class *Aircraft = (const Class *)&_description;