// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/23/2022.
//

#include "Controller.hpp"
void Controller::Update() {
    HandleObjectsToRemove();
    for(auto const& gameObject: gameObjects) {
        gameObject->Update();
    }
}
void Controller::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto const& gameUnit: gameObjects) {
        target.draw(*gameUnit, states);
    }
}

void Controller::HandleAllIntersectWith(GameObject* objectToHandle) {
    for(auto const& gameObject: gameObjects) {
        if(objectToHandle->HandleIntersectWith(gameObject.get())) {
            gameObject->HandleIntersectWith(objectToHandle);
        }
    }
}

size_t Controller::GetCountObjects() const {
    return gameObjects.size();
}



void Controller::AddGameObject(std::shared_ptr<GameObject> gameObject) {
    gameObjects.insert(std::move(gameObject));
}
void Controller::RemoveGameObject(GameObject* gameObject) {
    auto it = gameObjects.find(std::shared_ptr<GameObject>(gameObject, [](void*){}));
    if(it == gameObjects.end()) return;

    gameObjects.erase(it);
}
void Controller::HandleObjectsToRemove() {
    while(!objectsToDelete.empty()) {
        GameObject* toDelete = objectsToDelete.front();
        objectsToDelete.pop();
        RemoveGameObject(toDelete);
    }
}
void Controller::PlanToRemoveGameObject(GameObject* gameObject) {
    objectsToDelete.push(gameObject);
}

// const std::shared_ptr<GameObject>
// const std::shared_ptr<GameObject>
