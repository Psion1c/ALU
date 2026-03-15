#include "ALU.h"

// 1. Declare the global flags here (they are extern in ALU.h)
int SF = 0, OF = 0, ZF = 0, CF = 0;

// 2. Member 1's missing 2's Complement function
unsigned char twosComp(unsigned char operand2) {
    return ~operand2 + 1;
}

// 3. Helper function to print binary
void printBin(int data, unsigned char data_width) {
    for (int i = data_width - 1; i >= 0; i--) {
        printf("%d", (data >> i) & 1);
        if (i % 4 == 0) printf(" "); // Add space every 4 bits
    }
}

// 4. Safe and accurate Flag Management
void setFlags(unsigned int ACC) {
    SF = (ACC & 0x0080) ? 1 : 0;        // Check 8th bit for sign
    ZF = ((ACC & 0x00FF) == 0) ? 1 : 0; // Check if lower 8 bits are 0
    CF = (ACC & 0x0100) ? 1 : 0;        // Check 9th bit for carry out
}

// 5. The Main ALU Function (Integrated)
int ALU(unsigned char operand1, unsigned char operand2, unsigned char control_signal) {
    unsigned int ACC = 0;
    
    // Reset flags before each operation
    SF = 0; OF = 0; ZF = 0; CF = 0;

    switch(control_signal) {
        case ADDITION: // 0x01
            ACC = operand1 + operand2;
            setFlags(ACC);
            // Overflow Logic for Addition: (Pos + Pos = Neg) OR (Neg + Neg = Pos)
            if (((operand1 & 0x80) == (operand2 & 0x80)) && ((operand1 & 0x80) != (ACC & 0x80))) {
                OF = 1;
            }
            break;
            
        case SUBTRACTION: // 0x02
            ACC = operand1 + twosComp(operand2);
            setFlags(ACC);
            // Overflow Logic for Subtraction
            if (((operand1 & 0x80) != (operand2 & 0x80)) && ((operand1 & 0x80) != (ACC & 0x80))) {
                OF = 1;
            }
            break;

        case MULTIPLICATION: // 0x03
            ACC = booth_multiply(operand1, operand2);
            // Booth's handles its own math, but we can set basic zero/sign flags
            if (ACC == 0) ZF = 1;
            if (ACC & 0x8000) SF = 1; // Check 16-bit sign flag
            break;

        case AND: // 0x04
            ACC = operand1 & operand2;
            setFlags(ACC);
            break;

        case OR: // 0x05
            ACC = operand1 | operand2;
            setFlags(ACC);
            break;

        case NOT: // 0x06
            ACC = ~operand1 & 0xFF; // Only invert the 8 bits
            setFlags(ACC);
            break;

        case XOR: // 0x07
            ACC = operand1 ^ operand2;
            setFlags(ACC);
            break;

        case SHR: // 0x08
            ACC = operand1 >> 1;
            setFlags(ACC);
            break;

        case SHL: // 0x09
            ACC = operand1 << 1;
            setFlags(ACC);
            break;

        default:
            printf("  -> Error: Invalid Control Signal!\n");
            break;
    }
    
    return ACC;
}