//
// Created by User on 7/17/2022.
//

#ifndef TESTGAME_GAMEOBJECT_HPP
#define TESTGAME_GAMEOBJECT_HPP

#include "Bases.hpp"

class GameObject: public SceneObject {
  SET_EVENT_DISPATCHERS(
      DISPATCHER(hitpointsChanged);
  )
  
  public:
    GameObject(std::string name, sf::Vector2f pos, int hitpoints);
    virtual ~GameObject() = default;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
    bool CheckIntersect(GameObject const& other) const;
    
    virtual void ChangeHitpoints(int delta);
    
  public:
    virtual void HandleIntersectWith(GameObject* other);
    
    
  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    
    int hitpoints;
};


#endif // TESTGAME_GAMEOBJECT_HPP
