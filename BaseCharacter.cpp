#include "BaseCharacter.h"
#include "raymath.h"

BaseCharacter::BaseCharacter()
{
}

void BaseCharacter::undoMovement()
{
    worldPosition = worldPositionLastFrame;
}

void BaseCharacter::tick(float deltaTime)
{
    // storing the last worldPosition before next is set (important for stopping out of bounds)
    worldPositionLastFrame = worldPosition;

    // Updating animation frame
    runningTime += deltaTime; // deltatime will GetFrameTime() on main class
    if (runningTime >= updateTime)
    {
        animationFrame++;   // increment frame
        runningTime = 0.0f; // reset running time
        if (animationFrame > maxAnimationFrames)
            animationFrame = 0; // reset frame when it reaches ends
    }

    // vector2length used to see if there is movement
    if (Vector2Length(velocity) != 0.0)
    {
        // normalized use to make sure diagonal speed is normalized
        // moving the map position based on our movedirection
        // vector2scale allowing us to add a speed factor to our normalized direction
        // changing characters position - so changed to Add
        worldPosition = Vector2Add(worldPosition, Vector2Scale(Vector2Normalize(velocity), movementSpeed * boost));
        //----ADD CHANGE IN DIRECTION OF IMAGE BASED ON DIRECTION----//
        if (velocity.x < 0)
        {
            // Add Left Texture
            texture = movementLeft;
        }
        else if (velocity.x > 0)
        {
            // Add Right Texture
            texture = movementRight;
        }
        else if (velocity.x == 0 && velocity.y < 0)
        {
            // Add Up Texture
            texture = movementUp;
        }
        else if (velocity.x == 0 && velocity.y > 0)
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
    velocity = {}; // zero out velocity after movement

    // Drawing player to scene | All images to use imageScale
    // Texture Pro allows character scale and add rectangle from sprite sheet
    // width * animation frame = which frame is shown on top row
    Rectangle source{width * animationFrame, 0.f, width, height};
    Rectangle dest{screenPosition.x, screenPosition.y, imageScale * width, imageScale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, imageColor);

    //---------------FOR DEBUGGING---------------//
    DrawRectangleLinesEx(dest, 1.0f, RED);
}
