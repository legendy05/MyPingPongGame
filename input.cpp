#include "Input.h"

Input::Input()
{}

Input::~Input()
{}

void Input::ButtonPressed(SDL_Keycode keycode)
{
    this->_keysPressed[keycode] = true;
}
void Input::ButtonReleased(SDL_Keycode keycode)
{
    this->_keysPressed[keycode] = false;
}

bool Input::IsKeyHeld(SDL_Keycode keycode)
{
    return this->_keysPressed[keycode];
}