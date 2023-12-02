#include "Player.h"
#include "raymath.h"
// Source file to define class constructor and functions
Player::Player(int screenWidth, int screenHeight)
{
    width = texture.width / imageFrame; // get the width of a texture frame
    height = texture.height;            // get the width of a texture frame
    // screenPosition = Relation of the upper left corner of texture to the upper left corner of the screen
    screenPosition = {
        (float)screenWidth / 2.0f - (width * 0.5f) * imageScale,
        (float)screenHeight / 2.0f - (height * 0.5f) * imageScale};
}

// Called every frame receives deltaTime, allows all variables to be updated every frame
// movement and animation added to here
void Player::tick(float deltaTime)
{
    // storing the last worldPosition before next is set (important for stopping out of bounds)
    worldPositionLastFrame = worldPosition;
    // Adding Movement - moving the map / works with WASD and Arrows
    Vector2 moveDirection{};

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        moveDirection.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        moveDirection.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        moveDirection.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        moveDirection.x += 1.0f;

    // vector2length used to see if there is movement
    if (Vector2Length(moveDirection) != 0.0)
    {
        // normalized use to make sure diagonal speed is normalized
        // moving the map position based on our movedirection
        // vector2scale allowing us to add a speed factor to our normalized direction
        // changing characters position - so changed to Add
        worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(moveDirection), movementSpeed));
        //----ADD CHANGE IN DIRECTION OF IMAGE BASED ON DIRECTION----//
        if (moveDirection.x < 0)
        {
            // Add Left Texture
            texture = movementLeft;
        }
        else if (moveDirection.x > 0)
        {
            // Add Right Texture
            texture = movementRight;
        }
        else if (moveDirection.x == 0 && moveDirection.y < 0)
        {
            // Add Up Texture
            texture = movementUp;
        }
        else if (moveDirection.x == 0 && moveDirection.y > 0)
        {
            // Add Down Texture
            texture = movementDown;
        }
    }
    else
    {
        // if direction = 0, then idle animation plays
        texture = idle;
    }

    // Updating animation frame
    runningTime += deltaTime; // deltatime will GetFrameTime() on main class
    if (runningTime >= updateTime)
    {
        animationFrame++;   // increment frame
        runningTime = 0.0f; // reset running time
        if (animationFrame > maxAnimationFrames)
            animationFrame = 0; // reset frame when it reaches ends
    }

    // Drawing player to scene | All images to use imageScale
    // Texture Pro allows character scale and add rectangle from sprite sheet
    // width * animation frame = which frame is shown on top row
    Rectangle source{width * animationFrame, 0.f, width, height};
    Rectangle dest{screenPosition.x, screenPosition.y, imageScale * width, imageScale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);

    //---------------FOR DEBUGGING---------------//
    DrawRectangleLinesEx(dest, 1.0f, RED);
}