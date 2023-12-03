#include "Enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 spawnPosition, struct Color color)
{
    worldPosition = spawnPosition;      // takes vector2 to set location
    movementSpeed = 2.5f;               // enemy move
    width = texture.width / imageFrame; // get the width of a texture frame
    height = texture.height;            // get the width of a texture frame
    imageColor = color;                 // enemy color
}

void Enemy::tick(float deltaTime)
{
    // moving enemy towards the character
    //  Direction to target (using velocity, this is now normalized / scaled by speed and worldposition set in tick)
    velocity = Vector2Subtract(target->getScreenPosition(), screenPosition);
    if (Vector2Length(velocity) < minDistToPlayer)
        velocity = {}; // stop enemy from moving when close to the user
    // enemies screen position is the enemies positon - the targets position
    screenPosition = Vector2Subtract(worldPosition, target->getWorldPosition());
    // running the tick function on parent class - draw texture and movement
    BaseCharacter::tick(deltaTime);
    // Adding collision check to player
    if (CheckCollisionRecs(target->getCollisionRec(), getCollisionRec()))
    {
        target->setIsCaught(true);
    }
}
