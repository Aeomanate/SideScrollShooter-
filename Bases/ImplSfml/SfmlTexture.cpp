// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "SfmlTexture.hpp"

void SfmlTexture::LoadFromFile(std::string const& textureName) {
    if(!texture.loadFromFile(textureName)) {
        std::cout << "Texture \"" + textureName + "\" not loaded\n";
        return;
    }
}

SfmlTexture::operator sf::Texture&() {
    return texture;
}
Vector2u SfmlTexture::GetSize() {
    return {texture.getSize().x, texture.getSize().y};
}
