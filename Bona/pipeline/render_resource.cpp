#include "render_resource.h"

namespace Michael
{
    RenderResource::RenderResource(const int& width, const int& height)
    {
        tex_width = width;
        tex_height = height;

        color_buffer.resize(tex_width * tex_height * 4, 0);
    }

    RenderResource::~RenderResource()
    {

    }

    void RenderResource::set_color_buffer(int x, int y, const Color& c)
    {
        if (!color_buffer.size() || x < 0 || y < 0 || x >= tex_width || y >= tex_height)
            return;

        std::uint8_t rgba[4] = { c.r, c.g, c.b, c.a };
        memcpy(color_buffer.data() + (x + y * tex_width) * 4, rgba, 4);
    }

    void RenderResource::clear_color_buffer(Color color)
    {
        // 每个像素占 4 字节（RGBA）
        constexpr size_t bytes_per_pixel = 4;

        // 验证缓冲区大小是否为像素字节数的整数倍（避免越界）
        assert(color_buffer.size() % bytes_per_pixel == 0 && "Color buffer size is not a multiple of bytes per pixel (RGBA).");

        // 如果缓冲区为空，直接返回
        if (color_buffer.empty()) return;

        // 填充颜色数据
        const size_t num_pixels = color_buffer.size() / bytes_per_pixel;
        for (size_t i = 0; i < num_pixels; ++i)
        {
            // 计算当前像素在缓冲区中的起始位置
            const size_t offset = i * bytes_per_pixel;

            // 写入 RGBA 分量
            color_buffer[offset + 0] = color.r; // R
            color_buffer[offset + 1] = color.g; // G
            color_buffer[offset + 2] = color.b; // B
            color_buffer[offset + 3] = color.a; // A
        }
    }

    void RenderResource::color_buffer_flip_vertically()
    {
        // 每个像素占 4 字节（RGBA）
        constexpr size_t bytes_per_pixel = 4;
        // 验证缓冲区大小是否为像素字节数的整数倍（避免越界）
        assert(color_buffer.size() % bytes_per_pixel == 0 && "Color buffer size is not a multiple of bytes per pixel (RGBA).");
        // 如果缓冲区为空，直接返回
        if (color_buffer.empty()) return;
        // 获取宽度和高度
        int width = tex_width;
        int height = tex_height;
        // 逐行交换颜色数据
        for (int y = 0; y < height / 2; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                // 计算当前像素在缓冲区中的起始位置
                size_t top_offset = (x + y * width) * bytes_per_pixel;
                size_t bottom_offset = (x + (height - 1 - y) * width) * bytes_per_pixel;
                // 交换 RGBA 分量
                for (size_t i = 0; i < bytes_per_pixel; ++i)
                {
                    std::swap(color_buffer[top_offset + i], color_buffer[bottom_offset + i]);
                }
            }
        }
    }
}
