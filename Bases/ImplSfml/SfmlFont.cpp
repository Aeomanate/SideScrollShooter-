// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "SfmlFont.hpp"
#include "Game.hpp"

void SfmlFont::LoadFromFile(std::string const& fontName) {
    if(!font.loadFromFile(fontName)) {
        std::cout << "Font \"" + fontName + "\" not loaded\n";
        return;
    }
}

SfmlFont::operator sf::Font&() {
    return font;
}
