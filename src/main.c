#include <time.h>

#include "state.h"
#include "renderer.h"

void poll_events(void) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                state.exit_requested = 1;
                break;
        }
    }
}

int main() {
    state_init();
    
    while (!state.exit_requested) {
        clock_t start = clock();

        poll_events();

        renderer_render();

        /* Delay next frame to ensure MAX_FPS frames happen in one second
        //      * Consider execution time of previous frame to prevent unnecessary waiting */
        clock_t end = clock();
        double time_elapsed = (double) (end - start) * 1000.0 / CLOCKS_PER_SEC;

        double delay_nanos = 1000000000 / state.window.max_fps - time_elapsed * 1000000;
        if (delay_nanos > 0) {
            struct timespec delay = {0, delay_nanos};
            nanosleep(&delay, NULL);
        }
    }

    state_destroy();

    return 0;
}