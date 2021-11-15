#ifndef Z80REGISTERS_H
#define Z80REGISTERS_H

#include "config.h"
struct z80_registers
{
    //General Purpose Registers
    unsigned short AF; //	AH/FL(accumulator and flags)	8-bit accumulator (A) and flag bits (F) carry, zero, minus, parity/overflow, half-carry (used for BCD), and an Add/Subtract flag (usually called N) also for BCD
    unsigned short BC; //	BH/CL	16-bit data/address register or two 8-bit registers
    unsigned short DE; //	DH/EL	16-bit data/address register or two 8-bit registers
    unsigned short HL; //	HH/LL(indirect address)	16-bit accumulator/address register or two 8-bit registers
    
    //Alternate registers
    unsigned short AFl; //AF': alternate (or shadow) accumulator and flags (toggled in and out with EX AF,AF' )
    unsigned short BCl; //BC', DE' and HL': alternate (or shadow) registers (toggled in and out with EXX)
    unsigned short DEl; 
    unsigned short HLl; 

    //Index registers
    unsigned short IX;   //IX(Index X)  16-bit index or base register for 8-bit immediate offsets
    unsigned short IY;   //IYIndex Y)   16-bit index or base register for 8-bit immediate offsets
    unsigned short SP;  //SP            stack pointer, 16 bits

    //Program counter
    unsigned short PC;  //PC	-	program counter, 16 bits

    //Other registers
    unsigned char IFF,I;     //I: interrupt vector base register, 8 bits
    unsigned char R;     //R: DRAM refresh counter, 8 bits (msb does not count)

    //Interrupt registers
    //IFF1
    //IFF2
    //IM


    //Status register(F) - flags
    //unsigned char S;       /*flag S     Result negative         */
    //unsigned char Z;       /*flag Z     Result is zero          */
    //unsigned char H;       /*flag H     Halfcarry/Halfborrow    */
    //unsigned char P;       /*flag P     Result is even          */
    //unsigned char V;       /*flag V     Overflow occured        */
    //unsigned char N;       /*flag N     Subtraction occured     */
    //unsigned char C;       /*flag C     Carry/Borrow occured    */

};

#endif