8-Bit ALU & Control Unit Emulator

A C-based software emulator of an 8-bit Arithmetic Logic Unit (ALU) and Control Unit. This project was developed as a group laboratory exercise for CpE 3202 (Computer Organization and Architecture).

📌 Project Overview

This emulator simulates the core hardware operations of a CPU. It accepts two 8-bit hexadecimal operands and a control signal, processes the requested mathematical or logical operation, and outputs the 16-bit accumulator result alongside the status of four standard processor flags (Sign, Overflow, Zero, and Carry).

Supported Operations

The ALU supports the following 9 control signals:

0x01 - Addition (with 2's complement overflow detection)

0x02 - Subtraction (via 2's complement addition)

0x03 - Multiplication (Hardware-accurate Booth's Algorithm)

0x04 - AND (Bitwise)

0x05 - OR (Bitwise)

0x06 - NOT (1's Complement)

0x07 - XOR (Bitwise)

0x08 - Shift Right (Logical)

0x09 - Shift Left (Logical)

🗂️ File Structure

main.c: Emulates the Control Unit. Handles the user interface, infinite loop menu, input parsing, and formatted binary/hex output.

ALU.h: The central header file containing macro definitions, global flag declarations (extern), and function prototypes.

ALU.c: The core logic routing file. Contains the switch statement for control signals, standard arithmetic, bitwise logic, and precise flag setting mechanisms.

boothMultiply.c: A dedicated module for executing signed binary multiplication using Booth's Algorithm, complete with a step-by-step console trace table.

🚀 How to Compile and Run

This project requires a standard C compiler (like GCC) to build.

1. Compile the source code:
Open your terminal in the project directory and run:
```bash
gcc main.c ALU.c boothMultiply.c -o ALU_Emulator
```

2. Execute the program:
```bash

On Windows:

.\ALU_Emulator.exe

On Mac/Linux:

./ALU_Emulator
```

👥 Team Members

Member 1: Core Framework & Basic Arithmetic

Member 2: Booth's Algorithm Implementation

Member 3: Logic & Shift Operations

Member 4 (Team Lead): Control Unit Emulation & Systems Integration
