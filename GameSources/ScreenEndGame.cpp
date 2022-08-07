// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "ScreenEndGame.hpp"
#include "Game.hpp"

ScreenEndGame::ScreenEndGame()
: opacityChangeTimer(5ms)
, opacityChangeStep(1)
, curColor { 100, 160, 80, 0 }
{
    text = Game::GetResourceFactory()->MakeText(
        "WASTED\n\n"
        "Score: " + std::to_string(123) + "\n\n"
        "Press any key tocontinue..."
    );
    text->SetColor(curColor);
    float x = Game::GetWindowSize().x/2.f;
    float y = Game::GetWindowSize().y*0.7f;
    text->SetPosition({x, y});
}

void ScreenEndGame::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*text, states);
}
void ScreenEndGame::Update() {
    if(curColor.a < std::numeric_limits<uint8_t>::max()) {
        if(!opacityChangeTimer.isExpiredAndReset()) return;
        curColor.a += opacityChangeStep;
        text->SetColor(curColor);
    }
}
