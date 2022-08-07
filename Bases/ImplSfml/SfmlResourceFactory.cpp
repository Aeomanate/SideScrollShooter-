// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "SfmlResourceFactory.hpp"
#include "SfmlSprite.hpp"
#include "SfmlTexture.hpp"
#include "SfmlFont.hpp"
#include "SfmlText.hpp"

auto& SfmlResourceFactory::GetTupleOfMaps() {
    static std::tuple resourcesMaps {
        &textures,
        &fonts
    };
    
    return resourcesMaps;
}

template <class Interface, class Implementation>
SfmlResourceFactory::ReturnLoadT<Interface>
SfmlResourceFactory::Load(std::string const& resourceName) {
    using MapType = ResourceMapType<Interface>*;
    auto& resourceMap = std::get<MapType>(GetTupleOfMaps());
    
    if(resourceMap->find(resourceName) == resourceMap->end()) {
        std::unique_ptr<Interface> sfmlResource = std::make_unique<Implementation>();
        sfmlResource->LoadFromFile(resourceName);
        return resourceMap->insert({resourceName, std::move(sfmlResource)});
    }
    return ReturnLoadT<Interface>{{}, false};
}

SfmlResourceFactory::SfmlResourceFactory(std::string const& resourcesFolder)
: resourcesFolder(resourcesFolder)
{

}

ITexture* SfmlResourceFactory::GetTexture(std::string const& textureName) {
    std::string fullName = resourcesFolder + "Textures/" + textureName + ".png";
    auto [it, ok] = Load<ITexture, SfmlTexture>(fullName);
    
    if(ok) {
        return it->second.get();
    }
    return textures[fullName].get();
}

IFont* SfmlResourceFactory::GetFont(std::string const& fontName) {
    std::string fullName = resourcesFolder + "Fonts/" + fontName + ".otf";
    auto [it, ok] = Load<IFont, SfmlFont>(fullName);
    
    if(ok) {
        return it->second.get();
    }
    return fonts[fontName].get();
}

std::unique_ptr<IText> SfmlResourceFactory::MakeText(std::string const& text) {
    std::unique_ptr<IText> sfmlText = std::make_unique<SfmlText>();
    sfmlText->Init("CubicPixel-lgEmy");
    sfmlText->SetText(text);
    return sfmlText;
}
