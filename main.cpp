#include "raylib.h"

int main()
{
   //Window Dimensions
   const int windowWidth = 800;
   const int windowHeight = 600;
   InitWindow(windowWidth, windowHeight, "Dapper Dasher");
   //acceleration from gravity(pixels per frame)
   const int gravity = 1;
   bool isGrounded = true;
   bool isJumping = false;
   //rectangle dimensions
   const int rectWidth = 80;
   const int rectHeight = 50;
   int posY = windowHeight - rectHeight;
   int velocity = 0;
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        //Ground check
        if(posY >= windowHeight - rectHeight)
        {
            isGrounded = true;
            isJumping = false;
            velocity = 0;
        }
        else
        {
            isGrounded = false;
            velocity += gravity;
        }  
        
        if(IsKeyPressed(KEY_SPACE)&& !isJumping)
        {
            isJumping = true;
            velocity -= 10;
        }
        //Update position
        
        posY += velocity;
        
        DrawRectangle(windowWidth/2, posY, rectWidth, rectHeight, RED);
       
        EndDrawing();
    }
    CloseWindow();
}