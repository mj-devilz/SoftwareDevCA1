#include "raylib.h"
#include "raymath.h"
#include "Player.h"
#include "Enemy.h"
#include <string>

bool gameStopped{false}; // adding global bool variable for pause

int main()
{
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");
    Font bloppyFont = LoadFontEx("assets/BlopyFont.ttf", 32, 0, 250); // importing font
    Font SolidOoky = LoadFontEx("assets/SolidOoky.ttf", 32, 0, 250);  // importing font
    InitAudioDevice();                                                // Initializing game to use audio
    Music backgroundMusic = LoadMusicStream("audio/Back_Track.mp3");  // added background music track
    SetMusicVolume(backgroundMusic, 0.3f);                            // Controlling the track volume from here
    PlayMusicStream(backgroundMusic);                                 // start playing the music straight away
    // scaling for all images being added
    Player player(screenWidth, screenHeight);
    float imageScale = player.getImageScale(); // get scale from class for consistency
    Enemy blob{Vector2{400.0f, 500.0f}, RED};
    // Getting my map texture 32x32
    Texture2D mapTexture = LoadTexture("tileset/map.png");
    // Starting vector of the map
    Vector2 mapPosition{0.0f, 0.0f};
    // Creating a enemy classes
    Enemy redBlob{Vector2{400.0f, 500.0f}, RED};
    Enemy yellowBlob{Vector2{800.0f, 500.0f}, YELLOW};
    Enemy blueBlob{Vector2{900.0f, 900.0f}, BLUE};
    Enemy brownBlob{Vector2{1200.0f, 500.0f}, BROWN};
    Enemy blackBlob{Vector2{3000.0f, 9000.0f}, BLACK};
    Enemy orangeBlob{Vector2{6000.0f, 4000.0f}, ORANGE};
    Enemy purpleBlob{Vector2{980.0f, 1000.0f}, PURPLE};
    Enemy darkGrayBlob{Vector2{400.0f, 1200.0f}, DARKGRAY};
    Enemy pinkBlob{Vector2{1200.0f, 500.0f}, PINK};
    Enemy maroonBlob{Vector2{400.0f, 1500.0f}, MAROON};
    Enemy darkBlueBlob{Vector2{1400.0f, 2500.0f}, DARKBLUE};
    Enemy beigeBlob{Vector2{2400.0f, 3500.0f}, BEIGE};
    Enemy goldBlob{Vector2{4400.0f, 2300.0f}, GOLD};

    // creating an array of enemy pointers
    Enemy *enemies[]{
        &redBlob, &yellowBlob, &blueBlob, &brownBlob, &blackBlob, &orangeBlob, &purpleBlob,
        &darkGrayBlob, &pinkBlob, &maroonBlob, &darkBlueBlob, &beigeBlob, &goldBlob

    };

    // need to set the pointer target for the enemies
    for (auto enemy : enemies)
    {
        enemy->setTarget(&player);
    }

    int gameTime{0}; // win condition set - timer
    float timer{};   // stores the increment value for the timer
    bool paused{};

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

        UpdateMusicStream(backgroundMusic); // calling this to keep music streaming
                                            //  bool to set true/false value to paused when KEY_P is pressed
        if (IsKeyPressed(KEY_P))
        {
            PauseMusicStream(backgroundMusic); // When use pauses game, we pause backgroundMusic
            paused = !paused;
            gameStopped = !gameStopped;
        }
        // added this to text for paused will remain
        if (paused)
        {
            DrawTextEx(bloppyFont, "Paused", (Vector2){screenHeight / 3, screenWidth / 3}, 70, 2, GREEN);
            // DrawText("Paused", screenHeight / 3, screenWidth / 3, 44, GREEN);
        }
        // If character is caught (isCaught = true), we stop rendering all items and show game over message
        if (player.getIsCaught())
        { // character is caught
            //------------Add Game Over screen------------//
            DrawTextEx(SolidOoky, "You were caught!!!", (Vector2){20.0f, 40.0f}, 50, 2, RED);
            // DrawText("You were caught!!!", screenHeight / 7, screenWidth / 2, 44, RED);
            std::string playerScore = "You scored: ";
            playerScore.append(std::to_string(gameTime), 0, 3);
            DrawTextEx(SolidOoky, playerScore.c_str(), (Vector2){20.0f, screenWidth / 1.5}, 65.0f, 2, GREEN);
            PauseMusicStream(backgroundMusic); // When use pauses game, we pause backgroundMusic
            gameStopped = true;
        }

        // if gameStopped returns true, we stop all functions until returns false
        if (!gameStopped)
        {
            ResumeMusicStream(backgroundMusic); // if the user unpauses game, we resume the background music
            // creating a timer to increment the gameTime value
            timer += GetFrameTime();
            if (timer >= 1.0f)
            {
                gameTime++;
                timer = 0.0f;
            }

            // Timer displayed on top right of screen
            std::string timerCount = "Timer: ";
            timerCount.append(std::to_string(gameTime), 0, 3);
            DrawText(timerCount.c_str(), screenWidth * 0.6f, 20.0f, 40.0f, BLUE);

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

            // spawning the array of enemies
            for (int i = 0; i < 13; i++)
            {

                enemies[i]->tick(GetFrameTime());
            }
        }
        // teardown Canvas
        EndDrawing();
    }
    UnloadFont(SolidOoky);              // unloading font
    UnloadFont(bloppyFont);             // unloading font
    UnloadTexture(mapTexture);          // unload maptexture
    UnloadMusicStream(backgroundMusic); // unload backgroundMusic
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
