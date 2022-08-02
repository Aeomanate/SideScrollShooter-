//
// Created by User on 7/17/2022.
//

#ifndef TESTGAME_GAME_HPP
#define TESTGAME_GAME_HPP

#include "PCH.hpp"
#include "Player.hpp"
#include "Controller.hpp"
#include "EnemyController.hpp"


class Game {
  public:
    
    static Game& Create(std::string const& gameName, sf::VideoMode screen_size);
    
    static Game& Get();
    
    static sf::Vector2u GetWindowSize();
    
    void GameLoop();
    
    
  
  private:
    void HandleKeyPressed(sf::Event event);
    
    void HandleInput();
    
    void DrawGame();
    
    void UpdateGame();
    
    bool CheckEndGame();
    
    void HandleEndGame();
    
  private:
    Game(std::string const& gameName, sf::VideoMode screen_size);
    
  private:
    inline static std::unique_ptr<Game> game = nullptr;
    
    sf::RenderWindow window;
    Player player;
    
    std::shared_ptr<EnemyController> enemyController;
    std::vector<Controller*> controllers;
};


#endif // TESTGAME_GAME_HPP
