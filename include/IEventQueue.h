#pragma once

#include <queue>
#include <memory>
#include <mutex>

#include "IEvent.h"

namespace RixinSDL {
    class IEventQueue {
    public:
        virtual ~IEventQueue() {}
        //  Public stuff here
        virtual void queueEvent(std::unique_ptr<IEvent> event) = 0;
        virtual std::unique_ptr<IEvent> getEvent() = 0;
    };
} // EventQueue