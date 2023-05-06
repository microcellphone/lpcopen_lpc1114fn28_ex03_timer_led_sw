/*
===============================================================================
 Name        : lpcopen_lpc1114fn28_ex03_timer_led_sw.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "led.h"
#include "sw.h"

// TODO: insert other definitions and declarations here
#define TICKRATE_HZ (10) /* 10 ticks per second */

void TIMER16_0_IRQHandler(void)
{
	uint8_t sw;
	bool led;

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER0)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER0);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER1);

		sw = SW_Status_Read_Request(SW1);
		if(sw == 0) led = true;
		else		  led = false;

		LED_Set_Request(LED1, led);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER2)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER2);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_0, TIMER3)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_0, TIMER3);
	}
}

void TIMER16_1_IRQHandler(void)
{
	if (Chip_TIMER_MatchPending(LPC_TIMER16_1, TIMER0)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_1, TIMER0);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_1, TIMER1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_1, TIMER1);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_1, TIMER2)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_1, TIMER2);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER16_1, TIMER3)) {
		Chip_TIMER_ClearMatch(LPC_TIMER16_1, TIMER3);
	}
}

void TIMER32_0_IRQHandler(void)
{
	if (Chip_TIMER_MatchPending(LPC_TIMER32_0, TIMER0)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_0, TIMER0);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER32_0, TIMER1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_0, TIMER1);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER32_0, TIMER2)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_0, TIMER2);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER32_0, TIMER3)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_0, TIMER3);
	}
}

void TIMER32_1_IRQHandler(void)
{
	if (Chip_TIMER_MatchPending(LPC_TIMER32_1, TIMER0)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_1, TIMER0);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER32_1, TIMER1)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_1, TIMER1);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER32_1, TIMER2)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_1, TIMER2);
	}

	if (Chip_TIMER_MatchPending(LPC_TIMER32_1, TIMER3)) {
		Chip_TIMER_ClearMatch(LPC_TIMER32_1, TIMER3);
	}
}


int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here
    IOCON_Config_Request();
    LED1_Config_Request();
    SW1_Config_Request();
    TIMER_Config_Request(LPC_TIMER16_0, TIMER1, TICKRATE_HZ);

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
		  i++ ;
        // "Dummy" NOP to allow source level single
        // stepping of tight while() loop
        __asm volatile ("nop");
    }
    return 0 ;
}
