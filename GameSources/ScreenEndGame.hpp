//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SCREENENDGAME_HPP
#define MAIN_CPP_SCREENENDGAME_HPP


#include "ISceneObject.hpp"
#include "IText.hpp"
#include "Timer.hpp"

class ScreenEndGame: public ISceneObject {
  public:
    ScreenEndGame();
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
    void Update() override;
  
    
  private:
    std::unique_ptr<IText> text;
    Timer opacityChangeTimer;
    Color curColor;
    int opacityChangeStep;
};


#endif // MAIN_CPP_SCREENENDGAME_HPP
