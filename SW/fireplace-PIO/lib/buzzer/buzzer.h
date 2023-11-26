#pragma once

#include "funconfig.h"
#include "stdint.h"

/* some bit definitions for systick regs */
#define SYSTICK_SR_CNTIF (1 << 0)
#define SYSTICK_CTLR_STE (1 << 0)
#define SYSTICK_CTLR_STIE (1 << 1)
#define SYSTICK_CTLR_STCLK (1 << 2)
#define SYSTICK_CTLR_STRE (1 << 3)
#define SYSTICK_CTLR_SWIE (1 << 31)

#define TIM2_DEFAULT 0xff

volatile uint32_t systick_cnt;
volatile uint32_t tim_cnt = 0;
volatile uint16_t k = 0;

unsigned int freqz[] = {
    261, 277, 293, 311, 329, 349, 369, 391, 415, 440, 466, 493,
    523, 554, 587, 622, 659, 698, 739, 783, 830, 880, 932, 987};

typedef struct
{
    uint8_t note;
    uint16_t duration;
} note_tt;

const note_tt last_christmas[] = {{0, 0}, {17, 737}, {0, 64}, {17, 438}, {0, 93}, {15, 108}, {0, 427}, {10, 60}, {0, 206}, {17, 193}, {0, 73}, {17, 202}, {0, 65}, {19, 161}, {0, 107}, {15, 578}, {0, 222}, {12, 191}, {0, 75}, {12, 165}, {0, 97}, {17, 214}, {0, 51}, {17, 198}, {0, 70}, {19, 180}, {0, 354}, {15, 571}, {0, 225}, {12, 64}, {0, 204}, {14, 247}, {0, 20}, {15, 266}, {0, 0}, {14, 208}, {0, 60}, {12, 880}, {0, 455}, {19, 681}, {0, 120}, {17, 806}, {0, 261}, {12, 77}, {0, 191}, {19, 197}, {0, 66}, {20, 194}, {0, 72}, {19, 166}, {0, 101}, {17, 697}, {0, 376}, {15, 63}, {0, 202}, {14, 246}, {0, 21}, {15, 207}, {0, 58}, {14, 63}, {0, 207}, {14, 412}, {0, 120}, {15, 90}, {0, 446}, {14, 218}, {0, 318}, {10, 936}, {0, 936}, {0, 936}};
const note_tt i_want[] = {{1, 428}, {0, 0}, {5, 428}, {0, 0}, {8, 428}, {0, 0}, {12, 214}, {0, 0}, {13, 428}, {0, 0}, {12, 428}, {0, 0}, {10, 428}, {0, 0}, {8, 642}, {0, 0}, {15, 428}, {0, 0}, {13, 428}, {0, 0}, {13, 214}, {0, 0}, {12, 428}, {0, 0}, {13, 428}, {0, 0}, {12, 428}, {0, 0}, {10, 214}, {0, 0}, {8, 857}, {0, 428}, {10, 428}, {0, 0}, {13, 428}, {0, 0}, {15, 214}, {0, 0}, {17, 428}, {0, 0}, {15, 428}, {0, 0}, {13, 428}, {0, 0}, {10, 642}, {0, 0}, {6, 428}, {0, 0}, {9, 214}, {0, 0}, {13, 642}, {0, 0}, {15, 214}, {0, 0}, {16, 428}, {0, 0}, {15, 428}, {0, 0}, {11, 428}, {0, 0}, {9, 642}, {0, 0}, {13, 428}, {0, 0}, {15, 428}, {0, 0}, {12, 428}, {0, 0}, {13, 214}, {0, 0}, {10, 428}, {0, 0}, {12, 428}, {0, 0}, {9, 1071}, {0, 0}, {13, 428}, {0, 0}, {15, 428}, {0, 0}, {12, 428}, {0, 0}, {13, 214}, {0, 0}, {10, 428}, {0, 0}, {12, 428}, {0, 0}, {9, 1071}, {0, 0}, {8, 428}, {0, 0}, {10, 428}, {0, 0}, {13, 214}, {0, 0}, {20, 428}, {0, 0}, {18, 428}, {0, 0}, {20, 214}, {0, 0}, {18, 428}, {0, 428}, {20, 107}, {0, 107}, {20, 214}, {0, 0}, {17, 428}, {0, 0}, {15, 428}, {0, 0}, {13, 428}, {0, 0}, {10, 428}, {0, 0}, {9, 428}, {0, 0}, {15, 857}, {0, 0}, {17, 428}, {0, 0}, {13, 2142}};
const note_tt rickroll[] = {{6, 824}, {0, 75}, {8, 825}, {0, 74}, {1, 550}, {0, 49}, {8, 825}, {0, 74}, {10, 825}, {0, 74}, {13, 137}, {0, 12}, {11, 137}, {0, 12}, {10, 137}, {0, 12}, {6, 975}, {0, 74}, {8, 825}, {0, 75}, {1, 2024}, {0, 375}, {13, 137}, {0, 12}, {11, 137}, {0, 12}, {10, 137}, {0, 12}, {6, 974}, {0, 75}, {8, 825}, {0, 75}, {1, 549}, {0, 49}, {8, 825}, {0, 75}, {10, 825}, {0, 75}, {13, 137}, {0, 12}, {11, 137}, {0, 12}, {10, 137}, {0, 12}, {6, 975}, {0, 75}, {8, 824}, {0, 75}, {1, 2250}, {0, 150}, {1, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 137}, {0, 12}, {3, 137}, {0, 12}, {10, 412}, {0, 187}, {10, 274}, {0, 25}, {8, 849}, {0, 49}, {1, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 137}, {0, 12}, {3, 137}, {0, 12}, {8, 412}, {0, 187}, {8, 275}, {0, 24}, {6, 412}, {0, 37}, {5, 137}, {0, 12}, {3, 274}, {0, 25}, {1, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 549}, {0, 49}, {8, 275}, {0, 24}, {5, 412}, {0, 37}, {3, 137}, {0, 12}, {1, 375}, {0, 224}, {1, 262}, {0, 37}, {8, 549}, {0, 50}, {6, 1149}, {0, 49}, {1, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 137}, {0, 12}, {3, 137}, {0, 12}, {10, 412}, {0, 187}, {10, 275}, {0, 24}, {8, 850}, {0, 49}, {1, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 137}, {0, 12}, {3, 137}, {0, 12}, {13, 550}, {0, 49}, {5, 274}, {0, 25}, {6, 412}, {0, 37}, {5, 137}, {0, 12}, {3, 275}, {0, 25}, {1, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 137}, {0, 12}, {3, 137}, {0, 12}, {6, 549}, {0, 49}, {8, 275}, {0, 25}, {5, 412}, {0, 37}, {3, 137}, {0, 12}, {1, 412}, {0, 187}, {1, 275}, {0, 25}, {8, 549}, {0, 49}, {6, 1299}};
const note_tt undertale[] = {{1, 68}, {0, 68}, {1, 68}, {0, 68}, {13, 136}, {0, 136}, {8, 136}, {0, 272}, {7, 136}, {0, 136}, {6, 136}, {0, 136}, {4, 272}, {0, 0}, {1, 136}, {0, 0}, {4, 136}, {0, 0}, {6, 136}};
const note_tt feliz[] = {{0, 200}, {10, 217}, {0, 11}, {15, 316}, {0, 143}, {14, 213}, {0, 16}, {15, 225}, {0, 4}, {12, 428}, {0, 31}, {10, 62}, {0, 167}, {8, 71}, {0, 158}, {7, 62}, {0, 167}, {3, 69}, {0, 390}, {10, 229}, {0, 689}, {12, 213}, {0, 16}, {17, 299}, {0, 160}, {15, 193}, {0, 35}, {12, 229}, {0, 0}, {10, 423}, {0, 35}, {10, 67}, {0, 162}, {8, 76}, {0, 153}, {7, 71}, {0, 158}, {10, 76}, {0, 383}, {3, 229}, {0, 689}, {10, 229}, {0, 0}, {15, 292}, {0, 167}, {14, 205}, {0, 23}, {15, 229}, {0, 0}, {12, 500}, {0, 189}, {8, 170}, {0, 59}, {12, 311}, {0, 148}, {12, 205}, {0, 23}, {10, 263}, {0, 196}, {10, 244}, {0, 215}, {10, 203}, {0, 26}, {8, 282}, {0, 177}, {8, 229}, {0, 0}, {5, 344}};

