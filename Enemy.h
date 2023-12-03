#include "raylib.h"
#include "BaseCharacter.h"
#include "player.h"

class Enemy : public BaseCharacter
{

public:
    Enemy(Vector2 spawnPosition, struct Color color);
    virtual void tick(float deltaTime) override;                                         // movement and animation from BaseCharacter class
    void setTarget(Player *player) { target = player; };                                 // uses a pointer to Player to set the value of target
    void increaseMovementSpeed(float speedIncrease) { movementSpeed += speedIncrease; }; // increase movementspeed
    float getMovementSpeed() { return movementSpeed; };                                  // get movement speed

private:
    Player *target;               // pointer to player header
    float minDistToPlayer{20.0f}; // distance where enemy stops moving towards player (glitch fix)
};