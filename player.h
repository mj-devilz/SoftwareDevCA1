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
    virtual void tick(float deltaTime) override;            // movement and animation from BaseCharacter class
    Vector2 getScreenPosition() { return screenPosition; }; // gettng screen position
    bool getIsCaught() { return isCaught; }                 // getter for if player is caught
    void setIsCaught(bool caught) { isCaught = caught; }    // setter for if player is caught
private:
    float boostTime{1.5f};                                      // length of time the boost is active
    float boostCooldown{3.0f};                                  // cooldown added until boost can be activated again
    bool boostActive{false};                                    // if boost is active or not
    float boostStart{};                                         // frame when the boost was initiated
    Sound boostsound{LoadSound("audio/player_speedSound.mp3")}; // loading audio for boosting speed
    bool isCaught{};                                            // bool for if player is caught
};

#endif