const note_tt *curr_song = last_christmas;

const int note_end = sizeof(last_christmas) / sizeof(note_tt);

void t2pwm_init(void)
{
    // Enable TIM2
    RCC->APB1PCENR |= RCC_APB1Periph_TIM2;

    // If using T2CH3 must also enable GPIOC
    RCC->APB2PCENR |= RCC_APB2Periph_GPIOC;

    // PC0 is T2CH3, 10MHz Output alt func, push-pull
    GPIOC->CFGLR &= ~(0xf << (4 * 0));
    GPIOC->CFGLR |= (GPIO_Speed_10MHz | GPIO_CNF_OUT_PP_AF) << (4 * 0);

    // Reset TIM2 to init all regs
    RCC->APB1PRSTR |= RCC_APB1Periph_TIM2;
    RCC->APB1PRSTR &= ~RCC_APB1Periph_TIM2;

    // SMCFGR: default clk input is CK_INT
    // set TIM2 clock prescaler divider
    TIM2->PSC = 3;
    // set PWM total cycle width
    TIM2->ATRLR = 512;
    TIM2->CH3CVR = 255;

    // for channel 1 and 2, let CCxS stay 00 (output), set OCxM to 110 (PWM I)
    // enabling preload causes the new pulse width in compare capture register only to come into effect when UG bit in SWEVGR is set (= initiate update) (auto-clears)
    TIM2->CHCTLR2 |= TIM_OC3M_2 | TIM_OC3M_1 | TIM_OC3PE;

    // CTLR1: default is up, events generated, edge align
    // enable auto-reload of preload
    TIM2->CTLR1 |= TIM_ARPE;

    // Enable Channel outputs, set default state (based on TIM2_DEFAULT)
    TIM2->CCER |= TIM_CC3E | (TIM_CC3P & TIM2_DEFAULT);

    // initialize counter
    TIM2->SWEVGR |= TIM_UG;

    // Enable TIM2
    TIM2->CTLR1 |= TIM_CEN;
}

