#ifndef ALU_H
#define ALU_H

#include <stdlib.h>
#include <stdio.h>

#define ADDITION       0x01
#define SUBTRACTION    0x02
#define MULTIPLICATION 0x03
#define AND            0x04
#define OR             0x05
#define NOT            0x06
#define XOR            0x07
#define SHR            0x08
#define SHL            0x09

extern int SF, OF, ZF, CF;

int ALU(unsigned char operand1, unsigned char operand2, unsigned char control_signals);
void setFlags(unsigned int ACC);
unsigned char twosComp(unsigned char operand2);
void printBin(int data, unsigned char data_width);
int booth_multiply(unsigned char operand1, unsigned char operand2);

#endif