//
// Created by User on 7/17/2022.
//



#ifndef TESTGAME_BASES_HPP
#define TESTGAME_BASES_HPP

#include "PCH.hpp"

sf::Vector2f operator+(sf::Vector2f left, float value);

class Updatable {
  public:
    virtual void Update() = 0;
    virtual ~Updatable() = default;
};

class SceneObject: public sf::Drawable, public Updatable {
  public:
    virtual ~SceneObject() = default;
};




#endif // TESTGAME_BASES_HPP
