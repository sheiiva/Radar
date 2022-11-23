/*
** Description:
** IEntity's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef IENTITY_H_
    #define IENTITY_H_

    #include <SFML/System.h>

    #include "object.h"

    typedef struct s_IEntityClass {

        /* Inheritance */
        Class base;

    } IEntityClass;

    extern const Class *IEntity;

#endif /* !IENTITY_H_ */