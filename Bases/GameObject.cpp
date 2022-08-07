// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "GameObject.hpp"
#include "ImplSfml/SfmlSprite.hpp"

GameObject::GameObject(std::string const& textureName, sf::Vector2f pos, int hitpoints)
: hitpoints(hitpoints)
{
    sprite = std::make_unique<SfmlSprite>();
    sprite->Init(textureName);
    sprite->SetPosition(pos);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*sprite, states);
    
}

void GameObject::ChangeHitpoints(int delta) {
    hitpoints += delta;
    GetDispatchers().hitpointsChanged.EmitEvent();
}

bool GameObject::HandleIntersectWith(ISceneObject* objectToHandle) {
    return sprite->IsIntersectsWith(static_cast<GameObject*>(objectToHandle)->sprite.get());
}

