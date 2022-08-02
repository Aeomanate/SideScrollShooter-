// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Enemy.hpp"
#include "Game.hpp"
#include "Game.hpp"

Enemy::Enemy(sf::Vector2f pos, int direction)
: GameObject("../Resources/Textures/enemy.png", pos)
, moveVelocity(5)
, direction(direction)
, moveTimer(5ms)
{

}

Enemy::~Enemy() {
    std::cout << "Texture not load";
}

int Enemy::GetWidth() {
    return 128;
}

void Enemy::Update() {
    UpdatePos();
    CheckOutOfScreenBounds();
    
}


void Enemy::UpdatePos() {
    if(!moveTimer.isExpiredAndReset()) return;
    
    sf::Vector2f pos = sprite.getPosition();
    sprite.setPosition(pos.x + moveVelocity * direction, pos.y);
}

void Enemy::CheckOutOfScreenBounds() {
    unsigned screen_width = Game::Get().GetWindowSize().x;
    size_t count = GetDispatchers().death.GetSubscribersCount();
    float curPos = sprite.getPosition().x;
    bool isOutFromLeftBorder = sprite.getPosition().x <= -Enemy::GetWidth() / 2;
    bool isOutFromRightBorder = sprite.getPosition().x >= Game::GetWindowSize().x + Enemy::GetWidth() / 2;
    if(isOutFromLeftBorder || isOutFromRightBorder) {
        GetDispatchers().death.EmitEvent(this);
    }
}
