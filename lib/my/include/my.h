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

    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>

    #define STDIN   0
    #define STDOUT  1
    #define STDERR  2

    #define SUCCESS 0
    #define FAILURE 84
    #define ERROR   -1

    size_t count_n(const char *str, char n);

    void    my_freeArray(char **array);
    void*   my_memset(void *s, int c, size_t n);
    size_t  my_nstrlen(const char *str, char n);
    ssize_t my_putchar(char c, int fd);
    ssize_t my_putstr(const char *str, int fd);
    int     my_strcmp(const char *s1, const char *s2);
    char*   my_strcpy(char *dest, const char *src);
    char*   my_strdup(const char *s);
    size_t  my_strlen(char const *str);
    char**  my_strtowordarray(const char *str, char split);

#endif /* !MY_H_ */