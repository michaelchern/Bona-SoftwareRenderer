#include "frame_buffer.h"

namespace Michael
{
    FrameBuffer::FrameBuffer(const int& width, const int& height, const Window::Ptr& window, const RenderResource::Ptr& resource)
    {
        tex_width = width;
        tex_height = height;
        m_render_resource = resource;

        m_texture = SDL_CreateTexture(window->getRenderer(),
                                      SDL_PIXELFORMAT_RGBA8888,
                                      SDL_TEXTUREACCESS_STREAMING,
                                      tex_width,
                                      tex_height);

        if (!m_texture)
        {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateTexture failed: %s", SDL_GetError());
        }
    }

    FrameBuffer::~FrameBuffer()
    {
        SDL_DestroyTexture(m_texture);
    }

    void FrameBuffer::update_frame_buffer()
    {
        void* pixels;
        int pitch;
        SDL_LockTexture(m_texture, NULL, &pixels, &pitch);
        memcpy(pixels, m_render_resource->color_buffer.data(), tex_width * tex_height * sizeof(uint32_t));
        SDL_UnlockTexture(m_texture);
    }
}
