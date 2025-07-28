#include "application.h"

namespace Michael
{
    void Application::run()
    {
        init();
        main_loop();
        clean_up();
    }

    void Application::init()
    {
        m_window = Window::create(m_width, m_height);

        m_input_assembler = InputAssembler::create("assets/models/african_head/african_head.obj");
        m_render_resource = RenderResource::create(m_width, m_height);

        m_frame_buffer = FrameBuffer::create(m_width, m_height, m_window, m_render_resource);

        m_rasterize = Rasterize::create(m_input_assembler, m_render_resource);
    }

    void Application::main_loop()
    {
        while(m_window->should_close())
        {
            m_window->poll_events();

            render();
        }
    }

    void Application::render()
    {
        m_frame_buffer->update_frame_buffer();

        SDL_RenderClear(m_window->getRenderer());
        SDL_RenderTexture(m_window->getRenderer(), m_frame_buffer->getTexture(), NULL, NULL);
        SDL_RenderPresent(m_window->getRenderer());
    }

    void Application::clean_up()
    {
        m_window.reset();
    }
}
