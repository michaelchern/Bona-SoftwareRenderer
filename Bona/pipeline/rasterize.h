#pragma once

#include <memory>
#include "render_resource.h"
#include "input_assembler.h"

namespace Michael
{
    class Rasterize
    {
    public:
        using Ptr = std::shared_ptr<Rasterize>;
        static Ptr create(const InputAssembler::Ptr& input, const RenderResource::Ptr& resource)
        {
            return std::make_shared<Rasterize>(input, resource);
        }

        Rasterize(const InputAssembler::Ptr& input, const RenderResource::Ptr& resource);
        ~Rasterize();

        std::tuple<int, int> project(vec3 v);

        double signed_triangle_area(int ax, int ay, int bx, int by, int cx, int cy);

        void draw_line(int ax, int ay, int bx, int by, Color color);

        void rasterize_triangle(int ax, int ay, int bx, int by, int cx, int cy, Color color);

    public:
        InputAssembler::Ptr m_input_assembler = nullptr;
        RenderResource::Ptr m_render_resource = nullptr;
    };
}
