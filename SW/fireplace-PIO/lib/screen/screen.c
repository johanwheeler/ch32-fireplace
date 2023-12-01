#include "screen.h"

void screen_init() {
    // Neopixel pin push-pull
    SCREEN_GPIO_PORT->CFGLR &= ~(0xf << (4 * SCREEN_GPIO_PIN));
    SCREEN_GPIO_PORT->CFGLR |= (GPIO_Speed_2MHz | GPIO_CNF_OUT_PP) << (4 * SCREEN_GPIO_PIN);
};

void screen_write(uint16_t *data) {

    int maskon = 1 << SCREEN_GPIO_PIN;
    int maskoff = 1 << (16 + SCREEN_GPIO_PIN);

    SCREEN_GPIO_PORT->BSHR = maskoff;

    int pix = 0;
    while (pix != 64)
    {
        // reverse every other row
        uint16_t byte;
        if (pix % 16 < 8)
        {
            byte = *(data + (pix / 8) * 8 + 7 - pix % 16);
        }
        else
        {
            byte = *(data + pix);
        }

        uint32_t bits = (uint32_t)byte;
        uint32_t blue = (bits & 0x001F) << 3;  // 5 bits blue  ............bbbbb -> 000bbbbb
        uint32_t green = (bits & 0x07E0) >> 3; // 6 bits green .....ggg ggg..... -> 00gggggg
        uint32_t red = (bits & 0xF800) >> 8;   // 5 bits red   rrrrr... ........ -> 000rrrrr

        uint32_t expanded = (green / 16 << (16)) | (red / 16 << (8)) | (blue / 16) | 0x00000000; // divide to reduce brightness

        int i;
        for (i = 0; i < 24; i++)
        {
            if (expanded & 0x800000)
            {
                // WS2812B's need AT LEAST 625ns for a logical "1"
                SCREEN_GPIO_PORT->BSHR = maskon;
                DelaySysTick(25);
                SCREEN_GPIO_PORT->BSHR = maskoff;
                DelaySysTick(1);
            }
            else
            {
                // WS2812B's need BETWEEN 62.5 to about 500 ns for a logical "0"
                __disable_irq();
                SCREEN_GPIO_PORT->BSHR = maskon;
                asm volatile("nop\nnop\nnop\nnop");
                SCREEN_GPIO_PORT->BSHR = maskoff;
                __enable_irq();

                DelaySysTick(15);
            }
            expanded <<= 1;
        }

        pix++;
    }

    SCREEN_GPIO_PORT->BSHR = maskoff;
}
