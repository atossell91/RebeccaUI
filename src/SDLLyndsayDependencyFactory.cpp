#include "SDLLyndsayDependencyFactory.h"

#include <memory>
#include <iostream>

#include "Utils.h"
#include "Window/WindowManager.h"
#include "Window/WindowFactory.h"
#include "Window/SDLWindowFactory.h"
#include "Event/EventQueue.h"
#include "Event/ThreadEventManager.h"
#include "Event/SDLEventManager.h"
#include "Event/ExecutiveEventProcessor.h"
#include "Event/SDLEventManagerFactory.h"

using namespace LyndsayUI;

void SDLLyndsayDependencyFactory::setupEvents() {

}

void SDLLyndsayDependencyFactory::build() {
    auto evMgrFac = std::make_unique<SDLEventManagerFactory>();

    // Create a window factory
    std::unique_ptr<IPlatformWindowFactory> platWinFac = std::make_unique<SDLWindowFactory>();
    std::unique_ptr<IEventManagerFactory> platEvMgrFac = std::make_unique<SDLEventManagerFactory>();
    auto winFac = std::make_unique<WindowFactory>(
        std::move(platWinFac),
        std::move(platEvMgrFac)
    );

    // Assemble
    auto winMgr = std::make_unique<WindowManager>(
        std::move(winFac)
    );

    //  Create the thread event manager
    auto evQueue = std::make_unique<EventQueue>();
    auto trMgr = std::make_unique<ThreadEventManager>(
        std::move(evQueue)
    );

    // Create the SDL thread manager
    auto tmpEvMgr = evMgrFac->CreateEventManager();
    auto platMgr = Utils::CastUniquePtr<IEventManager, SDLEventManager>(std::move(tmpEvMgr));

    // Setup events
    platMgr->WindowCloseButtonClickedEvent.AddEventHandler([wPtr = winMgr.get()](auto data){
        std::cout << "Miko!" << std::endl;
        wPtr->WindowCloseButtonClickedEvent.Raise(data);
    });

    // Assemble the executive event processor
    auto evMgr = std::make_unique<ExecutiveEventProcessor>(
        std::move(trMgr),
        std::move(platMgr)
    );

    windowManager = std::move(winMgr);
    eventProcessor = std::move(evMgr);
}
