#include "raylib.h"

int main()
{
   //Window Dimensions
   const int windowWidth = 800;
   const int windowHeight = 600;
   InitWindow(windowWidth, windowHeight, "Dapper Dasher");
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
        posY += velocity;
        DrawRectangle(windowWidth/2, posY, rectWidth, rectHeight, RED);
        if(IsKeyPressed(KEY_SPACE))
        {
            velocity -= 10;
        }
        EndDrawing();
    }
    CloseWindow();
}