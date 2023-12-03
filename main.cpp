#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Enemy.h"
#include <string>

bool paused{false}; //adding global bool variable for pause

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
    // Creating a new enemy class
    Enemy redBlob{Vector2{},RED};
    redBlob.setTarget(&player); // target is the address of the player

    int gameTime{60}; // win condition set - timer 
    float timer{}; // stores the increment value for the timer

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/)
    {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
        // bool to set true/false value to paused when KEY_P is pressed
        if(IsKeyPressed(KEY_P)){
            paused = !paused;
        }

        // Here goes all the Game Logic
        // Need to update the map position based on the characters world position
        // Moving the Map, we need need to move map position based on the - value of the World Position
        mapPosition = Vector2Scale(player.getWorldPosition(), -1.0f);
        // Drawing map to scene | Map size scale it x 3
        DrawTextureEx(mapTexture, mapPosition, 0.0f, imageScale, WHITE);

        //if paused returns true, we stop all functions until returns false
        if(!paused){
            //creating a timer to decrement the gameTime value
            timer+=GetFrameTime();
            if(timer>=1.0f){
                gameTime--;
                timer = 0.0f;
            }
            //winning condition is to survive until timer is up once won, we stop the game.
            if(gameTime<=0){
                DrawText("You win!!!",screenHeight/3,screenWidth/3,44,GREEN);
                EndDrawing();
                continue; // skips to next iteration of while loop.
            }
            //If character is caught (isCaught = true), we stop rendering all items and show game over message
            if(player.getIsCaught()){ //character is caught
                //------------Add Game Over screen------------//
                DrawText("You were caught!!!",screenHeight/3,screenWidth/3,44,RED);
                EndDrawing();
                continue; // skips to next iteration of while loop.
            } else { // character alive
                std::string playersHealth = "Timer: ";
                playersHealth.append(std::to_string(gameTime), 0, 3);
                DrawText(playersHealth.c_str(),screenWidth*0.6f,20.0f,40.0f,RED);
                
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
          } else {
            DrawText("Paused",screenHeight/3,screenWidth/3,44,GREEN);
          }

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
