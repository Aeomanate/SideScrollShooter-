// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 7/17/2022.
//

#include "Bases.hpp"

sf::Vector2f operator+(sf::Vector2f left, float value) {
    return {left.x + value, left.x + value};
}
