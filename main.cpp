#include "raylib.h"

int main()
{
   //Window Dimensions
   int windowWidth = 800;
   int windowHeight = 600;
   InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    while(WindowShouldClose()== false)
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

}