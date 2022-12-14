// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy(sf::Vector2f pos, int direction)
: GameObject("enemy", pos, 1)
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
    
    sf::Vector2f pos = sprite->GetPosition();
    sprite->SetPosition({pos.x + moveVelocity * direction, pos.y});
}

void Enemy::CheckOutOfScreenBounds() {
    unsigned screen_width = Game::Get()->GetWindowSize().x;
    size_t count = GetDispatchers().death.GetSubscribersCount();
    float curPos = sprite->GetPosition().x;
    bool isOutFromLeftBorder = sprite->GetPosition().x <= -Enemy::GetWidth() / 2;
    bool isOutFromRightBorder = sprite->GetPosition().x >= Game::GetWindowSize().x + Enemy::GetWidth() / 2;
    if(isOutFromLeftBorder || isOutFromRightBorder) {
        GetDispatchers().death.EmitEvent(this);
    }
}

bool Enemy::HandleIntersectWith(ISceneObject* objectToHandle) {
    bool isIntersected = GameObject::HandleIntersectWith(objectToHandle);
    
    if(isIntersected) {
        static_cast<GameObject*>(objectToHandle)->ChangeHitpoints(-1);
    }
    
    return isIntersected;
}
