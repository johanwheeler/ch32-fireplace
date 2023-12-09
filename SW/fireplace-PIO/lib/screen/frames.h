#pragma once

#include <stdint.h>

/*
scan direction left to right
line scan backward
preset color r5g6b5
block size 16bit
*/

typedef struct
{
    const uint16_t * data;
    uint8_t numframes;
}animation_t;

uint16_t tree[64] = {
0x0000, 0x2589, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x2589, 0x2589, 0x0000, 0x2589, 0x0000, 0x0000, 0xfe01, 0x0000, 
0xff80, 0x2589, 0x2589, 0x2589, 0x2589, 0xfe01, 0xfe01, 0x0000, 
0x2589, 0x2589, 0x05bd, 0x2589, 0xe135, 0x2589, 0xfe01, 0xfe01, 
0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0x2589, 0xfe01, 0xfe01, 
0xfbe0, 0x2589, 0x2589, 0xe8e4, 0x2589, 0xfe01, 0xfe01, 0x0000, 
0x2589, 0x2589, 0x0000, 0x2589, 0x0000, 0x0000, 0xfe01, 0x0000, 
0x0000, 0x2589, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

static const uint16_t tree_idx[15] = {16, 26, 28, 40, 43, 14, 21, 22, 30, 31, 38, 39, 45, 46, 54};
static const uint16_t tree_colors[6] = {0xff80, 0x05bd, 0xe135, 0xfbe0, 0xe8e4, 0xfe01};


static const uint16_t santa[15*64] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0xe54f, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0xe8e4, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 0x0000, 
0xe54f, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 0x0000, 
0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 
0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 
0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 0x0000, 
0xe8e4, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xe54f, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xe8e4, 0x0000, 0xe54f, 0x0000, 0x0000, 0xffff, 0x0000, 
0x0000, 0x0000, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 
0x0000, 0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 
0x0000, 0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 
0x0000, 0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 
0x0000, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0xe8e4, 0x0000, 0x0000, 0xe54f, 0x0000, 0xffff, 
0x0000, 0x0000, 0x0000, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 
0x0000, 0x0000, 0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 
0x0000, 0x0000, 0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 
0x0000, 0x0000, 0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 
0x0000, 0x0000, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xe8e4, 0x0000, 0xe54f, 0x0000, 0x0000, 0xffff, 0x0000, 
0x0000, 0x0000, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 
0x0000, 0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 
0x0000, 0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 
0x0000, 0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 
0x0000, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xe54f, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0xe54f, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0xe54f, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0xe54f, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0xe54f, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0xe54f, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0xe54f, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0xe54f, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xe54f, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0xe8e4, 0x5922, 0xe8e4, 0xffff, 0xffff, 0xffff, 0xe8e4, 0xffff, 
0x0000, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0xe8e4, 
0x0000, 0xfe01, 0xffff, 0xffff, 0xe54f, 0xffff, 0xe8e4, 0xe8e4, 
0xe8e4, 0x5922, 0xffff, 0xffff, 0x9edd, 0xffff, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};



static const uint16_t reindeer[64*13] = {
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x0000, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x5922, 0x8225, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x5922, 0x8225, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5922, 0x8225, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x8225, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xe8e4, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x8225, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xe8e4, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xe8e4, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x5922, 0xe8e4, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x5922, 0xe8e4, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x0000, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x5922, 0xe8e4, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x0000, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x5922, 0xe8e4, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000, 
0x8225, 0x5922, 0x5922, 0x5922, 0x5922, 0x5922, 0xc3cb, 0xc3cb, 
0x0000, 0x5922, 0x5922, 0x5922, 0x0000, 0x5922, 0x0000, 0x0000, 
0x0000, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0x0000, 0x0000, 
0x8225, 0x8225, 0x8225, 0x5922, 0x5922, 0x5922, 0xc3cb, 0x0000, 
0x0000, 0x0000, 0x0000, 0x5922, 0x8225, 0x0000, 0xc3cb, 0xc3cb, 
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xc3cb, 0x0000
};

