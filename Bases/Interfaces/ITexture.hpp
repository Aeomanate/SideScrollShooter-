//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_ITEXTURE_HPP
#define MAIN_CPP_ITEXTURE_HPP

#include "PCH.hpp"
#include "IDestructable.hpp"
#include "Vector2.hpp"

class ITexture: public IDestructable {
  public:
    virtual void LoadFromFile(std::string const& textureName) = 0;
    virtual Vector2u GetSize() = 0;
};

#endif //MAIN_CPP_ITEXTURE_HPP
