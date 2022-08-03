// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "GameObject.hpp"

GameObject::GameObject(std::string name, sf::Vector2f pos, int hitpoints)
: hitpoints(hitpoints)
{
    if (!texture.loadFromFile(name))
    {
        std::cout << "Texture not load\n";
    }
    
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void GameObject::ChangeHitpoints(int delta) {
    hitpoints += delta;
    HandleHitpointsChanged();
}

bool GameObject::HandleIntersectWith(GameObject* collidedObject) {
    bool isCollided = sprite.getGlobalBounds().intersects(collidedObject->sprite.getGlobalBounds());
    return isCollided;
}

