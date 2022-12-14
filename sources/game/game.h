/*
** Description:
** Game's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef GAME_H_
    #define GAME_H_

    #include "object.h"

    #include "scene.h"
    #include "window.h"
    #include "system.h"

    typedef struct s_GameClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        SceneClass*     _scene;
        WindowClass*    _window;

        /* Methods definitions*/
        void (*__display__)(struct s_GameClass*, SystemClass*);
        void (*__process__)(struct s_GameClass*, SystemClass*);
        void (*__run__)(struct s_GameClass*, SystemClass*);
    } GameClass;

    extern const Class *Game;

    #define displayGame(r, s)   ((GameClass*)r)->__display__(r, s)
    #define processGame(r, s)   ((GameClass*)r)->__process__(r, s)
    #define runGame(r, s)       ((GameClass*)r)->__run__(r, s)

#endif /* !GAME_H_ */