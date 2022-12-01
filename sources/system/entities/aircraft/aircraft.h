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
    #include "image.h"

    typedef struct s_AircraftClass {

        /* Inheritance */
        IEntityClass base;

        /* Special Definition*/
        sfVector2f  _initPos;
        sfVector2f  _landingPos;
        sfVector2f  _pos;
        sfVector2f  _dir;
        size_t      _speed;
        size_t      _delay;

        /* Methods definitions*/
        void (*__move__)(struct s_AircraftClass*);
        void (*__setOrientation__)(struct s_AircraftClass*);
    } AircraftClass;

    extern const Class *Aircraft;

    #define createAircraft(a, ...)  ((Container*)a)->__setitem__(a, __VA_ARGS__)
    #define drawAircraft(a, w)      ((IEntityClass*)a)->__draw__(a, w)
    #define moveAircraft(a)         ((AircraftClass*)a)->__move__(a)

    #define AIRCRAFT_IPATH "assets/images/plane.png"

    #define DEFAULT_ANGLE -45

#endif /* !AIRCRAFT_H_ */