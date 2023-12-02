#include "raylib.h"
#include "raymath.h"
#include "Player.h"

int main()
{
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");
    // scaling for all images being added
    Player player;
    float imageScale = player.getImageScale();// get scale from class for consistency
    player.setScreenPosition(screenWidth,screenHeight);

    // Getting my map texture 32x32
    Texture2D mapTexture = LoadTexture("tileset/map.png");
    // Starting vector of the map
    Vector2 mapPosition{0.0f, 0.0f};

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/)
    {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

        // Here goes all the Game Logic
        // Need to update the map position based on the characters world position
        // Moving the Map, we need need to move map position based on the - value of the World Position
        mapPosition = Vector2Scale(player.getWorldPosition(), -1.0f);
        // Drawing map to scene | Map size scale it x 3
        DrawTextureEx(mapTexture, mapPosition, 0.0f, imageScale, WHITE);

        player.tick(GetFrameTime());

        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(mapTexture);
    CloseWindow();
    return 0;
}
