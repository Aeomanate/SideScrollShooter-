//
// Created by User on 8/3/2022.
//

#ifndef MAIN_CPP_ENDGAMESCREEN_HPP
#define MAIN_CPP_ENDGAMESCREEN_HPP

#include "SceneObject.hpp"
#include "Timer.hpp"

class EndGameScreen: public SceneObject {
  public:
    EndGameScreen();
    
    void Update() override;
  
  protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  
  private:
    sf::Text text;
    sf::Font font;
    Timer opacityTimer;
    int curOpacity;
    sf::Color color;
};


#endif // MAIN_CPP_ENDGAMESCREEN_HPP
