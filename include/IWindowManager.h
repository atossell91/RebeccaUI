#pragma once

namespace RixinSDL {
    class IWindowManager {
    public:
        virtual ~IWindowManager() {}
        //  Public stuff here
        virtual void Update() = 0;
        virtual void GetWindow(int windowId) = 0;
        virtual void AddWindow() = 0;
        virtual void RemoveWindow(int windowId) = 0;
    };
} // RixinSDL