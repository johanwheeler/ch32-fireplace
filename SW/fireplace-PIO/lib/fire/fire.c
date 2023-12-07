#include "fire.h"

// Fire parameters
#define UPPER_DECAY_DIV 3
#define DIRECTIONALITY 2
#define TRANSFER_DIV 13
#define SOURCE_VARIANCE 100
#define SOURCE_MEAN 255-SOURCE_VARIANCE
#define SOURCE_DECAY_DIV 32
#define COLOR_REDUCTION 4

// Fire state
uint32_t fire_seed = 0x12345678;

uint8_t fire_temps[64] = {
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
};

void fire_draw() {
    //loop through rows, add kernel of 3 lower pixels
    for(int i = 0; i < 7; i++) {
        // leftmost pixel
        fire_temps[i * 8] -= fire_temps[i * 8] / UPPER_DECAY_DIV;
        fire_temps[i*8] += (fire_temps[(i+1)*8]*DIRECTIONALITY + fire_temps[(i+1)*8+1])/TRANSFER_DIV;
        

        for(int j = 1; j < 7; j++) {
            fire_temps[i * 8 + j] -= fire_temps[i * 8 + j] / UPPER_DECAY_DIV;
            fire_temps[i*8+j] += (fire_temps[(i+1)*8+j-1] + fire_temps[(i+1)*8+j]*DIRECTIONALITY + fire_temps[(i+1)*8+j+1])/TRANSFER_DIV;
        }

        // rightmost pixel
        fire_temps[i * 8 + 7] -= fire_temps[i * 8 + 7] / UPPER_DECAY_DIV;
        fire_temps[i*8+7] += (fire_temps[(i+1)*8+6] + fire_temps[(i+1)*8+7]*DIRECTIONALITY)/TRANSFER_DIV;
    }

    // lower values means more likely to be lit
    uint8_t distribution[8] = {255, 64, 32, 16, 16, 32, 64, 255};

    // last row, add random new temperature
    for(int i = 0; i < 8; i++) {
        if(fire_random()%distribution[i] == 0){
            fire_temps[56+i] = fire_random()%SOURCE_VARIANCE + SOURCE_MEAN;
        }else{
            fire_temps[56+i] -=  fire_temps[56+i] / SOURCE_DECAY_DIV;
        }
    }

    // remap temperatures to colors
    uint16_t color[64];

    for(int i = 0; i<64; i++){
        int t = fire_temps[i] + (COLOR_REDUCTION-1);
        t = (t>>COLOR_REDUCTION)<<COLOR_REDUCTION;

        int red = t * 3 -30;
        int green = t * 2 - 100;
        int blue = t * 4 - 700;

        if(red < 0) red = 0;
        if(green < 0) green = 0;
        if(blue < 0) blue = 0;
        if(red > 255) red = 255;
        if(green > 255) green = 255;
        if(blue > 255) blue = 255;

        // flip row and column
        int j = i % 8;
        int k = 7 - i / 8;

        color[j*8+k] = ((red << 8) & 0xF800) | ((green << 3) & 0x07E0)  | ((blue >> 3) & 0x001F);
    }

    // draw fire
    screen_write(color);
}

void fire_reset(){
    for (int i = 0; i < 64; i++) {
        fire_temps[i] = 0;
    }
}

uint32_t fire_random() {
    //xorshift 
    fire_seed ^= fire_seed << 13;
    fire_seed ^= fire_seed >> 17;
    fire_seed ^= fire_seed << 5;
    return fire_seed;
}
