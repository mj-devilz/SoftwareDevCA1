#include "raylib.h"
#include "raymath.h"

int main()
{
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");
    // scaling for all images being added
    float imageScale{3.0f};

    // Getting my map texture 32x32
    Texture2D mapTexture = LoadTexture("tileset/map.png");
    // Starting vector of the map
    Vector2 mapPosition{0.0f, 0.0f};

    // frames in player texture
    float imageFrame{4.0f};

    // Getting Player texture and location
    Texture2D playerTexture = LoadTexture("assets/Slime_Idle.png");
    // Player position is centre of view
    // screenwidth and height divided by two (get centre of screen)
    // half the first image =  width and height divided by two and multiplied by scale
    Vector2 playerPosition{
        (float)screenWidth / 2.0f - (((float)playerTexture.width / imageFrame) * 0.5f) * imageScale,
        (float)screenHeight / 2.0f - (((float)playerTexture.height / imageFrame) * 0.5f) * imageScale};

    float movementSpeed{3.0f};

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
        // Drawing map to scene | Map size scale it x 3
        DrawTextureEx(mapTexture, mapPosition, 0.0f, imageScale, WHITE);

        // update animation frame

        // Drawing player to scene | All images to use imageScale
        // Texture Pro allows character scale and add rectangle from sprite sheet
        Rectangle source{0.f, 0.f, (float)playerTexture.width / imageFrame, (float)playerTexture.height / imageFrame};
        Rectangle dest{playerPosition.x, playerPosition.y,
                       ((float)playerTexture.width / imageFrame) * imageScale,
                       ((float)playerTexture.height / imageFrame) * imageScale};
        DrawTexturePro(playerTexture, source, dest, Vector2{},0.0f, WHITE);

        // Adding Movement - moving the map / works with WASD and Arrows
        Vector2 moveDirection{};
        
        if(IsKeyDown(KEY_W)||IsKeyDown(KEY_UP)) moveDirection.y -= 1.0f;
        if(IsKeyDown(KEY_S)||IsKeyDown(KEY_DOWN)) moveDirection.y += 1.0f;
        if(IsKeyDown(KEY_A)||IsKeyDown(KEY_LEFT)) moveDirection.x -= 1.0f;
        if(IsKeyDown(KEY_D)||IsKeyDown(KEY_RIGHT)) moveDirection.x += 1.0f;
        
        // vector2length used to see if there is movement
        if(Vector2Length(moveDirection) != 0.0){
            // normalized use to make sure diagonal speed is normalized
            // moving the map position based on our movedirection
            // vector2scale allowing us to add a speed factor to our normalized direction
            mapPosition = Vector2Subtract(mapPosition,Vector2Scale(Vector2Normalize(moveDirection),movementSpeed));
        }

        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(mapTexture);
    CloseWindow();
    return 0;
}
