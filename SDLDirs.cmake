set(SDL_DIR ${CMAKE_SOURCE_DIR}/../SDL)
set(SDL_IMAGE_DIR ${CMAKE_SOURCE_DIR}/../SDL_image)

if (WIN32)
    set(SDL_LIB ${SDL_DIR}/build/SDL3.dll)
    set(SDL_IMAGE_LIB ${SDL_IMAGE_DIR}/build/SDL3.dll)
else()
    set(SDL_LIB ${SDL_DIR}/build/libSDL3.so)
    set(SDL_IMAGE_LIB ${SDL_IMAGE_DIR}/build/libSDL3.so)
endif()
