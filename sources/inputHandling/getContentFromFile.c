/*
** Description:
** Parsing functions
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "my.h"

long int getFileSize(int fd)
{
    struct stat buf;

    if (fstat(fd, &buf) == ERROR)
        return (ERROR);
    return (buf.st_size);
}

int openFile(const char *path)
{
    return (open(path, O_RDONLY));
}

char *readContentFromFile(int fd, int fileSize)
{
    char *content = malloc(sizeof(char) * (fileSize + 1));

    if (!content)
        return (NULL);
    my_memset(content, 0, fileSize + 1);
    if (read(fd, content, fileSize) == ERROR) {
        free(content);
        return (NULL);
    }
    return (content);
}

char *getContentFromFile(const char* path)
{
    char *content = NULL;
    int fd = 0;
    int fileSize = 0;

    if ((fd = openFile(path)) == ERROR)
        return (NULL);
    if ((fileSize = getFileSize(fd)) == ERROR) {
        close(fd);
        return (NULL);
    }
    content = readContentFromFile(fd, fileSize);
    close(fd);
    return (content);
}