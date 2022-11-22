/*
** Description:
** Parser's class Definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#include "new.h"

#include "parser.h"
#include "file.h"

static int Parser_run(__UNUSED__ ParserClass *this, char *filePath)
{
    printf("Parsing...\n");

    FileClass *file = new(File, filePath);
    char *fileContent = readFile(file);

    printf("%s\n", fileContent);

    return (SUCCESS);
}

static void Parser_ctor(__UNUSED__ ParserClass *this, __UNUSED__ va_list *args)
{
    // Initialize internal resources

    printf("Parser()\n");
}

static void Parser_dtor(__UNUSED__ ParserClass *this)
{
    // Release internal resources

    printf("~Parser()\n");
}

static const ParserClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ParserClass),
        .__name__ = "Parser",
        .__ctor__ = (ctor_t)&Parser_ctor,
        .__dtor__ = (dtor_t)&Parser_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    /* Getter and Setters */
    /* Methods definitions */
    .__run__ = &Parser_run
};

const Class *Parser = (const Class *)&_description;