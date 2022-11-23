/*
** Description:
** Tower's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef TOWER_H_
    #define TOWER_H_

    #include "iEntity.h"

    typedef struct s_TowerClass {

        /* Inheritance */
        IEntityClass base;

        /* Special Definition*/
        sfVector2f  _pos;
        int         _rad;
        // t_image *image;
        // t_framebuffer *framebuffer;

        /* Methods definitions*/
    } TowerClass;

    extern const Class *Tower;

    #define createTower(a, ...) ((Container*)a)->__setitem__(a, __VA_ARGS__)

#endif /* !TOWER_H_ */