//
// Created by User on 7/17/2022.
//

#ifndef TESTGAME_GAMEOBJECT_HPP
#define TESTGAME_GAMEOBJECT_HPP

#include "Interfaces/IUpdatable.hpp"
#include "Interfaces/ISceneObject.hpp"
#include "Interfaces/ISprite.hpp"

class GameObject: public ISceneObject {
  SET_EVENT_DISPATCHERS(
      DISPATCHER(hitpointsChanged);
  )
  
  public:
    GameObject(std::string const& textureName, sf::Vector2f pos, int hitpoints);
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    virtual void ChangeHitpoints(int delta);
    
    bool HandleIntersectWith(ISceneObject* objectToHandle) override;
    
  protected:
    std::unique_ptr<ISprite> sprite;
    int hitpoints;
};


#endif // TESTGAME_GAMEOBJECT_HPP
