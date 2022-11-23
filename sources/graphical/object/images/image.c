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

static void Image_setScale(ImageClass *this, sfVector2f scale)
{
    sfSprite_setScale(this->sprite, scale);
}

static sfVector2f Image_getScale(const ImageClass *this)
{
    return sfSprite_getScale(this->sprite);
}

static void Image_setRotation(ImageClass *this, float angle)
{
    sfSprite_setRotation(this->sprite, angle);
}

static float Image_getRotation(const ImageClass *this)
{
    return sfSprite_getRotation(this->sprite);
}

static void Image_setPosition(ImageClass *this, sfVector2f position)
{
    sfSprite_setPosition(this->sprite, position);
}

static sfVector2f Image_getPosition(const ImageClass *this)
{
    return sfSprite_getPosition(this->sprite);
}

static void Image_setRect(ImageClass *this, sfIntRect rect)
{
    sfSprite_setTextureRect(this->sprite, rect);
}

static sfIntRect Image_setRect(const ImageClass *this)
{
    return sfSprite_getTextureRect(this->sprite);
}

static void Image_display(const ImageClass *this, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, this->sprite, NULL);
}

static void Image_ctor(ImageClass *this, va_list *args)
{
    // Initialize internal resources
    if (!(this->filePath = strdup(va_arg(*args, char*))))
        raise("Can't duplicate path");
    if (!(this->texture = sfTexture_createFromFile(this->filePath, NULL)))
        raise("Can't create Texture from file");
    if (!(this->sprite = sfSprite_create()))
        raise("Can't create Sprite");
    sfSprite_setPosition(this->sprite, va_arg(*args, sfVector2f));
    sfSprite_setTexture(this->sprite, this->texture, sfTrue);
    this->offset = va_arg(*args, int);

    sfIntRect *rect = va_arg(*args, sfIntRect*);
    if (rect)
        sfSprite_setTextureRect(this->sprite, *rect);

    printf("Image()\n");
}

static void Image_dtor(ImageClass *this)
{
    // Release internal resources
    free(this->filePath);
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
    .filePath = NULL,
    .texture = NULL,
    .sprite = NULL,
    /* GET / SET */
    .__setScale__ = &Image_setScale,
    .__getScale__ = &Image_getScale,
    .__setRotation__ = &Image_setRotation,
    .__getRotation__ = &Image_getRotation,
    .__setPosition__ = &Image_setPosition,
    .__getPosition__ = &Image_getPosition,
    .__setRect__ = &Image_setRect,
    .__getRect__ = &Image_getRect,
    /* Methods definitions */
    .__display__ = &Image_display
};

const Class *Image = (const Class *)&_description;