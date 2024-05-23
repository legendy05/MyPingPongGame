#ifndef SCORE_H
#define SCORE_H

#include <SDL.h>
#include<SDL_ttf.h>
class Score
{
public:
    Score();
    Score(int x, int y);
    ~Score();

    void increment() { this->_score=_score+1; }


    int getScore() { return _score; }

    void draw(SDL_Renderer* renderer);
    int _score;

private:
    SDL_Texture* _texture;
    TTF_Font* _font;

    int _x, _y;


};

#endif
