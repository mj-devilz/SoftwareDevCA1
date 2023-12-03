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
    imageColor = WHITE;
}

// Called every frame receives deltaTime, allows all variables to be updated every frame
// movement and animation added to here
void Player::tick(float deltaTime)
{
    if (getIsCaught())
        return; // getting isCaught value - if true, we don't move or render character
    // movement input
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        velocity.y -= 1.0f;
    if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        velocity.y += 1.0f;
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        velocity.x -= 1.0f;
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        velocity.x += 1.0f;
    if (IsKeyPressed(KEY_SPACE))
    {
        if (!boostActive)
        {
            boostActive = true;
            boost = 2.0f;
        }
    }
    if (boostActive)
    {
        boostStart += deltaTime;
        if (boostStart >= boostTime)
        {
            boost = 1.0f;
        }
        if (boostStart >= boostCooldown)
        {
            boostStart = 0.0f;
            boostActive = false;
        }
        DrawText("active", 20, 20, 20, RED);
    }
    else
    {
        DrawText("not active", 20, 20, 20, RED);
    }
    // calling base class tick - draws character and animates based on direction/speed
    BaseCharacter::tick(deltaTime);
}