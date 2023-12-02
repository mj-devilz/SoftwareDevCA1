#include "raylib.h"
#include "BaseCharacter.h"

class Enemy : public BaseCharacter{

    public:
        Enemy(Vector2 spawnPosition);
        void tick(float deltaTime);                          // movement and animation based on GetFrameTime()
    private:

};