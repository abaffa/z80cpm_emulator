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


void Z80::z80_exec_extended_FDCB(struct z80cpm_memory* z80cpm_memory)
{
    unsigned char I; //register
    unsigned short J; //register

    J = this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
    I = this->OpZ80(z80cpm_memory, this->registers.PC);
    unsigned char opcode = I;
    this->ICount -= CyclesFDCB[I];

    switch(I)
    {
        case RLC_xHL:      this->debug_opcode((char *)"RLC_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_RLC(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case RRC_xHL:      this->debug_opcode((char *)"RRC_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            I = this->RdZ80(z80cpm_memory, J); M_RRC(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case RL_xHL:      this->debug_opcode((char *)"RL_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_RL(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case RR_xHL:      this->debug_opcode((char *)"RR_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            I = this->RdZ80(z80cpm_memory, J); M_RR(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SLA_xHL:      this->debug_opcode((char *)"SLA_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_SLA(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SRA_xHL:      this->debug_opcode((char *)"SRA_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            I = this->RdZ80(z80cpm_memory, J); M_SRA(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SLL_xHL:      this->debug_opcode((char *)"SLL_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_SLL(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SRL_xHL:      this->debug_opcode((char *)"SRL_xIY+BYTE", (char *)"The contents of the memory location pointed to by iy plus BYTE are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            I = this->RdZ80(z80cpm_memory, J); M_SRL(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case BIT0_xHL:      this->debug_opcode((char *)"BIT0_xIY+BYTE", (char *)"Test bit 0 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 0, I); break; 
        case BIT1_xHL:      this->debug_opcode((char *)"BIT1_xIY+BYTE", (char *)"Test bit 1 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 1, I); break; 
        case BIT2_xHL:      this->debug_opcode((char *)"BIT2_xIY+BYTE", (char *)"Test bit 2 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 2, I); break; 
        case BIT3_xHL:      this->debug_opcode((char *)"BIT3_xIY+BYTE", (char *)"Test bit 3 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 3, I); break; 
        case BIT4_xHL:      this->debug_opcode((char *)"BIT4_xIY+BYTE", (char *)"Test bit 4 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 4, I); break; 
        case BIT5_xHL:      this->debug_opcode((char *)"BIT5_xIY+BYTE", (char *)"Test bit 5 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 5, I); break; 
        case BIT6_xHL:      this->debug_opcode((char *)"BIT6_xIY+BYTE", (char *)"Test bit 6 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 6, I); break; 
        case BIT7_xHL:      this->debug_opcode((char *)"BIT7_xIY+BYTE", (char *)"Test bit 7 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 7, I); break; 

        case SET0_xHL:      this->debug_opcode((char *)"SET0_xIY+BYTE", (char *)"Set bit 0 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 0, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET1_xHL:      this->debug_opcode((char *)"SET1_xIY+BYTE", (char *)"Set bit 1 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 1, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET2_xHL:      this->debug_opcode((char *)"SET2_xIY+BYTE", (char *)"Set bit 2 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 2, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET3_xHL:      this->debug_opcode((char *)"SET3_xIY+BYTE", (char *)"Set bit 3 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 3, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET4_xHL:      this->debug_opcode((char *)"SET4_xIY+BYTE", (char *)"Set bit 4 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 4, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET5_xHL:      this->debug_opcode((char *)"SET5_xIY+BYTE", (char *)"Set bit 5 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 5, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET6_xHL:      this->debug_opcode((char *)"SET6_xIY+BYTE", (char *)"Set bit 6 of  the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 6, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET7_xHL:      this->debug_opcode((char *)"SET7_xIY+BYTE", (char *)"Set bit 7 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 7, I); WrZ80(z80cpm_memory, J, I); break; 
        
        case RES0_xHL:      this->debug_opcode((char *)"RES0_xIY+BYTE", (char *)"Reset bit 0 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 0, I); WrZ80(z80cpm_memory, J, I); break;        
        case RES1_xHL:      this->debug_opcode((char *)"RES1_xIY+BYTE", (char *)"Reset bit 1 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 1, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES2_xHL:      this->debug_opcode((char *)"RES2_xIY+BYTE", (char *)"Reset bit 2 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 2, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES3_xHL:      this->debug_opcode((char *)"RES3_xIY+BYTE", (char *)"Reset bit 3 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 3, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES4_xHL:      this->debug_opcode((char *)"RES4_xIY+BYTE", (char *)"Reset bit 4 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 4, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES5_xHL:      this->debug_opcode((char *)"RES5_xIY+BYTE", (char *)"Reset bit 5 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 5, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES6_xHL:      this->debug_opcode((char *)"RES6_xIY+BYTE", (char *)"Reset bit 6 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 6, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES7_xHL:      this->debug_opcode((char *)"RES7_xIY+BYTE", (char *)"Reset bit 7 of the memory location pointed to by iy plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 7, I); WrZ80(z80cpm_memory, J, I); break; 
        
	

        default:{
            char str2[20];
            sprintf(str2,"unknown 0x%x",opcode);
            this->debug_opcode(str2,(char *)"");
             if(this->TrapBadOps)
            printf
            (
                "[Z80 %lX] Unrecognized instruction: FD CB %02X %02X at PC=%04X\n",
                (long)(this->User),this->OpZ80(z80cpm_memory, this->registers.PC-2),this->OpZ80(z80cpm_memory, this->registers.PC-1),this, this->registers.PC-4
            );
        }
    }
}


void Z80::z80_exec_extended_FD(struct z80cpm_memory* z80cpm_memory)
{
  unsigned char I; //register
  unsigned short J; //register

//  #define XX IY
  I = this->OpZ80(z80cpm_memory, this->registers.PC);
  unsigned char opcode = I;
  this->ICount -= CyclesFD[I];


  switch(I)
  {
  

    case ADD_HL_BC:     this->debug_opcode((char *)"ADD_IY_BC", (char *)"The value of BC is added to IY");
        M_ADDW(this, IY, BC);break; 
    case ADD_HL_DE:     this->debug_opcode((char *)"ADD_IY_DE", (char *)"The value of DE is added to IY");
        M_ADDW(this, IY, DE);break;
    case ADD_HL_HL:     this->debug_opcode((char *)"ADD_IY_IY", (char *)"The value of IY is added to IY");
        M_ADDW(this, IY, IY);break;
    case ADD_HL_SP:     this->debug_opcode((char *)"ADD_IY_SP", (char *)"The value of SP is added to IY");
        M_ADDW(this, IY, SP);break;

    case ADD_H:         this->debug_opcode((char *)"ADD_IYh", (char *)"Adds IYh to A");
        M_ADD(this, MSB(this->registers.IY));break;
    case ADD_L:         this->debug_opcode((char *)"ADD_IYl", (char *)"Adds IYl to A");
        M_ADD(this, LSB(this->registers.IY));break;
    case ADD_xHL:       this->debug_opcode((char *)"ADD_xIY+BYTE", (char *)"Adds the value pointed by (IY) plus BYTE to A");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_ADD(this, I); break;


    case INC_HL:         this->debug_opcode((char *)"INC_IY", (char *)"Adds one to IY");
        this->registers.IY++;break;
    case INC_H:           this->debug_opcode((char *)"INC_IYh", (char *)"Adds one to IYh");
        M_INC_H(this, this->registers.IY);break;
    case INC_L:           this->debug_opcode((char *)"INC_IYl", (char *)"Adds one to IYl");
        M_INC_L(this, this->registers.IY);break;
    case INC_xHL:       this->debug_opcode((char *)"INC_xIY+BYTE", (char *)"Adds one to the memory location pointed to by IY plus BYTE.");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + RdZ80(z80cpm_memory, this->registers.PC));
        M_INC_L(this, I);
        WrZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC), I);
        break;

    case DEC_HL:         this->debug_opcode((char *)"DEC_IY", (char *)"Subtracts one to IY");
        this->registers.IY--;break;
    case DEC_H:           this->debug_opcode((char *)"DEC_IYh", (char *)"Subtracts one to IYh");
        M_DEC_H(this, this->registers.IY);break;
    case DEC_L:           this->debug_opcode((char *)"DEC_IYl", (char *)"Subtracts one to IYl");
        M_DEC_L(this, this->registers.IY);break;
    case DEC_xHL:       this->debug_opcode((char *)"DEC_xIY+BYTE", (char *)"Subtracts one from the memory location pointed to by IY plus BYTE.");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + RdZ80(z80cpm_memory, this->registers.PC));
        M_INC_L(this, I);
        WrZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC), I);
        break;

    case ADC_H:         this->debug_opcode((char *)"ADC_IYh", (char *)"Adds IYh and the carry flag to A");
        M_ADC(this, MSB(this->registers.IY));break;
    case ADC_L:         this->debug_opcode((char *)"ADC_IYl", (char *)"Adds IYl and the carry flag to A");
        M_ADC(this, LSB(this->registers.IY));break;
    case ADC_xHL:      this->debug_opcode((char *)"ADC_xIY+BYTE", (char *)"Adds the value pointed to by IY plus BYTE and the carry flag to A");        
        I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_ADC(this, I);break;

    case SUB_H:      this->debug_opcode((char *)"SUB_IYh", (char *)"Subtracts IYh from A");    
        M_SUB(this, MSB(this->registers.IY));break;
    case SUB_L:      this->debug_opcode((char *)"SUB_IYl", (char *)"Subtracts IYl from A");    
        M_SUB(this, LSB(this->registers.IY));break;
    case SUB_xHL:       this->debug_opcode((char *)"SUB_xIY+BYTE", (char *)"Subtracts the value pointed to by IY plus BYTE from A.");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_SUB(this, I);break;


    case SBC_H:      this->debug_opcode((char *)"SBC_IYh", (char *)"Subtracts IYh and the carry flag from A");    
        M_SBC(this, MSB(this->registers.IY));break;
    case SBC_L:      this->debug_opcode((char *)"SBC_IYl", (char *)"Subtracts IYl and the carry flag from A");    
        M_SBC(this, LSB(this->registers.IY));break;
    case SBC_xHL:       this->debug_opcode((char *)"SBC_xIY+BYTE", (char *)"Subtracts the value pointed to by IY plus BYTE and the carry flag from A.");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_SBC(this, I);break;


    case AND_H:      this->debug_opcode((char *)"AND_IYh", (char *)"Bitwise AND on A with IYh");    
        M_AND(this, MSB(this->registers.IY));break;
    case AND_L:      this->debug_opcode((char *)"AND_IYl", (char *)"Bitwise AND on A with IYl");    
        M_AND(this, LSB(this->registers.IY));break;
    case AND_xHL:       this->debug_opcode((char *)"AND_xIY+BYTE", (char *)"Bitwise AND on A with value pointed to by IY plus BYTE");
      I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
      M_AND(this, I);break;

    case XOR_H:      this->debug_opcode((char *)"XOR_IYh", (char *)"Bitwise XOR on A with IYh");    
        M_XOR(this, MSB(this->registers.IY));break;
    case XOR_L:      this->debug_opcode((char *)"XOR_IYl", (char *)"Bitwise XOR on A with IYl");    
        M_XOR(this, LSB(this->registers.IY));break;
    case XOR_xHL:    this->debug_opcode((char *)"XOR_xIY+BYTE", (char *)"Bitwise XOR on A with value pointed to by IY plus BYTE");
      I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
      M_XOR(this, I);break;

    case OR_H:      this->debug_opcode((char *)"XOR_IYh", (char *)"Bitwise OR on A with IYh");    
        M_XOR(this, MSB(this->registers.IY));break;
    case OR_L:      this->debug_opcode((char *)"XOR_IYl", (char *)"Bitwise OR on A with IYl");    
        M_OR(this, LSB(this->registers.IY));break;
    case OR_xHL:    this->debug_opcode((char *)"XOR_xIY+BYTE", (char *)"Bitwise OR on A with value pointed to by IY plus BYTE");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_OR(this, I);break;

    case CP_H:      this->debug_opcode((char *)"CP_IYh", (char *)"Subtracts IYh from A and affects flags according to the result. A is not modified.");    
        M_CP(this, MSB(this->registers.IY));break;
    case CP_L:      this->debug_opcode((char *)"CP_IYl", (char *)"Subtracts IYl from A and affects flags according to the result. A is not modified.");    
        M_CP(this, LSB(this->registers.IY));break;
    case CP_xHL:    this->debug_opcode((char *)"CP_xIY+BYTE", (char *)"Subtracts the value pointed to by IY plus BYTE from A and affects flags according to the result. A is not modified.");
        I = this->RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_CP(this, I);break;

    case POP_HL:       this->debug_opcode((char *)"POP_IY", (char *)"The memory location pointed to by SP is stored into IYl and SP is incremented. The memory location pointed to by SP is stored into IYh and SP is incremented again"); 
        M_POP(this, z80cpm_memory, IY);break;

    case EX_xSP_HL:      this->debug_opcode((char *)"EX_xSP_IY", (char*)"Exchanges (SP) with IYl, and (SP+1) with IYh");
        J = this->registers.IY;
        SET_WORD(this->registers.IY, RdZ80(z80cpm_memory, this->registers.SP), 
                                    RdZ80(z80cpm_memory, this->registers.SP + 1)); 
        
        WrZ80(z80cpm_memory, this->registers.SP, LSB(J));
        WrZ80(z80cpm_memory, this->registers.SP+1, MSB(J));

      break;

    case PUSH_HL:       this->debug_opcode((char *)"PUSH_IY", (char *)"SP is decremented and IYh is stored into the memory location pointed to by SP. SP is decremented again and IYl is stored pointed to by SP"); 
        M_PUSH(this, z80cpm_memory,IY);break;

                    
      case LD_HL_WORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_IY_WORD", (char *)"Loads ** into IY"); 
        M_LDWORD(this, z80cpm_memory, this->registers.IY);break;
      case LD_xWORD_HL:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_xWORD_IY", (char *)"Stores IY into the memory location pointed to by WORD");
        M_LDWORD(this, z80cpm_memory, J); 
        WrZ80(z80cpm_memory, J, LSB(this->registers.IY));
        J += 1;
        WrZ80(z80cpm_memory, J, MSB(this->registers.IY));
        break;
      case LD_H_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_IYh_BYTE", (char *)"Load BYTE into IYh");
          SET_MSB(this->registers.IY, this->OpZ80(z80cpm_memory, this->registers.PC));
          break;
      case LD_HL_xWORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_IY_xWORD", (char *)"Load value pointed to by WORD into IY");
        M_LDWORD(this, z80cpm_memory, J); 
        SET_LSB(this->registers.IY, RdZ80(z80cpm_memory, J));
        J += 1;
        SET_MSB(this->registers.IY, RdZ80(z80cpm_memory, J));
        break;
      case LD_L_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_IYl_BYTE", (char *)"Load BYTE into IYl");
          SET_LSB(this->registers.IY, this->OpZ80(z80cpm_memory, this->registers.PC));
          break;

      case LD_xHL_BYTE:   this->debug_opcode_reg_byte_byte(z80cpm_memory, (char *)"LD_xIYl_BYTE", (char *)"Stores BYTE to the memory location pointed to by IY plus BYTE");
          J = this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,this->OpZ80(z80cpm_memory, this->registers.PC));
          break;


      case LD_B_H:        this->debug_opcode((char *)"LD_B_IYh", (char *)"The content of IYh is loaded into B");
          SET_MSB(this->registers.BC, MSB(this->registers.IY));break;
      case LD_B_L:        this->debug_opcode((char *)"LD_B_IYl", (char *)"The content of IYl is loaded into B");
          SET_MSB(this->registers.BC, LSB(this->registers.IY));break;
      case LD_B_xHL:      this->debug_opcode((char *)"LD_B_xIY", (char *)"The contents of IY plus BYTE are loaded into B");
          SET_MSB(this->registers.BC, RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_C_H:        this->debug_opcode((char *)"LD_C_IYh", (char *)"The content of IYh is loaded into C");
          SET_LSB(this->registers.BC, MSB(this->registers.IY));break;
      case LD_C_L:        this->debug_opcode((char *)"LD_C_IYl", (char *)"The content of IYl is loaded into C");
          SET_LSB(this->registers.BC, LSB(this->registers.IY));break;
      case LD_C_xHL:      this->debug_opcode((char *)"LD_C_xIY", (char *)"The contents of IY plus BYTE are loaded into C");
          SET_LSB(this->registers.BC, RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_D_H:        this->debug_opcode((char *)"LD_D_IYh", (char *)"The content of IYh is loaded into D");
          SET_MSB(this->registers.DE, MSB(this->registers.IY));break;
      case LD_D_L:        this->debug_opcode((char *)"LD_D_IYl", (char *)"The content of IYl is loaded into D");
          SET_MSB(this->registers.DE, LSB(this->registers.IY));break;
      case LD_D_xHL:      this->debug_opcode((char *)"LD_D_xIY", (char *)"The contents of IY plus BYTE are loaded into D");
          SET_MSB(this->registers.DE, RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_E_H:        this->debug_opcode((char *)"LD_E_IYh", (char *)"The content of IYh is loaded into E");
          SET_LSB(this->registers.DE, MSB(this->registers.IY));break;
      case LD_E_L:        this->debug_opcode((char *)"LD_E_IYl", (char *)"The content of IYl is loaded into E");
          SET_LSB(this->registers.DE, LSB(this->registers.IY));break;
      case LD_E_xHL:      this->debug_opcode((char *)"LD_E_xIY", (char *)"The contents of IY plus BYTE are loaded into E");
          SET_LSB(this->registers.DE, RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;


      case LD_H_B:        this->debug_opcode((char *)"LD_IYh_B", (char *)"The content of B is loaded into IYh");
          SET_MSB(this->registers.IY, MSB(this->registers.BC));break;
      case LD_H_C:        this->debug_opcode((char *)"LD_IYh_C", (char *)"The content of C is loaded into IYh");
          SET_MSB(this->registers.IY, LSB(this->registers.BC));break;
      case LD_H_D:        this->debug_opcode((char *)"LD_IYh_D", (char *)"The content of D is loaded into IYh");
          SET_MSB(this->registers.IY, MSB(this->registers.DE));break;
      case LD_H_E:        this->debug_opcode((char *)"LD_IYh_E", (char *)"The content of E is loaded into IYh");
          SET_MSB(this->registers.IY, LSB(this->registers.DE));break;

      case LD_H_H:        this->debug_opcode((char *)"LD_IYh_IYh", (char *)"The content of IYh is loaded into IYh");
          SET_MSB(this->registers.IY, MSB(this->registers.IY));break;
      case LD_H_L:        this->debug_opcode((char *)"LD_IYh_IYl", (char *)"The content of IYh is loaded into IYl");
          SET_MSB(this->registers.IY, LSB(this->registers.IY));break;
      case LD_H_xHL:      this->debug_opcode((char *)"LD_H_IYL", (char *)"Loads the value pointed to IY plus BYTE into H");
          SET_MSB(this->registers.HL, RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_H_A:      this->debug_opcode((char *)"LD_xIYh_A", (char *)"The contents of A are loaded into IYh");
          SET_MSB(this->registers.IY, MSB(this->registers.AF));break;

      case LD_L_B:      this->debug_opcode((char *)"LD_xIYl_B", (char *)"The contents of B are loaded into IYl");
          SET_LSB(this->registers.IY, MSB(this->registers.BC));break;
      case LD_L_C:      this->debug_opcode((char *)"LD_xIYl_C", (char *)"The contents of C are loaded into IYl");
          SET_LSB(this->registers.IY, LSB(this->registers.BC));break;
      case LD_L_D:      this->debug_opcode((char *)"LD_xIYl_D", (char *)"The contents of D are loaded into IYl");
          SET_LSB(this->registers.IY, MSB(this->registers.DE));break;
      case LD_L_E:      this->debug_opcode((char *)"LD_xIYl_E", (char *)"The contents of E are loaded into IYl");
          SET_LSB(this->registers.IY, LSB(this->registers.DE));break;

      case LD_L_H:        this->debug_opcode((char *)"LD_IYl_IYh", (char *)"The content of IYl is loaded into IYh");
          SET_LSB(this->registers.IY, MSB(this->registers.IY));break;
      case LD_L_L:        this->debug_opcode((char *)"LD_IYl_IYl", (char *)"The content of IYl is loaded into IYl");
          SET_LSB(this->registers.IY, LSB(this->registers.IY));break;
      case LD_L_xHL:        this->debug_opcode((char *)"LD_L_xIY", (char *)"Loads the value pointed to IY plus BYTE into L");
          SET_LSB(this->registers.HL, RdZ80(z80cpm_memory, this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;
      case LD_L_A:      this->debug_opcode((char *)"LD_xIYl_A", (char *)"The contents of A are loaded into IYl");
          SET_LSB(this->registers.IY, MSB(this->registers.AF));break;

      case LD_xHL_B:      this->debug_opcode((char *)"LD_xIY_B", (char *)"Stores B to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, MSB(this->registers.BC));break;
      case LD_xHL_C:      this->debug_opcode((char *)"LD_xIY_C", (char *)"Stores C to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,LSB(this->registers.BC));break;
      case LD_xHL_D:      this->debug_opcode((char *)"LD_xIY_D", (char *)"Stores D to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,MSB(this->registers.DE));break;
      case LD_xHL_E:      this->debug_opcode((char *)"LD_xIY_E", (char *)"Stores E to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, LSB(this->registers.DE));break;
      case LD_xHL_H:      this->debug_opcode((char *)"LD_xIY_H", (char *)"Stores H to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,MSB(this->registers.HL));break;
      case LD_xHL_L:      this->debug_opcode((char *)"LD_xIY_L", (char *)"Stores L to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, LSB(this->registers.HL));break;

      case LD_xHL_A:      this->debug_opcode((char *)"LD_xIY_A", (char *)"Stores A to the memory location pointed to by IY plus BYTE");
          J=this->registers.IY + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, MSB(this->registers.AF));break;
      case LD_A_H:        this->debug_opcode((char *)"LD_A_IYh", (char *)"The content of IYh is loaded into A");
          SET_MSB(this->registers.AF, MSB(this->registers.IY));break;
      case LD_A_L:        this->debug_opcode((char *)"LD_A_IYl", (char *)"The content of IYl is loaded into A");
          SET_MSB(this->registers.AF, LSB(this->registers.IY));break;
      case LD_A_xHL:        this->debug_opcode((char *)"LD_L_xIY", (char *)"Loads the value pointed to IY plus BYTE into A");
          SET_MSB(this->registers.AF, RdZ80(z80cpm_memory, this->registers.IY+ this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;


      case LD_PC_HL:        this->debug_opcode((char *)"LD_PC_IY", (char *)"Loads the value of IY into PC");
              this->registers.PC=this->registers.IY;this->JumpZ80( this->registers.PC);break;
      case LD_SP_HL:        this->debug_opcode((char *)"LD_SP_IY", (char *)"Loads the value of IY into SP");
              this->registers.SP=this->registers.IY;break;



    case PFX_FD:
    case PFX_DD:
      this->registers.PC--;break;
    case PFX_CB:
      this->z80_exec_extended_FDCB(z80cpm_memory);break;
    default:{
      char str2[20];
      sprintf(str2,"unknown 0x%x",opcode);
      this->debug_opcode(str2, (char*)"");
        if(this->TrapBadOps)
      printf
      (
          "[Z80 %lX] Unrecognized instruction: FD %02X at PC=%04X\n",
          (long)this->User,this->OpZ80(z80cpm_memory, this->registers.PC-1),this->registers.PC-2
      );
    }
  //#undef XX
  }
}