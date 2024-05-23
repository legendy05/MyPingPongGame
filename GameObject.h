#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>
class GameObject
{
public:
    GameObject();
    ~GameObject();
    GameObject(int corX, int corY);

    int getX() { return this->_x; };
    int getY() { return this->_y; };
    int getH() { return this->_rect.h; };
    int getW() { return this->_rect.w; };

    // Fills rect of current object on the renderer.
    void draw(SDL_Renderer* renderer);

    // Increment _x and _y by _dx and _dy
    // after that _dx = _dy = 0
    void update();

    // Increment _dx and _dy
    void move(float dx, float dy);

protected:
    float _x, _y;
    float _dx, _dy;

    SDL_Rect _rect;
};

#endif