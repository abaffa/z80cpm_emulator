static const unsigned char CyclesCB[256] =
{
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,12, 8, 8, 8, 8, 8, 8, 8,12, 8,
   8, 8, 8, 8, 8, 8,12, 8, 8, 8, 8, 8, 8, 8,12, 8,
   8, 8, 8, 8, 8, 8,12, 8, 8, 8, 8, 8, 8, 8,12, 8,
   8, 8, 8, 8, 8, 8,12, 8, 8, 8, 8, 8, 8, 8,12, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8,
   8, 8, 8, 8, 8, 8,15, 8, 8, 8, 8, 8, 8, 8,15, 8 
};


void Z80::z80_exec_extended_CB(struct z80cpm_memory* z80cpm_memory)
{
    unsigned char I; //register

    I = this->OpZ80(z80cpm_memory, this->registers.PC);
    unsigned char opcode = I;
    this->ICount -= CyclesCB[I];

    switch(I)
    {
        case RLC_A:      this->debug_opcode( (char *)"RLC_A", (char *)"The contents of A are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(this, this->registers.AF); break; 
        case RLC_B:      this->debug_opcode( (char *)"RLC_B", (char *)"The contents of B are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(this, this->registers.BC); break;
        case RLC_C:      this->debug_opcode( (char *)"RLC_C", (char *)"The contents of C are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_L(this, this->registers.BC); break; 
        case RLC_D:      this->debug_opcode( (char *)"RLC_D", (char *)"The contents of D are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(this, this->registers.DE); break;
        case RLC_E:      this->debug_opcode( (char *)"RLC_E", (char *)"The contents of E are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_L(this, this->registers.DE); break; 
        case RLC_H:      this->debug_opcode( (char *)"RLC_H", (char *)"The contents of H are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(this, this->registers.HL); break;
        case RLC_L:      this->debug_opcode( (char *)"RLC_L", (char *)"The contents of L are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_L(this, this->registers.HL); break; 
        case RLC_xHL:      this->debug_opcode( (char *)"RLC_xHL", (char *)"The contents of (HL) are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RLC(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case RRC_A:      this->debug_opcode( (char *)"RRC_A", (char *)"The contents of A are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(this, this->registers.AF); break; 
        case RRC_B:      this->debug_opcode( (char *)"RRC_B", (char *)"The contents of B are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(this, this->registers.BC); break;
        case RRC_C:      this->debug_opcode( (char *)"RRC_C", (char *)"The contents of C are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_L(this, this->registers.BC); break; 
        case RRC_D:      this->debug_opcode( (char *)"RRC_D", (char *)"The contents of D are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(this, this->registers.DE); break;
        case RRC_E:      this->debug_opcode( (char *)"RRC_E", (char *)"The contents of E are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_L(this, this->registers.DE); break; 
        case RRC_H:      this->debug_opcode( (char *)"RRC_H", (char *)"The contents of H are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(this, this->registers.HL); break;
        case RRC_L:      this->debug_opcode( (char *)"RRC_L", (char *)"The contents of L are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_L(this, this->registers.HL); break; 
        case RRC_xHL:      this->debug_opcode( (char *)"RRC_xHL", (char *)"The contents of (HL) are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RRC(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case RL_A:      this->debug_opcode( (char *)"RL_A", (char *)"The contents of A are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(this, this->registers.AF); break; 
        case RL_B:      this->debug_opcode( (char *)"RL_B", (char *)"The contents of B are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(this, this->registers.BC); break;
        case RL_C:      this->debug_opcode( (char *)"RL_C", (char *)"The contents of C are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_L(this, this->registers.BC); break; 
        case RL_D:      this->debug_opcode( (char *)"RL_D", (char *)"The contents of D are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(this, this->registers.DE); break;
        case RL_E:      this->debug_opcode( (char *)"RL_E", (char *)"The contents of E are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_L(this, this->registers.DE); break; 
        case RL_H:      this->debug_opcode( (char *)"RL_H", (char *)"The contents of H are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(this, this->registers.HL); break;
        case RL_L:      this->debug_opcode( (char *)"RL_L", (char *)"The contents of L are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_L(this, this->registers.HL); break; 
        case RL_xHL:      this->debug_opcode( (char *)"RL_xHL", (char *)"The contents of (HL) are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RL(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case RR_A:      this->debug_opcode( (char *)"RR_A", (char *)"The contents of A are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(this, this->registers.AF); break; 
        case RR_B:      this->debug_opcode( (char *)"RR_B", (char *)"The contents of B are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(this, this->registers.BC); break;
        case RR_C:      this->debug_opcode( (char *)"RR_C", (char *)"The contents of C are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_L(this, this->registers.BC); break; 
        case RR_D:      this->debug_opcode( (char *)"RR_D", (char *)"The contents of D are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(this, this->registers.DE); break;
        case RR_E:      this->debug_opcode( (char *)"RR_E", (char *)"The contents of E are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_L(this, this->registers.DE); break; 
        case RR_H:      this->debug_opcode( (char *)"RR_H", (char *)"The contents of H are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(this, this->registers.HL); break;
        case RR_L:      this->debug_opcode( (char *)"RR_L", (char *)"The contents of L are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_L(this, this->registers.HL); break; 
        case RR_xHL:      this->debug_opcode( (char *)"RR_xHL", (char *)"The contents of (HL) are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RR(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case SLA_A:      this->debug_opcode( (char *)"SLA_A", (char *)"The contents of A are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(this, this->registers.AF); break; 
        case SLA_B:      this->debug_opcode( (char *)"SLA_B", (char *)"The contents of B are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(this, this->registers.BC); break;
        case SLA_C:      this->debug_opcode( (char *)"SLA_C", (char *)"The contents of C are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_L(this, this->registers.BC); break; 
        case SLA_D:      this->debug_opcode( (char *)"SLA_D", (char *)"The contents of D are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(this, this->registers.DE); break;
        case SLA_E:      this->debug_opcode( (char *)"SLA_E", (char *)"The contents of E are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_L(this, this->registers.DE); break; 
        case SLA_H:      this->debug_opcode( (char *)"SLA_H", (char *)"The contents of H are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(this, this->registers.HL); break;
        case SLA_L:      this->debug_opcode( (char *)"SLA_L", (char *)"The contents of L are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_L(this, this->registers.HL); break; 
        case SLA_xHL:      this->debug_opcode( (char *)"SLA_xHL", (char *)"The contents of (HL) are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SLA(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case SRA_A:      this->debug_opcode( (char *)"SRA_A", (char *)"The contents of A are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(this, this->registers.AF); break; 
        case SRA_B:      this->debug_opcode( (char *)"SRA_B", (char *)"The contents of B are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(this, this->registers.BC); break;
        case SRA_C:      this->debug_opcode( (char *)"SRA_C", (char *)"The contents of C are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_L(this, this->registers.BC); break; 
        case SRA_D:      this->debug_opcode( (char *)"SRA_D", (char *)"The contents of D are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(this, this->registers.DE); break;
        case SRA_E:      this->debug_opcode( (char *)"SRA_E", (char *)"The contents of E are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_L(this, this->registers.DE); break; 
        case SRA_H:      this->debug_opcode( (char *)"SRA_H", (char *)"The contents of H are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(this, this->registers.HL); break;
        case SRA_L:      this->debug_opcode( (char *)"SRA_L", (char *)"The contents of L are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_L(this, this->registers.HL); break; 
        case SRA_xHL:      this->debug_opcode( (char *)"SRA_xHL", (char *)"The contents of (HL) are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SRA(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case SLL_A:      this->debug_opcode( (char *)"SLL_A", (char *)"The contents of A are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(this, this->registers.AF); break; 
        case SLL_B:      this->debug_opcode( (char *)"SLL_B", (char *)"The contents of B are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(this, this->registers.BC); break;
        case SLL_C:      this->debug_opcode( (char *)"SLL_C", (char *)"The contents of C are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_L(this, this->registers.BC); break; 
        case SLL_D:      this->debug_opcode( (char *)"SLL_D", (char *)"The contents of D are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(this, this->registers.DE); break;
        case SLL_E:      this->debug_opcode( (char *)"SLL_E", (char *)"The contents of E are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_L(this, this->registers.DE); break; 
        case SLL_H:      this->debug_opcode( (char *)"SLL_H", (char *)"The contents of H are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(this, this->registers.HL); break;
        case SLL_L:      this->debug_opcode( (char *)"SLL_L", (char *)"The contents of L are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_L(this, this->registers.HL); break; 
        case SLL_xHL:      this->debug_opcode( (char *)"SLL_xHL", (char *)"The contents of (HL) are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SLL(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case SRL_A:      this->debug_opcode( (char *)"SRL_A", (char *)"The contents of A are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(this, this->registers.AF); break; 
        case SRL_B:      this->debug_opcode( (char *)"SRL_B", (char *)"The contents of B are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(this, this->registers.BC); break;
        case SRL_C:      this->debug_opcode( (char *)"SRL_C", (char *)"The contents of C are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_L(this, this->registers.BC); break; 
        case SRL_D:      this->debug_opcode( (char *)"SRL_D", (char *)"The contents of D are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(this, this->registers.DE); break;
        case SRL_E:      this->debug_opcode( (char *)"SRL_E", (char *)"The contents of E are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_L(this, this->registers.DE); break; 
        case SRL_H:      this->debug_opcode( (char *)"SRL_H", (char *)"The contents of H are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(this, this->registers.HL); break;
        case SRL_L:      this->debug_opcode( (char *)"SRL_L", (char *)"The contents of L are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_L(this, this->registers.HL); break; 
        case SRL_xHL:      this->debug_opcode( (char *)"SRL_xHL", (char *)"The contents of (HL) are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SRL(this, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 

        case BIT0_A:      this->debug_opcode( (char *)"BIT0_A", (char *)"Test bit 0 of A");
            M_BIT(this, 0, MSB(this->registers.AF)); break;
        case BIT0_B:      this->debug_opcode( (char *)"BIT0_B", (char *)"Test bit 0 of B");
            M_BIT(this, 0, MSB(this->registers.BC)); break;
        case BIT0_C:      this->debug_opcode( (char *)"BIT0_C", (char *)"Test bit 0 of C");
            M_BIT(this, 0, LSB(this->registers.BC)); break;
        case BIT0_D:      this->debug_opcode( (char *)"BIT0_D", (char *)"Test bit 0 of D");
            M_BIT(this, 0, MSB(this->registers.DE)); break;
        case BIT0_E:      this->debug_opcode( (char *)"BIT0_E", (char *)"Test bit 0 of E");
            M_BIT(this, 0, LSB(this->registers.DE)); break;
        case BIT0_H:      this->debug_opcode( (char *)"BIT0_H", (char *)"Test bit 0 of H");
            M_BIT(this, 0, MSB(this->registers.HL)); break;
        case BIT0_L:      this->debug_opcode( (char *)"BIT0_L", (char *)"Test bit 0 of L");
            M_BIT(this, 0, LSB(this->registers.HL)); break;
        case BIT0_xHL:      this->debug_opcode( (char *)"BIT0_xHL", (char *)"Test bit 0 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 0, I); break; 

        case BIT1_A:      this->debug_opcode( (char *)"BIT1_A", (char *)"Test bit 1 of A");
            M_BIT(this, 1, MSB(this->registers.AF)); break;
        case BIT1_B:      this->debug_opcode( (char *)"BIT1_B", (char *)"Test bit 1 of B");
            M_BIT(this, 1, MSB(this->registers.BC)); break;
        case BIT1_C:      this->debug_opcode( (char *)"BIT1_C", (char *)"Test bit 1 of C");
            M_BIT(this, 1, LSB(this->registers.BC)); break;
        case BIT1_D:      this->debug_opcode( (char *)"BIT1_D", (char *)"Test bit 1 of D");
            M_BIT(this, 1, MSB(this->registers.DE)); break;
        case BIT1_E:      this->debug_opcode( (char *)"BIT1_E", (char *)"Test bit 1 of E");
            M_BIT(this, 1, LSB(this->registers.DE)); break;
        case BIT1_H:      this->debug_opcode( (char *)"BIT1_H", (char *)"Test bit 1 of H");
            M_BIT(this, 1, MSB(this->registers.HL)); break;
        case BIT1_L:      this->debug_opcode( (char *)"BIT1_L", (char *)"Test bit 1 of L");
            M_BIT(this, 1, LSB(this->registers.HL)); break;
        case BIT1_xHL:      this->debug_opcode( (char *)"BIT1_xHL", (char *)"Test bit 1 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 1, I); break; 
    
        case BIT2_A:      this->debug_opcode( (char *)"BIT2_A", (char *)"Test bit 2 of A");
            M_BIT(this, 2, MSB(this->registers.AF)); break;
        case BIT2_B:      this->debug_opcode( (char *)"BIT2_B", (char *)"Test bit 2 of B");
            M_BIT(this, 2, MSB(this->registers.BC)); break;
        case BIT2_C:      this->debug_opcode( (char *)"BIT2_C", (char *)"Test bit 2 of C");
            M_BIT(this, 2, LSB(this->registers.BC)); break;
        case BIT2_D:      this->debug_opcode( (char *)"BIT2_D", (char *)"Test bit 2 of D");
            M_BIT(this, 2, MSB(this->registers.DE)); break;
        case BIT2_E:      this->debug_opcode( (char *)"BIT2_E", (char *)"Test bit 2 of E");
            M_BIT(this, 2, LSB(this->registers.DE)); break;
        case BIT2_H:      this->debug_opcode( (char *)"BIT2_H", (char *)"Test bit 2 of H");
            M_BIT(this, 2, MSB(this->registers.HL)); break;
        case BIT2_L:      this->debug_opcode( (char *)"BIT2_L", (char *)"Test bit 2 of L");
            M_BIT(this, 2, LSB(this->registers.HL)); break;
        case BIT2_xHL:      this->debug_opcode( (char *)"BIT2_xHL", (char *)"Test bit 2 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 2, I); break; 

        case BIT3_A:      this->debug_opcode( (char *)"BIT3_A", (char *)"Test bit 3 of A");
            M_BIT(this, 3, MSB(this->registers.AF)); break;
        case BIT3_B:      this->debug_opcode( (char *)"BIT3_B", (char *)"Test bit 3 of B");
            M_BIT(this, 3, MSB(this->registers.BC)); break;
        case BIT3_C:      this->debug_opcode( (char *)"BIT3_C", (char *)"Test bit 3 of C");
            M_BIT(this, 3, LSB(this->registers.BC)); break;
        case BIT3_D:      this->debug_opcode( (char *)"BIT3_D", (char *)"Test bit 3 of D");
            M_BIT(this, 3, MSB(this->registers.DE)); break;
        case BIT3_E:      this->debug_opcode( (char *)"BIT3_E", (char *)"Test bit 3 of E");
            M_BIT(this, 3, LSB(this->registers.DE)); break;
        case BIT3_H:      this->debug_opcode( (char *)"BIT3_H", (char *)"Test bit 3 of H");
            M_BIT(this, 3, MSB(this->registers.HL)); break;
        case BIT3_L:      this->debug_opcode( (char *)"BIT3_L", (char *)"Test bit 3 of L");
            M_BIT(this, 3, LSB(this->registers.HL)); break;
        case BIT3_xHL:      this->debug_opcode( (char *)"BIT3_xHL", (char *)"Test bit 3 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 3, I); break; 

        case BIT4_A:      this->debug_opcode( (char *)"BIT4_A", (char *)"Test bit 4 of A");
            M_BIT(this, 4, MSB(this->registers.AF)); break;
        case BIT4_B:      this->debug_opcode( (char *)"BIT4_B", (char *)"Test bit 4 of B");
            M_BIT(this, 4, MSB(this->registers.BC)); break;
        case BIT4_C:      this->debug_opcode( (char *)"BIT4_C", (char *)"Test bit 4 of C");
            M_BIT(this, 4, LSB(this->registers.BC)); break;
        case BIT4_D:      this->debug_opcode( (char *)"BIT4_D", (char *)"Test bit 4 of D");
            M_BIT(this, 4, MSB(this->registers.DE)); break;
        case BIT4_E:      this->debug_opcode( (char *)"BIT4_E", (char *)"Test bit 4 of E");
            M_BIT(this, 4, LSB(this->registers.DE)); break;
        case BIT4_H:      this->debug_opcode( (char *)"BIT4_H", (char *)"Test bit 4 of H");
            M_BIT(this, 4, MSB(this->registers.HL)); break;
        case BIT4_L:      this->debug_opcode( (char *)"BIT4_L", (char *)"Test bit 4 of L");
            M_BIT(this, 4, LSB(this->registers.HL)); break;
        case BIT4_xHL:      this->debug_opcode( (char *)"BIT4_xHL", (char *)"Test bit 4 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 4, I); break; 
    
        case BIT5_A:      this->debug_opcode( (char *)"BIT5_A", (char *)"Test bit 5 of A");
            M_BIT(this, 5, MSB(this->registers.AF)); break;
        case BIT5_B:      this->debug_opcode( (char *)"BIT5_B", (char *)"Test bit 5 of B");
            M_BIT(this, 5, MSB(this->registers.BC)); break;
        case BIT5_C:      this->debug_opcode( (char *)"BIT5_C", (char *)"Test bit 5 of C");
            M_BIT(this, 5, LSB(this->registers.BC)); break;
        case BIT5_D:      this->debug_opcode( (char *)"BIT5_D", (char *)"Test bit 5 of D");
            M_BIT(this, 5, MSB(this->registers.DE)); break;
        case BIT5_E:      this->debug_opcode( (char *)"BIT5_E", (char *)"Test bit 5 of E");
            M_BIT(this, 5, LSB(this->registers.DE)); break;
        case BIT5_H:      this->debug_opcode( (char *)"BIT5_H", (char *)"Test bit 5 of H");
            M_BIT(this, 5, MSB(this->registers.HL)); break;
        case BIT5_L:      this->debug_opcode( (char *)"BIT5_L", (char *)"Test bit 5 of L");
            M_BIT(this, 5, LSB(this->registers.HL)); break;
        case BIT5_xHL:      this->debug_opcode( (char *)"BIT5_xHL", (char *)"Test bit 5 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 5, I); break; 

        case BIT6_A:      this->debug_opcode( (char *)"BIT6_A", (char *)"Test bit 6 of A");
            M_BIT(this, 6, MSB(this->registers.AF)); break;
        case BIT6_B:      this->debug_opcode( (char *)"BIT6_B", (char *)"Test bit 6 of B");
            M_BIT(this, 6, MSB(this->registers.BC)); break;
        case BIT6_C:      this->debug_opcode( (char *)"BIT6_C", (char *)"Test bit 6 of C");
            M_BIT(this, 6, LSB(this->registers.BC)); break;
        case BIT6_D:      this->debug_opcode( (char *)"BIT6_D", (char *)"Test bit 6 of D");
            M_BIT(this, 6, MSB(this->registers.DE)); break;
        case BIT6_E:      this->debug_opcode( (char *)"BIT6_E", (char *)"Test bit 6 of E");
            M_BIT(this, 6, LSB(this->registers.DE)); break;
        case BIT6_H:      this->debug_opcode( (char *)"BIT6_H", (char *)"Test bit 6 of H");
            M_BIT(this, 6, MSB(this->registers.HL)); break;
        case BIT6_L:      this->debug_opcode( (char *)"BIT6_L", (char *)"Test bit 6 of L");
            M_BIT(this, 6, LSB(this->registers.HL)); break;
        case BIT6_xHL:      this->debug_opcode( (char *)"BIT6_xHL", (char *)"Test bit 6 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 6, I); break; 

        case BIT7_A:      this->debug_opcode( (char *)"BIT7_A", (char *)"Test bit 7 of A");
            M_BIT(this, 7, MSB(this->registers.AF)); break;
        case BIT7_B:      this->debug_opcode( (char *)"BIT7_B", (char *)"Test bit 7 of B");
            M_BIT(this, 7, MSB(this->registers.BC)); break;
        case BIT7_C:      this->debug_opcode( (char *)"BIT7_C", (char *)"Test bit 7 of C");
            M_BIT(this, 7, LSB(this->registers.BC)); break;
        case BIT7_D:      this->debug_opcode( (char *)"BIT7_D", (char *)"Test bit 7 of D");
            M_BIT(this, 7, MSB(this->registers.DE)); break;
        case BIT7_E:      this->debug_opcode( (char *)"BIT7_E", (char *)"Test bit 7 of E");
            M_BIT(this, 7, LSB(this->registers.DE)); break;
        case BIT7_H:      this->debug_opcode( (char *)"BIT7_H", (char *)"Test bit 7 of H");
            M_BIT(this, 7, MSB(this->registers.HL)); break;
        case BIT7_L:      this->debug_opcode( (char *)"BIT7_L", (char *)"Test bit 7 of L");
            M_BIT(this, 7, LSB(this->registers.HL)); break;
        case BIT7_xHL:      this->debug_opcode( (char *)"BIT7_xHL", (char *)"Test bit 7 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_BIT(this, 7, I); break; 


        case SET0_A:      this->debug_opcode( (char *)"SET0_A", (char *)"Set bit 0 of A");
            M_SET_H(this, 0, this->registers.AF); break;
        case SET0_B:      this->debug_opcode( (char *)"SET0_B", (char *)"Set bit 0 of B");
            M_SET_H(this, 0, this->registers.BC); break;
        case SET0_C:      this->debug_opcode( (char *)"SET0_C", (char *)"Set bit 0 of C");
            M_SET_L(this, 0, this->registers.BC); break;
        case SET0_D:      this->debug_opcode( (char *)"SET0_D", (char *)"Set bit 0 of D");
            M_SET_H(this, 0, this->registers.DE); break;
        case SET0_E:      this->debug_opcode( (char *)"SET0_E", (char *)"Set bit 0 of E");
            M_SET_L(this, 0, this->registers.DE); break;
        case SET0_H:      this->debug_opcode( (char *)"SET0_H", (char *)"Set bit 0 of H");
            M_SET_H(this, 0, this->registers.HL); break;
        case SET0_L:      this->debug_opcode( (char *)"SET0_L", (char *)"Set bit 0 of L");
            M_SET_L(this, 0, this->registers.HL); break;
        case SET0_xHL:      this->debug_opcode( (char *)"SET0_xHL", (char *)"Set bit 0 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 0, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET1_A:      this->debug_opcode( (char *)"SET1_A", (char *)"Set bit 1 of A");
            M_SET_H(this, 1, this->registers.AF); break;
        case SET1_B:      this->debug_opcode( (char *)"SET1_B", (char *)"Set bit 1 of B");
            M_SET_H(this, 1, this->registers.BC); break;
        case SET1_C:      this->debug_opcode( (char *)"SET1_C", (char *)"Set bit 1 of C");
            M_SET_L(this, 1, this->registers.BC); break;
        case SET1_D:      this->debug_opcode( (char *)"SET1_D", (char *)"Set bit 1 of D");
            M_SET_H(this, 1, this->registers.DE); break;
        case SET1_E:      this->debug_opcode( (char *)"SET1_E", (char *)"Set bit 1 of E");
            M_SET_L(this, 1, this->registers.DE); break;
        case SET1_H:      this->debug_opcode( (char *)"SET1_H", (char *)"Set bit 1 of H");
            M_SET_H(this, 1, this->registers.HL); break;
        case SET1_L:      this->debug_opcode( (char *)"SET1_L", (char *)"Set bit 1 of L");
            M_SET_L(this, 1, this->registers.HL); break;
        case SET1_xHL:      this->debug_opcode( (char *)"SET1_xHL", (char *)"Set bit 1 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 1, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET2_A:      this->debug_opcode( (char *)"SET2_A", (char *)"Set bit 2 of A");
            M_SET_H(this, 2, this->registers.AF); break;
        case SET2_B:      this->debug_opcode( (char *)"SET2_B", (char *)"Set bit 2 of B");
            M_SET_H(this, 2, this->registers.BC); break;
        case SET2_C:      this->debug_opcode( (char *)"SET2_C", (char *)"Set bit 2 of C");
            M_SET_L(this, 2, this->registers.BC); break;
        case SET2_D:      this->debug_opcode( (char *)"SET2_D", (char *)"Set bit 2 of D");
            M_SET_H(this, 2, this->registers.DE); break;
        case SET2_E:      this->debug_opcode( (char *)"SET2_E", (char *)"Set bit 2 of E");
            M_SET_L(this, 2, this->registers.DE); break;
        case SET2_H:      this->debug_opcode( (char *)"SET2_H", (char *)"Set bit 2 of H");
            M_SET_H(this, 2, this->registers.HL); break;
        case SET2_L:      this->debug_opcode( (char *)"SET2_L", (char *)"Set bit 2 of L");
            M_SET_L(this, 2, this->registers.HL); break;
        case SET2_xHL:      this->debug_opcode( (char *)"SET2_xHL", (char *)"Set bit 2 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 2, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET3_A:      this->debug_opcode( (char *)"SET3_A", (char *)"Set bit 3 of A");
            M_SET_H(this, 3, this->registers.AF); break;
        case SET3_B:      this->debug_opcode( (char *)"SET3_B", (char *)"Set bit 3 of B");
            M_SET_H(this, 3, this->registers.BC); break;
        case SET3_C:      this->debug_opcode( (char *)"SET3_C", (char *)"Set bit 3 of C");
            M_SET_L(this, 3, this->registers.BC); break;
        case SET3_D:      this->debug_opcode( (char *)"SET3_D", (char *)"Set bit 3 of D");
            M_SET_H(this, 3, this->registers.DE); break;
        case SET3_E:      this->debug_opcode( (char *)"SET3_E", (char *)"Set bit 3 of E");
            M_SET_L(this, 3, this->registers.DE); break;
        case SET3_H:      this->debug_opcode( (char *)"SET3_H", (char *)"Set bit 3 of H");
            M_SET_H(this, 3, this->registers.HL); break;
        case SET3_L:      this->debug_opcode( (char *)"SET3_L", (char *)"Set bit 3 of L");
            M_SET_L(this, 3, this->registers.HL); break;
        case SET3_xHL:      this->debug_opcode( (char *)"SET3_xHL", (char *)"Set bit 3 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 3, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET4_A:      this->debug_opcode( (char *)"SET4_A", (char *)"Set bit 4 of A");
            M_SET_H(this, 4, this->registers.AF); break;
        case SET4_B:      this->debug_opcode( (char *)"SET4_B", (char *)"Set bit 4 of B");
            M_SET_H(this, 4, this->registers.BC); break;
        case SET4_C:      this->debug_opcode( (char *)"SET4_C", (char *)"Set bit 4 of C");
            M_SET_L(this, 4, this->registers.BC); break;
        case SET4_D:      this->debug_opcode( (char *)"SET4_D", (char *)"Set bit 4 of D");
            M_SET_H(this, 4, this->registers.DE); break;
        case SET4_E:      this->debug_opcode( (char *)"SET4_E", (char *)"Set bit 4 of E");
            M_SET_L(this, 4, this->registers.DE); break;
        case SET4_H:      this->debug_opcode( (char *)"SET4_H", (char *)"Set bit 4 of H");
            M_SET_H(this, 4, this->registers.HL); break;
        case SET4_L:      this->debug_opcode( (char *)"SET4_L", (char *)"Set bit 4 of L");
            M_SET_L(this, 4, this->registers.HL); break;
        case SET4_xHL:      this->debug_opcode( (char *)"SET4_xHL", (char *)"Set bit 4 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 4, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET5_A:      this->debug_opcode( (char *)"SET5_A", (char *)"Set bit 5 of A");
            M_SET_H(this, 5, this->registers.AF); break;
        case SET5_B:      this->debug_opcode( (char *)"SET5_B", (char *)"Set bit 5 of B");
            M_SET_H(this, 5, this->registers.BC); break;
        case SET5_C:      this->debug_opcode( (char *)"SET5_C", (char *)"Set bit 5 of C");
            M_SET_L(this, 5, this->registers.BC); break;
        case SET5_D:      this->debug_opcode( (char *)"SET5_D", (char *)"Set bit 5 of D");
            M_SET_H(this, 5, this->registers.DE); break;
        case SET5_E:      this->debug_opcode( (char *)"SET5_E", (char *)"Set bit 5 of E");
            M_SET_L(this, 5, this->registers.DE); break;
        case SET5_H:      this->debug_opcode( (char *)"SET5_H", (char *)"Set bit 5 of H");
            M_SET_H(this, 5, this->registers.HL); break;
        case SET5_L:      this->debug_opcode( (char *)"SET5_L", (char *)"Set bit 5 of L");
            M_SET_L(this, 5, this->registers.HL); break;
        case SET5_xHL:      this->debug_opcode( (char *)"SET5_xHL", (char *)"Set bit 5 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 5, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET6_A:      this->debug_opcode( (char *)"SET6_A", (char *)"Set bit 6 of A");
            M_SET_H(this, 6, this->registers.AF); break;
        case SET6_B:      this->debug_opcode( (char *)"SET6_B", (char *)"Set bit 6 of B");
            M_SET_H(this, 6, this->registers.BC); break;
        case SET6_C:      this->debug_opcode( (char *)"SET6_C", (char *)"Set bit 6 of C");
            M_SET_L(this, 6, this->registers.BC); break;
        case SET6_D:      this->debug_opcode( (char *)"SET6_D", (char *)"Set bit 6 of D");
            M_SET_H(this, 6, this->registers.DE); break;
        case SET6_E:      this->debug_opcode( (char *)"SET6_E", (char *)"Set bit 6 of E");
            M_SET_L(this, 6, this->registers.DE); break;
        case SET6_H:      this->debug_opcode( (char *)"SET6_H", (char *)"Set bit 6 of H");
            M_SET_H(this, 6, this->registers.HL); break;
        case SET6_L:      this->debug_opcode( (char *)"SET6_L", (char *)"Set bit 6 of L");
            M_SET_L(this, 6, this->registers.HL); break;
        case SET6_xHL:      this->debug_opcode( (char *)"SET6_xHL", (char *)"Set bit 6 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 6, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case SET7_A:      this->debug_opcode( (char *)"SET7_A", (char *)"Set bit 7 of A");
            M_SET_H(this, 7, this->registers.AF); break;
        case SET7_B:      this->debug_opcode( (char *)"SET7_B", (char *)"Set bit 7 of B");
            M_SET_H(this, 7, this->registers.BC); break;
        case SET7_C:      this->debug_opcode( (char *)"SET7_C", (char *)"Set bit 7 of C");
            M_SET_L(this, 7, this->registers.BC); break;
        case SET7_D:      this->debug_opcode( (char *)"SET7_D", (char *)"Set bit 7 of D");
            M_SET_H(this, 7, this->registers.DE); break;
        case SET7_E:      this->debug_opcode( (char *)"SET7_E", (char *)"Set bit 7 of E");
            M_SET_L(this, 7, this->registers.DE); break;
        case SET7_H:      this->debug_opcode( (char *)"SET7_H", (char *)"Set bit 7 of H");
            M_SET_H(this, 7, this->registers.HL); break;
        case SET7_L:      this->debug_opcode( (char *)"SET7_L", (char *)"Set bit 7 of L");
            M_SET_L(this, 7, this->registers.HL); break;
        case SET7_xHL:      this->debug_opcode( (char *)"SET7_xHL", (char *)"Set bit 7 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SET(this, 7, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        
        case RES0_A:      this->debug_opcode( (char *)"RES0_A", (char *)"Reset bit 0 of A");
            M_RES_H(this, 0, this->registers.AF); break;
        case RES0_B:      this->debug_opcode( (char *)"RES0_B", (char *)"Reset bit 0 of B");
            M_RES_H(this, 0, this->registers.BC); break;
        case RES0_C:      this->debug_opcode( (char *)"RES0_C", (char *)"Reset bit 0 of C");
            M_RES_L(this, 0, this->registers.BC); break;
        case RES0_D:      this->debug_opcode( (char *)"RES0_D", (char *)"Reset bit 0 of D");
            M_RES_H(this, 0, this->registers.DE); break;
        case RES0_E:      this->debug_opcode( (char *)"RES0_E", (char *)"Reset bit 0 of E");
            M_RES_L(this, 0, this->registers.DE); break;
        case RES0_H:      this->debug_opcode( (char *)"RES0_H", (char *)"Reset bit 0 of H");
            M_RES_H(this, 0, this->registers.HL); break;
        case RES0_L:      this->debug_opcode( (char *)"RES0_L", (char *)"Reset bit 0 of L");
            M_RES_L(this, 0, this->registers.HL); break;
        case RES0_xHL:      this->debug_opcode( (char *)"RES0_xHL", (char *)"Reset bit 0 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 0, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES1_A:      this->debug_opcode( (char *)"RES1_A", (char *)"Reset bit 1 of A");
            M_RES_H(this, 1, this->registers.AF); break;
        case RES1_B:      this->debug_opcode( (char *)"RES1_B", (char *)"Reset bit 1 of B");
            M_RES_H(this, 1, this->registers.BC); break;
        case RES1_C:      this->debug_opcode( (char *)"RES1_C", (char *)"Reset bit 1 of C");
            M_RES_L(this, 1, this->registers.BC); break;
        case RES1_D:      this->debug_opcode( (char *)"RES1_D", (char *)"Reset bit 1 of D");
            M_RES_H(this, 1, this->registers.DE); break;
        case RES1_E:      this->debug_opcode( (char *)"RES1_E", (char *)"Reset bit 1 of E");
            M_RES_L(this, 1, this->registers.DE); break;
        case RES1_H:      this->debug_opcode( (char *)"RES1_H", (char *)"Reset bit 1 of H");
            M_RES_H(this, 1, this->registers.HL); break;
        case RES1_L:      this->debug_opcode( (char *)"RES1_L", (char *)"Reset bit 1 of L");
            M_RES_L(this, 1, this->registers.HL); break;
        case RES1_xHL:      this->debug_opcode( (char *)"RES1_xHL", (char *)"Reset bit 1 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 1, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES2_A:      this->debug_opcode( (char *)"RES2_A", (char *)"Reset bit 2 of A");
            M_RES_H(this, 2, this->registers.AF); break;
        case RES2_B:      this->debug_opcode( (char *)"RES2_B", (char *)"Reset bit 2 of B");
            M_RES_H(this, 2, this->registers.BC); break;
        case RES2_C:      this->debug_opcode( (char *)"RES2_C", (char *)"Reset bit 2 of C");
            M_RES_L(this, 2, this->registers.BC); break;
        case RES2_D:      this->debug_opcode( (char *)"RES2_D", (char *)"Reset bit 2 of D");
            M_RES_H(this, 2, this->registers.DE); break;
        case RES2_E:      this->debug_opcode( (char *)"RES2_E", (char *)"Reset bit 2 of E");
            M_RES_L(this, 2, this->registers.DE); break;
        case RES2_H:      this->debug_opcode( (char *)"RES2_H", (char *)"Reset bit 2 of H");
            M_RES_H(this, 2, this->registers.HL); break;
        case RES2_L:      this->debug_opcode( (char *)"RES2_L", (char *)"Reset bit 2 of L");
            M_RES_L(this, 2, this->registers.HL); break;
        case RES2_xHL:      this->debug_opcode( (char *)"RES2_xHL", (char *)"Reset bit 2 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 2, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES3_A:      this->debug_opcode( (char *)"RES3_A", (char *)"Reset bit 3 of A");
            M_RES_H(this, 3, this->registers.AF); break;
        case RES3_B:      this->debug_opcode( (char *)"RES3_B", (char *)"Reset bit 3 of B");
            M_RES_H(this, 3, this->registers.BC); break;
        case RES3_C:      this->debug_opcode( (char *)"RES3_C", (char *)"Reset bit 3 of C");
            M_RES_L(this, 3, this->registers.BC); break;
        case RES3_D:      this->debug_opcode( (char *)"RES3_D", (char *)"Reset bit 3 of D");
            M_RES_H(this, 3, this->registers.DE); break;
        case RES3_E:      this->debug_opcode( (char *)"RES3_E", (char *)"Reset bit 3 of E");
            M_RES_L(this, 3, this->registers.DE); break;
        case RES3_H:      this->debug_opcode( (char *)"RES3_H", (char *)"Reset bit 3 of H");
            M_RES_H(this, 3, this->registers.HL); break;
        case RES3_L:      this->debug_opcode( (char *)"RES3_L", (char *)"Reset bit 3 of L");
            M_RES_L(this, 3, this->registers.HL); break;
        case RES3_xHL:      this->debug_opcode( (char *)"RES3_xHL", (char *)"Reset bit 3 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 3, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES4_A:      this->debug_opcode( (char *)"RES4_A", (char *)"Reset bit 4 of A");
            M_RES_H(this, 4, this->registers.AF); break;
        case RES4_B:      this->debug_opcode( (char *)"RES4_B", (char *)"Reset bit 4 of B");
            M_RES_H(this, 4, this->registers.BC); break;
        case RES4_C:      this->debug_opcode( (char *)"RES4_C", (char *)"Reset bit 4 of C");
            M_RES_L(this, 4, this->registers.BC); break;
        case RES4_D:      this->debug_opcode( (char *)"RES4_D", (char *)"Reset bit 4 of D");
            M_RES_H(this, 4, this->registers.DE); break;
        case RES4_E:      this->debug_opcode( (char *)"RES4_E", (char *)"Reset bit 4 of E");
            M_RES_L(this, 4, this->registers.DE); break;
        case RES4_H:      this->debug_opcode( (char *)"RES4_H", (char *)"Reset bit 4 of H");
            M_RES_H(this, 4, this->registers.HL); break;
        case RES4_L:      this->debug_opcode( (char *)"RES4_L", (char *)"Reset bit 4 of L");
            M_RES_L(this, 4, this->registers.HL); break;
        case RES4_xHL:      this->debug_opcode( (char *)"RES4_xHL", (char *)"Reset bit 4 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 4, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES5_A:      this->debug_opcode( (char *)"RES5_A", (char *)"Reset bit 5 of A");
            M_RES_H(this, 5, this->registers.AF); break;
        case RES5_B:      this->debug_opcode( (char *)"RES5_B", (char *)"Reset bit 5 of B");
            M_RES_H(this, 5, this->registers.BC); break;
        case RES5_C:      this->debug_opcode( (char *)"RES5_C", (char *)"Reset bit 5 of C");
            M_RES_L(this, 5, this->registers.BC); break;
        case RES5_D:      this->debug_opcode( (char *)"RES5_D", (char *)"Reset bit 5 of D");
            M_RES_H(this, 5, this->registers.DE); break;
        case RES5_E:      this->debug_opcode( (char *)"RES5_E", (char *)"Reset bit 5 of E");
            M_RES_L(this, 5, this->registers.DE); break;
        case RES5_H:      this->debug_opcode( (char *)"RES5_H", (char *)"Reset bit 5 of H");
            M_RES_H(this, 5, this->registers.HL); break;
        case RES5_L:      this->debug_opcode( (char *)"RES5_L", (char *)"Reset bit 5 of L");
            M_RES_L(this, 5, this->registers.HL); break;
        case RES5_xHL:      this->debug_opcode( (char *)"RES5_xHL", (char *)"Reset bit 5 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 5, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES6_A:      this->debug_opcode( (char *)"RES6_A", (char *)"Reset bit 6 of A");
            M_RES_H(this, 6, this->registers.AF); break;
        case RES6_B:      this->debug_opcode( (char *)"RES6_B", (char *)"Reset bit 6 of B");
            M_RES_H(this, 6, this->registers.BC); break;
        case RES6_C:      this->debug_opcode( (char *)"RES6_C", (char *)"Reset bit 6 of C");
            M_RES_L(this, 6, this->registers.BC); break;
        case RES6_D:      this->debug_opcode( (char *)"RES6_D", (char *)"Reset bit 6 of D");
            M_RES_H(this, 6, this->registers.DE); break;
        case RES6_E:      this->debug_opcode( (char *)"RES6_E", (char *)"Reset bit 6 of E");
            M_RES_L(this, 6, this->registers.DE); break;
        case RES6_H:      this->debug_opcode( (char *)"RES6_H", (char *)"Reset bit 6 of H");
            M_RES_H(this, 6, this->registers.HL); break;
        case RES6_L:      this->debug_opcode( (char *)"RES6_L", (char *)"Reset bit 6 of L");
            M_RES_L(this, 6, this->registers.HL); break;
        case RES6_xHL:      this->debug_opcode( (char *)"RES6_xHL", (char *)"Reset bit 6 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 6, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
        case RES7_A:      this->debug_opcode( (char *)"RES7_A", (char *)"Reset bit 7 of A");
            M_RES_H(this, 7, this->registers.AF); break;
        case RES7_B:      this->debug_opcode( (char *)"RES7_B", (char *)"Reset bit 7 of B");
            M_RES_H(this, 7, this->registers.BC); break;
        case RES7_C:      this->debug_opcode( (char *)"RES7_C", (char *)"Reset bit 7 of C");
            M_RES_L(this, 7, this->registers.BC); break;
        case RES7_D:      this->debug_opcode( (char *)"RES7_D", (char *)"Reset bit 7 of D");
            M_RES_H(this, 7, this->registers.DE); break;
        case RES7_E:      this->debug_opcode( (char *)"RES7_E", (char *)"Reset bit 7 of E");
            M_RES_L(this, 7, this->registers.DE); break;
        case RES7_H:      this->debug_opcode( (char *)"RES7_H", (char *)"Reset bit 7 of H");
            M_RES_H(this, 7, this->registers.HL); break;
        case RES7_L:      this->debug_opcode( (char *)"RES7_L", (char *)"Reset bit 7 of L");
            M_RES_L(this, 7, this->registers.HL); break;
        case RES7_xHL:      this->debug_opcode( (char *)"RES7_xHL", (char *)"Reset bit 7 of (HL)");
            I = this->RdZ80(z80cpm_memory, this->registers.HL); M_RES(this, 7, I); this->WrZ80(z80cpm_memory, this->registers.HL, I); break; 
        
	

        default:{
            char str2[20];
            sprintf(str2,"unknown 0x%x",opcode);
            this->debug_opcode(str2, (char*)"");
             if(this->TrapBadOps)
            printf
            (
                "[Z80 %lX] Unrecognized instruction: CB %02X at PC=%04X\n",
                (long)this->User,this->OpZ80(z80cpm_memory, this->registers.PC-1),this->registers.PC-2
            );
        }
    }
}
