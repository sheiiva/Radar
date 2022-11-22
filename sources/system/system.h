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

    typedef struct s_SystemClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        int _status;

        /* Methods definitions*/
        int (*__run__)(struct s_SystemClass*, int, char**);
    } SystemClass;

    extern const Class *System;

    #define runSystem(r, ac, av) ((SystemClass*)r)->__run__(r, ac, av)

    #define ERROR   84
    #define SUCCESS 0

#endif /* !SYSTEM_H_ */