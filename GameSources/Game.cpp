// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Game.hpp"
#include "Enemy.hpp"


Game& Game::Create(std::string const& gameName, sf::VideoMode screen_size) {
    if(!game) {
        game.reset(new Game(gameName, screen_size));
    }
    return *game;
}
Game& Game::Get() {
    return *game;
}

Game::Game(std::string const& gameName, sf::VideoMode screen_size)
: window(screen_size, gameName)
{
    enemyController = std::make_shared<EnemyController>();
    player = std::make_shared<Player>(sf::Vector2f{screen_size.width/2.0f, screen_size.height+0.0f});
    sceneObjects.insert(enemyController.get());
    sceneObjects.insert(player.get());
    
    player->GetDispatchers().death.Subscribe(this, &Game::HandleEndGame);
}

sf::Vector2u Game::GetWindowSize() {
    return Get().window.getSize();
}


void Game::GameLoop() {
    while(window.isOpen()) {
        HandleInput();
        UpdateGame();
        DrawGame();
    }
}
void Game::HandleKeyPressed(sf::Event event) {
    switch(event.key.code) {
        case sf::Keyboard::Key::Up:
            std::cout << "Up pressed!\n";
            player->Jump();
            break;
        case sf::Keyboard::Key::Down:
            std::cout << "Down pressed!\n";
            break;
        default:
            break;
    }
}
void Game::HandleInput() {
    sf::Event event { };
    while(window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::KeyPressed:
                HandleKeyPressed(event);
                break;
            
            default:
                break;
        }
    }
}



void Game::DrawGame() {
    window.clear({128, 128, 128});
    for(SceneObject* sceneObject: sceneObjects) {
        window.draw(*sceneObject);
    }
    window.display();
}
void Game::UpdateGame() {
    for(SceneObject* sceneObject: sceneObjects) {
        sceneObject->Update();
    }
    
}

void Game::HandleEndGame() {
    
    window.close();
}


