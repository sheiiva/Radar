/*
** Description:
** Aircraft's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef AIRCRAFT_H_
    #define AIRCRAFT_H_

    #include "iEntity.h"

    typedef struct s_AircraftClass {

        /* Inheritance */
        IEntityClass base;

        /* Special Definition*/
        sfVector2f  _initPos;
        sfVector2f  _landingPos;
        sfVector2f  _pos;
        size_t      _speed;
        size_t      _delay;
        // t_image *image;

        /* Methods definitions*/
    } AircraftClass;

    extern const Class *Aircraft;

    #define createAircraft(a, ...) ((Container*)a)->__setitem__(a, __VA_ARGS__)

#endif /* !AIRCRAFT_H_ */