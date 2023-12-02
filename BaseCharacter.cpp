#include "BaseCharacter.h"

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

    // Drawing player to scene | All images to use imageScale
    // Texture Pro allows character scale and add rectangle from sprite sheet
    // width * animation frame = which frame is shown on top row
    Rectangle source{width * animationFrame, 0.f, width, height};
    Rectangle dest{screenPosition.x, screenPosition.y, imageScale * width, imageScale * height};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, WHITE);

    //---------------FOR DEBUGGING---------------//
    DrawRectangleLinesEx(dest, 1.0f, RED);
}
