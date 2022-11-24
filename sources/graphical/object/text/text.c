/*
** Description:
** Text's class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "raise.h"

#include "text.h"

static void Text_setFont(TextClass *this, sfFont *font)
{
    if (!font)
        return;

    this->_font = font;
    sfText_setFont(this->_text, font);
}

static const sfFont *Text_getFont(const TextClass *this)
{
    return sfText_getFont(this->_text);
}

static void Text_draw(TextClass *this, sfRenderWindow *window)
{
    sfRenderWindow_drawText(window, this->_text, NULL);
}

static sfBool Text_mouseOnText(const TextClass *this, const sfRenderWindow *window)
{
    sfFloatRect rect = sfText_getGlobalBounds(this->_text);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x > rect.left && mouse.x < rect.left + rect.width
        && mouse.y > rect.top && mouse.y < rect.top + rect.height)
        return (sfTrue);
    return (sfFalse);
}

static sfBool Text_clickOnText(const TextClass *this, const sfRenderWindow *window)
{
    if (Text_mouseOnText(this, window) && sfMouse_isButtonPressed(sfMouseLeft))
        return (sfTrue);
    return (sfFalse);
}

static void Text_ctor(TextClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->_text = sfText_create()))
        raise("Can't create sfText");

    setTextString(this, va_arg(*args, char*));
    setTextSize(this, va_arg(*args, unsigned int));
	setTextColor(this, va_arg(*args, sfColor));
    setTextPosition(this, va_arg(*args, sfVector2f));

    if (!(this->_font = sfFont_createFromFile(va_arg(*args, char*))))
        raise("Can't create Sprite");
    setTextFont(this, this->_font);

    printf("Text()\n");
}

static void Text_dtor(TextClass *this)
{
    // Release internal resources
    if (this->_text)
        sfText_destroy(this->_text);
    if (this->_font)
        sfFont_destroy(this->_font);

    printf("~Text()\n");
}

static const TextClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(TextClass),
        .__name__ = "Text",
        .__ctor__ = (ctor_t)&Text_ctor,
        .__dtor__ = (dtor_t)&Text_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._text = NULL,
    ._font = NULL,
    /* Getter and Setter */
    .__setFont__ = &Text_setFont,
    .__getFont__ = &Text_getFont,
    /* Methods definitions */
    .__draw__ = &Text_draw,
    .__mouseOnText__ = &Text_mouseOnText,
    .__clickOnText__ = &Text_clickOnText
};

const Class *Text = (const Class *)&_description;