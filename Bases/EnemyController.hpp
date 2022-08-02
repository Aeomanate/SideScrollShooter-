//
// Created by User on 7/23/2022.
//

#ifndef TESTGAME_ENEMYCONTROLLER_HPP
#define TESTGAME_ENEMYCONTROLLER_HPP

#include "PCH.hpp"
#include "Controller.hpp"
#include "Enemy.hpp"

class EnemyController: public Controller {
  public:
    EnemyController();
    
    void Update() override;
    
    void SpawnEnemy();
  
  
  private:
    int maxCountEnemies;
    Timer enemySpawnTimer;
    std::shared_ptr<Enemy> CreateEnemy() const;
};


#endif // TESTGAME_ENEMYCONTROLLER_HPP
