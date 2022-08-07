//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLTEXT_HPP
#define MAIN_CPP_SFMLTEXT_HPP


#include "IText.hpp"

class SfmlText: public IText {
  public:
    void Init(std::string const& fontName) override;
    
    void SetPosition(sf::Vector2f pos) override;
    
    void SetText(std::string const& newText) override;
  
    void draw(sf:: RenderTarget& target, sf::RenderStates states) const override;
    
    Color GetColor() const override;
    void SetColor(Color newColor) override;
    
    void SetFont(IFont* font) override;
    IFont* GetFont() const override;
  
  private:
    sf::Text text;
};


#endif // MAIN_CPP_SFMLTEXT_HPP
