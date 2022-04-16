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

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hola mundirijillo!\n");
    
    
    // rota bit	
    #define POS_SHIFTHED 24
    #define RIGHT ON
    uint16_t var = 0xABCD;
    printf("variable: %x  \n", var);
    printf("Rotated value is %x \n",RotateBit(var,POS_SHIFTHED, RIGHT));
    
    return 0;
}
