/*
** Description:
** System's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include "object.h"

    #include "clock.h"
    #include "game.h"

    typedef struct s_GameClass GameClass;

    typedef struct s_SystemClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*         _aircrafts;
        Object*         _towers;
        ClockClass*     _clock;
        GameClass *     _game;

        /* Methods definitions*/
        int (*__run__)(struct s_SystemClass*, int, char**);
    } SystemClass;

    extern const Class *System;

    #define REFRESHTIME 100

    #define ctime(s)    sfTime_asMilliseconds(sfClock_getElapsedTime(((SystemClass*)s)->_clock->clock))
    #define refresh(s)  sfClock_restart(((SystemClass*)s)->_clock->clock)

    #define runSystem(r, ac, av) ((SystemClass*)r)->__run__(r, ac, av)

#endif /* !SYSTEM_H_ */