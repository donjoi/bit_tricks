//
//  bit_tricks.c
//  bit_tricks
//
//  Created by Donaldo Moreno Lopez on 4/16/22.
//

#include "bit_tricks.h"
#include <stdint.h>

/*  Rotabit is one the easiest implementation but the best code to learn masks
    this example consider an infinite rotabit
 
 */

#define SHORT_SIZE (sizeof(uint16_t)*8)

uint16_t RotateBit(uint16_t digit, uint32_t n, uint8_t rigth)
{
    uint8_t LocalShift = 0;
    uint16_t RetVal = 0;
    
    LocalShift = n % SHORT_SIZE; // this line allows to make the rotabit infinite.
     
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


/*  sqrt implementation uses fast inverse square root trick from Quake III
    to calculate square root, making and small adjustment at the end of the
    function to adjust the bit lost.
*/
float mySqrt(float x)
{
    
    uint32_t i;
    float x2, y;
    const float threehalfs = 1.5f;
    float number;
    float square = 0;
    
    number = (float)x;
    
    x2 = number * 0.5f;
    y = number;
    i = *(uint32_t*) &y;
    i = 0x5f3759df - (i>>1);
    y = *(float*) &i;
    y = y * (threehalfs - (x2*y*y));
    y = y * (threehalfs - (x2*y*y));
    
    square = (float)(1/y);

    return ((square*square) > x) ? square - 1: square;
}

/* Reverse bit implmentation
 
 */

#define SIZE_INT (sizeof(uint32_t)*8)

uint32_t ReverseBits(uint32_t number)
{
    uint32_t ReverseNumber = 0;
    
    for(uint32_t ii = 0; ii < SIZE_INT; ii++)
    {
        ReverseNumber = (ReverseNumber << 1) | (number & 0x01);
        number = number >> 1;
    }
    
    return ReverseNumber;
}

void SwapVars(uint8_t* a,uint8_t* b)
{
    *a ^= (*b);
    *b ^= (*a);
    *a ^= (*b);
}


void Dec2Hex(char* string, uint32_t number)
{
    uint8_t digit = 0;
    uint8_t ii = 0;
    
    for(; number; number/=16)
    {
        digit = number % 16;
        string[ii++] = (digit >= 0 && digit <= 9) ? digit + '0' : digit + ('a' - 10);
    }
    string[ii] = '\n';
}
