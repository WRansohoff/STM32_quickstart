#ifndef _VVC_MAIN_H
#define _VVC_MAIN_H

#include <stdint.h>
#include <string.h>

#if defined( VVC_F0 )
  #include "stm32f0xx.h"
#elif defined( VVC_WB )
  #include "stm32wbxx.h"
#endif

// Global defines.
// (LED pin depends on your board)
#if defined( STM32F030x6 )
  #define PoLED   ( GPIOA )
  #define PiLED   ( 1 )
#elif defined( STM32WB55xE )
  #define PoLED   ( GPIOE )
  #define PiLED   ( 4 )
#endif

// Pre-defined memory locations for program initialization.
extern uint32_t _sidata, _sdata, _edata, _sbss, _ebss;

uint32_t core_clock_hz;
volatile uint32_t systick;

#endif
