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
   //Hazard Sprite variables
   Texture2D hazardSprite = LoadTexture("/Volumes/ESD-USB/Dapper_Dasher_Project/textures/12_nebula_spritesheet.png");
   Rectangle hazardRect{0.0f, 0.0f, hazardSprite.width/8, hazardSprite.height };
   Vector2 hazardPos{windowWidth, windowHeight - hazardRect.height};
   //Scarfy Sprite variables
   Texture2D sprite = LoadTexture("/Volumes/ESD-USB/Dapper_Dasher_Project/textures/scarfy.png");
   Rectangle spriteRect{0.0f,0.0f,sprite.width/6,sprite.height};
   Vector2 spritePos{windowWidth/2 - spriteRect.width/2, windowHeight - spriteRect.height};
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
        if(spritePos.y >= windowHeight - spriteRect.height)
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
        //Jump input
        if(IsKeyPressed(KEY_SPACE)&& !isJumping)
        {
            isJumping = true;
            velocity += jumpHeight;
        }
        //Update position
        spritePos.y += velocity * deltaTime;
        //Update animation frame
        runningTime += deltaTime;
        if(runningTime >= updateTime)
        {
            runningTime = 0.0;
            spriteRect.x = frame * spriteRect.width;
            frame++;
        }
        if(frame > 5)
            frame = 0;
        DrawTextureRec(sprite, spriteRect, spritePos, WHITE);
        EndDrawing();
    }
    UnloadTexture(sprite);
    UnloadTexture(hazardSprite);
    CloseWindow();
}