static const unsigned char CyclesFD[256] =
{
   0, 0, 0, 0, 0, 0, 0, 0, 0,15, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0,15, 0, 0, 0, 0, 0, 0,
   0,14,20,10, 9, 9, 9, 0, 0,15,20,10, 9, 9, 9, 0,
   0, 0, 0, 0,23,23,19, 0, 0,15, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 9, 9,19, 0, 0, 0, 0, 0, 9, 9,19, 0,
   0, 0, 0, 0, 9, 9,19, 0, 0, 0, 0, 0, 9, 9,19, 0,
   9, 9, 9, 9, 9, 9,19, 9, 9, 9, 9, 9, 9, 9,19, 9,
  19,19,19,19,19,19,19,19, 0, 0, 0, 0, 9, 9,19, 0,
   0, 0, 0, 0, 9, 9,19, 0, 0, 0, 0, 0, 9, 9,19, 0,
   0, 0, 0, 0, 9, 9,19, 0, 0, 0, 0, 0, 9, 9,19, 0,
   0, 0, 0, 0, 9, 9,19, 0, 0, 0, 0, 0, 9, 9,19, 0,
   0, 0, 0, 0, 9, 9,19, 0, 0, 0, 0, 0, 9, 9,19, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0,14, 0,23, 0,15, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0,10, 0, 0, 0, 0, 0, 0
};


static const unsigned char CyclesFDCB[256] =
{
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
  20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
  20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
  20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
  20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0,
   0, 0, 0, 0, 0, 0,23, 0, 0, 0, 0, 0, 0, 0,23, 0
};


