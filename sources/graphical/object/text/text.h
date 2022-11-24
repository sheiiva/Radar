/*
** Description:
** Scene's Text structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "object.h"

    typedef struct s_TextClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        sfText*         _text;
        sfFont*   _font;

        /* Getter and Setter */
        void            (*__setFont__)(struct s_TextClass*, sfFont*);
        const sfFont*   (*__getFont__)(const struct s_TextClass*);

        /* Methods definitions */
        void (*__draw__)(struct s_TextClass*, sfRenderWindow*);
        sfBool (*__mouseOnText__)(const struct s_TextClass*, const sfRenderWindow*);
        sfBool (*__clickOnText__)(const struct s_TextClass*, const sfRenderWindow*);

    } TextClass;

    /* METHODS */
    #define drawText(t, w)   ((TextClass*)t)->__draw__(t, w)

    /* GET/SET */

    #define setTextString(t, s)     sfText_setString(((TextClass*)t)->_text, s)
    #define getTextString(t)        sfText_getString(((TextClass*)t)->_text)

    #define setTextColor(t, c)      sfText_setColor(((TextClass*)t)->_text, c)
    #define getTextColor(t)         sfText_getColor(((TextClass*)t)->_text)

    #define setTextPosition(t, p)   sfText_setPosition(((TextClass*)t)->_text, p)
    #define getTextPosition(t)      sfText_getPosition(((TextClass*)t)->_text)

    #define setTextSize(t, s)       sfText_setCharacterSize(((TextClass*)t)->_text, s)
    #define getTextSize(t)          sfText_getCharacterSize(((TextClass*)t)->_text)

    #define setTextFont(t, f)       ((TextClass*)t)->__setFont__(t, f)
    #define getTextFont(t)          ((TextClass*)t)->__getFont__(t)

    /* OTHERS */
    #define mouseOnText(t, w)      ((TextClass*)t)->__mouseOnText__(t, w)
    #define clickOnText(t, w)      ((TextClass*)t)->__clickOnText__(t, w)

    #define ORANGE  (sfColor){255, 140, 0, 255}
    #define YELLOW  (sfColor){255, 255, 0, 255}
    #define PURPLE  (sfColor){128, 0, 128, 255}
    #define RED     sfRed
    #define GREEN   sfGreen
    #define BLUE    sfBlue
    #define BLACK   sfBlack
    #define WHITE   sfWhite

    extern const Class *Text;

#endif /* !TEXT_H_ */