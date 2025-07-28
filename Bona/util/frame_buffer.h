#pragma once

#include <SDL3/SDL.h>
#include "window.h"
#include "../pipeline/render_resource.h"

namespace Michael
{
    class FrameBuffer
    {
    public:
        using Ptr = std::shared_ptr<FrameBuffer>;
        static Ptr create(const int& width, const int& height, const Window::Ptr& window, const RenderResource::Ptr& resource)
        {
            return std::make_shared<FrameBuffer>(width, height, window, resource);
        }

        FrameBuffer(const int& width, const int& height, const Window::Ptr& window, const RenderResource::Ptr& resource);
        ~FrameBuffer();

        void update_frame_buffer();

        [[nodiscard]] auto getTexture() const { return m_texture; }

    public:
        int                 tex_width { 0 };
        int                 tex_height{ 0 };
        SDL_Texture*        m_texture         = nullptr;
        RenderResource::Ptr m_render_resource = nullptr;
    };
}
