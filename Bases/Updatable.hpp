//
// Created by User on 7/17/2022.
//



#ifndef TESTGAME_BASES_HPP
#define TESTGAME_BASES_HPP

#include "PCH.hpp"

class Updatable {
  public:
    virtual void Update() = 0;
    virtual ~Updatable() = default;
};

#endif // TESTGAME_BASES_HPP
