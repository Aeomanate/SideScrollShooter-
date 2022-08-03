//
// Created by User on 7/17/2022.
//

#ifndef TESTGAME_ENEMY_HPP
#define TESTGAME_ENEMY_HPP

#include "PCH.hpp"
#include "Updatable.hpp"
#include "GameObject.hpp"
#include "Timer.hpp"

class Enemy: public GameObject {
  SET_EVENT_DISPATCHERS(
      DISPATCHER(death, Enemy*);
  );
    
  public:
    Enemy(sf::Vector2f pos, int direction);
    ~Enemy();
    
    static int GetWidth();
    
    void Update() override;
    
    bool HandleIntersectWith(GameObject* collidedObject) override;
  
  private:
    void UpdatePos();
    void CheckOutOfScreenBounds();
    
  private:
    int moveVelocity;
    int direction;
    Timer moveTimer;
    
};


#endif // TESTGAME_ENEMY_HPP
