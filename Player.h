#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include <SDL.h>

class Player : public GameObject
{
public:
    Player();
    Player(int corX, int corY);
    ~Player();


    void move(float dx, float dy);


};

#endif