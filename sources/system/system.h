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

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    typedef struct s_SystemClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        int                 state;

        /* Methods definitions*/
    } SystemClass;

    extern const Class *System;

    enum _GAMESTATE {
        QUIT=       -1,
        GAMESCENE=  0,
    };

    #define TIMEREFRESH 0.1

#endif /* !SYSTEM_H_ */