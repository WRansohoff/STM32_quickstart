/* Label for the program's entry point */
ENTRY(reset_handler)

/* End of RAM/Start of stack */
/* (36KB SRAM) */
_estack = 0x20009000;

/* Set minimum size for stack and dynamic memory. */
/* (The linker will generate an error if there is
 * less than this much RAM leftover.) */
/* (1KB) */
_Min_Leftover_RAM = 0x400;

MEMORY
{
    FLASH ( rx )      : ORIGIN = 0x08000000, LENGTH = 128K
    RAM ( rxw )       : ORIGIN = 0x20000000, LENGTH = 36K
}

INCLUDE "sections.ld"
