#include <list>
#include <string>
#include <memory>
#include <thread>

#include "../include/Window.h"
#include "../include/WindowThread.h"

namespace RixinSDL
{
    class WindowManager {
     private:
        std::list<WindowThread> windows;
     public:
        void AddWindow(const std::string& name, int width, int height);
        void CloseWindow(int sdlWinId);
        int GetNumWindows() const { return windows.size(); }
        void UpdateAll();
    };
} // namespace RixinSDL
