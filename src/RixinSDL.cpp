#include "../include/RixinSDL.h"

#include <thread>
#include <chrono>
#include <list>
#include <iostream>
#include <memory>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "RixinSDLContext.h"
#include "IUpdateable.h"
#include "Event/EventTypes.h"
#include "Event/SDLEventManager.h"
#include "Event/IEventRouter.h"
#include "Event/EventRouter.h"
#include "Event/EventSpace.h"

#include "MappedIndexResolver.h"

RixinSDL::RixinSDL::RixinSDL() {
    initSDL();
    initOpenGl();
    init();
}

void RixinSDL::RixinSDL::initSDL() {
    if (!SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO)) {
        std::cout << "SDL Init failed." << std::endl;
    }

    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
}

void RixinSDL::RixinSDL::initOpenGl() {
    // Nothing to be done here (at the moment)
}

void RixinSDL::RixinSDL::init() {
    windowResolver = std::make_shared<MappedIndexResolver>();

    //  The WindowManager class needs to be modified to update the resolver
    //    when a new window is created
    //  Also! The window manager depends on a specific implementation of the
    //    index resolver. IIndexResolver only allows resoling, it doesn't
    //    have methods for mapping (since not all resolvers will use a map).
    //    You need to figure out if you want to couple the two classes together
    //    that closely  or if you want to do something else.
    //    You could add a new interface, like 'IMappableIndexResolver' that
    //    allows mapping of indices.
    windowManager = std::make_unique<WindowManager>(windowResolver);
    eventFactory = std::make_shared<EventFactory>();
    eventRouter = std::make_shared<EventRouter>(windowResolver);

    // Might want to give this a 'copy' of the IndexResolver -- It makes more sense for this
    //  to resolve the window ID from the SDL window, no?
    eventManager = std::make_unique<SDLEventManager>(eventFactory, eventRouter);
}

void RixinSDL::RixinSDL::registerEvents() {
    eventFactory->registerEvent(EventTypes::CLOSE_BUTTON_PRESSED_EVENT, [](){ return std::make_unique<CloseButtonPressedEvent>();});
}

void RixinSDL::RixinSDL::mainLoop() {
    while (!gameContext.ShouldClose) {
        eventManager->ProcessEvents();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(kMainLoopDelay));
    }
}

void RixinSDL::RixinSDL::Run() {
    mainLoop();
    cleanup();
}

void RixinSDL::RixinSDL::cleanup() {
    SDL_Quit();
}
