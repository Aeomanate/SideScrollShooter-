//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLRESOURCEFACTORY_HPP
#define MAIN_CPP_SFMLRESOURCEFACTORY_HPP

#include "PCH.hpp"
#include "ISprite.hpp"
#include "ITexture.hpp"
#include "IResourceFactory.hpp"

class SfmlResourceFactory: public IResourceFactory {
    template <class T>
    using ResourceMapType = std::map<std::string, std::unique_ptr<T>>;
    
    template <class Interface, class RMT = ResourceMapType<Interface>>
    using ReturnLoadT = std::pair<typename RMT::iterator, bool>;
    
    template <class Interface, class Implementation>
    ReturnLoadT<Interface> Load(std::string const& resourceName);
    
    auto& GetTupleOfMaps();
    
    
  public:
    SfmlResourceFactory(std::string const& resourcesFolder);
    ITexture* GetTexture(std::string const& textureName) override;
    IFont* GetFont(std::string const& fontName) override;
    
    std::unique_ptr<IText> MakeText(std::string const& text) override;
    
  private:
    std::string resourcesFolder;
    ResourceMapType<ITexture> textures;
    ResourceMapType<IFont> fonts;
};


#endif // MAIN_CPP_SFMLRESOURCEFACTORY_HPP
