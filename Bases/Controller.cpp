// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/23/2022.
//

#include "Controller.hpp"
void Controller::Update() {
    HandleObjectsToRemove();
    
    for(std::shared_ptr<GameObject> const& gameObject: gameObjects) {
        gameObject->Update();
    }
}
void Controller::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for(auto const& gameObject: gameObjects) {
        target.draw(*gameObject, states);
    }
}

void Controller::HandleAllIntersectsWith(ISceneObject* objectToHandle) {
    for(auto const& gameObject: gameObjects) {
        gameObject->HandleIntersectWith(objectToHandle);
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
