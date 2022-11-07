/*
** Description:
** Image Manager
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "image.h"
#include "my.h"

void destroyImage(t_image *image)
{
    free(image->source);
    if (image->texture)
        sfTexture_destroy(image->texture);
    if (image->sprite)
        sfSprite_destroy(image->sprite);
}

void drawImage(sfRenderWindow* window, t_image *image)
{
    sfRenderWindow_drawSprite(window, image->sprite, NULL);
}

void setPos(t_image *image, sfVector2f position)
{
    image->position = position;
    sfSprite_setPosition(image->sprite, image->position);
}

t_image *createImage(char const *path, sfVector2f position)
{
    t_image *image = malloc(sizeof(t_image));

    if (!image)
        return (NULL);
    image->source = my_strdup(path);
    if (!image->source) {
        destroyImage(image);
        return (NULL);
    }
    image->texture = sfTexture_createFromFile(path, NULL);
    if (!image->texture) {
        destroyImage(image);
        return (NULL);
    }
    image->sprite = sfSprite_create();
    if (!image->sprite) {
        destroyImage(image);
        return (NULL);
    }
    setPos(image, position);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    return (image); 
}