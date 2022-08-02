//
// Created by User on 7/17/2022.
//

#include "PCH.hpp"

// [from; to]
int RAND(int from, int to) {
    static std::mt19937 RAND;
    std::uniform_int_distribution range(from, to);
    return range(RAND);
}
