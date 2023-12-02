#include "BaseCharacter.h"

BaseCharacter::BaseCharacter(){

}

void BaseCharacter::undoMovement()
{
    worldPosition = worldPositionLastFrame;
}