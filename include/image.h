/*
** Description:
** Game Images' structure
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/Radar
**
*/

#ifndef IMAGE_H_
    #define IMAGE_H_

    #include <SFML/Graphics.h>

    typedef struct s_image {
        char *source;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f position;
    } t_image;

    t_image *createImage(char const *path, sfVector2f position);
    void destroyImage(t_image *image);
    void drawImage(sfRenderWindow* window, t_image *image);
    void setPos(t_image *image, sfVector2f position);

#endif /* !IMAGE_H_ */