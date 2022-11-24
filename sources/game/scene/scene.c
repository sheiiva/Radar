/*
** Description:
** Scene's Interface class definition
**
** Corentin COUTRET-ROZET
** https://github.com/sheiiva/DuckHunt
**
*/

#include "new.h"
#include "array.h"

#include "scene.h"

static void Scene_draw(SceneClass *this, WindowClass* window)
{
    for (size_t i = 0; i < len(this->_images); i++)
        drawImage(getitem(this->_images, i), window->_window);
    for (size_t i = 0; i < len(this->_texts); i++)
        drawText(getitem(this->_texts, i), window->_window);
}

static void Scene_process(__UNUSED__ SceneClass *this, __UNUSED__ SystemClass *system){}

static void Scene_ctor(SceneClass *this, __UNUSED__ va_list *args)
{
    /* Create images Array */
    this->_images = new(Array, IMAGENUMBER, Image,
        BACKGROUND_PATH, (sfVector2f){0, 0}, NULL
    );
    /* Create texts Array */
    this->_texts = new(Array, TEXTNUMBER, Text);

    printf("Scene()\n");
}

static void Scene_dtor(SceneClass *this)
{
    // Release internal resources
    delete(this->_images);
    delete(this->_texts);

    printf("~Scene()\n");
}

static const SceneClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(SceneClass),
        .__name__ = "Scene",
        .__ctor__ = (ctor_t)&Scene_ctor,
        .__dtor__ = (dtor_t)&Scene_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    ._images = NULL,
    ._texts = NULL,
    /* Methods definitions */
    .__draw__ = &Scene_draw,
    .__process__ = &Scene_process
};

const Class *Scene = (const Class *)&_description;