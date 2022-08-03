// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/3/2022.
//

#include "EndGameScreen.hpp"

EndGameScreen::EndGameScreen()
: opacityTimer(50ms)
, curOpacity(0)
, color(200, 150, 20, curOpacity)
{
    if(!font.loadFromFile("../Resources/Catalish Huntera.ttf")) {
        std::cout << "Font not load\n";
    }
    text.setFont(font);
    text.setString("WASTED\nScore: xxx\n\nPress any key to restart");
    text.setFillColor(color);
    text.setStyle(sf::Text::Style::Bold);
}

void EndGameScreen::Update() {
    if(color.a == 255) return;
    if(!opacityTimer.isExpiredAndReset()) return;
    color.a = std::clamp(color.a + 5, 0, 255);
    text.setFillColor(color);
    
}

void EndGameScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}
