/*
** Description:
** File's structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef FILE_H_
    #define FILE_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>

    #include "object.h"

    typedef struct s_FileClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        long    _size;
        int     _fd;

        /* Methods definitions*/
        char* (*__read__)(struct s_FileClass*);
    } FileClass;

    extern const Class *File;

    #define readFile(f) ((FileClass*)f)->__read__(f)

#endif /* !FILE_H_ */