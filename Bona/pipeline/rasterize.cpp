#include "rasterize.h"

namespace Michael
{
    Rasterize::Rasterize(const InputAssembler::Ptr& input, const RenderResource::Ptr& resource)
    {
        m_render_resource = resource;
		m_input_assembler = input;

        //TGAColor red = { 255,   0, 0, 255 };
        //draw_line(0, 0, 0, 0, red);
        //draw_line(56, 56, 56, 56, red);

        //for (int i = 0; i < m_input_assembler->nfaces(); i++)
        //{
        //    auto [ax, ay] = project(m_input_assembler->vert(i, 0));
        //    auto [bx, by] = project(m_input_assembler->vert(i, 1));
        //    auto [cx, cy] = project(m_input_assembler->vert(i, 2));

        //    TGAColor red = {255,   0, 0, 255 };

        //    //draw_line(ax, ay, bx, by, red);
        //    //draw_line(bx, by, cx, cy, red);
        //    //draw_line(cx, cy, ax, ay, red);
        //    

        //}
    }

    std::tuple<int, int> Rasterize::project(vec3 v) { // First of all, (x,y) is an orthogonal projection of the vector (x,y,z).
        return { (v.x + 1.) * 800 / 2,   // Second, since the input models are scaled to have fit in the [-1,1]^3 world coordinates,
                 (v.y + 1.) * 800 / 2 }; // we want to shift the vector (x,y) and then scale it to span the entire screen.
    }

    Rasterize::~Rasterize()
    {
        m_render_resource.reset();
	}

    void Rasterize::draw_line(int ax, int ay, int bx, int by, TGAColor color)
    {
        /*bool steep = std::abs(ax - bx) < std::abs(ay - by);
        if (steep)
        {
            std::swap(ax, ay);
            std::swap(bx, by);
        }

        if (ax > bx)
        {
            std::swap(ax, bx);
            std::swap(ay, by);
        }
        int y = ay;
        int ierror = 0;

        for (int x = ax; x <= bx; x++)
        {
            if (steep)
            {
                m_render_resource->set_color_buffer(y, x, color);
            }
            else
            {
                m_render_resource->set_color_buffer(x, y, color);
            }

            ierror += 2 * std::abs(by - ay);
            if (ierror > bx - ax)
            {
                y += by > ay ? 1 : -1;
                ierror -= 2 * (bx - ax);
            }
        }*/
    }
}
