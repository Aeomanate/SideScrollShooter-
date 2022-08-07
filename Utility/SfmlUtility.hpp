//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_SFMLUTILITY_HPP
#define MAIN_CPP_SFMLUTILITY_HPP

#include "Color.hpp"

inline sf::Color toSf(Color c) {
    return {c.r, c.g, c.b, c.a};
}


#endif // MAIN_CPP_SFMLUTILITY_HPP
