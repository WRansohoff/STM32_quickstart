# Overview

Minimal C program which boots an STM32 chip and blinks an LED on a 1-second interval.

I hope that this project can be a super-simple starting point for an application using these chips. My goal is to minimize the amount of assembly code, the number of files, and the dependencies on vendor-provided code.

Eventually, I would like to have a workflow which can generate device header files and vector tables from raw SVD files, but for now I'm using hand-written vector tables, the device header files distributed by ST, and the standard CMSIS ARM Cortex-M device headers. I'm also interested in finding a way to simplify the vector table code, because while it seems like a standard approach to use a dedicated assembly file, that is frankly very ugly.
