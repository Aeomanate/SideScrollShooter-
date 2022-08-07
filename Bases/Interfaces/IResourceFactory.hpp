//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_IRESOURCEFACTORY_HPP
#define MAIN_CPP_IRESOURCEFACTORY_HPP

#include "ITexture.hpp"
#include "IFont.hpp"
#include "IText.hpp"

class IResourceFactory {
  public:
    virtual ITexture* GetTexture(std::string const& textureName) = 0;
    virtual IFont* GetFont(std::string const& fontName) = 0;
    
    virtual std::unique_ptr<IText> MakeText(std::string const& text) = 0;
  private:
  
};

#endif //MAIN_CPP_IRESOURCEFACTORY_HPP
