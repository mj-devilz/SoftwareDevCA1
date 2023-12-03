#include "raylib.h"
#include "BaseCharacter.h"
#include "player.h"

class Enemy : public BaseCharacter
{

public:
    Enemy(Vector2 spawnPosition, struct Color color);
    virtual void tick(float deltaTime) override; // movement and animation from BaseCharacter class
    void setTarget(Player *player) { target = player; };

private:
    Player *target; // pointer to character header
    float damagePerSecond{20.0f}; // damage the enemy does
    float minDistToPlayer{20.0f}; // distance where enemy stops moving towards player (glitch fix)
};