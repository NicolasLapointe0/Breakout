#include "Paddle.h"

    void Paddle::SetPos(Vector2 pos){
        this->pos.x = pos.x;
        this->pos.y = pos.y;
    }
    void Paddle::SetSize(Vector2 size){
        this->size.x = size.x;
        this->size.y = size.y;
    }
    void Paddle::Draw(void){
        DrawRectangle(pos.x,pos.y,size.x,size.y,col);
    }