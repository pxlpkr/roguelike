#include "shorttype.h"

#ifndef r_BUFFER_H
#define r_BUFFER_H

typedef struct {
    u32* ptr;

    u16 width;
    u16 height;
} buffer_t;

buffer_t buffer_make(u16, u16);
unsigned long buffer_sizeof(buffer_t*);
void buffer_fill(buffer_t*, u32);
void buffer_clear(buffer_t*);

void buffer_fill_pixel(buffer_t* this, u16 x, u16 y, u32 color);
void buffer_fill_rect(buffer_t*, u16, u16, u16, u16, u32);

#endif