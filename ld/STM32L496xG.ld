/*
 * Minimal linker script for an STM32L496RG.
 */

/* Label for the program's entry point */
ENTRY(reset_handler)

/* End of RAM/Start of stack */
/* (256KB SRAM, excluding 64KB CCMRAM) */
_estack = 0x20040000;

/* Set minimum size for stack and dynamic memory. */
/* (The linker will generate an error if there is
 * less than this much RAM leftover.) */
/* (1KB) */
_Min_Leftover_RAM = 0x400;

MEMORY
{
    FLASH ( rx )      : ORIGIN = 0x08000000, LENGTH = 1M
    /* RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 320K */
    /* (Alternate mapping to specify RAM region w/ parity check) */
    RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 256K
    CCMRAM ( rw )     : ORIGIN = 0x10000000, LENGTH = 64K
}

INCLUDE "sections.ld"
