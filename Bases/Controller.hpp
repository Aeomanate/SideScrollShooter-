//
// Created by User on 7/23/2022.
//

#ifndef TESTGAME_CONTROLLER_HPP
#define TESTGAME_CONTROLLER_HPP

#include "PCH.hpp"
#include "Interfaces/ISceneObject.hpp"
#include "GameObject.hpp"

class Controller: public ISceneObject {
  public:
    void Update() override;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    void HandleAllIntersectsWith(ISceneObject* objectToHandle);
    
    size_t GetCountObjects() const;
    
  public:
    void AddGameObject(std::shared_ptr<GameObject> gameObject);
    
    void RemoveGameObject(GameObject* gameObject);
    
    void HandleObjectsToRemove();
    
    void PlanToRemoveGameObject(GameObject* gameObject);
  
  private:
    std::set<std::shared_ptr<GameObject>> gameObjects;
    std::queue<GameObject*> objectsToDelete;
};



#endif // TESTGAME_CONTROLLER_HPP
