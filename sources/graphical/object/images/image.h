/*
** Description:
** Scene's Image structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
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
        char*       filePath;
        sfTexture*  texture;
        sfSprite*   sprite;

        /* GET/SET*/
        void        (*__setScale__)(struct s_ImageClass*, sfVector2f);
        sfVector2f  (*__getScale__)(const struct s_ImageClass*);
        void        (*__setRotation__)(struct s_ImageClass*, float);
        float       (*__getRotation__)(const struct s_ImageClass*);
        void        (*__setPosition__)(struct s_ImageClass*, sfVector2f);
        sfVector2f  (*__getPosition__)(const struct s_ImageClass*);
        void        (*__setRect__)(struct s_ImageClass*, sfIntRect);
        sfIntRect   (*__getRect__)(const struct s_ImageClass*);

        /* Methods definitions */
        void (*__display__)(const struct s_ImageClass*, sfRenderWindow*);

    } ImageClass;

    extern const Class *Image;

    /* METHODS */
    #define displayImage(i, w)          ((ImageClass*)i)->__display__(i, w)

    /* GET/SET */
    #define setImageScale(i, s)         ((ImageClass*)i)->__setScale__(i, s)
    #define getImageScale(i)            ((ImageClass*)i)->__getScale__(i)

    #define setImageRotation(i, a)      ((ImageClass*)i)->__setRotation__(i, a)
    #define getImageRotation(i)         ((ImageClass*)i)->__getRotation__(i)

    #define setImagePosition(i, p)      ((ImageClass*)i)->__setPosition__(i, p)
    #define getImagePosition(i)         ((ImageClass*)i)->__getPosition__(i)

    #define setImageRect(i, r)          ((ImageClass*)i)->__setRect__(i, r)
    #define getImageRect(i)             ((ImageClass*)i)->__getRect__(i)

    /* OTHERS */
    #define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
    #define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)


#endif /* !IMAGE_H_ */