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
    #include <stdlib.h>

    typedef struct s_aircraft {
        sfVector2f initPos;
        sfVector2f landingPos;
        sfVector2f pos;
        size_t speed;
        size_t delay;
    } t_aircraft;

    typedef struct s_tower {
        sfVector2f pos;
        int rad;
    } t_tower;

    typedef struct s_system {
        t_aircraft **aircrafts;
        t_tower ** towers;
    } t_system;

    t_aircraft *createAircraft(sfVector2f initPos, sfVector2f landingPos, sfVector2f pos, size_t speed, size_t delay);
    t_aircraft **createAircraftArray(size_t aircraftNumber);
    void removeAircraft(t_aircraft *aircraft);

    t_tower *createTower(sfVector2f pos, int rad);
    t_tower **createTowerArray(size_t towerNumber);
    void removeTower(t_tower *tower);

#endif /* !SYSTEM_H_ */