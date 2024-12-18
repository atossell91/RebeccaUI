#pragma once

#include <memory>

#include "Window/IWindow.h"
#include "Drawing/IGraphics.h"

#include "Event/Event.h"
#include "Event/EventData/WindowCloseButtonClickedEventData.h"
#include "Event/EventData/MouseMovedEventData.h"
#include "Event/EventData/MouseButtonEventData.h"
#include "Event/EventData/KeyboardEventData.h"

namespace NSLyndsayUI {
    class CustomWindow : public IWindow {
    private:
        //  Private stuff here
        std::unique_ptr<IWindow> platformWindow;
    public:
        //  Public stuff here
        int GetWindowId() { return platformWindow->GetWindowId(); }
        void Close() {}
        IGraphics* GetGraphics() { 
            return platformWindow->GetGraphics();
        }

        virtual void Setup() {}

        Event<WindowCloseButtonClickedEventData> CloseButtonPressed;
        Event<MouseButtonEventData> MouseButtonDown;
        Event<MouseButtonEventData> MouseButtonUp;
        Event<MouseMovedEventData> MouseMoved;
        Event<KeyboardEventData> KeyDown;
        Event<KeyboardEventData> KeyUp;

        friend class CustomWindowFactory;
    };
} // NSLyndsayUI