static const uint16_t snowman_snow[64*8] = {
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x9ac7, 0x9edd, 0x0000, 0x5371, 0x0000, 0x9edd, 
0xffff, 0x9edd, 0xffff, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xffff, 0xaf23, 0x9edd, 0xfe01, 0x5371, 
0xffff, 0xffff, 0x9ac7, 0x9edd, 0xffff, 0x5371, 0xfe01, 0x5371, 
0x9edd, 0x0000, 0x9ac7, 0x0000, 0x0000, 0x5371, 0x9edd, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x9edd, 0x0000, 0x0000, 0x5371, 0x9edd, 0x0000, 
0x9edd, 0xffff, 0xffff, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xffff, 0x9edd, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0x9edd, 0xffff, 0xffff, 0x5371, 0xfe01, 0x9edd, 
0x0000, 0x0000, 0x9ac7, 0x0000, 0x0000, 0x9edd, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9edd, 0x9ac7, 0x0000, 0x0000, 0x9edd, 0x0000, 0x0000, 
0xffff, 0xffff, 0xffff, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x9edd, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0x9edd, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0x9edd, 0x9ac7, 0xffff, 0xffff, 0x5371, 0x9edd, 0x5371, 
0x0000, 0x0000, 0x9ac7, 0x0000, 0x9edd, 0x5371, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x9edd, 0x0000, 0x9ac7, 0x0000, 0x9edd, 0x5371, 0x0000, 0x0000, 
0xffff, 0xffff, 0xffff, 0xffff, 0xaf23, 0x5371, 0x9edd, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0x9edd, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0x9edd, 0xffff, 0x9ac7, 0xffff, 0xffff, 0x9edd, 0xfe01, 0x5371, 
0x0000, 0x0000, 0x9ac7, 0x9edd, 0x0000, 0x5371, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x9ac7, 0x9edd, 0x0000, 0x5371, 0x0000, 0x9edd, 
0xffff, 0xffff, 0xffff, 0xffff, 0xaf23, 0x9edd, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0x9edd, 0xffff, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0x9ac7, 0xffff, 0x9edd, 0x5371, 0xfe01, 0x9edd, 
0x0000, 0x0000, 0x9edd, 0x0000, 0x0000, 0x5371, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0x9edd, 0x0000, 0x0000, 0x5371, 0x9edd, 0x0000, 
0xffff, 0xffff, 0xffff, 0xffff, 0x9edd, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0x9edd, 0xffff, 0xffff, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0x9ac7, 0x9edd, 0xffff, 0x5371, 0x9edd, 0x5371, 
0x0000, 0x9edd, 0x9ac7, 0x0000, 0x0000, 0x5371, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x9edd, 0x9ac7, 0x0000, 0x0000, 0x9edd, 0x0000, 0x0000, 
0xffff, 0xffff, 0xffff, 0x9edd, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x9edd, 
0xffff, 0xffff, 0x9edd, 0xffff, 0xffff, 0x9edd, 0xfe01, 0x5371, 
0x9edd, 0x0000, 0x9ac7, 0x0000, 0x0000, 0x5371, 0x0000, 0x0000, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000,     
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000, 
0x9edd, 0x0000, 0x9ac7, 0x0000, 0x9edd, 0x5371, 0x0000, 0x0000, 
0xffff, 0xffff, 0x9edd, 0xffff, 0xaf23, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xfbe0, 0xffff, 0x5371, 0xfe01, 0x5371, 
0xffff, 0xffff, 0xffff, 0xffff, 0xaf23, 0x5371, 0x9edd, 0x5371, 
0xffff, 0x9edd, 0x9ac7, 0xffff, 0x9edd, 0x5371, 0xfe01, 0x5371, 
0x0000, 0x0000, 0x9ac7, 0x0000, 0x0000, 0x5371, 0x0000, 0x9edd, 
0x0000, 0x9ac7, 0x9ac7, 0x9ac7, 0x0000, 0x0000, 0x0000, 0x0000
};



