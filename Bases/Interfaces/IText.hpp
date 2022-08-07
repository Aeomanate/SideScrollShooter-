//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_ITEXT_HPP
#define MAIN_CPP_ITEXT_HPP

#include <SFML/Graphics.hpp>
#include "PCH.hpp"
#include "IDestructable.hpp"
#include "IFont.hpp"
#include "Color.hpp"

class IText: public sf::Drawable, public IDestructable {
  public:
    virtual void Init(std::string const& fontName) = 0;
    
    virtual void SetPosition(sf::Vector2f pos) = 0;
    
    virtual void SetText(std::string const& text) = 0;
    
    virtual Color GetColor() const = 0;
    virtual void SetColor(Color newColor) = 0;
    
    virtual void SetFont(IFont* newFont) = 0;
    virtual IFont* GetFont() const = 0;
    
  protected:
    Color color;
    IFont* font;
};

#endif //MAIN_CPP_ITEXT_HPP
