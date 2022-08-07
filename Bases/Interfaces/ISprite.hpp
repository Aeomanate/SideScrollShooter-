//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_ISPRITE_HPP
#define MAIN_CPP_ISPRITE_HPP

#include <SFML/Graphics.hpp>
#include "IDestructable.hpp"

class ISprite: public sf::Drawable, public IDestructable {
  public:
    virtual void Init(std::string const& TextureName) = 0;
    
    virtual void SetPosition(sf::Vector2f pos) = 0;
    
    virtual sf::Vector2f GetPosition() const = 0;
    
    virtual bool IsIntersectsWith(ISprite* other) const {
        return false;
    }
};


#endif // MAIN_CPP_ISPRITE_HPP
