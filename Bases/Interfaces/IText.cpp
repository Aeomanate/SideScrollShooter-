// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
//
// Created by User on 8/7/2022.
//

#include "IText.hpp"

Color IText::GetColor() const {
    return color;
}

void IText::SetColor(Color newColor) {
    color = newColor;
}

void IText::SetFont(IFont* newFont) {
    font = newFont;
}

IFont* IText::GetFont() const {
    return font;
}

