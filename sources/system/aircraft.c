/*
** Description:
** Aircraft Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "system.h"

void removeAircraft(t_aircraft *aircraft)
{
    free(aircraft);
}

t_aircraft *createAircraft(sfVector2f initPos, sfVector2f landingPos,
                            sfVector2f pos, size_t speed, size_t delay)
{
    t_aircraft *aircraft = malloc(sizeof(t_aircraft));

    if (!aircraft)
        return (NULL);
    aircraft->initPos = initPos;
    aircraft->landingPos = landingPos;
    aircraft->pos = pos;
    aircraft->speed = speed;
    aircraft->delay = delay;
    return (aircraft);
}

t_aircraft **createAircraftArray(size_t aircraftNumber)
{
    size_t i = 0;
    t_aircraft **array = malloc(sizeof(t_aircraft*) * (aircraftNumber + 1));

    if (!array)
        return (NULL);
    while (i <= aircraftNumber) {
        array[i] = NULL;
        i += 1;
    }
    return (array);
}