# Overview

Minimal C program which boots an STM32 chip and blinks an LED on a 1-second interval.

I hope that this project can be a super-simple starting point for an application using these chips. My goal is to minimize the amount of assembly code, the number of files, and the dependencies on vendor-provided code. The vector tables are still written in assembly rather than C, but they are auto-generated from the device header files so you shouldn't have to worry about them.

Eventually, I would like to have a workflow which can support a variety of ARM cores by generating device header files and vector tables from raw SVD files, but for now I'm using the device header files distributed by ST. This project also uses the standard CMSIS ARM Cortex-M device headers, but those seem like reasonable dependencies because they provide functionality which is shared by all Cortex-M cores regardless of who manufactures them.

# Building

Un-comment the MCU that you want to target in the Makefile, and run `make`. If you switch to a different microcontroller, run `make clean` before you update the Makefile.
