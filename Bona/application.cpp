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

        load_data();
        set_render_state();

        
        

        m_frame_buffer = FrameBuffer::create(m_width, m_height, m_window, m_render_resource);
        m_rasterize = Rasterize::create(m_input_assembler, m_render_resource);

        
    }

    void Application::load_data()
    {
        m_input_assembler = InputAssembler::create("assets/models/diablo3_pose/diablo3_pose.obj");
        m_render_resource = RenderResource::create(m_width, m_height);
    }

    void Application::set_render_state()
    {
        // 设置渲染状态，比如启用深度测试、混合等
        // 目前没有实现具体的渲染状态设置逻辑
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
