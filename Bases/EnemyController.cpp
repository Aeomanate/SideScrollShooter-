// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/23/2022.
//

#include "EnemyController.hpp"
#include "Game.hpp"
#include "Enemy.hpp"

EnemyController::EnemyController()
: maxCountEnemies(1)
, enemySpawnTimer(1s)
{

}
void EnemyController::Update() {
    Controller::Update();
    SpawnEnemy();
}

void EnemyController::SpawnEnemy() {
    if(GetCountObjects() >= maxCountEnemies || !enemySpawnTimer.isExpiredAndReset()) return;
    std::shared_ptr<Enemy> enemy = CreateEnemy();
    enemy->GetDispatchers().death.Subscribe(this, &EnemyController::PlanToRemoveGameObject);
    AddGameObject(enemy);
}

std::shared_ptr<Enemy> EnemyController::CreateEnemy() const {
    int direction= -1 + 2 * RAND(0, 1);
    bool isLeft = direction == -1;
    
    int xpos = Game::GetWindowSize().x * isLeft + (Enemy::GetWidth()/2 + 1) * direction;
    sf::Vector2f pos = {xpos + 0.f, Game::GetWindowSize().y + 0.f};
    
    return std::make_shared<Enemy>(pos, direction);
}
