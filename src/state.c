#include "state.h"

#include "window.h"
#include "buffer.h"
#include "shorttype.h"

u_long get_buf_size(void) {
    return sizeof(u32) * state.window.width * state.window.height;
}

void state_init(void) {
    state.window.width = 800;
    state.window.height = 800;

    state.window.max_fps = 60;

    state.window.title = "Window";

    state.window.buffer = buffer_make(state.window.width, state.window.height);

    state.exit_requested = 0;

    window_initialize();
}

void state_destroy(void) {
    window_destroy();
}