#pragma once

//#include "color.h"

namespace Michael
{
    class FrameBuffer
    {
    public:
        FrameBuffer(int width, int height);
        ~FrameBuffer();

        int width, height;
        unsigned char* color_buffer;
        float* depth_buffer;

        void set_depth(int x, int y, float depth);
        float get_depth(int x, int y);
        //void set_color(int x, int y, Color color);
        //Color get_color(int x, int y);

        void renderbuffer_release();
        //void renderbuffer_clear_color(Color color);
        void renderbuffer_clear_depth(float depth);
    };
}
