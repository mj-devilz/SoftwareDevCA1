#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 spawnPosition)
{
    worldPosition = spawnPosition;
    width = texture.width / imageFrame; // get the width of a texture frame 
    height = texture.height;            // get the width of a texture frame
    movementSpeed = 3.0f;
}

void Enemy::tick(float deltaTime){
    //moving enemy towards the character
    // Direction to target
    Vector2 toTarget = Vector2Subtract(target->getScreenPosition(),screenPosition);
    //Normalize so no movement issues
    toTarget = Vector2Normalize(toTarget);
    //multiply totarget by speed
    toTarget = Vector2Scale(toTarget,movementSpeed);
    //multiply totarget by speed
    worldPosition = Vector2Add(worldPosition,toTarget);
    //enemies screen position is the enemies positon - the targets position
    screenPosition = Vector2Subtract(worldPosition, target->getWorldPosition());
    //running the tick function on parent class - draw texture and movement
    BaseCharacter::tick(deltaTime);
}