#include "raylib.h"
#include "BaseCharacter.h"
// Deriving Player from parent class BaseCharacter
// Header file used for declaring variables and functions
class Player : public BaseCharacter 
{
public:
    Player(int screenWidth, int screenHeight);
    void tick(float deltaTime);                          // movement and animation based on GetFrameTime()

private:

};