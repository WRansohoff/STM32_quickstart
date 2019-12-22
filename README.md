# Overview

Minimal C program which boots an STM32 chip and blinks an LED on a 1-second interval.

This is a super-simple starting point for an application using these chips. My goal is to minimize the amount of assembly code, the number of files, and the dependencies on vendor-provided code. The vector tables are still written in assembly rather than C, but they are auto-generated from the device header files so you shouldn't have to worry about them.

Eventually, I would like to have a workflow which can support a variety of ARM cores by generating device header files and vector tables from raw SVD files, but for now I'm using the device header files distributed by ST. This project also uses the standard CMSIS ARM Cortex-M device headers, which seem like reasonable dependencies because they provide functionality which is shared by all Cortex-M cores regardless of who manufactures them.

# Building

Un-comment the MCU that you want to target in the Makefile, and run `make`. If you switch to a different microcontroller, run `make clean` before you update the Makefile. If your board's LED is on a different pin from the configuration in `src/main.h`, change those definitions before building it.

I'm traveling, so I don't have much hardware to test with and I've only run the generated application on an STM32WB55CE chip. I'm planning to build in basic support for all STM32 lines (`F0`, `F1`, `F2`, `F3`, `F4`, `F7`, `L0`, `L1`, `L4`, `G0`, `G4`, `H7`, `WB`), and hopefully figure out how to cleanly manage that wide variety of configurations. I don't plan to support the `MP1` line yet, because those are much more complicated.

If you're a hobbyist, note that the `L1`/`F1` lines seem to be practically deprecated; the `F1` line does continue to see plenty of use thanks to the low cost of `STM32F103C8` boards, but be aware that its peripherals are often quite different from those in the more modern STM32 lines. Also, the `G0` line might supercede the `F0`/`L0` ones in the near future, and the `F2`/`F7`/`H7` lines are high-performance chips which are often only available in larger packages which are difficult to solder by hand.
