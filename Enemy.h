#include "raylib.h"
#include "BaseCharacter.h"
#include "player.h"

class Enemy : public BaseCharacter
{

public:
    Enemy(Vector2 spawnPosition);
    virtual void tick(float deltaTime) override; // movement and animation from BaseCharacter class
    void setTarget(Player *player) { target = player; };

private:
    Player *target; // pointer to character header
};