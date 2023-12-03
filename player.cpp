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

    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        velocity.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        velocity.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        velocity.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        velocity.x += 1.0f;

    BaseCharacter::tick(deltaTime);
}