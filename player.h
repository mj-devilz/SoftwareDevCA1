#include "raylib.h"
// Header file used for declaring variables and functions
class Player {
    public:
        Vector2 getWorldPosition(){return worldPosition; } //getter for where player is in world
        void setScreenPosition(int screenWidth,int screenHeight){}; // setting the center of screen 
        void tick(float deltaTime){};
    private:
        Texture2D texture{LoadTexture("assets/Slime_Idle.png")}; // default texture
        Texture2D idle{LoadTexture("assets/Slime_Idle.png")}; // idle texture
        Texture2D movement{LoadTexture("assets/Slime_Walk.png")}; // movement texture
        Vector2 screenPosition{};//center of screen where character is drawn
        Vector2 worldPosition{}; //where the character is in the world
        float imageFrame{4.0f}; // frames in player texture
        float imageScale{3.0f};// scaling for all images being added
        float movementSpeed{3.0f}; //movement for the character
        // Animation variables
        float runningTime{};                 // updated every frame
        int animationFrame{};                // frame count
        const int maxAnimationFrames{4};     // max number of frames for image
        const float updateTime{1.0f / 8.0f}; // amount of time to pass before updating animation frame (8 times /second)

};