#pragma once

#include "raylib.h"


class Bricks {
 private:
    Vector2 pos;
    Vector2 size;
    Color col;
    bool is_active;
    public: 
    Bricks();
    Bricks(Vector2 brick_pos, Vector2 brick_dim, Color color);
    inline Vector2 GetPos(void){ return pos;};
    inline Vector2 GetSize(void){ return size;};
    void Draw(void);
    bool BrickStatus();
    void SetActive(bool status);
};