//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_ILOADABLE_HPP
#define MAIN_CPP_ILOADABLE_HPP

#include "PCH.hpp"
#include "IDestructable.hpp"

class ILoadable: public IDestructable {
    friend class SfmlResourceFactory;
  public:
    ILoadable() = default;
    
  private:
    virtual void LoadFromFile(std::string const& textureName) = 0;
    
    ILoadable(ILoadable const&) = delete;
    ILoadable& operator=(ILoadable const&) = delete;
};

#endif //MAIN_CPP_ILOADABLE_HPP
