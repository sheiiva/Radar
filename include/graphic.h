/*
** Description:
** GRAPHIC Structures
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef GRAPHIC_H_
    #define GRAPHIC_H_

    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #define TIMEREFRESH 0.1
    #include <stdio.h>      
    enum _GAMESTATE {
        QUIT=       -1,
        GAMESCENE=  0,
    };

    typedef struct s_window {
        sfVideoMode mode;
        sfRenderWindow* window;
    } t_window;

    typedef struct s_graphic {
        t_window *window;
        sfClock *clock;
        sfEvent event;
        int state;
    } t_graphic;

    void        destroygraphics(t_graphic *graphics);
    t_graphic*  initgraphics();

    sfRenderWindow* createWindow(sfVideoMode mode);
    void            destroyWindow(t_window *window);
    t_window*      initWindow();

#endif /* !GRAPHIC_H_ */