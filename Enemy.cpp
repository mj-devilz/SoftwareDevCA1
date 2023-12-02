#include "Enemy.h"

Enemy::Enemy(Vector2 spawnPosition)
{
    worldPosition = spawnPosition;
    width = texture.width / imageFrame; // get the width of a texture frame 
    height = texture.height;            // get the width of a texture frame 
}

void Enemy::tick(float deltaTime){
    BaseCharacter::tick(deltaTime);
}