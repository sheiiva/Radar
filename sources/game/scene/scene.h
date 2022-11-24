/*
** Description:
** Scene structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#ifndef SCENE_H_
    #define SCENE_H_

    #include "object.h"

    #include "window.h"
    #include "image.h"
    #include "text.h"

    typedef struct s_SystemClass SystemClass;

    typedef struct s_SceneClass {

        /* Inheritance */
        Class base;

        /* Special Definition*/
        Object*     _images;
        Object*     _texts;

        // EventManagerClass* eventManager;

        /* Methods definitions */
        void    (*__draw__)(struct s_SceneClass*, WindowClass*);
        void    (*__process__)(struct s_SceneClass*, SystemClass*);
    } SceneClass;

    extern const Class *Scene;

    #define drawScene(s, w)      ((SceneClass*)s)->__draw__(s, w)
    #define processScene(s, sys)    ((SceneClass*)s)->__process__(s, sys)

    /* IMAGES */
    #define IMAGENUMBER     1

    #define BACKGROUND          0
    #define BACKGROUND_PATH     "assets/images/background.png"

    /* TEXTS */
    #define TEXTNUMBER      0

    #define FONT_PATH "JosefinSans-Italic-VariableFont_wght.ttf"

#endif /* !SCENE_H_ */