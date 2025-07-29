#pragma once

#include <SDL3/SDL.h>
#include <iostream>
#include <stdexcept>
#include <string>

namespace Michael
{
    class Window
    {
    public:
        using Ptr = std::shared_ptr<Window>;
        static Ptr create(const int& width, const int& height)
        {
            return std::make_shared<Window>(width, height);
        }

        Window(const int& width, const int& height);

        ~Window();

        bool should_close();

        void poll_events();

        [[nodiscard]] auto getWindow() const { return m_window; }
        [[nodiscard]] auto getRenderer() const { return m_renderer; }

    private:
        int           m_width { 0 };
        int           m_height{ 0 };
        bool          m_run = true;
        SDL_Event     m_event{};
        SDL_Renderer* m_renderer = nullptr;
        SDL_Window*   m_window   = nullptr;
    };
}
