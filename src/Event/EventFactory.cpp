#include "Event/EventFactory.h"

using namespace RebeccaUI;

//  Declare functions here
std::unique_ptr<IEvent> EventFactory::createEvent(int eventId) {
    auto facIter = eventFactories.find(eventId);
    if (facIter != eventFactories.end()) {
        return facIter->second();
    }
    else {
        return nullptr;
    }
}

bool EventFactory::registerEvent(int eventId, EventFunc func) {
    auto facIter = eventFactories.find(eventId);
    if (facIter != eventFactories.end()) {
        return false;
    }
    else {
        eventFactories.emplace(eventId, func);
        return true;
    }
}
