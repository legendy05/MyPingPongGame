#ifndef INPUT_H
#define INPUT_H
#include <map>
#include <string>
#include <SDL.h>
class Input
{
public:
    Input();
    ~Input();

    bool IsKeyHeld(SDL_Keycode keycode);

    // Fills map of pressed keys
    void ButtonPressed(SDL_Keycode);

    // Clears map of pressed keys
    void ButtonReleased(SDL_Keycode);
private:
    std::map <SDL_Keycode, bool> _keysPressed;

};

#endif