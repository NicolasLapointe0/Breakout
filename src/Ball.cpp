#include "Ball.h"

    void Ball::SetPos(Vector2 pos){
        this->pos.x = pos.x;
        this->pos.y = pos.y;
    }
    void Ball::SetSize(Vector2 size){
        this->size.x = size.x;
        this->size.y = size.y;
    }
    void Ball::Draw(void){
        DrawRectangle(pos.x,pos.y,size.x,size.y,col);
    }