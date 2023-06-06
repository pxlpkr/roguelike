#include <SDL.h>

#include "window.h"
#include "state.h"

void window_initialize(void) {
    state.sdl.window = SDL_CreateWindow(
        state.window.title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        state.window.width,
        state.window.height,
        SDL_WINDOW_ALLOW_HIGHDPI
    );

    state.sdl.renderer = SDL_CreateRenderer(
        state.sdl.window,
        -1,
        0
    );

    state.sdl.texture = SDL_CreateTexture(
        state.sdl.renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        state.window.width,
        state.window.height
    );
}

void window_destroy(void) {
    SDL_DestroyWindow(state.sdl.window);
    SDL_DestroyRenderer(state.sdl.renderer);
    SDL_DestroyTexture(state.sdl.texture);
}