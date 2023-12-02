#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter{

    public:
        Enemy(Vector2 spawnPosition);
        virtual void tick(float deltaTime) override;    // movement and animation from BaseCharacter class
    private:

};