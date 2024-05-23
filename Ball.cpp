#include "Ball.h"

#include "Globals.h"
#include <cmath>
#include <random>
#include <ctime>

Ball::Ball()
{
    this->resetBall();
}


Ball::~Ball()
{
    this->_x = 0;
    this->_y = 0;
    this->_dx = 0;
    this->_dy = 0;
    this->_ballSpeed = 0;
    this->_speedVector = Vector2();
    this->_rect = { 0,0 };

}

void Ball::resetBall()
{
    this->_rect = { globals::SCREEN_WIDTH / 2 - globals::BALL_SIZE / 2, globals::SCREEN_HEIGHT / 2 - globals::BALL_SIZE / 2, globals::BALL_SIZE, globals::BALL_SIZE };
    this->_x = globals::SCREEN_WIDTH / 2 - globals::BALL_SIZE / 2;
    this->_y = globals::SCREEN_HEIGHT / 2 - globals::BALL_SIZE / 2;
    this->_ballSpeed = globals::BALL_SPEED;

    // generate random degree for ball
    std::srand(std::time(0));
    int randDegree = rand() % 70 + 1;

    // (-1)^n  gives random sign
    this->_speedVector.x = std::pow(-1, rand()) *this->_ballSpeed * std::cos(randDegree * 3.14159 / 180.0);
    this->_speedVector.y = std::pow(-1, rand()) *this->_ballSpeed * std::sin(randDegree * 3.14159 / 180.0);
}


void Ball::update()
{
    this->move(this->_speedVector.x, this->_speedVector.y);
    GameObject::update();

}

void Ball::collisionCheck(Player& player1, Player& player2)
{

    // Check collision with first player
    if (this->_x + this->getW() >= player1.getX() && this->_x <= player1.getX() + player1.getW())
    {
        if (this->_y + this->getW() >= player1.getY() && this->_y <= player1.getY() + player1.getH())
        {


            if (this->_x + this->getW() < player1.getX() + player1.getW())
            {
                // vertical collision --> the ball contact with midpoint of the paddle
                this->_speedVector.y = -this->_speedVector.y;
            }
            else
            {
                this->move(player1.getX() + player1.getW() - this->_x, 0);
                collision(player1);
            }
        }
    }

    // Check collision with second player
    if (this->_x + this->getW() >= player2.getX() && this->_x <= player2.getX() + player2.getW())
    {
        if (this->_y + this->getH() >= player2.getY() && this->_y <= player2.getY() + player2.getH())
        {

            if (this->_x > player2.getX())
            {
                // vertical collision
                this->_speedVector.y = -this->_speedVector.y;
            }
            else
            {
                this->move(-(this->_x + this->getW() - player2.getX()), 0);
                collision(player2);
            }

        }
    }

    // Check collision with screen
    if (this->_y < 0 || this->_y + globals::BALL_SIZE > globals::SCREEN_HEIGHT)
    {
        this->_speedVector.y = -this->_speedVector.y;
    }
}

void Ball::collision(Player& player)
{
    this->_ballSpeed *= globals::BALL_ACCELERATION; //ball contact with paddle will increase its speed
    // degree = [0->1]
    float degree = (this->_y - (player.getY() - globals::BALL_SIZE)) / (player.getH() + globals::BALL_SIZE);
    if (degree <= 0.1)
        degree = 0.1;
    if (degree >= 0.9)
        degree = 0.9;
    degree = degree * 3.14159;
    if (std::signbit(this->_speedVector.x))
    {
    //* if (_speedVector.x < 0) *//
        this->_speedVector.x = this->_ballSpeed * sin(degree);
        this->_speedVector.y = -this->_ballSpeed * cos(degree);
    }
    else
    {
        this->_speedVector.x = -this->_ballSpeed * sin(degree);
        this->_speedVector.y = -this->_ballSpeed * cos(degree);
    }

}
