/*
** Description:
** ErrorHandling's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "errorHandling.h"

static int ErrorHandling_getStatus(ErrorHandlingClass *this){return (this->_status);}
static void ErrorHandling_setStatus(ErrorHandlingClass *this, int status){this->_status = status;}

static int ErrorHandling_run(__UNUSED__ ErrorHandlingClass *this, __UNUSED__ int ac, __UNUSED__ char **av)
{
    printf("Checking inputs...\n");

    printf("-> ok!\n");
    return (0);
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
    /* Getter and Setters */
    .__getStatus__ = &ErrorHandling_getStatus,
    .__setStatus__ = &ErrorHandling_setStatus,
    /* Methods definitions */
    .__run__ = &ErrorHandling_run
};

const Class *ErrorHandling = (const Class *)&_description;