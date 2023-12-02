#include "raylib.h"

class Enemy{

    public:
        Enemy(Vector2 spawnPosition);
        Vector2 getWorldPosition() { return worldPosition; } // getter for where player is in world
        void tick(float deltaTime);                          // movement and animation based on GetFrameTime()
        float getImageScale() { return imageScale; }         // getter for image Scale
        void undoMovement();                                 // undoing the last movement (out of bounds)
    private:
        Texture2D texture{LoadTexture("assets/slime_idles.png")};            // default texture
        Texture2D idle{LoadTexture("assets/slime_idles.png")};               // idle texture
        Texture2D movementLeft{LoadTexture("assets/slime_move_left.png")};   // movement texture left
        Texture2D movementRight{LoadTexture("assets/slime_move_right.png")}; // movement texture right
        Texture2D movementUp{LoadTexture("assets/slime_move_up.png")};       // movement texture up
        Texture2D movementDown{LoadTexture("assets/slime_move_down.png")};   // movement texture Down
        Vector2 screenPosition{};                                            // center of screen where character is drawn
        Vector2 worldPosition{};                                             // where the character is in the world
        Vector2 worldPositionLastFrame{};                                    // Last frame the character was positioned (out of bounds)
        float imageFrame{4.0f};                                              // frames in player texture 4 x 4
        float imageScale{3.0f};                                              // scaling for all images being added
        float movementSpeed{3.0f};                                           // movement for the character
        float width{};                                                       // width of the player texture
        float height{};                                                      // height of the player texture
        // Animation variables
        float runningTime{};           // updated every frame
        int animationFrame{};          // frame count
        int maxAnimationFrames{4};     // max number of frames for image
        float updateTime{1.0f / 8.0f}; // amount of time to pass before updating animation frame (8 times /second)

};