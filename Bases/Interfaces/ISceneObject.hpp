//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_ISCENEOBJECT_HPP
#define MAIN_CPP_ISCENEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "IUpdatable.hpp"
#include "ISprite.hpp"

class ISceneObject: public sf::Drawable, public IUpdatable, public IDestructable {
  public:
    virtual bool HandleIntersectWith(ISceneObject* objectToHandle) {
        return false;
    }
  
  protected:
};


#endif // MAIN_CPP_ISCENEOBJECT_HPP
