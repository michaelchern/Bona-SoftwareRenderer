#include "application.h"

namespace Michael
{
    void Application::run()
    {
        init();
        mainLoop();
        cleanUp();
    }

    void Application::init()
    {
        m_window = Window::create(m_width, m_height);
        //m_inputAssembler = InputAssembler::create("assts/to/your/model.obj");
    }

    void Application::mainLoop()
    {
        while(m_window->shouldClose())
        {
            m_window->pollEvents();

            render();
        }
    }

    void Application::render()
    {
		m_window->Present();
    }

    void Application::cleanUp()
    {
        m_window.reset();
    }
}
