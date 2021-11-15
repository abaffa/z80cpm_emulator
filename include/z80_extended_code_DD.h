static const unsigned char CyclesDD[256] =
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


static const unsigned char CyclesDDCB[256] =
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


void Z80::z80_exec_extended_DDCB(struct z80cpm_memory* z80cpm_memory)
{
    unsigned char I; //register
    unsigned short J; //register

    J = this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
    I = this->OpZ80(z80cpm_memory, this->registers.PC);
    unsigned char opcode = I;
    this->ICount -= CyclesDDCB[I];

    switch(I)
    {
        case RLC_xHL:      this->debug_opcode((char *)"RLC_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_RLC(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case RRC_xHL:      this->debug_opcode((char *)"RRC_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            I = this->RdZ80(z80cpm_memory, J); M_RRC(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case RL_xHL:      this->debug_opcode((char *)"RL_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_RL(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case RR_xHL:      this->debug_opcode((char *)"RR_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            I = this->RdZ80(z80cpm_memory, J); M_RR(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SLA_xHL:      this->debug_opcode((char *)"SLA_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_SLA(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SRA_xHL:      this->debug_opcode((char *)"SRA_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            I = this->RdZ80(z80cpm_memory, J); M_SRA(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SLL_xHL:      this->debug_opcode((char *)"SLL_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            I = this->RdZ80(z80cpm_memory, J); M_SLL(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case SRL_xHL:      this->debug_opcode((char *)"SRL_xIX+BYTE", (char *)"The contents of the memory location pointed to by ix plus BYTE are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            I = this->RdZ80(z80cpm_memory, J); M_SRL(this, I); WrZ80(z80cpm_memory, J, I); break; 

        case BIT0_xHL:      this->debug_opcode((char *)"BIT0_xIX+BYTE", (char *)"Test bit 0 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 0, I); break; 
        case BIT1_xHL:      this->debug_opcode((char *)"BIT1_xIX+BYTE", (char *)"Test bit 1 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 1, I); break; 
        case BIT2_xHL:      this->debug_opcode((char *)"BIT2_xIX+BYTE", (char *)"Test bit 2 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 2, I); break; 
        case BIT3_xHL:      this->debug_opcode((char *)"BIT3_xIX+BYTE", (char *)"Test bit 3 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 3, I); break; 
        case BIT4_xHL:      this->debug_opcode((char *)"BIT4_xIX+BYTE", (char *)"Test bit 4 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 4, I); break; 
        case BIT5_xHL:      this->debug_opcode((char *)"BIT5_xIX+BYTE", (char *)"Test bit 5 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 5, I); break; 
        case BIT6_xHL:      this->debug_opcode((char *)"BIT6_xIX+BYTE", (char *)"Test bit 6 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 6, I); break; 
        case BIT7_xHL:      this->debug_opcode((char *)"BIT7_xIX+BYTE", (char *)"Test bit 7 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_BIT(this, 7, I); break; 

        case SET0_xHL:      this->debug_opcode((char *)"SET0_xIX+BYTE", (char *)"Set bit 0 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 0, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET1_xHL:      this->debug_opcode((char *)"SET1_xIX+BYTE", (char *)"Set bit 1 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 1, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET2_xHL:      this->debug_opcode((char *)"SET2_xIX+BYTE", (char *)"Set bit 2 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 2, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET3_xHL:      this->debug_opcode((char *)"SET3_xIX+BYTE", (char *)"Set bit 3 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 3, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET4_xHL:      this->debug_opcode((char *)"SET4_xIX+BYTE", (char *)"Set bit 4 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 4, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET5_xHL:      this->debug_opcode((char *)"SET5_xIX+BYTE", (char *)"Set bit 5 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 5, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET6_xHL:      this->debug_opcode((char *)"SET6_xIX+BYTE", (char *)"Set bit 6 of  the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 6, I); WrZ80(z80cpm_memory, J, I); break; 
        case SET7_xHL:      this->debug_opcode((char *)"SET7_xIX+BYTE", (char *)"Set bit 7 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_SET(this, 7, I); WrZ80(z80cpm_memory, J, I); break; 
        
        case RES0_xHL:      this->debug_opcode((char *)"RES0_xIX+BYTE", (char *)"Reset bit 0 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 0, I); WrZ80(z80cpm_memory, J, I); break;        
        case RES1_xHL:      this->debug_opcode((char *)"RES1_xIX+BYTE", (char *)"Reset bit 1 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 1, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES2_xHL:      this->debug_opcode((char *)"RES2_xIX+BYTE", (char *)"Reset bit 2 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 2, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES3_xHL:      this->debug_opcode((char *)"RES3_xIX+BYTE", (char *)"Reset bit 3 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 3, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES4_xHL:      this->debug_opcode((char *)"RES4_xIX+BYTE", (char *)"Reset bit 4 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 4, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES5_xHL:      this->debug_opcode((char *)"RES5_xIX+BYTE", (char *)"Reset bit 5 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 5, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES6_xHL:      this->debug_opcode((char *)"RES6_xIX+BYTE", (char *)"Reset bit 6 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 6, I); WrZ80(z80cpm_memory, J, I); break; 
        case RES7_xHL:      this->debug_opcode((char *)"RES7_xIX+BYTE", (char *)"Reset bit 7 of the memory location pointed to by ix plus BYTE.");
            I = this->RdZ80(z80cpm_memory, J); M_RES(Z80, 7, I); WrZ80(z80cpm_memory, J, I); break; 
        
	

        default:{
            char str2[20];
            sprintf(str2,"unknown 0x%x",opcode);
            this->debug_opcode(str2, (char*)"");
             if(this->TrapBadOps)
            printf
            (
                "[Z80 %lX] Unrecognized instruction: DD CB %02X %02X at PC=%04X\n",
                (long)(this->User),this->OpZ80(z80cpm_memory, this->registers.PC-2),this->OpZ80(z80cpm_memory, this->registers.PC-1),this, this->registers.PC-4
            );
        }
    }
}


void Z80::z80_exec_extended_DD(struct z80cpm_memory* z80cpm_memory)
{
  unsigned char I; //register
  unsigned short J; //register

//  #define XX IX
  I = this->OpZ80(z80cpm_memory, this->registers.PC);
  unsigned char opcode = I;
  this->ICount -= CyclesDD[I];


  switch(I)
  {
  

    case ADD_HL_BC:     this->debug_opcode((char *)"ADD_IX_BC", (char *)"The value of BC is added to IX");
        M_ADDW(this, IX, BC);break; 
    case ADD_HL_DE:     this->debug_opcode((char *)"ADD_IX_DE", (char *)"The value of DE is added to IX");
        M_ADDW(this, IX, DE);break;
    case ADD_HL_HL:     this->debug_opcode((char *)"ADD_IX_IX", (char *)"The value of IX is added to IX");
        M_ADDW(this, IX, IX);break;
    case ADD_HL_SP:     this->debug_opcode((char *)"ADD_IX_SP", (char *)"The value of SP is added to IX");
        M_ADDW(this, IX, SP);break;

    case ADD_H:         this->debug_opcode((char *)"ADD_IXh", (char *)"Adds IXh to A");
        M_ADD(this, MSB(this->registers.IX));break;
    case ADD_L:         this->debug_opcode((char *)"ADD_IXl", (char *)"Adds IXl to A");
        M_ADD(this, LSB(this->registers.IX));break;
    case ADD_xHL:       this->debug_opcode((char *)"ADD_xIX+BYTE", (char *)"Adds the value pointed by (IX) plus BYTE to A");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_ADD(this, I); break;


    case INC_HL:         this->debug_opcode((char *)"INC_IX", (char *)"Adds one to IX");
        this->registers.IX++;break;
    case INC_H:           this->debug_opcode((char *)"INC_IXh", (char *)"Adds one to IXh");
        M_INC_H(this, this->registers.IX);break;
    case INC_L:           this->debug_opcode((char *)"INC_IXl", (char *)"Adds one to IXl");
        M_INC_L(this, this->registers.IX);break;
    case INC_xHL:       this->debug_opcode((char *)"INC_xIX+BYTE", (char *)"Adds one to the memory location pointed to by IX plus BYTE.");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->RdZ80(z80cpm_memory, this->registers.PC));
        M_INC_L(this, I);
		this->WrZ80(z80cpm_memory,  this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC), I);
        break;

    case DEC_HL:         this->debug_opcode((char *)"DEC_IX", (char *)"Subtracts one to IX");
        this->registers.IX--;break;
    case DEC_H:           this->debug_opcode((char *)"DEC_IXh", (char *)"Subtracts one to IXh");
        M_DEC_H(this, this->registers.IX);break;
    case DEC_L:           this->debug_opcode((char *)"DEC_IXl", (char *)"Subtracts one to IXl");
        M_DEC_L(this, this->registers.IX);break;
    case DEC_xHL:       this->debug_opcode((char *)"DEC_xIX+BYTE", (char *)"Subtracts one from the memory location pointed to by IX plus BYTE.");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->RdZ80(z80cpm_memory, this->registers.PC));
        M_INC_L(this, I);
		this->WrZ80(z80cpm_memory,  this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC), I);
        break;

    case ADC_H:         this->debug_opcode((char *)"ADC_IXh", (char *)"Adds IXh and the carry flag to A");
        M_ADC(this, MSB(this->registers.IX));break;
    case ADC_L:         this->debug_opcode((char *)"ADC_IXl", (char *)"Adds IXl and the carry flag to A");
        M_ADC(this, LSB(this->registers.IX));break;
    case ADC_xHL:      this->debug_opcode((char *)"ADC_xIX+BYTE", (char *)"Adds the value pointed to by IX plus BYTE and the carry flag to A");        
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_ADC(this, I);break;

    case SUB_H:      this->debug_opcode((char *)"SUB_IXh", (char *)"Subtracts IXh from A");    
        M_SUB(this, MSB(this->registers.IX));break;
    case SUB_L:      this->debug_opcode((char *)"SUB_IXl", (char *)"Subtracts IXl from A");    
        M_SUB(this, LSB(this->registers.IX));break;
    case SUB_xHL:       this->debug_opcode((char *)"SUB_xIX+BYTE", (char *)"Subtracts the value pointed to by IX plus BYTE from A.");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_SUB(this, I);break;


    case SBC_H:      this->debug_opcode((char *)"SBC_IXh", (char *)"Subtracts IXh and the carry flag from A");    
        M_SBC(this, MSB(this->registers.IX));break;
    case SBC_L:      this->debug_opcode((char *)"SBC_IXl", (char *)"Subtracts IXl and the carry flag from A");    
        M_SBC(this, LSB(this->registers.IX));break;
    case SBC_xHL:       this->debug_opcode((char *)"SBC_xIX+BYTE", (char *)"Subtracts the value pointed to by IX plus BYTE and the carry flag from A.");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_SBC(this, I);break;


    case AND_H:      this->debug_opcode((char *)"AND_IXh", (char *)"Bitwise AND on A with IXh");    
        M_AND(this, MSB(this->registers.IX));break;
    case AND_L:      this->debug_opcode((char *)"AND_IXl", (char *)"Bitwise AND on A with IXl");    
        M_AND(this, LSB(this->registers.IX));break;
    case AND_xHL:       this->debug_opcode((char *)"AND_xIX+BYTE", (char *)"Bitwise AND on A with value pointed to by IX plus BYTE");
      I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
      M_AND(this, I);break;

    case XOR_H:      this->debug_opcode((char *)"XOR_IXh", (char *)"Bitwise XOR on A with IXh");    
        M_XOR(this, MSB(this->registers.IX));break;
    case XOR_L:      this->debug_opcode((char *)"XOR_IXl", (char *)"Bitwise XOR on A with IXl");    
        M_XOR(this, LSB(this->registers.IX));break;
    case XOR_xHL:    this->debug_opcode((char *)"XOR_xIX+BYTE", (char *)"Bitwise XOR on A with value pointed to by IX plus BYTE");
      I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
      M_XOR(this, I);break;

    case OR_H:      this->debug_opcode((char *)"XOR_IXh", (char *)"Bitwise OR on A with IXh");    
        M_XOR(this, MSB(this->registers.IX));break;
    case OR_L:      this->debug_opcode((char *)"XOR_IXl", (char *)"Bitwise OR on A with IXl");    
        M_OR(this, LSB(this->registers.IX));break;
    case OR_xHL:    this->debug_opcode((char *)"XOR_xIX+BYTE", (char *)"Bitwise OR on A with value pointed to by IX plus BYTE");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_OR(this, I);break;

    case CP_H:      this->debug_opcode((char *)"CP_IXh", (char *)"Subtracts IXh from A and affects flags according to the result. A is not modified.");    
        M_CP(this, MSB(this->registers.IX));break;
    case CP_L:      this->debug_opcode((char *)"CP_IXl", (char *)"Subtracts IXl from A and affects flags according to the result. A is not modified.");    
        M_CP(this, LSB(this->registers.IX));break;
    case CP_xHL:    this->debug_opcode((char *)"CP_xIX+BYTE", (char *)"Subtracts the value pointed to by IX plus BYTE from A and affects flags according to the result. A is not modified.");
        I = this->RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC));
        M_CP(this, I);break;

    case POP_HL:       this->debug_opcode((char *)"POP_IX", (char *)"The memory location pointed to by SP is stored into IXl and SP is incremented. The memory location pointed to by SP is stored into IXh and SP is incremented again"); 
        M_POP(this, z80cpm_memory, IX);break;

    case EX_xSP_HL:      this->debug_opcode((char *)"EX_xSP_IX", (char*)"Exchanges (SP) with IXl, and (SP+1) with IXh");
        J = this->registers.IX;
        SET_WORD(this->registers.IX, RdZ80(z80cpm_memory, this->registers.SP), 
                                    RdZ80(z80cpm_memory, this->registers.SP + 1)); 
        
        WrZ80(z80cpm_memory,  this->registers.SP, LSB(J));
        WrZ80(z80cpm_memory,  this->registers.SP+1, MSB(J));

      break;

    case PUSH_HL:       this->debug_opcode((char *)"PUSH_IX", (char *)"SP is decremented and IXh is stored into the memory location pointed to by SP. SP is decremented again and IXl is stored pointed to by SP"); 
        M_PUSH(this, z80cpm_memory, IX);break;

                    
      case LD_HL_WORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_IX_WORD", (char *)"Loads ** into IX"); 
          M_LDWORD(this, z80cpm_memory, this->registers.IX);break;
      case LD_xWORD_HL:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_xWORD_IX", (char *)"Stores IX into the memory location pointed to by WORD");
        SET_LSB(J, this->OpZ80(z80cpm_memory, this->registers.PC));
        SET_MSB(J, this->OpZ80(z80cpm_memory, this->registers.PC));
        WrZ80(z80cpm_memory, J, LSB(this->registers.IX));
        J += 1;
        WrZ80(z80cpm_memory, J, MSB(this->registers.IX));
        break;
      case LD_H_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_IXh_BYTE", (char *)"Load BYTE into IXh");
          SET_MSB(this->registers.IX, this->OpZ80(z80cpm_memory, this->registers.PC));
          break;
      case LD_HL_xWORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_IX_xWORD", (char *)"Load value pointed to by WORD into IX");
        SET_LSB(J, this->OpZ80(z80cpm_memory, this->registers.PC));
        SET_MSB(J, this->OpZ80(z80cpm_memory, this->registers.PC));
        SET_LSB(this->registers.IX, RdZ80(z80cpm_memory, J));
        J += 1;
        SET_MSB(this->registers.IX, RdZ80(z80cpm_memory, J));
        break;
      case LD_L_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_IXl_BYTE", (char *)"Load BYTE into IXl");
          SET_LSB(this->registers.IX, this->OpZ80(z80cpm_memory, this->registers.PC));
          break;

      case LD_xHL_BYTE:   this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_xIXl_BYTE", (char *)"Stores BYTE to the memory location pointed to by IX plus BYTE");
          J = this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,this->OpZ80(z80cpm_memory, this->registers.PC));
          break;


      case LD_B_H:        this->debug_opcode((char *)"LD_B_IXh", (char *)"The content of IXh is loaded into B");
          SET_MSB(this->registers.BC, MSB(this->registers.IX));break;
      case LD_B_L:        this->debug_opcode((char *)"LD_B_IXl", (char *)"The content of IXl is loaded into B");
          SET_MSB(this->registers.BC, LSB(this->registers.IX));break;
      case LD_B_xHL:      this->debug_opcode((char *)"LD_B_xIX", (char *)"The contents of IX plus BYTE are loaded into B");
          SET_MSB(this->registers.BC, RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_C_H:        this->debug_opcode((char *)"LD_C_IXh", (char *)"The content of IXh is loaded into C");
          SET_LSB(this->registers.BC, MSB(this->registers.IX));break;
      case LD_C_L:        this->debug_opcode((char *)"LD_C_IXl", (char *)"The content of IXl is loaded into C");
          SET_LSB(this->registers.BC, LSB(this->registers.IX));break;
      case LD_C_xHL:      this->debug_opcode((char *)"LD_C_xIX", (char *)"The contents of IX plus BYTE are loaded into C");
          SET_LSB(this->registers.BC, RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_D_H:        this->debug_opcode((char *)"LD_D_IXh", (char *)"The content of IXh is loaded into D");
          SET_MSB(this->registers.DE, MSB(this->registers.IX));break;
      case LD_D_L:        this->debug_opcode((char *)"LD_D_IXl", (char *)"The content of IXl is loaded into D");
          SET_MSB(this->registers.DE, LSB(this->registers.IX));break;
      case LD_D_xHL:      this->debug_opcode((char *)"LD_D_xIX", (char *)"The contents of IX plus BYTE are loaded into D");
          SET_MSB(this->registers.DE, RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_E_H:        this->debug_opcode((char *)"LD_E_IXh", (char *)"The content of IXh is loaded into E");
          SET_LSB(this->registers.DE, MSB(this->registers.IX));break;
      case LD_E_L:        this->debug_opcode((char *)"LD_E_IXl", (char *)"The content of IXl is loaded into E");
          SET_LSB(this->registers.DE, LSB(this->registers.IX));break;
      case LD_E_xHL:      this->debug_opcode((char *)"LD_E_xIX", (char *)"The contents of IX plus BYTE are loaded into E");
          SET_LSB(this->registers.DE, RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;


      case LD_H_B:        this->debug_opcode((char *)"LD_IXh_B", (char *)"The content of B is loaded into IXh");
          SET_MSB(this->registers.IX, MSB(this->registers.BC));break;
      case LD_H_C:        this->debug_opcode((char *)"LD_IXh_C", (char *)"The content of C is loaded into IXh");
          SET_MSB(this->registers.IX, LSB(this->registers.BC));break;
      case LD_H_D:        this->debug_opcode((char *)"LD_IXh_D", (char *)"The content of D is loaded into IXh");
          SET_MSB(this->registers.IX, MSB(this->registers.DE));break;
      case LD_H_E:        this->debug_opcode((char *)"LD_IXh_E", (char *)"The content of E is loaded into IXh");
          SET_MSB(this->registers.IX, LSB(this->registers.DE));break;

      case LD_H_H:        this->debug_opcode((char *)"LD_IXh_IXh", (char *)"The content of IXh is loaded into IXh");
          SET_MSB(this->registers.IX, MSB(this->registers.IX));break;
      case LD_H_L:        this->debug_opcode((char *)"LD_IXh_IXl", (char *)"The content of IXh is loaded into IXl");
          SET_MSB(this->registers.IX, LSB(this->registers.IX));break;
      case LD_H_xHL:      this->debug_opcode((char *)"LD_H_IXL", (char *)"Loads the value pointed to IX plus BYTE into H");
          SET_MSB(this->registers.HL, RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;

      case LD_H_A:      this->debug_opcode((char *)"LD_xIXh_A", (char *)"The contents of A are loaded into IXh");
          SET_MSB(this->registers.IX, MSB(this->registers.AF));break;

      case LD_L_B:      this->debug_opcode((char *)"LD_xIXl_B", (char *)"The contents of B are loaded into IXl");
          SET_LSB(this->registers.IX, MSB(this->registers.BC));break;
      case LD_L_C:      this->debug_opcode((char *)"LD_xIXl_C", (char *)"The contents of C are loaded into IXl");
          SET_LSB(this->registers.IX, LSB(this->registers.BC));break;
      case LD_L_D:      this->debug_opcode((char *)"LD_xIXl_D", (char *)"The contents of D are loaded into IXl");
          SET_LSB(this->registers.IX, MSB(this->registers.DE));break;
      case LD_L_E:      this->debug_opcode((char *)"LD_xIXl_E", (char *)"The contents of E are loaded into IXl");
          SET_LSB(this->registers.IX, LSB(this->registers.DE));break;

      case LD_L_H:        this->debug_opcode((char *)"LD_IXl_IXh", (char *)"The content of IXl is loaded into IXh");
          SET_LSB(this->registers.IX, MSB(this->registers.IX));break;
      case LD_L_L:        this->debug_opcode((char *)"LD_IXl_IXl", (char *)"The content of IXl is loaded into IXl");
          SET_LSB(this->registers.IX, LSB(this->registers.IX));break;
      case LD_L_xHL:        this->debug_opcode((char *)"LD_L_xIX", (char *)"Loads the value pointed to IX plus BYTE into L");
          SET_LSB(this->registers.HL, RdZ80(z80cpm_memory, this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;
      case LD_L_A:      this->debug_opcode((char *)"LD_xIXl_A", (char *)"The contents of A are loaded into IXl");
          SET_LSB(this->registers.IX, MSB(this->registers.AF));break;

      case LD_xHL_B:      this->debug_opcode((char *)"LD_xIX_B", (char *)"Stores B to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, MSB(this->registers.BC));break;
      case LD_xHL_C:      this->debug_opcode((char *)"LD_xIX_C", (char *)"Stores C to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,LSB(this->registers.BC));break;
      case LD_xHL_D:      this->debug_opcode((char *)"LD_xIX_D", (char *)"Stores D to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,MSB(this->registers.DE));break;
      case LD_xHL_E:      this->debug_opcode((char *)"LD_xIX_E", (char *)"Stores E to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, LSB(this->registers.DE));break;
      case LD_xHL_H:      this->debug_opcode((char *)"LD_xIX_H", (char *)"Stores H to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J,MSB(this->registers.HL));break;
      case LD_xHL_L:      this->debug_opcode((char *)"LD_xIX_L", (char *)"Stores L to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, LSB(this->registers.HL));break;

      case LD_xHL_A:      this->debug_opcode((char *)"LD_xIX_A", (char *)"Stores A to the memory location pointed to by IX plus BYTE");
          J=this->registers.IX + this->OpZ80(z80cpm_memory, this->registers.PC);
          WrZ80(z80cpm_memory, J, MSB(this->registers.AF));break;
      case LD_A_H:        this->debug_opcode((char *)"LD_A_IXh", (char *)"The content of IXh is loaded into A");
          SET_MSB(this->registers.AF, MSB(this->registers.IX));break;
      case LD_A_L:        this->debug_opcode((char *)"LD_A_IXl", (char *)"The content of IXl is loaded into A");
          SET_MSB(this->registers.AF, LSB(this->registers.IX));break;
      case LD_A_xHL:        this->debug_opcode((char *)"LD_L_xIX", (char *)"Loads the value pointed to IX plus BYTE into A");
          SET_MSB(this->registers.AF, RdZ80(z80cpm_memory, this->registers.IX+ this->OpZ80(z80cpm_memory, this->registers.PC)));
          break;


      case LD_PC_HL:        this->debug_opcode((char *)"LD_PC_IX", (char *)"Loads the value of IX into PC");
              this->registers.PC=this->registers.IX;this->JumpZ80( this->registers.PC);break;
      case LD_SP_HL:        this->debug_opcode((char *)"LD_SP_IX", (char *)"Loads the value of IX into SP");
              this->registers.SP=this->registers.IX;break;



    case PFX_FD:
    case PFX_DD:
      this->registers.PC--;break;
    case PFX_CB:
      this->z80_exec_extended_DDCB(z80cpm_memory);break;
    default:{
      char str2[20];
      sprintf(str2,"unknown 0x%x",opcode);
      this->debug_opcode(str2, (char*)"");
        if(this->TrapBadOps)
      printf
      (
          "[Z80 %lX] Unrecognized instruction: DD %02X at PC=%04X\n",
          (long)this->User,this->OpZ80(z80cpm_memory, this->registers.PC-1),this->registers.PC-2
      );
    }
  //#undef XX
  }
}