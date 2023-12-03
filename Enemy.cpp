#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 spawnPosition)
{
    worldPosition = spawnPosition;
    width = texture.width / imageFrame; // get the width of a texture frame 
    height = texture.height;            // get the width of a texture frame
    movementSpeed = 2.0f;
}

void Enemy::tick(float deltaTime){
    //moving enemy towards the character
    // Direction to target (using velocity, this is now normalized / scaled by speed and worldposition set in tick)
    velocity = Vector2Subtract(target->getScreenPosition(),screenPosition);
    //enemies screen position is the enemies positon - the targets position
    screenPosition = Vector2Subtract(worldPosition, target->getWorldPosition());
    //running the tick function on parent class - draw texture and movement
    BaseCharacter::tick(deltaTime);
}