#pragma once

#include <thread>
#include <memory>

#include "Window/Window.h"

namespace RixinSDL
{
    class WindowThread {
    public:
        bool windowOpened = false;
        Window* window = nullptr;
        std::unique_ptr<std::thread> thread = nullptr;
    };
} // namespace RixinSDL
