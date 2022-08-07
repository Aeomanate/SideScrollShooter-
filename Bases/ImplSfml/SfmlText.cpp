// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "SfmlText.hpp"
#include "SfmlFont.hpp"
#include "Game.hpp"
#include "SfmlUtility.hpp"

void SfmlText::Init(std::string const& fontName) {
    IFont* sfmlFont = Game::GetResourceFactory()->GetFont(fontName);
    text.setFont(*static_cast<SfmlFont*>(sfmlFont));
    text.setCharacterSize(64);
    text.setFillColor({100, 160, 80});
    text.setStyle(sf::Text::Style::Bold);
}

void SfmlText::SetText(std::string const& newText) {
    text.setString(newText);
    sf::FloatRect localTextBounds = text.getLocalBounds();
    float width = localTextBounds.width;
    float height = localTextBounds.height;
    text.setOrigin(width/2, height);
}

void SfmlText::SetPosition(sf::Vector2f pos) {
    text.setPosition(pos);
}

void SfmlText::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text, states);
}

Color SfmlText::GetColor() const {
    return Color();
}

void SfmlText::SetColor(Color newColor) {
    IText::SetColor(newColor);
    text.setFillColor(toSf(color));
}

void SfmlText::SetFont(IFont* font) {
    IText::SetFont(font);
    text.setFont(*static_cast<SfmlFont*>(font));
}

IFont* SfmlText::GetFont() const {
    return nullptr;
}
