#pragma once

#include "Window/IWindowFactory.h"

#include <memory>

#include "Window/IWindow.h"

namespace RebeccaUI {
    class SDLWindowFactory : public IWindowFactory{
    private:
        //  Private stuff here
    public:
        //  Public stuff here
        std::unique_ptr<IWindow> CreateSynchronousWindow();
        std::unique_ptr<IWindow> CreateAsynchronousWindow();
    };
} // RebeccaUI
