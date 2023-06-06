#include "buffer.h"

#include <stdlib.h>
#include <string.h>

unsigned long size_of_u32_array_(u16 width, u16 height) {
    return sizeof(u32) * width * height;
}

int check_pt_bounds_(buffer_t* this, u16 x, u16 y) {
    return x >= 0 && x < this->width && y >= 0 && y < this->height;
}

void safe_set_px_(buffer_t* this, u16 offset, u32 color) {
    if (offset <= this->width * this->height) {
        this->ptr[offset] = color;
    }
}

unsigned long buffer_sizeof(buffer_t* this) {
    return size_of_u32_array_(this->width, this->height);
}

void buffer_fill(buffer_t* this, u32 color) {
    memset(this->ptr, color, buffer_sizeof(this));
}

void buffer_clear(buffer_t* this) {
    buffer_fill(this, 0x00000000);
}

buffer_t buffer_make(u16 width, u16 height) {
    buffer_t buf;
    buf.width = width;
    buf.height = height;
    buf.ptr = malloc(buffer_sizeof(&buf));
    buffer_clear(&buf);

    return buf;
}

void buffer_fill_pixel(buffer_t* this, u16 x, u16 y, u32 color) {
    safe_set_px_(this, y * this->height + x, color);
}

void buffer_fill_rect(buffer_t* this, u16 x1, u16 y1, u16 width, u16 height, u32 color) {
    if (x1 >= this->width || y1 >= this->height) {
        return;
    }

    if (x1 < 0) {
        width += x1;
        x1 = 0;
    }
    if (y1 < 0) {
        height += y1;
        y1 = 0;
    }

    if (width <= 0 || height <= 0)
        return;
    
    for (int y = 0; y < height - 1 && y + y1 < this->height; y++) {
        for (int x = 0; x < width - 1 && x + x1 < this->width; x++) {
            buffer_fill_pixel(this, x1 + x, y1 + y, color);
        }
    }
}