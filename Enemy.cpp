#include "Enemy.h"

Enemy::Enemy(Vector2 spawnPosition):
        worldPosition(spawnPosition) // member initalizer list to intialize variable
{
    width = texture.width / imageFrame; // get the width of a texture frame 
    height = texture.height;            // get the width of a texture frame 
}

void Enemy::tick(float deltaTime){
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
    DrawTexturePro(texture, source, dest, Vector2{}, 0.0f, RED);

    //---------------FOR DEBUGGING---------------//
    DrawRectangleLinesEx(dest, 1.0f, RED);
}

void Enemy::undoMovement(){
    worldPosition = worldPositionLastFrame;
}