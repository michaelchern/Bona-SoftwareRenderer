#include "render_resource.h"

namespace Michael
{
    RenderResource::RenderResource(const int& width, const int& height)
    {
        tex_width = width;
        tex_height = height;
    }

    RenderResource::~RenderResource()
    {

    }

    //void RenderResource::set_color_buffer(int x, int y, const Color& c)
    //{
    //    if (!color_buffer.size() || x < 0 || y < 0 || x >= width || y >= height)
    //        return;

    //    //memcpy(color_buffer.data() + (x + y * width) * 4,  c, 4);
    //}

//    void RenderResource::clear_color_buffer(TGAColor color)
//    {
//        /*int num_pixels = this->width * this->height;
//        int i;
//        for (i = 0; i < num_pixels; i++)
//{
//            this->color_buffer[i * 4 + 0] = color.r * 255;
//            this->color_buffer[i * 4 + 1] = color.g * 255;
//            this->color_buffer[i * 4 + 2] = color.b * 255;
//            this->color_buffer[i * 4 + 3] = color.a * 255;
//        }*/
//    }
}
