#include "raylib.h"

int main()
{
   //Window Dimensions
   const int windowWidth = 512;
   const int windowHeight = 350;
   InitWindow(windowWidth, windowHeight, "Dapper Dasher");
   //acceleration from gravity(pixels per frame)
   const int gravity = 1;
   const int jumpHeight = -22;
   bool isGrounded = true;
   bool isJumping = false;
   //Sprite variables
   Texture2D scarfy = LoadTexture("/Volumes/ESD-USB/Dapper_Dasher_Project/textures/scarfy.png");
   Rectangle scarfyRect;
   scarfyRect.width = scarfy.width/6;
   scarfyRect.height = scarfy.height;
   scarfyRect.x = 0;
   scarfyRect.y = 0;
   Vector2 scarfyPos;
   scarfyPos.x = windowWidth/2 - scarfyRect.width/2;
   scarfyPos.y = windowHeight - scarfyRect.height;
   int velocity = 0;
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        //Ground check
        if(scarfyPos.y >= windowHeight - scarfyRect.height)
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
            velocity += jumpHeight;
        }
        //Update position
        
        scarfyPos.y += velocity;
        
        DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);
       
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}