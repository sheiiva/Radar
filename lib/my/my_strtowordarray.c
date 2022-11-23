/*
** Description:
** Parse string into array
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stdlib.h>
#include <string.h>
#include <stddef.h>

static size_t nstrlen(const char *str, char n)
{
    size_t i = 0;

    while ((str[i]) && (str[i] != n))
        i += 1;
    return (i);
}

size_t count_n(const char *str, char n)
{
    size_t i = 0;
    size_t count = 0;

    while (str[i]) {
        if (str[i] == n)
            count += 1;
        i += 1;
    }
    return (count);
}

void freeArray(char **array)
{
    size_t i = 0;

    if (!array)
        return;
    while (array[i]) {
        free(array[i]);
        i += 1;
    }
    free(array);
}

char **strtowordarray(const char *str, char split)
{
    size_t word_i = 0;
    size_t i = 0;
    size_t wordNumber = count_n(str, split) + 1;
    char **array = malloc(sizeof(char*) * (wordNumber + 1));

    if (!array)
        return (NULL);
    array[wordNumber] = NULL;
    while (str[i] && (word_i < wordNumber)) {
        array[word_i] = strndup(&str[i], nstrlen(&str[i], split));
        if (!array[word_i]) {
            freeArray(array);
            return (NULL);
        }
        word_i += 1;
        i += nstrlen(&str[i], split);
        while (str[i] == split)
            i += 1;
    }
    return (array);
}