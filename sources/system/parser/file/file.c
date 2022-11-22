/*
** Description:
** File's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include <string.h>

#include "raise.h"
#include "file.h"

static char *File_read(FileClass *this)
{
    char *content = malloc(sizeof(char) * (this->_size + 1));

    if (!content)
        raise("Can't malloc.");

    memset(content, 0, this->_size + 1);
    if (read(this->_fd, content, this->_size) == -1)
        raise("Can't read file.");

    return (content);
}

static void File_ctor(FileClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources
    struct stat info;

    this->_fd = open(va_arg(*args, char*), O_RDONLY);
    if (this->_fd == -1)
        raise("Can't open file.");

    if (fstat(this->_fd, &info) == ERROR)
        raise("Can't get file information.");
    this->_size = info.st_size;

    printf("File()\n");
}

static void File_dtor(FileClass *this)
{
    // Release internal resources
    close(this->_fd);

    printf("~File()\n");
}

static const FileClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FileClass),
        .__name__ = "File",
        .__ctor__ = (ctor_t)&File_ctor,
        .__dtor__ = (dtor_t)&File_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._size = 0,
    ._fd = 0,
    /* Getter and Setters */
    /* Methods definitions */
    .__read__ = &File_read
};

const Class *File = (const Class *)&_description;