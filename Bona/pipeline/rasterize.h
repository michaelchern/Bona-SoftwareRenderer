#pragma once

#include <memory>

namespace Michael
{
    class Rasterize
    {
    public:
        using Ptr = std::shared_ptr<Rasterize>;
        static Ptr create()
        {
            return std::make_shared<Rasterize>();
        }

        Rasterize();
        ~Rasterize();
        void line(int ax, int ay, int bx, int by, TGAImage& framebuffer, TGAColor color);
    private:
        
    };
    
} 