#include "Player.h"
#include "Globals.h"
Player::Player()
{}

Player::Player(int corX, int corY) :GameObject(corX, corY)
{
    this->_rect.h = globals::PADDLE_HEIGHT;
    this->_rect.w = globals::PADDLE_WIDTH;
    this->_rect.x = corX;
    this->_rect.y = corY;
}

Player::~Player()
{}

void Player::move(float dx, float dy)
{
    // Player on the upper edge of the screen
    if ((this->_y + this->_dy + dy) < 0)
    {
        this->_y = 0;
        this->_dy = 0;
    }
    // Player on the bottom edge of the screen
    else if ((this->_y + this->_dy + dy) > globals::SCREEN_HEIGHT - globals::PADDLE_HEIGHT)
    {
        this->_y = globals::SCREEN_HEIGHT - globals::PADDLE_HEIGHT;
        this->_dy = 0;
    }
    //Player somewhere in between
    else GameObject::move(dx, dy);
}
