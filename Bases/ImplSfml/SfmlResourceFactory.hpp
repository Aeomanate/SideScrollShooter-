//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLRESOURCEFACTORY_HPP
#define MAIN_CPP_SFMLRESOURCEFACTORY_HPP

#include "PCH.hpp"
#include "Interfaces/ISprite.hpp"
#include "Interfaces/ITexture.hpp"
#include "Interfaces/IResourceFactory.hpp"

class SfmlResourceFactory: public IResourceFactory {
  public:
    ITexture* GetTexture(std::string const& textureName) override;
  
  private:
    std::map<std::string, std::unique_ptr<ITexture>> textures;
};


#endif // MAIN_CPP_SFMLRESOURCEFACTORY_HPP
