//
// Created by User on 8/3/2022.
//

#ifndef MAIN_CPP_SCENEOBJECT_HPP
#define MAIN_CPP_SCENEOBJECT_HPP

#include <SFML/Graphics.hpp>
#include "Updatable.hpp"

class SceneObject: public sf::Drawable, public Updatable {
  public:
    virtual ~SceneObject() = default;
};

#endif //MAIN_CPP_SCENEOBJECT_HPP
