/*
** Description:
** Parse string into array
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "my.h"

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

void my_freeArray(char **array)
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

char **malloc_array_index(char **array, const char *str, size_t word_i, size_t size, char split)
{
    size_t i = 0;
    array[word_i] = malloc(sizeof(char) * (size + 1));

    if (!array[word_i]) {
        my_freeArray(array);
        return (NULL);
    }
    while (str[i] && (str[i] != split)) {
        array[word_i][i] = str[i];
        i += 1;
    }
    array[word_i][i] = '\0';
    return (array);
}

char **my_strtowordarray(const char *str, char split)
{
    size_t size = 0;
    size_t word_i = 0;
    size_t i = 0;
    size_t lineNumber = count_n(str, split);
    char **array = malloc(sizeof(char*) * (lineNumber + 1));

    if (!array)
        return (NULL);
    array[lineNumber] = NULL;
    while (str[i] && (word_i < lineNumber)) {
        size = my_nstrlen(&str[i], split);
        if (!malloc_array_index(array, &str[i], word_i, size, split))
            return (NULL);
        word_i += 1;
        i += size;
        while (str[i] == split)
            i += 1;
    }
    return (array);
}