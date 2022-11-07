/*
** Description:
** Parsing functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"
#include "parsing.h"
#include "system.h"
#include "image.h"

t_aircraft *parseAircraft(char **array)
{
    t_aircraft *aircraft = malloc(sizeof(t_aircraft));

    if (!aircraft)
        return (NULL);
    aircraft->initPos = (sfVector2f){atoi(array[0]), atoi(array[1])};
    aircraft->landingPos = (sfVector2f){atoi(array[2]), atoi(array[3])};
    aircraft->pos = aircraft->initPos;
    aircraft->speed = atoi(array[4]);
    aircraft->delay = atoi(array[5]);
    aircraft->image = createImage("assets/images/plane.png", aircraft->initPos);
    return (aircraft);
}

t_tower *parseTower(char **array)
{
    t_tower *tower = malloc(sizeof(t_tower));

    if (!tower)
        return (NULL);
    tower->pos = (sfVector2f){atoi(array[0]), atoi(array[1])};
    tower->rad = atoi(array[2]);
    tower->image = createImage("assets/images/tower.png", tower->pos);
    return (tower);
}

t_system *fillSystem(t_system *system, char **array, size_t aircraftNumber, size_t towerNumber)
{
    size_t i = 0;
    size_t aircraft_i = 0;
    size_t tower_i = 0;
    system = initSystem(aircraftNumber, towerNumber);

    if (!system)
        return (system);
    while (array[i]) {
        if (my_strcmp(array[i], "A") == SUCCESS)
            system->aircrafts[aircraft_i++] = parseAircraft(&array[i + 1]);
        else if (my_strcmp(array[i], "T") == SUCCESS)
            system->towers[tower_i++] = parseTower(&array[i + 1]);
        i += 1;
        while (array[i]
                && my_strcmp(array[i], "A") != SUCCESS
                && my_strcmp(array[i], "T") != SUCCESS)
            i += 1;
    }
    return (system);
}

t_system *parsing(const char *path)
{
    char **array = NULL;
    t_system *system = NULL;
    char *content = getContentFromFile(path);

    if (!content)
        return (NULL);
    cleanString(content);
    array = my_strtowordarray(content, ' ');
    system = fillSystem(system, array, count_n(content, 'A'), count_n(content, 'T'));

    free(content);
    my_freeArray(array);
    return (system);
}