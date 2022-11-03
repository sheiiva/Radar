/*
** Description:
** Clean String
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <stddef.h>

void shiftLeft(char *string)
{
    size_t i = 0;

    while (string[i + 1]) {
        string[i] = string[i + 1];
        i += 1;
    }
    string[i] = '\0';
}

void removeDuplicate(char *string, char c)
{
    size_t i = 0;

    while (string[i]) {
        while (string[i + 1] && string[i] == c && string[i + 1] == c) {
            shiftLeft(&string[i]);
            i += 1;
        }
        i += 1;
    }
}

void cleanString(char *string)
{
    size_t i = 0;

    while (string[i]) {
        if ((string[i] == '\t') || (string[i] == '\n') || (string[i] == '\r'))
            string[i] = ' ';
        i += 1;
    }
    removeDuplicate(string, ' ');
}