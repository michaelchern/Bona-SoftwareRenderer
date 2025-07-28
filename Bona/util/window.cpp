#include "window.h"

namespace Michael
{
    Window::Window(const int& width, const int& height)
    {
        m_width = width;
        m_height = height;

        // ��ʼ��SDL��Ƶ��ϵͳ
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
            throw std::runtime_error("SDL��ʼ��ʧ��: " + std::string(SDL_GetError()));
        }

        // ����SDL��־���ȼ�ΪVERBOSE����ϸģʽ������������������Ϣ
        // SDL_LOG_PRIORITY_VERBOSE��������ȼ�������ϸ��������������DEBUG/INFO/WARNING/ERROR/CRITICAL
        SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);

        // SDL_WINDOW_RESIZABLE�����ڿɵ�����С����ѡ��־��
        m_window = SDL_CreateWindow("Bona", m_width, m_height, SDL_WINDOW_RESIZABLE);

        // ��鴰���Ƿ񴴽��ɹ���ָ��ǿձ�ʾ�ɹ���
        if (!m_window)
        {
            SDL_Log("Could not create a window: %s", SDL_GetError());
            SDL_Quit();
        }

        // �����ھ�����ʾ����Ļ��
        // SDL_WINDOWPOS_CENTERED������ֵ����ʾ�Զ����㵽��Ļ���ĵ�λ��
        SDL_SetWindowPosition(m_window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }

    Window::~Window()
    {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    bool Window::shouldClose()
    {
        return m_run;
    }

    void Window::pollEvents()
    {
        // �����ȴ��¼���������߳�ֱ�����¼������ʡCPU��Դ��
        // �Ա�SDL_PollEvent�����������������أ����¼�ʱ����false��
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

        SDL_Log("Event: %d", m_event.type);
    }
}
