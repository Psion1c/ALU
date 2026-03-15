#include "ALU.h"
int booth_multiply(unsigned char operand1, unsigned char operand2)
{
    signed char M   = (signed char)operand1;
    signed char Q   = (signed char)operand2;
    signed char A   = 0;
    signed char Q_r = Q;
    int         Q_1 = 0;
    int         Q0;
    int         steps = 8;
    int         i;
 
    printf("\n  [Booth's Algorithm Trace]\n");
    printf("  Multiplicand (M) = %d (0x%02X)\n", M, (unsigned char)M);
    printf("  Multiplier   (Q) = %d (0x%02X)\n", Q, (unsigned char)Q);
    printf("  %-6s | %-10s | %-10s | %-5s\n", "Step", "A (ACC)", "Q (MUL)", "Q-1");
    printf("  -------+------------+------------+------\n");
    printf("  INIT   | %10d | %10d | %d\n", A, Q_r, Q_1);
 
    for (i = 0; i < steps; i++)
    {
        Q0 = Q_r & 1;
 
        if      (Q0 == 0 && Q_1 == 1) A = A + M;
        else if (Q0 == 1 && Q_1 == 0) A = A - M;
 
        Q_1  = Q_r & 1;
        Q_r  = (Q_r >> 1) & 0x7F;
        Q_r |= (A & 1) << 7;
        A    = A >> 1;
 
        printf("  %-6d | %10d | %10d | %d\n", i + 1, A, Q_r, Q_1);
    }
 
    int product = ((int)(signed char)A << 8) | (unsigned char)Q_r;
 
    printf("  -------+------------+------------+------\n");
    printf("  Final Product = A:Q = %d : %d\n", A, (unsigned char)Q_r);
 
    return product;
}