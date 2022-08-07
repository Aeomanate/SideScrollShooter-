//
// Created by User on 8/7/2022.
//

#ifndef MAIN_CPP_VECTOR2_HPP
#define MAIN_CPP_VECTOR2_HPP

template <class T>
class Vector2 {
  public:
    Vector2(T x, T y): x(x), y(y) { }
    
    T x, y;
};

using Vector2f = Vector2<float>;
using Vector2u = Vector2<unsigned>;
using Vector2i = Vector2<int>;

#endif //MAIN_CPP_VECTOR2_HPP
