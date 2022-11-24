/*
** Description:
** Scene's Image structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include <math.h>

    #include "object.h"

    typedef struct s_ImageClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfTexture*  texture;
        sfSprite*   sprite;

        /* Methods definitions */
        void (*__draw__)(const struct s_ImageClass*, sfRenderWindow*);

    } ImageClass;

    extern const Class *Image;

    /* METHODS */
    #define drawImage(i, w)          ((ImageClass*)i)->__draw__(i, w)

    /* GET/SET */
    #define setImageScale(i, s)         sfSprite_setScale(((ImageClass*)i)->sprite, s)
    #define getImageScale(i)            sfSprite_getScale(((ImageClass*)i)->sprite)

    #define setImageRotation(i, a)      sfSprite_setRotation(((ImageClass*)i)->sprite, a)
    #define getImageRotation(i)         sfSprite_getRotation(((ImageClass*)i)->sprite)

    #define setImagePosition(i, p)      sfSprite_setPosition(((ImageClass*)i)->sprite, p)
    #define getImagePosition(i)         sfSprite_getPosition(((ImageClass*)i)->sprite)

    #define setImageRect(i, r)          sfSprite_setTextureRect(((ImageClass*)i)->sprite, r)
    #define getImageRect(i)             sfSprite_getTextureRect(((ImageClass*)i)->sprite)

    /* OTHERS */
    #define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
    #define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)


#endif /* !IMAGE_H_ */