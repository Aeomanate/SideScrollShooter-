// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "SfmlResourceFactory.hpp"
#include "SfmlSprite.hpp"
#include "SfmlTexture.hpp"

ITexture* SfmlResourceFactory::GetTexture(std::string const& textureName) {
    if(textures.find(textureName) == textures.end()) {
        auto sfmlTexture = std::make_unique<SfmlTexture>();
        sfmlTexture->LoadFromFile("../Resources/Textures/" + textureName + ".png");
        textures.insert({textureName, std::move(sfmlTexture)});
    }
    
    return textures[textureName].get();
}
