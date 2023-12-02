#include "raylib.h"

int main() {
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");
    //scaling for all images being added
    float imageScale{3.0f};

    // Getting my map texture 32x32
    Texture2D mapTexture = LoadTexture("tileset/map.png");
    // Starting vector of the map
    Vector2 mapPosition{0.0f,0.0f};

    //frames in player texture
    float maxFrames{4.0f};

    // Getting Player texture and location
    Texture2D playerTexture = LoadTexture("assets/Slime_Idle.png");
    // Player position is centre of view
    //screenwidth and height divided by two (get centre of screen)
    //the first image width and height divided by two and multiplied by scale
    Vector2 playerPosition {
        screenWidth/2.0f - ((playerTexture.width/maxFrames)*0.5f) * imageScale,
        screenHeight/2.0f - ((playerTexture.height/maxFrames)*0.5f) * imageScale
    };

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

        // Here goes all the Game Logic
        // Drawing map to scene | Map size is too small, going to scale it x 3
        DrawTextureEx(mapTexture,mapPosition,0.0f,imageScale,WHITE);

        // Drawing player to scene | All images to use imageScale
        DrawTextureEx(playerTexture,playerPosition,0.0f,imageScale,WHITE);


        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(mapTexture);
    CloseWindow();
    return 0;
}
