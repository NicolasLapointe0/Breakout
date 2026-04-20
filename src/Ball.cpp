#include "Ball.h"

void Ball::Movement(Vector2 pos, float speed_x, float speed_y)
{
    float dt = GetFrameTime();
    this->pos.y += speed_y * dt;
    this->pos.x += speed_x * dt;

}

void Ball::SetPos(Vector2 pos)
{
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

void Ball::SetSize(float radius){
    this->size.x = radius;
    
}
void Ball::Draw(void){
    col = WHITE;
    DrawCircle(pos.x,pos.y,size.x,col);
}