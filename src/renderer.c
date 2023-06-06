#include "renderer.h"

#include "state.h"
#include "buffer.h"

void renderer_render(void) {
    buffer_clear(&state.window.buffer);

    buffer_fill_rect(&state.window.buffer, 20, 20, 40, 40, 0xFF0000FF);

    SDL_UpdateTexture(
        state.sdl.texture, NULL, state.window.buffer.ptr, state.window.buffer.width * 4
    );
    SDL_RenderCopy(state.sdl.renderer, state.sdl.texture, NULL, NULL);

    SDL_RenderPresent(state.sdl.renderer);
}