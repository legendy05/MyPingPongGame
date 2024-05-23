#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Player.h"
#include "Globals.h"
#include <SDL.h>


class  Ball : public GameObject
{
public:
    Ball();
    ~Ball();

    void update();
    void collisionCheck(Player& player1, Player& player2);

    void resetBall();

private:
    Vector2 _speedVector;
    void collision(Player& player);
    float _ballSpeed;


};

#endif