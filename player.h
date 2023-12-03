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

private:
    float health{100.0f};      // player health set
    float boostTime{1.5f};     // length of time the boost is active
    float boostCooldown{3.0f}; // cooldown added until boost can be activated again
    bool boostActive{false};   // if boost is active or not
    float boostStart{};        // frame when the boost was initiated
};

#endif