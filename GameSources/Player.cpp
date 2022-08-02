// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Player.hpp"

Player::Player(sf::Vector2f pos)
    : GameObject("../Resources/Textures/player.png", pos, 10)
    , jumpVelocity(3)
    , maxJumpHeight(373)
    , isJumping(false)
    , isFallinng(false)
    , curJumpHeight(0)
    , jumpDuration(400ms)
    , timer(jumpDuration / int(maxJumpHeight / jumpVelocity))
{
    GameObject::GetDispatchers().hitpointsChanged.Subscribe();
}

void Player::Update() {
    if(!timer.isExpiredAndReset()) return;
    
    if(isJumping) {
        if(curJumpHeight <= maxJumpHeight) {
            sprite.setPosition(sprite.getPosition() - sf::Vector2f { 0, jumpVelocity });
            curJumpHeight += jumpVelocity;
        } else {
            isJumping = false;
            isFallinng = true;
        }
    }
    
    if(isFallinng) {
        if(curJumpHeight != 0) {
            sprite.setPosition(sprite.getPosition() + sf::Vector2f { 0, jumpVelocity });
            curJumpHeight -= jumpVelocity;
        } else {
            isFallinng = false;
        }
        
    }
}

void Player::Jump() {
    if(isJumping || isFallinng) return;
    isJumping = true;
    timer.reset();
}
void Player::HandleHitpointsChanged() {

}
