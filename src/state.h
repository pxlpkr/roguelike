#include <SDL.h>

#include "buffer.h"
#include "shorttype.h"

#ifndef r_STATE_H
#define r_STATE_H

struct {
    struct {
        u16 width;
        u16 height;

        u16 max_fps;

        char* title;

        buffer_t buffer;
    } window;

    struct {
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
    } sdl;

    int exit_requested;
} state;

void state_init(void);
void state_destroy(void);

#endif