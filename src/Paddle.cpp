#include "Paddle.h"

void Paddle::Movement(Vector2 pos)
{
    float dt = GetFrameTime();
    float speed = 300.0f;
    if(IsKeyDown(KEY_A))
    {
        this->pos.x -= speed * dt;
    }

    if(IsKeyDown(KEY_D))
    {
        this->pos.x += speed * dt;
    }
}

void Paddle::SetPos(Vector2 pos)
{
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

void Paddle::SetSize(Vector2 size){
    this->size.x = size.x;
    this->size.y = size.y;
}

void Paddle::Draw(void){
    col = BLUE;
    DrawRectangle(pos.x,pos.y,size.x,size.y,col);
}