static void z80_exec_extended_FDCB(struct z80* z80, struct z80cpm_memory* z80cpm_memory)
{
    unsigned char I; //register
    unsigned short J; //register

    J = z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
    I = OpZ80(z80, z80cpm_memory, z80->registers.PC);
    unsigned char opcode = I;
    z80->ICount -= CyclesFDCB[I];

    switch(I)
    {
        case RLC_xHL:      debug_opcode(z80, (char *)"RLC_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            I = RdZ80(z80cpm_memory, J); M_RLC(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case RRC_xHL:      debug_opcode(z80, (char *)"RRC_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            I = RdZ80(z80cpm_memory, J); M_RRC(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case RL_xHL:      debug_opcode(z80, (char *)"RL_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            I = RdZ80(z80cpm_memory, J); M_RL(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case RR_xHL:      debug_opcode(z80, (char *)"RR_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            I = RdZ80(z80cpm_memory, J); M_RR(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case SLA_xHL:      debug_opcode(z80, (char *)"SLA_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            I = RdZ80(z80cpm_memory, J); M_SLA(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case SRA_xHL:      debug_opcode(z80, (char *)"SRA_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            I = RdZ80(z80cpm_memory, J); M_SRA(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case SLL_xHL:      debug_opcode(z80, (char *)"SLL_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            I = RdZ80(z80cpm_memory, J); M_SLL(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case SRL_xHL:      debug_opcode(z80, (char *)"SRL_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            I = RdZ80(z80cpm_memory, J); M_SRL(z80, I); WrZ80(z80cpm_memory, J, I); break; 

        case BIT0_xHL:      debug_opcode(z80, (char *)"BIT0_xIY+BYTE", (char *)"Test bit 0 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 0, I); break; 
        case BIT1_xHL:      debug_opcode(z80, (char *)"BIT1_xIY+BYTE", (char *)"Test bit 1 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 1, I); break; 
        case BIT2_xHL:      debug_opcode(z80, (char *)"BIT2_xIY+BYTE", (char *)"Test bit 2 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 2, I); break; 
        case BIT3_xHL:      debug_opcode(z80, (char *)"BIT3_xIY+BYTE", (char *)"Test bit 3 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 3, I); break; 
        case BIT4_xHL:      debug_opcode(z80, (char *)"BIT4_xIY+BYTE", (char *)"Test bit 4 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 4, I); break; 
        case BIT5_xHL:      debug_opcode(z80, (char *)"BIT5_xIY+BYTE", (char *)"Test bit 5 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 5, I); break; 
        case BIT6_xHL:      debug_opcode(z80, (char *)"BIT6_xIY+BYTE", (char *)"Test bit 6 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 6, I); break; 
        case BIT7_xHL:      debug_opcode(z80, (char *)"BIT7_xIY+BYTE", (char *)"Test bit 7 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_BIT(z80, 7, I); break; 

        case SET0_xHL:      debug_opcode(z80, (char *)"SET0_xIY+BYTE", (char *)"Set bit 0 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 0, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET1_xHL:      debug_opcode(z80, (char *)"SET1_xIY+BYTE", (char *)"Set bit 1 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 1, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET2_xHL:      debug_opcode(z80, (char *)"SET2_xIY+BYTE", (char *)"Set bit 2 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 2, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET3_xHL:      debug_opcode(z80, (char *)"SET3_xIY+BYTE", (char *)"Set bit 3 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 3, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET4_xHL:      debug_opcode(z80, (char *)"SET4_xIY+BYTE", (char *)"Set bit 4 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 4, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET5_xHL:      debug_opcode(z80, (char *)"SET5_xIY+BYTE", (char *)"Set bit 5 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 5, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET6_xHL:      debug_opcode(z80, (char *)"SET6_xIY+BYTE", (char *)"Set bit 6 of  the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 6, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET7_xHL:      debug_opcode(z80, (char *)"SET7_xIY+BYTE", (char *)"Set bit 7 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_SET(z80, 7, I); WrZ80(z80cpm_memory, J, I); break; 
        
        case RES0_xHL:      debug_opcode(z80, (char *)"RES0_xIY+BYTE", (char *)"Reset bit 0 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 0, I); WrZ80(z80cpm_memory, J, I); break;        
        case RES1_xHL:      debug_opcode(z80, (char *)"RES1_xIY+BYTE", (char *)"Reset bit 1 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 1, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES2_xHL:      debug_opcode(z80, (char *)"RES2_xIY+BYTE", (char *)"Reset bit 2 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 2, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES3_xHL:      debug_opcode(z80, (char *)"RES3_xIY+BYTE", (char *)"Reset bit 3 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 3, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES4_xHL:      debug_opcode(z80, (char *)"RES4_xIY+BYTE", (char *)"Reset bit 4 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 4, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES5_xHL:      debug_opcode(z80, (char *)"RES5_xIY+BYTE", (char *)"Reset bit 5 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 5, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES6_xHL:      debug_opcode(z80, (char *)"RES6_xIY+BYTE", (char *)"Reset bit 6 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 6, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES7_xHL:      debug_opcode(z80, (char *)"RES7_xIY+BYTE", (char *)"Reset bit 7 of the memory location pointed to by iy plus BYTE.");
            I = RdZ80(z80cpm_memory, J); M_RES(z80, 7, I); WrZ80(z80cpm_memory, J, I); break; 
        
	

        default:{
            char str2[20];
            sprintf(str2,"unknown 0x%x",opcode);
            debug_opcode(z80, str2,(char *)"");
             if(z80->TrapBadOps)
            printf
            (
                "[Z80 %lX] Unrecognized instruction: FD CB %02X %02X at PC=%04X\n",
                (long)(z80->User),OpZ80(z80, z80cpm_memory, z80->registers.PC-2),OpZ80(z80, z80cpm_memory, z80->registers.PC-1),z80, z80->registers.PC-4
            );
        }
    }
}


static void z80_exec_extended_FD(struct z80* z80, struct z80cpm_memory* z80cpm_memory)
{
  unsigned char I; //register
  unsigned short J; //register

//  #define XX IY
  I = OpZ80(z80, z80cpm_memory, z80->registers.PC);
  unsigned char opcode = I;
  z80->ICount -= CyclesFD[I];


  switch(I)
  {
  

    case ADD_HL_BC:     debug_opcode(z80, (char *)"ADD_IY_BC", (char *)"The value of BC is added to IY");
        M_ADDW(z80, IY, BC);break; 
    case ADD_HL_DE:     debug_opcode(z80, (char *)"ADD_IY_DE", (char *)"The value of DE is added to IY");
        M_ADDW(z80, IY, DE);break;
    case ADD_HL_HL:     debug_opcode(z80, (char *)"ADD_IY_IY", (char *)"The value of IY is added to IY");
        M_ADDW(z80, IY, IY);break;
    case ADD_HL_SP:     debug_opcode(z80, (char *)"ADD_IY_SP", (char *)"The value of SP is added to IY");
        M_ADDW(z80, IY, SP);break;

    case ADD_H:         debug_opcode(z80, (char *)"ADD_IYh", (char *)"Adds IYh to A");
        M_ADD(z80, MSB(z80->registers.IY));break;
    case ADD_L:         debug_opcode(z80, (char *)"ADD_IYl", (char *)"Adds IYl to A");
        M_ADD(z80, LSB(z80->registers.IY));break;
    case ADD_xHL:       debug_opcode(z80, (char *)"ADD_xIY+BYTE", (char *)"Adds the value pointed by (IY) plus BYTE to A");
        I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
        M_ADD(z80, I); break;


    case INC_HL:         debug_opcode(z80, (char *)"INC_IY", (char *)"Adds one to IY");
        z80->registers.IY++;break;
    case INC_H:           debug_opcode(z80, (char *)"INC_IYh", (char *)"Adds one to IYh");
        M_INC_H(z80, z80->registers.IY);break;
    case INC_L:           debug_opcode(z80, (char *)"INC_IYl", (char *)"Adds one to IYl");
        M_INC_L(z80, z80->registers.IY);break;
    case INC_xHL:       debug_opcode(z80, (char *)"INC_xIY+BYTE", (char *)"Adds one to the memory location pointed to by IY plus BYTE.");
        I = RdZ80(z80cpm_memory, z80->registers.IY + RdZ80(z80cpm_memory, z80->registers.PC));
        M_INC_L(z80, I);
        WrZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC), I);
        break;

    case DEC_HL:         debug_opcode(z80, (char *)"DEC_IY", (char *)"Subtracts one to IY");
        z80->registers.IY--;break;
    case DEC_H:           debug_opcode(z80, (char *)"DEC_IYh", (char *)"Subtracts one to IYh");
        M_DEC_H(z80, z80->registers.IY);break;
    case DEC_L:           debug_opcode(z80, (char *)"DEC_IYl", (char *)"Subtracts one to IYl");
        M_DEC_L(z80, z80->registers.IY);break;
    case DEC_xHL:       debug_opcode(z80, (char *)"DEC_xIY+BYTE", (char *)"Subtracts one from the memory location pointed to by IY plus BYTE.");
        I = RdZ80(z80cpm_memory, z80->registers.IY + RdZ80(z80cpm_memory, z80->registers.PC));
        M_INC_L(z80, I);
        WrZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC), I);
        break;

    case ADC_H:         debug_opcode(z80, (char *)"ADC_IYh", (char *)"Adds IYh and the carry flag to A");
        M_ADC(z80, MSB(z80->registers.IY));break;
    case ADC_L:         debug_opcode(z80, (char *)"ADC_IYl", (char *)"Adds IYl and the carry flag to A");
        M_ADC(z80, LSB(z80->registers.IY));break;
    case ADC_xHL:      debug_opcode(z80, (char *)"ADC_xIY+BYTE", (char *)"Adds the value pointed to by IY plus BYTE and the carry flag to A");        
        I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
        M_ADC(z80, I);break;

    case SUB_H:      debug_opcode(z80, (char *)"SUB_IYh", (char *)"Subtracts IYh from A");    
        M_SUB(z80, MSB(z80->registers.IY));break;
    case SUB_L:      debug_opcode(z80, (char *)"SUB_IYl", (char *)"Subtracts IYl from A");    
        M_SUB(z80, LSB(z80->registers.IY));break;
    case SUB_xHL:       debug_opcode(z80, (char *)"SUB_xIY+BYTE", (char *)"Subtracts the value pointed to by IY plus BYTE from A.");
        I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
        M_SUB(z80, I);break;


    case SBC_H:      debug_opcode(z80, (char *)"SBC_IYh", (char *)"Subtracts IYh and the carry flag from A");    
        M_SBC(z80, MSB(z80->registers.IY));break;
    case SBC_L:      debug_opcode(z80, (char *)"SBC_IYl", (char *)"Subtracts IYl and the carry flag from A");    
        M_SBC(z80, LSB(z80->registers.IY));break;
    case SBC_xHL:       debug_opcode(z80, (char *)"SBC_xIY+BYTE", (char *)"Subtracts the value pointed to by IY plus BYTE and the carry flag from A.");
        I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
        M_SBC(z80, I);break;


    case AND_H:      debug_opcode(z80, (char *)"AND_IYh", (char *)"Bitwise AND on A with IYh");    
        M_AND(z80, MSB(z80->registers.IY));break;
    case AND_L:      debug_opcode(z80, (char *)"AND_IYl", (char *)"Bitwise AND on A with IYl");    
        M_AND(z80, LSB(z80->registers.IY));break;
    case AND_xHL:       debug_opcode(z80, (char *)"AND_xIY+BYTE", (char *)"Bitwise AND on A with value pointed to by IY plus BYTE");
      I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
      M_AND(z80, I);break;

    case XOR_H:      debug_opcode(z80, (char *)"XOR_IYh", (char *)"Bitwise XOR on A with IYh");    
        M_XOR(z80, MSB(z80->registers.IY));break;
    case XOR_L:      debug_opcode(z80, (char *)"XOR_IYl", (char *)"Bitwise XOR on A with IYl");    
        M_XOR(z80, LSB(z80->registers.IY));break;
    case XOR_xHL:    debug_opcode(z80, (char *)"XOR_xIY+BYTE", (char *)"Bitwise XOR on A with value pointed to by IY plus BYTE");
      I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
      M_XOR(z80, I);break;

    case OR_H:      debug_opcode(z80, (char *)"XOR_IYh", (char *)"Bitwise OR on A with IYh");    
        M_XOR(z80, MSB(z80->registers.IY));break;
    case OR_L:      debug_opcode(z80, (char *)"XOR_IYl", (char *)"Bitwise OR on A with IYl");    
        M_OR(z80, LSB(z80->registers.IY));break;
    case OR_xHL:    debug_opcode(z80, (char *)"XOR_xIY+BYTE", (char *)"Bitwise OR on A with value pointed to by IY plus BYTE");
        I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
        M_OR(z80, I);break;

    case CP_H:      debug_opcode(z80, (char *)"CP_IYh", (char *)"Subtracts IYh from A and affects flags according to the result. A is not modified.");    
        M_CP(z80, MSB(z80->registers.IY));break;
    case CP_L:      debug_opcode(z80, (char *)"CP_IYl", (char *)"Subtracts IYl from A and affects flags according to the result. A is not modified.");    
        M_CP(z80, LSB(z80->registers.IY));break;
    case CP_xHL:    debug_opcode(z80, (char *)"CP_xIY+BYTE", (char *)"Subtracts the value pointed to by IY plus BYTE from A and affects flags according to the result. A is not modified.");
        I = RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC));
        M_CP(z80, I);break;

    case POP_HL:       debug_opcode(z80, (char *)"POP_IY", (char *)"The memory location pointed to by SP is stored into IYl and SP is incremented. The memory location pointed to by SP is stored into IYh and SP is incremented again"); 
        M_POP(z80, z80cpm_memory, IY);break;

    case EX_xSP_HL:      debug_opcode(z80, (char *)"EX_xSP_IY", (char*)"Exchanges (SP) with IYl, and (SP+1) with IYh");
        J = z80->registers.IY;
        SET_WORD(z80->registers.IY, RdZ80(z80cpm_memory, z80->registers.SP), 
                                    RdZ80(z80cpm_memory, z80->registers.SP + 1)); 
        
        WrZ80(z80cpm_memory, z80->registers.SP, LSB(J));
        WrZ80(z80cpm_memory, z80->registers.SP+1, MSB(J));

      break;

    case PUSH_HL:       debug_opcode(z80, (char *)"PUSH_IY", (char *)"SP is decremented and IYh is stored into the memory location pointed to by SP. SP is decremented again and IYl is stored pointed to by SP"); 
        M_PUSH(z80, z80cpm_memory,IY);break;

                    
      case LD_HL_WORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_IY_WORD", (char *)"Loads ** into IY"); 
        M_LDWORD(z80, z80cpm_memory, z80->registers.IY);break;
      case LD_xWORD_HL:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_xWORD_IY", (char *)"Stores IY into the memory location pointed to by WORD");
        M_LDWORD(z80, z80cpm_memory, J); 
        WrZ80(z80cpm_memory, J, LSB(z80->registers.IY));
        J += 1;
        WrZ80(z80cpm_memory, J, MSB(z80->registers.IY));
        break;
      case LD_H_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_IYh_BYTE", (char *)"Load BYTE into IYh");
          SET_MSB(z80->registers.IY, OpZ80(z80, z80cpm_memory, z80->registers.PC));
          break;
      case LD_HL_xWORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_IY_xWORD", (char *)"Load value pointed to by WORD into IY");
        M_LDWORD(z80, z80cpm_memory, J); 
        SET_LSB(z80->registers.IY, RdZ80(z80cpm_memory, J));
        J += 1;
        SET_MSB(z80->registers.IY, RdZ80(z80cpm_memory, J));
        break;
      case LD_L_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_IYl_BYTE", (char *)"Load BYTE into IYl");
          SET_LSB(z80->registers.IY, OpZ80(z80, z80cpm_memory, z80->registers.PC));
          break;

      case LD_xHL_BYTE:   debug_opcode_reg_byte_byte(z80, z80cpm_memory, (char *)"LD_xIYl_BYTE", (char *)"Stores BYTE to the memory location pointed to by IY plus BYTE");
          J = z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J,OpZ80(z80, z80cpm_memory, z80->registers.PC));
          break;


      case LD_B_H:        debug_opcode(z80, (char *)"LD_B_IYh", (char *)"The content of IYh is loaded into B");
          SET_MSB(z80->registers.BC, MSB(z80->registers.IY));break;
      case LD_B_L:        debug_opcode(z80, (char *)"LD_B_IYl", (char *)"The content of IYl is loaded into B");
          SET_MSB(z80->registers.BC, LSB(z80->registers.IY));break;
      case LD_B_xHL:      debug_opcode(z80, (char *)"LD_B_xIY", (char *)"The contents of IY plus BYTE are loaded into B");
          SET_MSB(z80->registers.BC, RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;

      case LD_C_H:        debug_opcode(z80, (char *)"LD_C_IYh", (char *)"The content of IYh is loaded into C");
          SET_LSB(z80->registers.BC, MSB(z80->registers.IY));break;
      case LD_C_L:        debug_opcode(z80, (char *)"LD_C_IYl", (char *)"The content of IYl is loaded into C");
          SET_LSB(z80->registers.BC, LSB(z80->registers.IY));break;
      case LD_C_xHL:      debug_opcode(z80, (char *)"LD_C_xIY", (char *)"The contents of IY plus BYTE are loaded into C");
          SET_LSB(z80->registers.BC, RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;

      case LD_D_H:        debug_opcode(z80, (char *)"LD_D_IYh", (char *)"The content of IYh is loaded into D");
          SET_MSB(z80->registers.DE, MSB(z80->registers.IY));break;
      case LD_D_L:        debug_opcode(z80, (char *)"LD_D_IYl", (char *)"The content of IYl is loaded into D");
          SET_MSB(z80->registers.DE, LSB(z80->registers.IY));break;
      case LD_D_xHL:      debug_opcode(z80, (char *)"LD_D_xIY", (char *)"The contents of IY plus BYTE are loaded into D");
          SET_MSB(z80->registers.DE, RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;

      case LD_E_H:        debug_opcode(z80, (char *)"LD_E_IYh", (char *)"The content of IYh is loaded into E");
          SET_LSB(z80->registers.DE, MSB(z80->registers.IY));break;
      case LD_E_L:        debug_opcode(z80, (char *)"LD_E_IYl", (char *)"The content of IYl is loaded into E");
          SET_LSB(z80->registers.DE, LSB(z80->registers.IY));break;
      case LD_E_xHL:      debug_opcode(z80, (char *)"LD_E_xIY", (char *)"The contents of IY plus BYTE are loaded into E");
          SET_LSB(z80->registers.DE, RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;


      case LD_H_B:        debug_opcode(z80, (char *)"LD_IYh_B", (char *)"The content of B is loaded into IYh");
          SET_MSB(z80->registers.IY, MSB(z80->registers.BC));break;
      case LD_H_C:        debug_opcode(z80, (char *)"LD_IYh_C", (char *)"The content of C is loaded into IYh");
          SET_MSB(z80->registers.IY, LSB(z80->registers.BC));break;
      case LD_H_D:        debug_opcode(z80, (char *)"LD_IYh_D", (char *)"The content of D is loaded into IYh");
          SET_MSB(z80->registers.IY, MSB(z80->registers.DE));break;
      case LD_H_E:        debug_opcode(z80, (char *)"LD_IYh_E", (char *)"The content of E is loaded into IYh");
          SET_MSB(z80->registers.IY, LSB(z80->registers.DE));break;

      case LD_H_H:        debug_opcode(z80, (char *)"LD_IYh_IYh", (char *)"The content of IYh is loaded into IYh");
          SET_MSB(z80->registers.IY, MSB(z80->registers.IY));break;
      case LD_H_L:        debug_opcode(z80, (char *)"LD_IYh_IYl", (char *)"The content of IYh is loaded into IYl");
          SET_MSB(z80->registers.IY, LSB(z80->registers.IY));break;
      case LD_H_xHL:      debug_opcode(z80, (char *)"LD_H_IYL", (char *)"Loads the value pointed to IY plus BYTE into H");
          SET_MSB(z80->registers.HL, RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;

      case LD_H_A:      debug_opcode(z80, (char *)"LD_xIYh_A", (char *)"The contents of A are loaded into IYh");
          SET_MSB(z80->registers.IY, MSB(z80->registers.AF));break;

      case LD_L_B:      debug_opcode(z80, (char *)"LD_xIYl_B", (char *)"The contents of B are loaded into IYl");
          SET_LSB(z80->registers.IY, MSB(z80->registers.BC));break;
      case LD_L_C:      debug_opcode(z80, (char *)"LD_xIYl_C", (char *)"The contents of C are loaded into IYl");
          SET_LSB(z80->registers.IY, LSB(z80->registers.BC));break;
      case LD_L_D:      debug_opcode(z80, (char *)"LD_xIYl_D", (char *)"The contents of D are loaded into IYl");
          SET_LSB(z80->registers.IY, MSB(z80->registers.DE));break;
      case LD_L_E:      debug_opcode(z80, (char *)"LD_xIYl_E", (char *)"The contents of E are loaded into IYl");
          SET_LSB(z80->registers.IY, LSB(z80->registers.DE));break;

      case LD_L_H:        debug_opcode(z80, (char *)"LD_IYl_IYh", (char *)"The content of IYl is loaded into IYh");
          SET_LSB(z80->registers.IY, MSB(z80->registers.IY));break;
      case LD_L_L:        debug_opcode(z80, (char *)"LD_IYl_IYl", (char *)"The content of IYl is loaded into IYl");
          SET_LSB(z80->registers.IY, LSB(z80->registers.IY));break;
      case LD_L_xHL:        debug_opcode(z80, (char *)"LD_L_xIY", (char *)"Loads the value pointed to IY plus BYTE into L");
          SET_LSB(z80->registers.HL, RdZ80(z80cpm_memory, z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;
      case LD_L_A:      debug_opcode(z80, (char *)"LD_xIYl_A", (char *)"The contents of A are loaded into IYl");
          SET_LSB(z80->registers.IY, MSB(z80->registers.AF));break;

      case LD_xHL_B:      debug_opcode(z80, (char *)"LD_xIY_B", (char *)"Stores B to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J, MSB(z80->registers.BC));break;
      case LD_xHL_C:      debug_opcode(z80, (char *)"LD_xIY_C", (char *)"Stores C to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J,LSB(z80->registers.BC));break;
      case LD_xHL_D:      debug_opcode(z80, (char *)"LD_xIY_D", (char *)"Stores D to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J,MSB(z80->registers.DE));break;
      case LD_xHL_E:      debug_opcode(z80, (char *)"LD_xIY_E", (char *)"Stores E to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J, LSB(z80->registers.DE));break;
      case LD_xHL_H:      debug_opcode(z80, (char *)"LD_xIY_H", (char *)"Stores H to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J,MSB(z80->registers.HL));break;
      case LD_xHL_L:      debug_opcode(z80, (char *)"LD_xIY_L", (char *)"Stores L to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J, LSB(z80->registers.HL));break;

      case LD_xHL_A:      debug_opcode(z80, (char *)"LD_xIY_A", (char *)"Stores A to the memory location pointed to by IY plus BYTE");
          J=z80->registers.IY + OpZ80(z80, z80cpm_memory, z80->registers.PC);
          WrZ80(z80cpm_memory, J, MSB(z80->registers.AF));break;
      case LD_A_H:        debug_opcode(z80, (char *)"LD_A_IYh", (char *)"The content of IYh is loaded into A");
          SET_MSB(z80->registers.AF, MSB(z80->registers.IY));break;
      case LD_A_L:        debug_opcode(z80, (char *)"LD_A_IYl", (char *)"The content of IYl is loaded into A");
          SET_MSB(z80->registers.AF, LSB(z80->registers.IY));break;
      case LD_A_xHL:        debug_opcode(z80, (char *)"LD_L_xIY", (char *)"Loads the value pointed to IY plus BYTE into A");
          SET_MSB(z80->registers.AF, RdZ80(z80cpm_memory, z80->registers.IY+ OpZ80(z80, z80cpm_memory, z80->registers.PC)));
          break;


      case LD_PC_HL:        debug_opcode(z80, (char *)"LD_PC_IY", (char *)"Loads the value of IY into PC");
              z80->registers.PC=z80->registers.IY;JumpZ80(z80, z80->registers.PC);break;
      case LD_SP_HL:        debug_opcode(z80, (char *)"LD_SP_IY", (char *)"Loads the value of IY into SP");
              z80->registers.SP=z80->registers.IY;break;



    case PFX_FD:
    case PFX_DD:
      z80->registers.PC--;break;
    case PFX_CB:
      z80_exec_extended_FDCB(z80, z80cpm_memory);break;
    default:{
      char str2[20];
      sprintf(str2,"unknown 0x%x",opcode);
      debug_opcode(z80, str2, (char*)"");
        if(z80->TrapBadOps)
      printf
      (
          "[Z80 %lX] Unrecognized instruction: FD %02X at PC=%04X\n",
          (long)z80->User,OpZ80(z80, z80cpm_memory, z80->registers.PC-1),z80->registers.PC-2
      );
    }
  //#undef XX
  }
}