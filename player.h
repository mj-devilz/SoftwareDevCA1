#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "BaseCharacter.h"
// Deriving Player from parent class BaseCharacter
// Header file used for declaring variables and functions
class Player : public BaseCharacter
{
public:
    Player(int screenWidth, int screenHeight);
    virtual void tick(float deltaTime) override; // movement and animation from BaseCharacter class
    Vector2 getScreenPosition() { return screenPosition; };
    float getHealth() { return health; } // get health
    void takeDamage(float damgage);      // take damage

private:
    float health{100.0f}; // player health set
};

#endif