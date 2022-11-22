/*
** Description:
** Object Class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef CLASS_H_
    # define CLASS_H_

    # include <sys/types.h>
    # include <stdarg.h>
    # include <stdbool.h>
    # include <string.h>

    # include "raise.h"

    #define __UNUSED__ __attribute__ ((unused))

    #define ERROR   84
    #define SUCCESS 0

    typedef void Object;
    typedef void (*ctor_t)(Object *this, va_list *args);
    typedef void (*dtor_t)(Object *this);
    typedef char *(*to_string_t)(Object *this);
    typedef Object *(*binary_operator_t)(const Object *this, const Object *other);
    typedef bool (*binary_comparator_t)(const Object *this, const Object *other);

    typedef struct {
        const size_t        __size__;
        const char          *__name__;
        ctor_t              __ctor__;
        dtor_t              __dtor__;
        to_string_t         __str__;
        binary_operator_t   __add__;
        binary_operator_t   __sub__;
        binary_operator_t   __mul__;
        binary_operator_t   __div__;
        binary_comparator_t __eq__;
        binary_comparator_t __gt__;
        binary_comparator_t __lt__;
    }   Class;

    # define str(o)                 (((Class *)o)->__str__ != NULL ? ((Class *)o)->__str__(o) : strdup(((Class *)o)->__name__))
    # define addition(a, b)         ((Class *)a)->__add__(a, b)
    # define subtraction(a, b)      ((Class *)a)->__sub__(a, b)
    # define multiplication(a, b)   ((Class *)a)->__mul__(a, b)
    # define division(a, b)         ((Class *)a)->__div__(a, b)
    # define eq(a, b)               ((Class *)a)->__eq__(a, b)
    # define gt(a, b)               ((Class *)a)->__gt__(a, b)
    # define lt(a, b)               ((Class *)a)->__lt__(a, b)

#endif /* !CLASS_H_ */