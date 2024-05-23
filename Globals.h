#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals
{
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    const int PADDLE_WIDTH = 10;
    const int PADDLE_HEIGHT = 80;
    const float PADDLE_SPEED = 0.4;

    const int BALL_SIZE = 20;
    const float BALL_SPEED = 0.35;
    const float BALL_ACCELERATION = 1.07; //everytime contact with paddle

    const float PLAYER_GAP_PERCENT =0.03; //compared with left and right window margin
}

class Vector2 //speed vector of the ball
{
    public:
    float x, y;
    Vector2()
    {
        this->x = 0;
        this->y = 0;
    }
};

#endif