static const uint16_t snowman[64*3] = {
    // ∙∙▒▒▒▒∙∙
    // ∙∙▓▓▓▓∙∙
    // ∙▒▒▒▒▒▒∙
    // ∙∙∙█∙█∙∙
    // ∙∙████∙∙
    // ▒▒███▒▒▒
    // ∙∙████∙∙
    // ∙∙████∙∙
    0x0000, 0x0000, 0x5371, 0x5371, 0x5371, 0x5371, 0x0000, 0x0000,
    0x0000, 0x0000, 0xfe01, 0xfe01, 0xfe01, 0xfe01, 0x0000, 0x0000,
    0x0000, 0x5371, 0x5371, 0x5371, 0x5371, 0x5371, 0x5371, 0x0000,
    0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    0x5922, 0x5922, 0xffff, 0xffff, 0xffff, 0x5922, 0x5922, 0x5922,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    // ∙∙▒▒▒▒∙∙
    // ∙∙▓▓▓▓∙∙
    // ∙▒▒▒▒▒▒∙
    // ∙∙████∙∙
    // ▒∙████∙▒
    // ▒▒███▒▒▒
    // ▒∙████∙▒
    // ∙∙████∙∙
    0x0000, 0x0000, 0x5371, 0x5371, 0x5371, 0x5371, 0x0000, 0x0000,
    0x0000, 0x0000, 0xfe01, 0xfe01, 0xfe01, 0xfe01, 0x0000, 0x0000,
    0x0000, 0x5371, 0x5371, 0x5371, 0x5371, 0x5371, 0x5371, 0x0000,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    0x5922, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x5922,
    0x5922, 0x5922, 0xffff, 0xffff, 0xffff, 0x5922, 0x5922, 0x5922,
    0x5922, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x5922,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
    // ∙∙▒▒▒▒∙∙
    // ∙∙▓▓▓▓∙∙
    // ∙▒▒▒▒▒▒∙
    // ∙∙∙█∙█∙∙
    // ▒∙████∙▒
    // ▒▒███▒▒▒
    // ▒∙████∙▒
    // ∙∙████∙∙
    0x0000, 0x0000, 0x5371, 0x5371, 0x5371, 0x5371, 0x0000, 0x0000,
    0x0000, 0x0000, 0xfe01, 0xfe01, 0xfe01, 0xfe01, 0x0000, 0x0000,
    0x0000, 0x5371, 0x5371, 0x5371, 0x5371, 0x5371, 0x5371, 0x0000,
    0x0000, 0x0000, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0x0000,
    0x5922, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x5922,
    0x5922, 0x5922, 0xffff, 0xffff, 0xffff, 0x5922, 0x5922, 0x5922,
    0x5922, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x5922,
    0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000,
};

uint16_t fire[] = {
0xb842, 0x0000, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0xfbe0, 0xfbe0, 0xffd7, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xffd7, 0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 
0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0xb842, 0x0000, 
0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0xb842, 
0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 
0x0000, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 
0xb842, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 0x0000, 0x0000, 
0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 0xb842, 
0xffd7, 0xffd7, 0xffd7, 0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xb842, 
0xffd7, 0xffd7, 0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 
0xfc20, 0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 0x0000, 
0xb842, 0xfc20, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 0x0000, 
0x0000, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 
0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0xb842, 
0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0xb842, 0x0000, 
0xffd7, 0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 
0xfbe0, 0xfbe0, 0xffd7, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xb842, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0x0000, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 
0xb842, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 0x0000, 0x0000, 
0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 0xb842, 
0xffd7, 0xffd7, 0xffd7, 0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xb842, 
0xffd7, 0xffd7, 0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 
0xfc20, 0xffd7, 0xfc20, 0xfc20, 0xfc20, 0xb842, 0xb842, 0x0000, 
0xb842, 0xfc20, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 0x0000, 
0x0000, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
0x0000, 0x0000, 0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000, 
0xb842, 0xb842, 0xb842, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 
0xfc20, 0xffd7, 0xffd7, 0xfbe0, 0xb842, 0xb842, 0xb842, 0x0000, 
0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0xffd7, 0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 
0xfbe0, 0xfbe0, 0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xb842, 0xb842, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 
0x0000, 0xb842, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 0x0000, 
0xb842, 0xfbe0, 0xfc20, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0x0000, 
0xffd7, 0xffd7, 0xffd7, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0xffd7, 0xffd7, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 
0xfbe0, 0xffd7, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 0x0000, 
0xfbe0, 0xfbe0, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0x0000, 0x0000, 
0xb842, 0xb842, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0xb842, 0xb842, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 
0xfbe0, 0xfbe0, 0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0xffd7, 0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 
0xffd7, 0xffd7, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 0x0000, 0x0000, 
0xfc20, 0xffd7, 0xffd7, 0xfbe0, 0xb842, 0xb842, 0xb842, 0x0000, 
0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 0xb842, 
0xb842, 0xb842, 0xb842, 0xfbe0, 0xfbe0, 0xfbe0, 0xfbe0, 0xb842, 
0x0000, 0x0000, 0xb842, 0xb842, 0xb842, 0xb842, 0xb842, 0x0000
}; 

// animations, including number of frames
animation_t animations[] = {{santa, 15}, {snowman, 3}, {snowman_snow, 8}, {reindeer, 13}};
