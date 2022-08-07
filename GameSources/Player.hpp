//
// Created by User on 7/17/2022.
//

#ifndef TESTGAME_PLAYER_HPP
#define TESTGAME_PLAYER_HPP

#include "PCH.hpp"
#include "Interfaces/IUpdatable.hpp"
#include "GameObject.hpp"
#include "EventDispatcher.hpp"

class Player: public GameObject {
  SET_EVENT_DISPATCHERS(
      DISPATCHER(death);
  )
  
  public:
    Player(sf::Vector2f pos);
    
    void Jump();
    
    void Update() override;
    
  private:
    void HandleHitpointsChanged();
  
  private:
    float curJumpHeight;
    float jumpVelocity;
    float maxJumpHeight;
    bool isJumping;
    bool isFallinng;
    std::chrono::milliseconds jumpDuration;
    Timer timer;
};


#endif // TESTGAME_PLAYER_HPP
