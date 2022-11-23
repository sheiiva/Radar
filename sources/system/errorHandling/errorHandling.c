/*
** Description:
** ErrorHandling's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <string.h>
#include <stdio.h>

#include "errorHandling.h"

static int ErrorHandling_run(__UNUSED__ ErrorHandlingClass *this, __UNUSED__ int ac, __UNUSED__ char **av)
{
    printf("Checking inputs...\n");

    if (ac != 2) {
        printf("-> ko!\n%s\n", HELP_MESSAGE);
        return (ERROR);
    } else if (strcmp(av[1], "-h") == SUCCESS) {
        printf("%s\n", HELP_MESSAGE);
        return (-1);
    } else {
        printf("-> ok!\n");
        return (SUCCESS);
    }
}

static void ErrorHandling_ctor(__UNUSED__ ErrorHandlingClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources

    printf("ErrorHandling()\n");
}

static void ErrorHandling_dtor(__UNUSED__ ErrorHandlingClass *this)
{
    // Release internal resources

    printf("~ErrorHandling()\n");
}

static const ErrorHandlingClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ErrorHandlingClass),
        .__name__ = "ErrorHandling",
        .__ctor__ = (ctor_t)&ErrorHandling_ctor,
        .__dtor__ = (dtor_t)&ErrorHandling_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._status = 0,
    /* Methods definitions */
    .__run__ = &ErrorHandling_run
};

const Class *ErrorHandling = (const Class *)&_description;