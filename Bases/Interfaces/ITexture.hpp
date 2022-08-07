//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_ITEXTURE_HPP
#define MAIN_CPP_ITEXTURE_HPP

#include "PCH.hpp"
#include "ILoadable.hpp"
#include "Vector2.hpp"

class ITexture: public ILoadable {
  public:
    virtual Vector2u GetSize() = 0;
};

#endif //MAIN_CPP_ITEXTURE_HPP
