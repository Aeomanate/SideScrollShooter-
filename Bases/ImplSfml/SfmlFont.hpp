//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLFONT_HPP
#define MAIN_CPP_SFMLFONT_HPP


#include "IFont.hpp"

class SfmlFont: public IFont {
  public:
    void LoadFromFile(std::string const& fontName) override;
    
    operator sf::Font&();
    
  private:
    sf::Font font;
};


#endif // MAIN_CPP_SFMLFONT_HPP
