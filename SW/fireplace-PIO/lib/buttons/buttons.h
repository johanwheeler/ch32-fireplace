#ifndef BUTTONS_H
#define BUTTONS_H

#include "ch32v003fun.h"

uint32_t endtime;

typedef enum {
    buttonNone = 0x0,
    buttonSound = 0x1,
    buttonNext = 0x2,
    buttonPresent = 0x4,
} buttonPress_t;

void EXTI7_0_IRQHandler(void) __attribute__((interrupt));
void EXTI7_0_IRQHandler(void)
{
    endtime = SysTick->CNT;
    EXTI->INTFR = 0xffffffff;
}

#define GPIOPortByBase(i) ((GPIO_TypeDef *)(GPIOA_BASE + 0x0400 * (i)))

// The "port" is:
// 0 for Port A
// 1 for Port B
// 2 for Port C
// 3 for Port D
int MeasureTouch(int portno, int pin, int pu_mode)
{
    uint32_t starttime;
    GPIO_TypeDef *port = GPIOPortByBase(portno);
    uint32_t pinx4 = pin << 2;

    // Mask out just our specific port.  This way we don't interfere with other
    // stuff that may be on this port.
    uint32_t base = port->CFGLR & (~(0xf << pinx4));

    // Mode for CFGLR when asserted.
    uint32_t setmode = base | (GPIO_CFGLR_OUT_2Mhz_PP) << (pinx4);

    // Mode for CFGLR when it drifts.
    uint32_t releasemode = base | (pu_mode) << (pinx4);

    // Assert pin
    port->CFGLR = setmode;
    port->BSHR = 1 << (pin + 16);

    // Setup pin-change-interrupt.  This will trigger when the voltage on the
    // pin rises above the  schmitt trigger threshold.
    AFIO->EXTICR = portno << (pin * 2);
    EXTI->INTENR = 0xffffffff; // Enable EXT3
    EXTI->RTENR = 0xffffffff;  // Rising edge trigger

    // Tricky, we want the release to happen at an un-aligned address.
    // This actually doubles our touch sensor resolution.
    asm volatile(".balign 4; c.nop");
    port->CFGLR = releasemode;
    starttime = SysTick->CNT;
    endtime = starttime - 1;
    port->BSHR = 1 << (pin);

// Allow up to 384 cycles for the pin to change.
#define DELAY8 \
    asm volatile("c.nop;c.nop;c.nop;c.nop;c.nop;c.nop;c.nop;c.nop;");
    DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8
    DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8
    DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8
    DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8
    DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8
    DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8 DELAY8

    // Optimization: If you did the nop sled in assembly, the interrupt could scoot to the end

    // Disable EXTI
    EXTI->INTENR = 0;

    // Optional assert pin when done to prevent it from noodling around.
    // port->CFGLR = setmode;
    // port->BSHR = 1<<(pin+16);

    return endtime - starttime;
}

void buttons_init(){
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO;

    // enable pin-change-interrupt.
    NVIC_EnableIRQ(EXTI7_0_IRQn);
}

buttonPress_t buttons_read() {
    buttonPress_t read = buttonNone;

    int thr = 250;

    for(int i=0; i<3; i++){
        int result = MeasureTouch(3, 2, GPIO_CFGLR_IN_FLOAT);
        if(result > thr){
            read |= buttonSound;
        }
        result = MeasureTouch(3, 3, GPIO_CFGLR_IN_FLOAT);
        if (result > thr)
        {
            read |= buttonNext;
        }
        result = MeasureTouch(3, 4, GPIO_CFGLR_IN_FLOAT);
        if(result > thr){
            read |= buttonPresent;
        }
    }

    return read;
}

#endif