// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include <SFML/Window.hpp>
#include "SfmlSprite.hpp"
#include "SfmlTexture.hpp"
#include "Game.hpp"

void SfmlSprite::Init(std::string const& textureName) {
    ITexture* sfmlTexture = Game::GetResourceFactory()->GetTexture(textureName);
    sprite.setTexture(*static_cast<SfmlTexture*>(sfmlTexture));
    sprite.setOrigin(sfmlTexture->GetSize().x/2, sfmlTexture->GetSize().y);
}

void SfmlSprite::SetPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

sf::Vector2f SfmlSprite::GetPosition() const {
    return sprite.getPosition();
}

void SfmlSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

bool SfmlSprite::IsIntersectsWith(ISprite* other) const {
    return sprite.getGlobalBounds().intersects(
        // Cast used in current library bounds
        static_cast<SfmlSprite*>(other)->sprite.getGlobalBounds()
    );
}


