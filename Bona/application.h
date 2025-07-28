#pragma once

#include "util/window.h"
#include "pipeline/input_assembler.h"

namespace Michael
{
    class Application
    {
    public:
        Application() = default;
        ~Application() = default;

        void run();

    private:
        void init();
        void mainLoop();
        void render();
        void cleanUp();

    private:
        unsigned int m_width{ 700 };
        unsigned int m_height{ 700 };

        Window::Ptr         m_window         { nullptr };
        InputAssembler::Ptr m_inputAssembler { nullptr };

    private:
    };
}
