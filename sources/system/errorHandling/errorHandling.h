/*
** Description:
** ErrorHandling's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef ERRORHANDLING_H_
    #define ERRORHANDLING_H_

    #include "object.h"

    typedef struct s_ErrorHandlingClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        int _status;

        /* Methods definitions*/
        int (*__run__)(struct s_ErrorHandlingClass*, int, char**);
    } ErrorHandlingClass;

    extern const Class *ErrorHandling;

    #define HELP_MESSAGE "\n\
Air traffic simulation panel\n\n\
USAGE\n\
    ./my_radar [OPTIONS] path_to_script\n\
    path_to_script\tThe path to the script file.\n\n\
OPTIONS\n\
    -h\t\tprint the usage and quit.\n\n\
USER INTERACTIONS\n\
    \'L\' key\tenable/disable hitboxes and areas.\n\
    \'S\' key\tenable/disable sprites.\n\0"

#endif /* !ERRORHANDLING_H_ */