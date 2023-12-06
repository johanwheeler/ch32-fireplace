#include "fire.h"

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
        fire_temps[i * 8] -= fire_temps[i * 8] / 3;
        fire_temps[i*8] += (fire_temps[(i+1)*8]*2 + fire_temps[(i+1)*8+1])/13;
        

        for(int j = 1; j < 7; j++) {
            fire_temps[i * 8 + j] -= fire_temps[i * 8 + j] / 3;
            fire_temps[i*8+j] += (fire_temps[(i+1)*8+j-1] + fire_temps[(i+1)*8+j]*2 + fire_temps[(i+1)*8+j+1])/13;
            
        }

        // rightmost pixel
        fire_temps[i * 8 + 7] -= fire_temps[i * 8 + 7] / 3;
        fire_temps[i*8+7] += (fire_temps[(i+1)*8+6] + fire_temps[(i+1)*8+7]*2)/13;
    }

    // lower values means more likely to be lit
    uint8_t distribution[8] = {255, 64, 32, 16, 16, 32, 64, 255};

    // last row, add random new temperature
    for(int i = 0; i < 8; i++) {
        if(fire_random()%distribution[i] == 0){
            fire_temps[56+i] = fire_random()%100 + 155;
        }else{
            fire_temps[56+i] -=  fire_temps[56+i] >> 5;
        }
    }

    // remap temperatures to colors
    uint16_t color[64];

    for(int i = 0; i<64; i++){
        int red = ((int) fire_temps[i]) * 3 -30;
        int green = ((int) fire_temps[i])*2 - 100;
        int blue = ((int)fire_temps[i]) * 4 - 700;

        if(red < 0) red = 0;
        if(green < 0) green = 0;
        if(blue < 0) blue = 0;
        if(red > 255) red = 255;
        if(green > 255) green = 255;
        if(blue > 255) blue = 255;

        color[i] = ((red << 8) & 0xF800) | ((green << 3) & 0x07E0)  | ((blue >> 3) & 0x001F);
    }

    // draw fire
    screen_write(color);
}

uint32_t fire_random() {
    //xorshift 
    fire_seed ^= fire_seed << 13;
    fire_seed ^= fire_seed >> 17;
    fire_seed ^= fire_seed << 5;
    return fire_seed;
}
