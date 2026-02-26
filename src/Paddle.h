#pragma once

#include "raylib.h"

class Paddle{
    private:
    Vector2 pos;
    Vector2 size;
    Color col = BLUE;
    public:
    void SetPos(Vector2 pos);
    void SetSize(Vector2 size);
    inline Vector2 GetPos(void){ return pos;};
    inline Vector2 GetSize(void){ return size;};
    void Draw(void);
};
