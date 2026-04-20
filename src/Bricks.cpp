#include "Bricks.h"

Bricks::Bricks()
{
    pos = {0,0};
    size = {1,1};
    col = WHITE;
    is_active = true;
}

Bricks::Bricks(Vector2 brick_pos, Vector2 brick_dim, Color color)
{
    pos = brick_pos;
    size = brick_dim;
    col = color;
    is_active = true;
}

void Bricks::Draw(void)
{
    if(is_active)
    {
        DrawRectangle(pos.x,pos.y,size.x,size.y,col);
        DrawRectangleLines(pos.x,pos.y,size.x,size.y,BLACK);
    }
    
}

bool Bricks::BrickStatus()
{
    return is_active;
}

void Bricks::SetActive(bool status)
{
    is_active = status;
}
