#include "GameObject.h"

#include "Globals.h"
GameObject::GameObject()
{
}

GameObject::GameObject(int corX, int corY)
{
    this->_x = corX;
    this->_y = corY;
    this->_dx = 0;
    this->_dy = 0;
}


GameObject::~GameObject()
{
}


void GameObject::draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 225, 255, 255, 255);
    SDL_RenderFillRect(renderer, &this->_rect);
}

void GameObject::update()
{

    this->_x += this->_dx;
    this->_dx = 0;
    this->_rect.x = this->_x;

    this->_y += this->_dy;
    this->_dy = 0;
    this->_rect.y = this->_y;
}

void GameObject::move(float dx, float dy)
{
    this->_dx += dx;
    this->_dy += dy;
}
