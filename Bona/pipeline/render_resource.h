#pragma once

#include <memory>
#include <vector>
#include "../util/color.h"

namespace Michael
{
    class RenderResource
    {
    public:
        using Ptr = std::shared_ptr<RenderResource>;
        static Ptr create(const int& width, const int& height)
        {
            return std::make_shared<RenderResource>(width, height);
        }

        RenderResource(const int& width, const int& height);
        ~RenderResource();

        //void set_color_buffer(int x, int y, const Color& c);
        //void clear_color_buffer(Color color);
        
    public:
        int tex_width, tex_height;
        std::vector<uint8_t> color_buffer;
    };
}
