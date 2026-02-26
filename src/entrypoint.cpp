#include "entrypoint.h"
#include "Paddle.h"

#define W 800
#define H 600
const Vector2 player_dim = {100,25};
void raylib_start(void){
    Paddle player;
    player.SetPos(CLITERAL(Vector2){W * 0.5f - player_dim.x *0.5f,H - player_dim.y * 2});
    player.SetSize(player_dim);

    InitWindow(W,H,"Breakout");
    SetTargetFPS(60);


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        player.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}