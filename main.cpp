#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Enemy.h"
#include <string>

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

        //If character is dead (isAlive = false), we stop rendering all items and show game over message
        if(!player.getIsAlive()){ //character not alive
            //------------Add Game Over screen------------//
            DrawText("You died!!!",screenHeight/3,screenWidth/3,44,RED);
            EndDrawing();
            continue; // skips to next iteration of while loop.
        } else { // character alive
            std::string playersHealth = "Health: ";
            playersHealth.append(std::to_string(player.getHealth()), 0, 3);
            DrawText(playersHealth.c_str(),55.0f,40.0f,34.0f,RED);
            
        }
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
            
            ///added to test character death (keep commented out)
            // if(IsKeyDown(KEY_R)){
            //     player.setIsAlive(false);
            // }
        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(mapTexture);
    CloseWindow();
    return 0;
}
