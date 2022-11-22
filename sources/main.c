/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "new.h"
#include "system.h"

int main(int ac, char **av)
{
    SystemClass* system = new(System);
    int returnv = runSystem(system, ac, av);

    delete(system);
    return (returnv);
}