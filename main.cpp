#include "raylib.h"

int main() {
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");

    // Getting my map texture 32x32
    Texture2D map = LoadTexture("tileset/map.png");
    // Starting vector of the map
    Vector2 mapPosition{0.0f,0.0f};

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

        // Here goes all the Game Logic
        //Drawing map to scene 
        DrawTexture(map,mapPosition.x,mapPosition.y,WHITE);




        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
