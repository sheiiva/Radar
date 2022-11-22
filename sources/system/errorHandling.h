/*
** Description:
** ErrorHandling's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef ERRORHANDLING_H_
    #define ERRORHANDLING_H_

    #include "object.h"

    typedef struct s_ErrorHandlingClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        int _status;

        /* Getter and Setters */
        int (*__getStatus__)(struct s_ErrorHandlingClass*);
        void (*__setStatus__)(struct s_ErrorHandlingClass*, int);

        /* Methods definitions*/
        int (*__run__)(struct s_ErrorHandlingClass*, int, char**);
    } ErrorHandlingClass;

    extern const Class *ErrorHandling;

#endif /* !ERRORHANDLING_H_ */