#include "raylib.h"

int main() {
    // Changed window width and height to give a nice square view
    const int screenWidth = 500;
    const int screenHeight = 500;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Blobbo");
    // Setting the Frames Per Second
    SetTargetFPS(60);

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);

        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
