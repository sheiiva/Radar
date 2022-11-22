/*
** Description:
** Parser's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef PARSER_H_
    #define PARSER_H_

    #include "object.h"

    typedef struct s_ParserClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/

        /* Getter and Setters */

        /* Methods definitions*/
        int (*__run__)(struct s_ParserClass*, char*);
    } ParserClass;

    extern const Class *Parser;

#endif /* !PARSER_H_ */