/*
 * Start up the SysTick IRQ
 */
void systick_init(void)
{
    /* disable default SysTick behavior */
    SysTick->CTLR = 0;

    /* enable the SysTick IRQ */
    NVIC_EnableIRQ(SysTicK_IRQn);

    /* Set the tick interval to 1ms for normal op */
    SysTick->CMP = (FUNCONF_SYSTEM_CORE_CLOCK / 1000) - 1;

    /* Start at zero */
    SysTick->CNT = 0;
    systick_cnt = 0;

    /* Enable SysTick counter, IRQ, HCLK/1 */
    SysTick->CTLR = SYSTICK_CTLR_STE | SYSTICK_CTLR_STIE |
                    SYSTICK_CTLR_STCLK;
}

void tone(uint32_t freq) {
    // ATRLR = clock/(freqz*prescaler)
    if(freq == 0){
        TIM2->ATRLR = (uint16_t)1024;
        TIM2->CH3CVR = 1023;
        TIM2->SWEVGR |= TIM_UG;
        return;
    }

    uint16_t per = FUNCONF_SYSTEM_CORE_CLOCK / (freq * 4);
    TIM2->ATRLR = (uint16_t)per;
    TIM2->CH3CVR = per / 2;
    TIM2->SWEVGR |= TIM_UG;
}

/*
 * SysTick ISR just counts ticks
 * note - the __attribute__((interrupt)) syntax is crucial!
 */
void SysTick_Handler(void) __attribute__((interrupt));
void SysTick_Handler(void)
{
    // move the compare further ahead in time.
    // as a warning, if more than this length of time
    // passes before triggering, you may miss your
    // interrupt.
    SysTick->CMP += (FUNCONF_SYSTEM_CORE_CLOCK / 1000);

    /* clear IRQ */
    SysTick->SR = 0;

    /* update counter */
    systick_cnt++;
    tim_cnt++;

    if (tim_cnt > curr_song[k].duration)
    {
        tim_cnt = 0;

        // Set timer freq here!
        // printf("note: %u \n", curr_song[k].note);

        if (curr_song[k + 1].note == 0)
        {
            tone(0);
        }
        else
        {
            tone(freqz[curr_song[k + 1].note - 1]);
        }

        // TIM2->ATRLR = 256;
        // TIM2->CH3CVR = 128;
        // TIM2->SWEVGR |= TIM_UG;

        // set correct note length here!
        k++;
        k = k % (note_end - 1);
    }
}