/*
** Description:
** Aircraft Functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "system.h"
#include "image.h"

void deleteTower(t_tower *tower)
{
    if (!tower)
        return;
    destroyImage(tower->image);
    free(tower);
}

void deleteTowers(t_tower **towers)
{
    size_t i = 0;

    if (!towers)
        return;
    while (towers[i]) {
        deleteTower(towers[i]);
        i += 1;
    }
    free(towers);
}

t_tower *createTower(sfVector2f pos, int rad)
{
    t_tower *tower = malloc(sizeof(tower));

    if (!tower)
        return (NULL);
    tower->pos = pos;
    tower->rad = rad;
    tower->image = NULL;
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