#include "entrypoint.h"
#include "Paddle.h"
#include "Ball.h"
#include "Bricks.h"

#define W 800
#define H 600

struct Circle{
    Vector2 pos;
    float radius;
};

const Vector2 player_dim = {100,25};
const Vector2 ball_dim = {10,10};
const float ball_radius = 10.0f;
const int columns = 14;
const int rows = 8;
const int bricks = columns * rows;
bool start = false;
bool invincible = false;
bool minus_y = false;
bool minus_x = false;

void raylib_start(void)
{

    Paddle player;
    player.SetPos(CLITERAL(Vector2){W * 0.5f - player_dim.x *0.5f,H - player_dim.y * 2});
    player.SetSize(player_dim);
   

    Ball ball;
    ball.SetPos(CLITERAL(Vector2){W * 0.5f - ball_dim.x * 0.5f, H - ball_dim.y * 10});
    ball.SetSize(ball_radius); 
    ball.speed_x = 150.0f;
    ball.speed_y = 150.0f;
    const float default_ball_speed = ball.speed_x;
    float ball_target_speed = 250.0f;
    bool target_speed_reach = false;

    Bricks brick[bricks];
    float widht = 57.0f;
    float height = 25.0f;

    for(int row = 0; row < rows; row++)
    {
        for(int column = 0; column < columns; column++)
        {
            int current_brick = row * columns + column;
            Vector2 brick_pos = {column * widht, row * height};
            Vector2 brick_size = {widht,height};
            Color brick_color;

            if(column %2 == 0)
            {
                brick_color = RED;
            }
            else
            {
                brick_color = BLUE;
            }

            brick[current_brick] = Bricks(brick_pos,brick_size, brick_color);
        }
    }
    

    InitWindow(W,H,"Breakout");
    SetTargetFPS(60);


    while(!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);

        for(int Brick = 0; Brick < bricks; Brick++)
        {
            brick[Brick].Draw();
        }

        Rectangle left_screen_hitbox = {0,0,1,H};
        Rectangle top_screen_hitbox = {0,0,W,1};
        Rectangle right_screen_hitbox = {W-1,0,1,H};
        Rectangle bottom_screen_hitbox = {0,H-1,W,1};

        ball.Draw();
        Circle ball_hitbox = {ball.GetPos().x,ball.GetPos().y,ball.GetSize().x};

        player.Draw();
        Rectangle player_hitbox = {player.GetPos().x,player.GetPos().y,player.GetSize().x,player.GetSize().y};

        DrawRectangleLinesEx(left_screen_hitbox,1,BLACK);
        DrawRectangleLinesEx(top_screen_hitbox,1,BLACK);
        DrawRectangleLinesEx(right_screen_hitbox,1,BLACK);
        DrawRectangleLinesEx(bottom_screen_hitbox,1,BLACK);
        DrawRectangleLinesEx(player_hitbox,1,BLUE);
        DrawCircleLinesV(ball_hitbox.pos,ball_hitbox.radius,WHITE);

        if(IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D))
        {
            start = true;
        }
        
        if(start){

            ball.Movement(ball_dim, ball.speed_x, ball.speed_y);
            player.Movement(player_dim);
            DrawText(TextFormat("%f",ball.speed_x),2,0,5,WHITE);
            DrawText(TextFormat("%f",ball.speed_y),2,10,5,WHITE);

            for(int i = 0; i < bricks; i++)
            {
                if(brick[i].BrickStatus())
                {
                    Rectangle brick_hitbox = {brick[i].GetPos().x,brick[i].GetPos().y,brick[i].GetSize().x,brick[i].GetSize().y};

                    if(CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,brick_hitbox))
                    {
                        if(!invincible)
                        {            
                            brick[i].SetActive(false);
                            ball.speed_y *= -1;
                            minus_y = true;

                        }

                        invincible = true;
                        break;
                    }
                }
            }

            if(CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,player_hitbox) || CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,top_screen_hitbox) || CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,bottom_screen_hitbox))
            {
                if(!invincible)
                {            
                    
                    ball.speed_y *= -1;
                    minus_y = true;

                }

                invincible = true;
                
            }

            if(CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,right_screen_hitbox) || CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,left_screen_hitbox))
            {
                if(!invincible)
                {
                    
                    ball.speed_x *= -1;
                    minus_x = true;
                    
                }

                invincible = true;

            }

            if(!CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,player_hitbox) && !CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,left_screen_hitbox) && !CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,top_screen_hitbox) && !CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,right_screen_hitbox) && !CheckCollisionCircleRec(ball_hitbox.pos,ball_hitbox.radius,bottom_screen_hitbox))
            {

                invincible = false;

                if(minus_y)
                {
                    if(!target_speed_reach)
                    {
                        if(ball.speed_y > 0)
                        {
                            ball.speed_y += 5;

                            if(ball.speed_y >= ball_target_speed)
                            {
                                target_speed_reach = true;
                            }
                        }
                        else
                        {
                            ball.speed_y -= 5;

                            if(ball.speed_y <= -ball_target_speed)
                            {
                                target_speed_reach = true;
                            }
                        }
                        
                    }
                    else
                    {
                        if(ball.speed_y > 0)
                        {
                            ball.speed_y -= 5;

                            if(ball.speed_y <= default_ball_speed)
                            {
                                ball.speed_y = default_ball_speed;
                                minus_y = false;
                                target_speed_reach = false;
                            }
                        }
                        else
                        {
                            ball.speed_y += 5;

                            if(ball.speed_y >= -default_ball_speed)
                            {
                                ball.speed_y = -default_ball_speed;
                                minus_y = false;
                                target_speed_reach = false;
                            }
                        }
                        
                    }
                }

                if(minus_x)
                {
                    if(!target_speed_reach)
                    {
                        if(ball.speed_x > 0)
                        {
                            ball.speed_x += 5;

                            if(ball.speed_x >= ball_target_speed)
                            {
                                target_speed_reach = true;
                            }
                        }
                        else
                        {
                            ball.speed_x -= 5;

                            if(ball.speed_x <= -ball_target_speed)
                            {
                                target_speed_reach = true;
                            }
                        }
                        
                    }
                    else
                    {
                        if(ball.speed_x > 0)
                        {
                            ball.speed_x -= 5;

                            if(ball.speed_x >= default_ball_speed)
                            {
                                ball.speed_x = default_ball_speed;
                                minus_x = false;
                                target_speed_reach = false;
                            }
                        }
                        else
                        {
                            ball.speed_x += 5;

                            if(ball.speed_x >= -default_ball_speed)
                            {
                                ball.speed_x = -default_ball_speed;
                                minus_x = false;
                                target_speed_reach = false;
                            }
                        }
                        
                    }
 
                }

            }
            
            
            
            
        }
        
        EndDrawing();
    }
    
    CloseWindow();
}