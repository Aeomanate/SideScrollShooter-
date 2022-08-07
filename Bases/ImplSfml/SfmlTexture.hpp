//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLTEXTURE_HPP
#define MAIN_CPP_SFMLTEXTURE_HPP

#include <SFML/Graphics.hpp>
#include "Interfaces/ITexture.hpp"

class SfmlTexture: public ITexture {
  public:
    void LoadFromFile(std::string const& textureName) override;
  
    operator sf::Texture&();
    Vector2u GetSize() override;
    
  private:
    sf::Texture texture;
};


#endif // MAIN_CPP_SFMLTEXTURE_HPP
