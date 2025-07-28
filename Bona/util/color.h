#pragma once

#include <cassert>
#include "tgaimage.h"

namespace Michael
{
    class Color
    {
    public:
        uint8_t r, g, b, a;
        Color();
        Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 255);
        Color(const TGAColor& tga_color);

        static uint8_t MAX_CHANNEL_VALUE;
        static Color White;
        static Color Red;
        static Color Green;
        static Color Blue;
        static Color Black;

        uint8_t& operator[](const size_t i);

        uint8_t operator[](const size_t i) const;

        Color operator+(const Color& color) const;

        Color operator*(float intensity) const;

        Color operator*(const Color& color) const;
    };
}
