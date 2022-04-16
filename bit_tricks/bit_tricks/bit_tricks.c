//
//  bit_tricks.c
//  bit_tricks
//
//  Created by Donaldo Moreno Lopez on 4/16/22.
//

#include "bit_tricks.h"
#include <stdint.h>

#define SHORT_SIZE (sizeof(uint16_t)*8)

uint16_t RotateBit(uint16_t digit, uint32_t n, uint8_t rigth)
{
    uint8_t LocalShift = 0;
    uint16_t RetVal = 0;
    
    LocalShift = n % SHORT_SIZE;
     
    if(rigth)
    {
        RetVal =  (digit << LocalShift | (digit >> (SHORT_SIZE - LocalShift)));
    }
    else
    {
        RetVal =  (digit >> LocalShift | (digit << (SHORT_SIZE - LocalShift)));
    }
    
    return RetVal;
}


