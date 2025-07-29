#include "rasterize.h"

namespace Michael
{
    Rasterize::Rasterize(const InputAssembler::Ptr& input, const RenderResource::Ptr& resource)
    {
        m_render_resource = resource;
		m_input_assembler = input;

        for (int i = 0; i < m_input_assembler->nfaces(); i++)
        {
            auto [ax, ay] = project(m_input_assembler->vert(i, 0));
            auto [bx, by] = project(m_input_assembler->vert(i, 1));
            auto [cx, cy] = project(m_input_assembler->vert(i, 2));

            //draw_line(ax, ay, bx, by, Color::Red);
            //draw_line(bx, by, cx, cy, Color::Red);
            //draw_line(cx, cy, ax, ay, Color::Red);
            Color rnd;
            for (int c = 0; c < 3; c++) rnd[c] = std::rand() % 255;
			rasterize_triangle(ax, ay, bx, by, cx, cy, rnd);
        }

        m_render_resource->color_buffer_flip_vertically();
    }

    std::tuple<int, int> Rasterize::project(vec3 v) { // First of all, (x,y) is an orthogonal projection of the vector (x,y,z).
        return { (v.x + 1.) * 800 / 2,   // Second, since the input models are scaled to have fit in the [-1,1]^3 world coordinates,
                 (v.y + 1.) * 800 / 2 }; // we want to shift the vector (x,y) and then scale it to span the entire screen.
    }

    Rasterize::~Rasterize()
    {
        m_render_resource.reset();
	}

    void Rasterize::draw_line(int ax, int ay, int bx, int by, Color color)
    {
        bool steep = std::abs(ax - bx) < std::abs(ay - by);
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
        }
    }

    void Rasterize::rasterize_triangle(int ax, int ay, int bx, int by, int cx, int cy, Color color)
    {
        int bbminx = std::min(std::min(ax, bx), cx); // bounding box for the triangle
        int bbminy = std::min(std::min(ay, by), cy); // defined by its top left and bottom right corners
        int bbmaxx = std::max(std::max(ax, bx), cx);
        int bbmaxy = std::max(std::max(ay, by), cy);
        double total_area = signed_triangle_area(ax, ay, bx, by, cx, cy);
        if (total_area < 1) return; // backface culling + discarding triangles that cover less than a pixel

#pragma omp parallel for
        for (int x = bbminx; x <= bbmaxx; x++)
        {
            for (int y = bbminy; y <= bbmaxy; y++)
            {
                double alpha = signed_triangle_area(x, y, bx, by, cx, cy) / total_area;
                double beta = signed_triangle_area(x, y, cx, cy, ax, ay) / total_area;
                double gamma = signed_triangle_area(x, y, ax, ay, bx, by) / total_area;
                if (alpha < 0 || beta < 0 || gamma < 0) continue; // negative barycentric coordinate => the pixel is outside the triangle
                m_render_resource->set_color_buffer(x, y, color);
            }
        }
    }

    double Rasterize::signed_triangle_area(int ax, int ay, int bx, int by, int cx, int cy) {
        return .5 * ((by - ay) * (bx + ax) + (cy - by) * (cx + bx) + (ay - cy) * (ax + cx));
    }
}
