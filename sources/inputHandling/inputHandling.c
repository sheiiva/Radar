/*
** Description:
** Main Function
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "macro.h"

void printHelp(void)
{
    my_putstr(HELP_MESSAGE, STDIN);
}

void printErrorMessage(int ac)
{
    my_putstr("./my_radar: bad arguments: ", STDERR);
    my_putchar((ac-1) + '0', STDERR);
    my_putstr(" given but 1 is required\n", STDERR);
    my_putstr("retry with -h\n", STDERR);
}

int checkInputArgs(int ac, char **av)
{
    if (ac != 2) {
        printErrorMessage(ac);
        return (FAILURE);
    } else if (my_strcmp(av[1], "-h") == SUCCESS) {
        printHelp();
        return (HELP);
    } else {
        return (SUCCESS);
    }
}