#include <stdio.h>
#include <stdlib.h>
#include "ALU.h"

int main() {
    unsigned int op1_input, op2_input, ctrl_input;
    unsigned char operand1, operand2, control_signal;
    unsigned int ACC;

    while (1) {
        printf("==========================================\n");
        printf("       ALU & CONTROL UNIT EMULATOR        \n");
        printf("==========================================\n");

        // 1. Menu for Control Signal (Moved to top so we can exit easily)
        printf("Select Operation (Control Signal):\n");
        printf("  0x01 - Addition\n");
        printf("  0x02 - Subtraction\n");
        printf("  0x03 - Multiplication (Booth's)\n");
        printf("  0x04 - AND\n");
        printf("  0x05 - OR\n");
        printf("  0x06 - NOT\n");
        printf("  0x07 - XOR\n");
        printf("  0x08 - Shift Right (logical)\n");
        printf("  0x09 - Shift Left (logical)\n");
        printf("  0x00 - EXIT PROGRAM\n");
        printf("------------------------------------------\n");
        printf("Enter Control Signal (Hex): ");
        scanf("%x", &ctrl_input);
        
        // Exit check
        if (ctrl_input == 0x00) {
            printf("\nExiting ALU Emulator. Goodbye!\n");
            break; // This breaks us out of the infinite loop
        }
        
        control_signal = (unsigned char)ctrl_input;

        // 2. Prompt for Operands
        printf("Enter Operand 1 (Hex, e.g., 0A or FF): ");
        scanf("%x", &op1_input);
        operand1 = (unsigned char)op1_input;

        printf("Enter Operand 2 (Hex, e.g., 0B or 02): ");
        scanf("%x", &op2_input);
        operand2 = (unsigned char)op2_input;

        printf("\n==========================================\n");
        printf("Executing ALU...\n");
        printf("==========================================\n");

        // 3. Call the ALU Function
        ACC = ALU(operand1, operand2, control_signal);

        // 4. Display the Results
        printf("\n--- ALU OUTPUT ---\n");
        printf("Accumulator (Hex) : 0x%04X\n", ACC);
        printf("Accumulator (Bin) : ");
        
        // Print binary inline
        for (int i = 15; i >= 0; i--) {
            printf("%d", (ACC >> i) & 1);
            if (i % 4 == 0) printf(" "); 
        }
        printf("\n");

        printf("\n--- FLAGS STATUS ---\n");
        printf("Sign Flag (SF)     : %d\n", SF);
        printf("Overflow Flag (OF) : %d\n", OF);
        printf("Zero Flag (ZF)     : %d\n", ZF);
        printf("Carry Flag (CF)    : %d\n", CF);
        printf("==========================================\n");

        // 5. Pause before clearing the screen and looping back
        printf("\nPress ENTER to continue to the next operation...");
        getchar(); // Catches the leftover newline from scanf
        getchar(); // Actually waits for the user to press Enter
        printf("\n\n\n"); // Adds some spacing before the menu prints again
    }

    return 0;
}