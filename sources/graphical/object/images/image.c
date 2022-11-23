/*
** Description:
** Image's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "raise.h"

#include "image.h"

static void Image_display(const ImageClass *this, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, this->sprite, NULL);
}

static void Image_ctor(ImageClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->texture = sfTexture_createFromFile(va_arg(*args, char*), NULL)))
        raise("Can't create Texture from file");
    if (!(this->sprite = sfSprite_create()))
        raise("Can't create Sprite");
    sfSprite_setTexture(this->sprite, this->texture, sfTrue);

    setImagePosition(this, va_arg(*args, sfVector2f));

    sfIntRect *rect = va_arg(*args, sfIntRect*);
    if (rect)
        setImageRect(this, *rect);

    printf("Image()\n");
}

static void Image_dtor(ImageClass *this)
{
    // Release internal resources
    if (this->texture)
        sfTexture_destroy(this->texture);
    if (this->sprite)
        sfSprite_destroy(this->sprite);

    printf("~Image()\n");
}

static const ImageClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ImageClass),
        .__name__ = "Image",
        .__ctor__ = (ctor_t)&Image_ctor,
        .__dtor__ = (dtor_t)&Image_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .texture = NULL,
    .sprite = NULL,
    /* Methods definitions */
    .__display__ = &Image_display
};

const Class *Image = (const Class *)&_description;