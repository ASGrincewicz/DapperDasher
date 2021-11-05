#include "raylib.h"

int main()
{
   //Window Dimensions
   const int windowWidth = 512;
   const int windowHeight = 350;
   InitWindow(windowWidth, windowHeight, "Dapper Dasher");
   //acceleration from gravity(pixels per second/per second)
   const int gravity = 1200;
   const int jumpHeight = -600;
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
   // Animation
   int frame = 0;
   const float updateTime = 1.0/12.0;
   float runningTime = 0;
   int velocity = 0;
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        const float deltaTime = GetFrameTime();
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
            velocity += gravity * deltaTime;
        }  
        
        if(IsKeyPressed(KEY_SPACE)&& !isJumping)
        {
            isJumping = true;
            velocity += jumpHeight;
        }
        //Update position
        scarfyPos.y += velocity * deltaTime;
        //Update animation frame
        runningTime += deltaTime;
        if(runningTime >= updateTime)
        {
            runningTime = 0.0;
            scarfyRect.x = frame * scarfyRect.width;
            frame++;
        }
       
        if(frame > 5)
            frame = 0;
        DrawTextureRec(scarfy, scarfyRect, scarfyPos, WHITE);
       
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}