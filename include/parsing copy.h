/*
** Description:
** System Structures
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #include <SFML/System.h>

    #include <stddef.h>

    typedef struct s_aircraft {
        sfVector2f initPos;
        sfVector2f LandingPos;
        sfVector2f pos;
        size_t speed;
        size_t delay;
    } t_aircraft;

    typedef struct s_tour {
        sfVector2f pos;
        int rad;
    } t_tour;

    typedef struct s_system {
        t_aircraft **aircrafts;
        t_tour ** tours;
    } t_system;

#endif /* !SYSTEM_H_ */