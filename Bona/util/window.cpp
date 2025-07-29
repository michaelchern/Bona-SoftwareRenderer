#include "window.h"

namespace Michael
{
    Window::Window(const int& width, const int& height)
    {
        m_width = width;
        m_height = height;

        // 设置SDL日志优先级为VERBOSE（详细模式），会输出更多调试信息
        // SDL_LOG_PRIORITY_VERBOSE是最低优先级（最详细），其他级别如DEBUG/INFO/WARNING/ERROR/CRITICAL
        SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);

        // SDL_WINDOW_RESIZABLE：窗口可调整大小（可选标志）
        m_window = SDL_CreateWindow("Bona", m_width, m_height, SDL_WINDOW_RESIZABLE);

        // 检查窗口是否创建成功（指针非空表示成功）
        if (!m_window)
        {
            SDL_Log("Could not create a window: %s", SDL_GetError());
            SDL_Quit();
        }

        // 将窗口居中显示在屏幕上
        // SDL_WINDOWPOS_CENTERED：特殊值，表示自动计算到屏幕中心的位置
        SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

        m_renderer = SDL_CreateRenderer(m_window, nullptr);
        if (!m_renderer)
        {
            SDL_Log("Create renderer failed: %s", SDL_GetError());
        }
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    bool Window::should_close()
    {
        return m_run;
    }

    void Window::poll_events()
    {
        // 阻塞等待事件（会挂起线程直到有事件到达，节省CPU资源）
        // 对比SDL_PollEvent（非阻塞，立即返回，无事件时返回false）
        SDL_WaitEvent(&m_event);

        switch (m_event.type)
        {
            case SDL_EVENT_QUIT:
            {
                m_run = false;
                break;
            }

            case SDL_EVENT_KEY_DOWN:
            {
                break;
            }

            case SDL_EVENT_WINDOW_EXPOSED:
            {
                break;
            }
        }

        //SDL_Log("Event: %d", m_event.type);
    }
}
