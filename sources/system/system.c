/*
** Description:
** System Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "system.h"

void deleteSystem(t_system *system)
{
    if (!system)
        return;
    deleteAircrafts(system->aircrafts);
    deleteTowers(system->towers);
    free(system);
}

t_system *initSystem(size_t aircraftNumber, size_t towerNumber)
{
    t_system *system = malloc(sizeof(t_system));

    if (!system)
        return (NULL);
    if (!(system->aircrafts = createAircraftArray(aircraftNumber))
        || (system->towers = createTowerArray(towerNumber))) {
            deleteSystem(system);
            return (NULL);
    }
    return (system);
}