/*
** Description:
** Aircraft Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "system.h"

void removeTower(t_tower *tower)
{
    free(tower);
}

t_tower *createTower(sfVector2f pos, int rad)
{
    t_tower *tower = malloc(sizeof(tower));

    if (!tower)
        return (NULL);
    tower->pos = pos;
    tower->rad = rad;
    return (tower);
}

t_tower **createTowerArray(size_t towerNumber)
{
    size_t i = 0;
    t_tower **array = malloc(sizeof(t_tower*) * (towerNumber + 1));

    if (!array)
        return (NULL);
    while (i <= towerNumber) {
        array[i] = NULL;
        i += 1;
    }
    return (array);
}