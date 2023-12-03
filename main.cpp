#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Enemy.h"

int main()
{
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");
    // scaling for all images being added
    Player player(screenWidth, screenHeight);
    float imageScale = player.getImageScale(); // get scale from class for consistency

    // Getting my map texture 32x32
    Texture2D mapTexture = LoadTexture("tileset/map.png");
    // Starting vector of the map
    Vector2 mapPosition{0.0f, 0.0f};

    Enemy redBlob{Vector2{}};
    redBlob.setTarget(&player); // target is the address of the player

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
        // runs all the functions needed for drawing player / movement /animating player
        player.tick(GetFrameTime());
        // check to see if player goes out of bounds i.e. worldPosition moves off map. (take scaling into account)
        if (player.getWorldPosition().x < 0.0f ||
            player.getWorldPosition().y < 0.0f ||
            player.getWorldPosition().x + screenWidth > mapTexture.width * imageScale ||
            player.getWorldPosition().y + screenHeight > mapTexture.height * imageScale)
        {
            // this will return player to previous position if they try to go out of bounds.
            player.undoMovement();
        }

        redBlob.tick(GetFrameTime());

        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(mapTexture);
    CloseWindow();
    return 0;
}
