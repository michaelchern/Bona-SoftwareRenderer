#pragma once

#include "util/window.h"
#include "util/frame_buffer.h"
#include "pipeline/input_assembler.h"
#include "pipeline/render_resource.h"
#include "pipeline/rasterize.h"

namespace Michael
{
    class Application
    {
    public:
        Application()  = default;
        ~Application() = default;

        void run();

    private:
        void init();
        void load_data();
        void set_render_state();
        void main_loop();
        void render();
        void clean_up();

    private:
        unsigned int m_width  { 800 };
        unsigned int m_height { 800 };

        Window::Ptr         m_window          { nullptr };
        InputAssembler::Ptr m_input_assembler { nullptr };
        RenderResource::Ptr m_render_resource { nullptr };
        FrameBuffer::Ptr    m_frame_buffer    { nullptr };
        Rasterize::Ptr      m_rasterize       { nullptr };
    };
}
