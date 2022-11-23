/*
** Description:
** Library's Prototypes
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>

    size_t count_n(const char *str, char n);

    void    freeArray(char **array);
    char**  strtowordarray(const char *str, char split);

#endif /* !MY_H_ */