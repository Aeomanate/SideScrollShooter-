// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Game.hpp"
#include "ImplSfml/SfmlResourceFactory.hpp"
#include "ImplSfml/SfmlSprite.hpp"


Game* Game::Create(std::string const& gameName, sf::VideoMode screen_size) {
    if(!game) {
        Game* gameRawPtr = new Game(gameName, screen_size);
        game.reset(gameRawPtr);
        game->Init();
    }
    return game.get();
}

Game* Game::Get() {
    if(!game) {
        std::cout << "Error: game was not created\n";
    }
    return game.get();
}

IResourceFactory* Game::GetResourceFactory() {
    return Get()->resourceFactory.get();
}

Game::Game(std::string const& gameName, sf::VideoMode screen_size)
: window(screen_size, gameName)
{
    resourceFactory = std::make_unique<SfmlResourceFactory>();
}

void Game::Init() {
    sf::Vector2f playerPos = {window.getSize().x/2.0f, window.getSize().y+0.0f};
    player = std::make_unique<Player>(playerPos);
    
    enemyController = std::make_unique<EnemyController>();
    
    sceneObjects.push_back(enemyController.get());
    sceneObjects.push_back(player.get());
    
    player->GetDispatchers().death.Subscribe(this, &Game::HandleEndGame);
}


sf::Vector2u Game::GetWindowSize() {
    return Get()->window.getSize();
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
    window.clear({200, 160, 80});
    for(auto sceneObject: sceneObjects) {
        
        window.draw(*sceneObject);
    }
    window.display();
}

void Game::UpdateGame() {
    enemyController->HandleAllIntersectsWith(player.get());
    for(auto sceneObject: sceneObjects) {
        sceneObject->Update();
    }
    
}
void Game::HandleEndGame() {
    std::cout << "Game ended\n";
    window.close();
}


