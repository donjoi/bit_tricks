//
//  main.c
//  bit_tricks
//
//  Created by Donaldo Moreno Lopez on 4/16/22.
//

#include <stdio.h>
#include "bit_tricks.h"

#define ON 1
#define OFF 0


#define ROTABIT OFF
#define SQUARE_ROOT OFF
#define REVERSE_BITS OFF
#define SWAP_VARS OFF
#define DEC2HEX ON

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Bit tricks!\n");
    
#if ROTABIT
    // rota bit	
    #define POS_SHIFTHED 24
    #define RIGHT ON
    uint16_t var = 0xABCD;
    
    printf("variable: %x  \n", var);
    printf("Rotated value is %x \n",RotateBit(var,POS_SHIFTHED, RIGHT));
#endif
    
#if SQUARE_ROOT
    uint32_t var1 = 18;
    
    printf("root implementation var: %d \n", var1);
    printf("square root: %f \n", mySqrt(var1));
#endif
    
#if REVERSE_BITS
    uint32_t var1 = 0x101;
    
    printf("var: %x \n", var1);
    printf("reverse bit: %x \n", ReverseBits(var1));
#endif
    
#if SWAP_VARS
    uint8_t a = 23;
    uint8_t b = 45;
    
    SwapVars(&a,&b);
    printf("variables a: %d, b: %d \n", a , b);
#endif
    
#if DEC2HEX
    char string[10];
    uint32_t number = 200;
    
    Dec2Hex(string, number);
    
    for(uint32_t ii = 0;(string[ii] != '\n' && ii < 10); ii++)
    {
        printf("%c",string[ii]);
    }
    printf("\n");
#endif
    
    return 0;
}
