#include "main.h"

// Default values for global variables.
#if defined( VVC_F0 )
  uint32_t core_clock_hz = 8000000;
#elif defined( VVC_WB )
  uint32_t core_clock_hz = 4000000;
#endif

// SysTick counter definition.
volatile uint32_t systick = 0;

// Reset handler: copy .data section, and clear .bss section.
__attribute__( ( naked ) ) void reset_handler( void ) {
  // Set the stack pointer to the 'end of stack' value.
  __asm__( "LDR r0, =_estack\n\t"
           "MOV sp, r0" );
  // Branch to main().
  __asm__( "B main" );
}

// Delay for a specified number of milliseconds.
// TODO: Prevent rollover bug on the 'systick' value.
void delay_ms( uint32_t ms ) {
  // Calculate the tick value when the system should stop delaying.
  uint32_t next = systick + ms;

  // Wait until the system reaches that tick value.
  // Use the 'wait for interrupt' instruction to save power.
  while ( systick < next ) { __asm__( "WFI" ); }
}

/**
 * Main program.
 */
int main(void) {
  // Copy initialized data from .sidata (Flash) to .data (RAM)
  memcpy( ( void* )&_sdata,
          ( const void* )&_sidata,
          ( ( void* )&_edata - ( void* )&_sdata ) );
  // Clear the .bss section in RAM.
  memset( &_sbss, 0x00, ( ( void* )&_ebss - ( void* )&_sbss ) );

  // Setup the SysTick peripheral to 1ms ticks.
  // This must be called before `delay_ms(...)`.
  SysTick_Config( core_clock_hz / 1000 );

  // Enable the GPIO peripherals.
  #if defined( VVC_F0 )
    RCC->AHBENR   |= ( RCC_AHBENR_GPIOAEN |
                       RCC_AHBENR_GPIOBEN );
  #elif defined( VVC_WB )
    RCC->AHB2ENR   |= ( RCC_AHB2ENR_GPIOAEN |
                        RCC_AHB2ENR_GPIOBEN |
                        RCC_AHB2ENR_GPIOCEN |
                        RCC_AHB2ENR_GPIOEEN );
  #endif

  // GPIO pin setup: output, push-pull, low-speed.
  PoLED->MODER    &= ~( 0x3 << ( PiLED * 2 ) );
  PoLED->MODER    |=  ( 0x1 << ( PiLED * 2 ) );
  PoLED->OTYPER   &= ~( 0x1 << PiLED );
  PoLED->OSPEEDR  &= ~( 0x3 << ( PiLED * 2 ) );
  PoLED->OSPEEDR  |=  ( 0x1 << ( PiLED * 2 ) );
  PoLED->ODR      |=  ( 1 << PiLED );

  // Toggle the LED every second.
  while ( 1 ) {
    delay_ms( 1000 );
    PoLED->ODR ^=  ( 1 << PiLED );
  }

  return 0; // lol
}

// SysTick interrupt handler: increment the global 'systick' value.
void SysTick_handler( void ) {
  ++systick;
}
