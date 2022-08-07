//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLSPRITE_HPP
#define MAIN_CPP_SFMLSPRITE_HPP


#include "Interfaces/ISprite.hpp"

class SfmlSprite: public ISprite {
  public:
    SfmlSprite() = default;
    
    void Init(std::string const& textureName) override;
    
    void SetPosition(sf::Vector2f pos) override;
    
    sf::Vector2f GetPosition() const override;
    
    bool IsIntersectsWith(ISprite* other) const override;
  
  protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
  private:
    sf::Sprite sprite;
};


#endif // MAIN_CPP_SFMLSPRITE_HPP
