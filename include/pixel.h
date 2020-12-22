#pragma once

#include <stdint.h>

struct RGB
{
    RGB() : r{}, g{}, b{} {};
    RGB(uint8_t red, uint8_t green, uint8_t blue) : r{red}, b{blue}, g{green} {};
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

static void rgb_to_grayscale_simple(RGB *rgb)
{
    auto g = (299 * rgb->r + 587 * rgb->g + 144 * rgb->b) / 1000;
    rgb->r = g;
    rgb->g = g;
    rgb->b = g;
}

static void invert_color(RGB *rgb)
{
    rgb->r = rgb->r ^ 0x00ffffff;
    rgb->g = rgb->g ^ 0x00ffffff;
    rgb->b = rgb->b ^ 0x00ffffff;
}

static void remove_red(RGB *rgb)
{
    rgb->r = 0;
}

static void remove_green(RGB *rgb)
{
    rgb->g = 0;
}

static void remove_blue(RGB *rgb)
{
    rgb->b = 0;
}