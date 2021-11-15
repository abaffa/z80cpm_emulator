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


static void z80_exec_extended_CB(struct z80* z80, struct z80cpm_memory* z80cpm_memory)
{
    unsigned char I; //register

    I = OpZ80(z80, z80cpm_memory, z80->registers.PC);
    unsigned char opcode = I;
    z80->ICount -= CyclesCB[I];

    switch(I)
    {
        case RLC_A:      debug_opcode(z80, (char *)"RLC_A", (char *)"The contents of A are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(z80, z80->registers.AF); break; 
        case RLC_B:      debug_opcode(z80, (char *)"RLC_B", (char *)"The contents of B are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(z80, z80->registers.BC); break;
        case RLC_C:      debug_opcode(z80, (char *)"RLC_C", (char *)"The contents of C are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_L(z80, z80->registers.BC); break; 
        case RLC_D:      debug_opcode(z80, (char *)"RLC_D", (char *)"The contents of D are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(z80, z80->registers.DE); break;
        case RLC_E:      debug_opcode(z80, (char *)"RLC_E", (char *)"The contents of E are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_L(z80, z80->registers.DE); break; 
        case RLC_H:      debug_opcode(z80, (char *)"RLC_H", (char *)"The contents of H are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_H(z80, z80->registers.HL); break;
        case RLC_L:      debug_opcode(z80, (char *)"RLC_L", (char *)"The contents of L are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            M_RLC_L(z80, z80->registers.HL); break; 
        case RLC_xHL:      debug_opcode(z80, (char *)"RLC_xHL", (char *)"The contents of (HL) are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RLC(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case RRC_A:      debug_opcode(z80, (char *)"RRC_A", (char *)"The contents of A are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(z80, z80->registers.AF); break; 
        case RRC_B:      debug_opcode(z80, (char *)"RRC_B", (char *)"The contents of B are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(z80, z80->registers.BC); break;
        case RRC_C:      debug_opcode(z80, (char *)"RRC_C", (char *)"The contents of C are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_L(z80, z80->registers.BC); break; 
        case RRC_D:      debug_opcode(z80, (char *)"RRC_D", (char *)"The contents of D are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(z80, z80->registers.DE); break;
        case RRC_E:      debug_opcode(z80, (char *)"RRC_E", (char *)"The contents of E are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_L(z80, z80->registers.DE); break; 
        case RRC_H:      debug_opcode(z80, (char *)"RRC_H", (char *)"The contents of H are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_H(z80, z80->registers.HL); break;
        case RRC_L:      debug_opcode(z80, (char *)"RRC_L", (char *)"The contents of L are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            M_RRC_L(z80, z80->registers.HL); break; 
        case RRC_xHL:      debug_opcode(z80, (char *)"RRC_xHL", (char *)"The contents of (HL) are rotated right one bit position. The content of bit 0 are copied to the carry flag and bit 7.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RRC(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case RL_A:      debug_opcode(z80, (char *)"RL_A", (char *)"The contents of A are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(z80, z80->registers.AF); break; 
        case RL_B:      debug_opcode(z80, (char *)"RL_B", (char *)"The contents of B are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(z80, z80->registers.BC); break;
        case RL_C:      debug_opcode(z80, (char *)"RL_C", (char *)"The contents of C are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_L(z80, z80->registers.BC); break; 
        case RL_D:      debug_opcode(z80, (char *)"RL_D", (char *)"The contents of D are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(z80, z80->registers.DE); break;
        case RL_E:      debug_opcode(z80, (char *)"RL_E", (char *)"The contents of E are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_L(z80, z80->registers.DE); break; 
        case RL_H:      debug_opcode(z80, (char *)"RL_H", (char *)"The contents of H are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_H(z80, z80->registers.HL); break;
        case RL_L:      debug_opcode(z80, (char *)"RL_L", (char *)"The contents of L are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            M_RL_L(z80, z80->registers.HL); break; 
        case RL_xHL:      debug_opcode(z80, (char *)"RL_xHL", (char *)"The contents of (HL) are rotated left one bit position. The content of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RL(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case RR_A:      debug_opcode(z80, (char *)"RR_A", (char *)"The contents of A are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(z80, z80->registers.AF); break; 
        case RR_B:      debug_opcode(z80, (char *)"RR_B", (char *)"The contents of B are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(z80, z80->registers.BC); break;
        case RR_C:      debug_opcode(z80, (char *)"RR_C", (char *)"The contents of C are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_L(z80, z80->registers.BC); break; 
        case RR_D:      debug_opcode(z80, (char *)"RR_D", (char *)"The contents of D are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(z80, z80->registers.DE); break;
        case RR_E:      debug_opcode(z80, (char *)"RR_E", (char *)"The contents of E are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_L(z80, z80->registers.DE); break; 
        case RR_H:      debug_opcode(z80, (char *)"RR_H", (char *)"The contents of H are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_H(z80, z80->registers.HL); break;
        case RR_L:      debug_opcode(z80, (char *)"RR_L", (char *)"The contents of L are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            M_RR_L(z80, z80->registers.HL); break; 
        case RR_xHL:      debug_opcode(z80, (char *)"RR_xHL", (char *)"The contents of (HL) are rotated right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RR(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case SLA_A:      debug_opcode(z80, (char *)"SLA_A", (char *)"The contents of A are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(z80, z80->registers.AF); break; 
        case SLA_B:      debug_opcode(z80, (char *)"SLA_B", (char *)"The contents of B are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(z80, z80->registers.BC); break;
        case SLA_C:      debug_opcode(z80, (char *)"SLA_C", (char *)"The contents of C are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_L(z80, z80->registers.BC); break; 
        case SLA_D:      debug_opcode(z80, (char *)"SLA_D", (char *)"The contents of D are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(z80, z80->registers.DE); break;
        case SLA_E:      debug_opcode(z80, (char *)"SLA_E", (char *)"The contents of E are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_L(z80, z80->registers.DE); break; 
        case SLA_H:      debug_opcode(z80, (char *)"SLA_H", (char *)"The contents of H are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_H(z80, z80->registers.HL); break;
        case SLA_L:      debug_opcode(z80, (char *)"SLA_L", (char *)"The contents of L are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            M_SLA_L(z80, z80->registers.HL); break; 
        case SLA_xHL:      debug_opcode(z80, (char *)"SLA_xHL", (char *)"The contents of (HL) are shifted left one bit position. The content of bit 7 are copied to the carry flag and a zero is put into bit 0.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SLA(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case SRA_A:      debug_opcode(z80, (char *)"SRA_A", (char *)"The contents of A are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(z80, z80->registers.AF); break; 
        case SRA_B:      debug_opcode(z80, (char *)"SRA_B", (char *)"The contents of B are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(z80, z80->registers.BC); break;
        case SRA_C:      debug_opcode(z80, (char *)"SRA_C", (char *)"The contents of C are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_L(z80, z80->registers.BC); break; 
        case SRA_D:      debug_opcode(z80, (char *)"SRA_D", (char *)"The contents of D are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(z80, z80->registers.DE); break;
        case SRA_E:      debug_opcode(z80, (char *)"SRA_E", (char *)"The contents of E are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_L(z80, z80->registers.DE); break; 
        case SRA_H:      debug_opcode(z80, (char *)"SRA_H", (char *)"The contents of H are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_H(z80, z80->registers.HL); break;
        case SRA_L:      debug_opcode(z80, (char *)"SRA_L", (char *)"The contents of L are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            M_SRA_L(z80, z80->registers.HL); break; 
        case SRA_xHL:      debug_opcode(z80, (char *)"SRA_xHL", (char *)"The contents of (HL) are shifted right one bit position. The content of bit 0 are copied to the carry flag and the previous contents of bit 7 are unchanged.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SRA(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case SLL_A:      debug_opcode(z80, (char *)"SLL_A", (char *)"The contents of A are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(z80, z80->registers.AF); break; 
        case SLL_B:      debug_opcode(z80, (char *)"SLL_B", (char *)"The contents of B are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(z80, z80->registers.BC); break;
        case SLL_C:      debug_opcode(z80, (char *)"SLL_C", (char *)"The contents of C are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_L(z80, z80->registers.BC); break; 
        case SLL_D:      debug_opcode(z80, (char *)"SLL_D", (char *)"The contents of D are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(z80, z80->registers.DE); break;
        case SLL_E:      debug_opcode(z80, (char *)"SLL_E", (char *)"The contents of E are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_L(z80, z80->registers.DE); break; 
        case SLL_H:      debug_opcode(z80, (char *)"SLL_H", (char *)"The contents of H are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_H(z80, z80->registers.HL); break;
        case SLL_L:      debug_opcode(z80, (char *)"SLL_L", (char *)"The contents of L are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            M_SLL_L(z80, z80->registers.HL); break; 
        case SLL_xHL:      debug_opcode(z80, (char *)"SLL_xHL", (char *)"The contents of (HL) are shifted left one bit position. The content of bit 7 are put into the carry flag and a one is put into bit 0.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SLL(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case SRL_A:      debug_opcode(z80, (char *)"SRL_A", (char *)"The contents of A are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(z80, z80->registers.AF); break; 
        case SRL_B:      debug_opcode(z80, (char *)"SRL_B", (char *)"The contents of B are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(z80, z80->registers.BC); break;
        case SRL_C:      debug_opcode(z80, (char *)"SRL_C", (char *)"The contents of C are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_L(z80, z80->registers.BC); break; 
        case SRL_D:      debug_opcode(z80, (char *)"SRL_D", (char *)"The contents of D are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(z80, z80->registers.DE); break;
        case SRL_E:      debug_opcode(z80, (char *)"SRL_E", (char *)"The contents of E are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_L(z80, z80->registers.DE); break; 
        case SRL_H:      debug_opcode(z80, (char *)"SRL_H", (char *)"The contents of H are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_H(z80, z80->registers.HL); break;
        case SRL_L:      debug_opcode(z80, (char *)"SRL_L", (char *)"The contents of L are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            M_SRL_L(z80, z80->registers.HL); break; 
        case SRL_xHL:      debug_opcode(z80, (char *)"SRL_xHL", (char *)"The contents of (HL) are shifted right one bit position. The content of bit 0 are copied to the carry flag and a zero is put into bit 7.");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SRL(z80, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 

        case BIT0_A:      debug_opcode(z80, (char *)"BIT0_A", (char *)"Test bit 0 of A");
            M_BIT(z80, 0, MSB(z80->registers.AF)); break;
        case BIT0_B:      debug_opcode(z80, (char *)"BIT0_B", (char *)"Test bit 0 of B");
            M_BIT(z80, 0, MSB(z80->registers.BC)); break;
        case BIT0_C:      debug_opcode(z80, (char *)"BIT0_C", (char *)"Test bit 0 of C");
            M_BIT(z80, 0, LSB(z80->registers.BC)); break;
        case BIT0_D:      debug_opcode(z80, (char *)"BIT0_D", (char *)"Test bit 0 of D");
            M_BIT(z80, 0, MSB(z80->registers.DE)); break;
        case BIT0_E:      debug_opcode(z80, (char *)"BIT0_E", (char *)"Test bit 0 of E");
            M_BIT(z80, 0, LSB(z80->registers.DE)); break;
        case BIT0_H:      debug_opcode(z80, (char *)"BIT0_H", (char *)"Test bit 0 of H");
            M_BIT(z80, 0, MSB(z80->registers.HL)); break;
        case BIT0_L:      debug_opcode(z80, (char *)"BIT0_L", (char *)"Test bit 0 of L");
            M_BIT(z80, 0, LSB(z80->registers.HL)); break;
        case BIT0_xHL:      debug_opcode(z80, (char *)"BIT0_xHL", (char *)"Test bit 0 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 0, I); break; 

        case BIT1_A:      debug_opcode(z80, (char *)"BIT1_A", (char *)"Test bit 1 of A");
            M_BIT(z80, 1, MSB(z80->registers.AF)); break;
        case BIT1_B:      debug_opcode(z80, (char *)"BIT1_B", (char *)"Test bit 1 of B");
            M_BIT(z80, 1, MSB(z80->registers.BC)); break;
        case BIT1_C:      debug_opcode(z80, (char *)"BIT1_C", (char *)"Test bit 1 of C");
            M_BIT(z80, 1, LSB(z80->registers.BC)); break;
        case BIT1_D:      debug_opcode(z80, (char *)"BIT1_D", (char *)"Test bit 1 of D");
            M_BIT(z80, 1, MSB(z80->registers.DE)); break;
        case BIT1_E:      debug_opcode(z80, (char *)"BIT1_E", (char *)"Test bit 1 of E");
            M_BIT(z80, 1, LSB(z80->registers.DE)); break;
        case BIT1_H:      debug_opcode(z80, (char *)"BIT1_H", (char *)"Test bit 1 of H");
            M_BIT(z80, 1, MSB(z80->registers.HL)); break;
        case BIT1_L:      debug_opcode(z80, (char *)"BIT1_L", (char *)"Test bit 1 of L");
            M_BIT(z80, 1, LSB(z80->registers.HL)); break;
        case BIT1_xHL:      debug_opcode(z80, (char *)"BIT1_xHL", (char *)"Test bit 1 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 1, I); break; 
    
        case BIT2_A:      debug_opcode(z80, (char *)"BIT2_A", (char *)"Test bit 2 of A");
            M_BIT(z80, 2, MSB(z80->registers.AF)); break;
        case BIT2_B:      debug_opcode(z80, (char *)"BIT2_B", (char *)"Test bit 2 of B");
            M_BIT(z80, 2, MSB(z80->registers.BC)); break;
        case BIT2_C:      debug_opcode(z80, (char *)"BIT2_C", (char *)"Test bit 2 of C");
            M_BIT(z80, 2, LSB(z80->registers.BC)); break;
        case BIT2_D:      debug_opcode(z80, (char *)"BIT2_D", (char *)"Test bit 2 of D");
            M_BIT(z80, 2, MSB(z80->registers.DE)); break;
        case BIT2_E:      debug_opcode(z80, (char *)"BIT2_E", (char *)"Test bit 2 of E");
            M_BIT(z80, 2, LSB(z80->registers.DE)); break;
        case BIT2_H:      debug_opcode(z80, (char *)"BIT2_H", (char *)"Test bit 2 of H");
            M_BIT(z80, 2, MSB(z80->registers.HL)); break;
        case BIT2_L:      debug_opcode(z80, (char *)"BIT2_L", (char *)"Test bit 2 of L");
            M_BIT(z80, 2, LSB(z80->registers.HL)); break;
        case BIT2_xHL:      debug_opcode(z80, (char *)"BIT2_xHL", (char *)"Test bit 2 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 2, I); break; 

        case BIT3_A:      debug_opcode(z80, (char *)"BIT3_A", (char *)"Test bit 3 of A");
            M_BIT(z80, 3, MSB(z80->registers.AF)); break;
        case BIT3_B:      debug_opcode(z80, (char *)"BIT3_B", (char *)"Test bit 3 of B");
            M_BIT(z80, 3, MSB(z80->registers.BC)); break;
        case BIT3_C:      debug_opcode(z80, (char *)"BIT3_C", (char *)"Test bit 3 of C");
            M_BIT(z80, 3, LSB(z80->registers.BC)); break;
        case BIT3_D:      debug_opcode(z80, (char *)"BIT3_D", (char *)"Test bit 3 of D");
            M_BIT(z80, 3, MSB(z80->registers.DE)); break;
        case BIT3_E:      debug_opcode(z80, (char *)"BIT3_E", (char *)"Test bit 3 of E");
            M_BIT(z80, 3, LSB(z80->registers.DE)); break;
        case BIT3_H:      debug_opcode(z80, (char *)"BIT3_H", (char *)"Test bit 3 of H");
            M_BIT(z80, 3, MSB(z80->registers.HL)); break;
        case BIT3_L:      debug_opcode(z80, (char *)"BIT3_L", (char *)"Test bit 3 of L");
            M_BIT(z80, 3, LSB(z80->registers.HL)); break;
        case BIT3_xHL:      debug_opcode(z80, (char *)"BIT3_xHL", (char *)"Test bit 3 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 3, I); break; 

        case BIT4_A:      debug_opcode(z80, (char *)"BIT4_A", (char *)"Test bit 4 of A");
            M_BIT(z80, 4, MSB(z80->registers.AF)); break;
        case BIT4_B:      debug_opcode(z80, (char *)"BIT4_B", (char *)"Test bit 4 of B");
            M_BIT(z80, 4, MSB(z80->registers.BC)); break;
        case BIT4_C:      debug_opcode(z80, (char *)"BIT4_C", (char *)"Test bit 4 of C");
            M_BIT(z80, 4, LSB(z80->registers.BC)); break;
        case BIT4_D:      debug_opcode(z80, (char *)"BIT4_D", (char *)"Test bit 4 of D");
            M_BIT(z80, 4, MSB(z80->registers.DE)); break;
        case BIT4_E:      debug_opcode(z80, (char *)"BIT4_E", (char *)"Test bit 4 of E");
            M_BIT(z80, 4, LSB(z80->registers.DE)); break;
        case BIT4_H:      debug_opcode(z80, (char *)"BIT4_H", (char *)"Test bit 4 of H");
            M_BIT(z80, 4, MSB(z80->registers.HL)); break;
        case BIT4_L:      debug_opcode(z80, (char *)"BIT4_L", (char *)"Test bit 4 of L");
            M_BIT(z80, 4, LSB(z80->registers.HL)); break;
        case BIT4_xHL:      debug_opcode(z80, (char *)"BIT4_xHL", (char *)"Test bit 4 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 4, I); break; 
    
        case BIT5_A:      debug_opcode(z80, (char *)"BIT5_A", (char *)"Test bit 5 of A");
            M_BIT(z80, 5, MSB(z80->registers.AF)); break;
        case BIT5_B:      debug_opcode(z80, (char *)"BIT5_B", (char *)"Test bit 5 of B");
            M_BIT(z80, 5, MSB(z80->registers.BC)); break;
        case BIT5_C:      debug_opcode(z80, (char *)"BIT5_C", (char *)"Test bit 5 of C");
            M_BIT(z80, 5, LSB(z80->registers.BC)); break;
        case BIT5_D:      debug_opcode(z80, (char *)"BIT5_D", (char *)"Test bit 5 of D");
            M_BIT(z80, 5, MSB(z80->registers.DE)); break;
        case BIT5_E:      debug_opcode(z80, (char *)"BIT5_E", (char *)"Test bit 5 of E");
            M_BIT(z80, 5, LSB(z80->registers.DE)); break;
        case BIT5_H:      debug_opcode(z80, (char *)"BIT5_H", (char *)"Test bit 5 of H");
            M_BIT(z80, 5, MSB(z80->registers.HL)); break;
        case BIT5_L:      debug_opcode(z80, (char *)"BIT5_L", (char *)"Test bit 5 of L");
            M_BIT(z80, 5, LSB(z80->registers.HL)); break;
        case BIT5_xHL:      debug_opcode(z80, (char *)"BIT5_xHL", (char *)"Test bit 5 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 5, I); break; 

        case BIT6_A:      debug_opcode(z80, (char *)"BIT6_A", (char *)"Test bit 6 of A");
            M_BIT(z80, 6, MSB(z80->registers.AF)); break;
        case BIT6_B:      debug_opcode(z80, (char *)"BIT6_B", (char *)"Test bit 6 of B");
            M_BIT(z80, 6, MSB(z80->registers.BC)); break;
        case BIT6_C:      debug_opcode(z80, (char *)"BIT6_C", (char *)"Test bit 6 of C");
            M_BIT(z80, 6, LSB(z80->registers.BC)); break;
        case BIT6_D:      debug_opcode(z80, (char *)"BIT6_D", (char *)"Test bit 6 of D");
            M_BIT(z80, 6, MSB(z80->registers.DE)); break;
        case BIT6_E:      debug_opcode(z80, (char *)"BIT6_E", (char *)"Test bit 6 of E");
            M_BIT(z80, 6, LSB(z80->registers.DE)); break;
        case BIT6_H:      debug_opcode(z80, (char *)"BIT6_H", (char *)"Test bit 6 of H");
            M_BIT(z80, 6, MSB(z80->registers.HL)); break;
        case BIT6_L:      debug_opcode(z80, (char *)"BIT6_L", (char *)"Test bit 6 of L");
            M_BIT(z80, 6, LSB(z80->registers.HL)); break;
        case BIT6_xHL:      debug_opcode(z80, (char *)"BIT6_xHL", (char *)"Test bit 6 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 6, I); break; 

        case BIT7_A:      debug_opcode(z80, (char *)"BIT7_A", (char *)"Test bit 7 of A");
            M_BIT(z80, 7, MSB(z80->registers.AF)); break;
        case BIT7_B:      debug_opcode(z80, (char *)"BIT7_B", (char *)"Test bit 7 of B");
            M_BIT(z80, 7, MSB(z80->registers.BC)); break;
        case BIT7_C:      debug_opcode(z80, (char *)"BIT7_C", (char *)"Test bit 7 of C");
            M_BIT(z80, 7, LSB(z80->registers.BC)); break;
        case BIT7_D:      debug_opcode(z80, (char *)"BIT7_D", (char *)"Test bit 7 of D");
            M_BIT(z80, 7, MSB(z80->registers.DE)); break;
        case BIT7_E:      debug_opcode(z80, (char *)"BIT7_E", (char *)"Test bit 7 of E");
            M_BIT(z80, 7, LSB(z80->registers.DE)); break;
        case BIT7_H:      debug_opcode(z80, (char *)"BIT7_H", (char *)"Test bit 7 of H");
            M_BIT(z80, 7, MSB(z80->registers.HL)); break;
        case BIT7_L:      debug_opcode(z80, (char *)"BIT7_L", (char *)"Test bit 7 of L");
            M_BIT(z80, 7, LSB(z80->registers.HL)); break;
        case BIT7_xHL:      debug_opcode(z80, (char *)"BIT7_xHL", (char *)"Test bit 7 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_BIT(z80, 7, I); break; 


        case SET0_A:      debug_opcode(z80, (char *)"SET0_A", (char *)"Set bit 0 of A");
            M_SET_H(z80, 0, z80->registers.AF); break;
        case SET0_B:      debug_opcode(z80, (char *)"SET0_B", (char *)"Set bit 0 of B");
            M_SET_H(z80, 0, z80->registers.BC); break;
        case SET0_C:      debug_opcode(z80, (char *)"SET0_C", (char *)"Set bit 0 of C");
            M_SET_L(z80, 0, z80->registers.BC); break;
        case SET0_D:      debug_opcode(z80, (char *)"SET0_D", (char *)"Set bit 0 of D");
            M_SET_H(z80, 0, z80->registers.DE); break;
        case SET0_E:      debug_opcode(z80, (char *)"SET0_E", (char *)"Set bit 0 of E");
            M_SET_L(z80, 0, z80->registers.DE); break;
        case SET0_H:      debug_opcode(z80, (char *)"SET0_H", (char *)"Set bit 0 of H");
            M_SET_H(z80, 0, z80->registers.HL); break;
        case SET0_L:      debug_opcode(z80, (char *)"SET0_L", (char *)"Set bit 0 of L");
            M_SET_L(z80, 0, z80->registers.HL); break;
        case SET0_xHL:      debug_opcode(z80, (char *)"SET0_xHL", (char *)"Set bit 0 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 0, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET1_A:      debug_opcode(z80, (char *)"SET1_A", (char *)"Set bit 1 of A");
            M_SET_H(z80, 1, z80->registers.AF); break;
        case SET1_B:      debug_opcode(z80, (char *)"SET1_B", (char *)"Set bit 1 of B");
            M_SET_H(z80, 1, z80->registers.BC); break;
        case SET1_C:      debug_opcode(z80, (char *)"SET1_C", (char *)"Set bit 1 of C");
            M_SET_L(z80, 1, z80->registers.BC); break;
        case SET1_D:      debug_opcode(z80, (char *)"SET1_D", (char *)"Set bit 1 of D");
            M_SET_H(z80, 1, z80->registers.DE); break;
        case SET1_E:      debug_opcode(z80, (char *)"SET1_E", (char *)"Set bit 1 of E");
            M_SET_L(z80, 1, z80->registers.DE); break;
        case SET1_H:      debug_opcode(z80, (char *)"SET1_H", (char *)"Set bit 1 of H");
            M_SET_H(z80, 1, z80->registers.HL); break;
        case SET1_L:      debug_opcode(z80, (char *)"SET1_L", (char *)"Set bit 1 of L");
            M_SET_L(z80, 1, z80->registers.HL); break;
        case SET1_xHL:      debug_opcode(z80, (char *)"SET1_xHL", (char *)"Set bit 1 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 1, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET2_A:      debug_opcode(z80, (char *)"SET2_A", (char *)"Set bit 2 of A");
            M_SET_H(z80, 2, z80->registers.AF); break;
        case SET2_B:      debug_opcode(z80, (char *)"SET2_B", (char *)"Set bit 2 of B");
            M_SET_H(z80, 2, z80->registers.BC); break;
        case SET2_C:      debug_opcode(z80, (char *)"SET2_C", (char *)"Set bit 2 of C");
            M_SET_L(z80, 2, z80->registers.BC); break;
        case SET2_D:      debug_opcode(z80, (char *)"SET2_D", (char *)"Set bit 2 of D");
            M_SET_H(z80, 2, z80->registers.DE); break;
        case SET2_E:      debug_opcode(z80, (char *)"SET2_E", (char *)"Set bit 2 of E");
            M_SET_L(z80, 2, z80->registers.DE); break;
        case SET2_H:      debug_opcode(z80, (char *)"SET2_H", (char *)"Set bit 2 of H");
            M_SET_H(z80, 2, z80->registers.HL); break;
        case SET2_L:      debug_opcode(z80, (char *)"SET2_L", (char *)"Set bit 2 of L");
            M_SET_L(z80, 2, z80->registers.HL); break;
        case SET2_xHL:      debug_opcode(z80, (char *)"SET2_xHL", (char *)"Set bit 2 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 2, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET3_A:      debug_opcode(z80, (char *)"SET3_A", (char *)"Set bit 3 of A");
            M_SET_H(z80, 3, z80->registers.AF); break;
        case SET3_B:      debug_opcode(z80, (char *)"SET3_B", (char *)"Set bit 3 of B");
            M_SET_H(z80, 3, z80->registers.BC); break;
        case SET3_C:      debug_opcode(z80, (char *)"SET3_C", (char *)"Set bit 3 of C");
            M_SET_L(z80, 3, z80->registers.BC); break;
        case SET3_D:      debug_opcode(z80, (char *)"SET3_D", (char *)"Set bit 3 of D");
            M_SET_H(z80, 3, z80->registers.DE); break;
        case SET3_E:      debug_opcode(z80, (char *)"SET3_E", (char *)"Set bit 3 of E");
            M_SET_L(z80, 3, z80->registers.DE); break;
        case SET3_H:      debug_opcode(z80, (char *)"SET3_H", (char *)"Set bit 3 of H");
            M_SET_H(z80, 3, z80->registers.HL); break;
        case SET3_L:      debug_opcode(z80, (char *)"SET3_L", (char *)"Set bit 3 of L");
            M_SET_L(z80, 3, z80->registers.HL); break;
        case SET3_xHL:      debug_opcode(z80, (char *)"SET3_xHL", (char *)"Set bit 3 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 3, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET4_A:      debug_opcode(z80, (char *)"SET4_A", (char *)"Set bit 4 of A");
            M_SET_H(z80, 4, z80->registers.AF); break;
        case SET4_B:      debug_opcode(z80, (char *)"SET4_B", (char *)"Set bit 4 of B");
            M_SET_H(z80, 4, z80->registers.BC); break;
        case SET4_C:      debug_opcode(z80, (char *)"SET4_C", (char *)"Set bit 4 of C");
            M_SET_L(z80, 4, z80->registers.BC); break;
        case SET4_D:      debug_opcode(z80, (char *)"SET4_D", (char *)"Set bit 4 of D");
            M_SET_H(z80, 4, z80->registers.DE); break;
        case SET4_E:      debug_opcode(z80, (char *)"SET4_E", (char *)"Set bit 4 of E");
            M_SET_L(z80, 4, z80->registers.DE); break;
        case SET4_H:      debug_opcode(z80, (char *)"SET4_H", (char *)"Set bit 4 of H");
            M_SET_H(z80, 4, z80->registers.HL); break;
        case SET4_L:      debug_opcode(z80, (char *)"SET4_L", (char *)"Set bit 4 of L");
            M_SET_L(z80, 4, z80->registers.HL); break;
        case SET4_xHL:      debug_opcode(z80, (char *)"SET4_xHL", (char *)"Set bit 4 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 4, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET5_A:      debug_opcode(z80, (char *)"SET5_A", (char *)"Set bit 5 of A");
            M_SET_H(z80, 5, z80->registers.AF); break;
        case SET5_B:      debug_opcode(z80, (char *)"SET5_B", (char *)"Set bit 5 of B");
            M_SET_H(z80, 5, z80->registers.BC); break;
        case SET5_C:      debug_opcode(z80, (char *)"SET5_C", (char *)"Set bit 5 of C");
            M_SET_L(z80, 5, z80->registers.BC); break;
        case SET5_D:      debug_opcode(z80, (char *)"SET5_D", (char *)"Set bit 5 of D");
            M_SET_H(z80, 5, z80->registers.DE); break;
        case SET5_E:      debug_opcode(z80, (char *)"SET5_E", (char *)"Set bit 5 of E");
            M_SET_L(z80, 5, z80->registers.DE); break;
        case SET5_H:      debug_opcode(z80, (char *)"SET5_H", (char *)"Set bit 5 of H");
            M_SET_H(z80, 5, z80->registers.HL); break;
        case SET5_L:      debug_opcode(z80, (char *)"SET5_L", (char *)"Set bit 5 of L");
            M_SET_L(z80, 5, z80->registers.HL); break;
        case SET5_xHL:      debug_opcode(z80, (char *)"SET5_xHL", (char *)"Set bit 5 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 5, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET6_A:      debug_opcode(z80, (char *)"SET6_A", (char *)"Set bit 6 of A");
            M_SET_H(z80, 6, z80->registers.AF); break;
        case SET6_B:      debug_opcode(z80, (char *)"SET6_B", (char *)"Set bit 6 of B");
            M_SET_H(z80, 6, z80->registers.BC); break;
        case SET6_C:      debug_opcode(z80, (char *)"SET6_C", (char *)"Set bit 6 of C");
            M_SET_L(z80, 6, z80->registers.BC); break;
        case SET6_D:      debug_opcode(z80, (char *)"SET6_D", (char *)"Set bit 6 of D");
            M_SET_H(z80, 6, z80->registers.DE); break;
        case SET6_E:      debug_opcode(z80, (char *)"SET6_E", (char *)"Set bit 6 of E");
            M_SET_L(z80, 6, z80->registers.DE); break;
        case SET6_H:      debug_opcode(z80, (char *)"SET6_H", (char *)"Set bit 6 of H");
            M_SET_H(z80, 6, z80->registers.HL); break;
        case SET6_L:      debug_opcode(z80, (char *)"SET6_L", (char *)"Set bit 6 of L");
            M_SET_L(z80, 6, z80->registers.HL); break;
        case SET6_xHL:      debug_opcode(z80, (char *)"SET6_xHL", (char *)"Set bit 6 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 6, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case SET7_A:      debug_opcode(z80, (char *)"SET7_A", (char *)"Set bit 7 of A");
            M_SET_H(z80, 7, z80->registers.AF); break;
        case SET7_B:      debug_opcode(z80, (char *)"SET7_B", (char *)"Set bit 7 of B");
            M_SET_H(z80, 7, z80->registers.BC); break;
        case SET7_C:      debug_opcode(z80, (char *)"SET7_C", (char *)"Set bit 7 of C");
            M_SET_L(z80, 7, z80->registers.BC); break;
        case SET7_D:      debug_opcode(z80, (char *)"SET7_D", (char *)"Set bit 7 of D");
            M_SET_H(z80, 7, z80->registers.DE); break;
        case SET7_E:      debug_opcode(z80, (char *)"SET7_E", (char *)"Set bit 7 of E");
            M_SET_L(z80, 7, z80->registers.DE); break;
        case SET7_H:      debug_opcode(z80, (char *)"SET7_H", (char *)"Set bit 7 of H");
            M_SET_H(z80, 7, z80->registers.HL); break;
        case SET7_L:      debug_opcode(z80, (char *)"SET7_L", (char *)"Set bit 7 of L");
            M_SET_L(z80, 7, z80->registers.HL); break;
        case SET7_xHL:      debug_opcode(z80, (char *)"SET7_xHL", (char *)"Set bit 7 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_SET(z80, 7, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        
        case RES0_A:      debug_opcode(z80, (char *)"RES0_A", (char *)"Reset bit 0 of A");
            M_RES_H(z80, 0, z80->registers.AF); break;
        case RES0_B:      debug_opcode(z80, (char *)"RES0_B", (char *)"Reset bit 0 of B");
            M_RES_H(z80, 0, z80->registers.BC); break;
        case RES0_C:      debug_opcode(z80, (char *)"RES0_C", (char *)"Reset bit 0 of C");
            M_RES_L(z80, 0, z80->registers.BC); break;
        case RES0_D:      debug_opcode(z80, (char *)"RES0_D", (char *)"Reset bit 0 of D");
            M_RES_H(z80, 0, z80->registers.DE); break;
        case RES0_E:      debug_opcode(z80, (char *)"RES0_E", (char *)"Reset bit 0 of E");
            M_RES_L(z80, 0, z80->registers.DE); break;
        case RES0_H:      debug_opcode(z80, (char *)"RES0_H", (char *)"Reset bit 0 of H");
            M_RES_H(z80, 0, z80->registers.HL); break;
        case RES0_L:      debug_opcode(z80, (char *)"RES0_L", (char *)"Reset bit 0 of L");
            M_RES_L(z80, 0, z80->registers.HL); break;
        case RES0_xHL:      debug_opcode(z80, (char *)"RES0_xHL", (char *)"Reset bit 0 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 0, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES1_A:      debug_opcode(z80, (char *)"RES1_A", (char *)"Reset bit 1 of A");
            M_RES_H(z80, 1, z80->registers.AF); break;
        case RES1_B:      debug_opcode(z80, (char *)"RES1_B", (char *)"Reset bit 1 of B");
            M_RES_H(z80, 1, z80->registers.BC); break;
        case RES1_C:      debug_opcode(z80, (char *)"RES1_C", (char *)"Reset bit 1 of C");
            M_RES_L(z80, 1, z80->registers.BC); break;
        case RES1_D:      debug_opcode(z80, (char *)"RES1_D", (char *)"Reset bit 1 of D");
            M_RES_H(z80, 1, z80->registers.DE); break;
        case RES1_E:      debug_opcode(z80, (char *)"RES1_E", (char *)"Reset bit 1 of E");
            M_RES_L(z80, 1, z80->registers.DE); break;
        case RES1_H:      debug_opcode(z80, (char *)"RES1_H", (char *)"Reset bit 1 of H");
            M_RES_H(z80, 1, z80->registers.HL); break;
        case RES1_L:      debug_opcode(z80, (char *)"RES1_L", (char *)"Reset bit 1 of L");
            M_RES_L(z80, 1, z80->registers.HL); break;
        case RES1_xHL:      debug_opcode(z80, (char *)"RES1_xHL", (char *)"Reset bit 1 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 1, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES2_A:      debug_opcode(z80, (char *)"RES2_A", (char *)"Reset bit 2 of A");
            M_RES_H(z80, 2, z80->registers.AF); break;
        case RES2_B:      debug_opcode(z80, (char *)"RES2_B", (char *)"Reset bit 2 of B");
            M_RES_H(z80, 2, z80->registers.BC); break;
        case RES2_C:      debug_opcode(z80, (char *)"RES2_C", (char *)"Reset bit 2 of C");
            M_RES_L(z80, 2, z80->registers.BC); break;
        case RES2_D:      debug_opcode(z80, (char *)"RES2_D", (char *)"Reset bit 2 of D");
            M_RES_H(z80, 2, z80->registers.DE); break;
        case RES2_E:      debug_opcode(z80, (char *)"RES2_E", (char *)"Reset bit 2 of E");
            M_RES_L(z80, 2, z80->registers.DE); break;
        case RES2_H:      debug_opcode(z80, (char *)"RES2_H", (char *)"Reset bit 2 of H");
            M_RES_H(z80, 2, z80->registers.HL); break;
        case RES2_L:      debug_opcode(z80, (char *)"RES2_L", (char *)"Reset bit 2 of L");
            M_RES_L(z80, 2, z80->registers.HL); break;
        case RES2_xHL:      debug_opcode(z80, (char *)"RES2_xHL", (char *)"Reset bit 2 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 2, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES3_A:      debug_opcode(z80, (char *)"RES3_A", (char *)"Reset bit 3 of A");
            M_RES_H(z80, 3, z80->registers.AF); break;
        case RES3_B:      debug_opcode(z80, (char *)"RES3_B", (char *)"Reset bit 3 of B");
            M_RES_H(z80, 3, z80->registers.BC); break;
        case RES3_C:      debug_opcode(z80, (char *)"RES3_C", (char *)"Reset bit 3 of C");
            M_RES_L(z80, 3, z80->registers.BC); break;
        case RES3_D:      debug_opcode(z80, (char *)"RES3_D", (char *)"Reset bit 3 of D");
            M_RES_H(z80, 3, z80->registers.DE); break;
        case RES3_E:      debug_opcode(z80, (char *)"RES3_E", (char *)"Reset bit 3 of E");
            M_RES_L(z80, 3, z80->registers.DE); break;
        case RES3_H:      debug_opcode(z80, (char *)"RES3_H", (char *)"Reset bit 3 of H");
            M_RES_H(z80, 3, z80->registers.HL); break;
        case RES3_L:      debug_opcode(z80, (char *)"RES3_L", (char *)"Reset bit 3 of L");
            M_RES_L(z80, 3, z80->registers.HL); break;
        case RES3_xHL:      debug_opcode(z80, (char *)"RES3_xHL", (char *)"Reset bit 3 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 3, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES4_A:      debug_opcode(z80, (char *)"RES4_A", (char *)"Reset bit 4 of A");
            M_RES_H(z80, 4, z80->registers.AF); break;
        case RES4_B:      debug_opcode(z80, (char *)"RES4_B", (char *)"Reset bit 4 of B");
            M_RES_H(z80, 4, z80->registers.BC); break;
        case RES4_C:      debug_opcode(z80, (char *)"RES4_C", (char *)"Reset bit 4 of C");
            M_RES_L(z80, 4, z80->registers.BC); break;
        case RES4_D:      debug_opcode(z80, (char *)"RES4_D", (char *)"Reset bit 4 of D");
            M_RES_H(z80, 4, z80->registers.DE); break;
        case RES4_E:      debug_opcode(z80, (char *)"RES4_E", (char *)"Reset bit 4 of E");
            M_RES_L(z80, 4, z80->registers.DE); break;
        case RES4_H:      debug_opcode(z80, (char *)"RES4_H", (char *)"Reset bit 4 of H");
            M_RES_H(z80, 4, z80->registers.HL); break;
        case RES4_L:      debug_opcode(z80, (char *)"RES4_L", (char *)"Reset bit 4 of L");
            M_RES_L(z80, 4, z80->registers.HL); break;
        case RES4_xHL:      debug_opcode(z80, (char *)"RES4_xHL", (char *)"Reset bit 4 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 4, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES5_A:      debug_opcode(z80, (char *)"RES5_A", (char *)"Reset bit 5 of A");
            M_RES_H(z80, 5, z80->registers.AF); break;
        case RES5_B:      debug_opcode(z80, (char *)"RES5_B", (char *)"Reset bit 5 of B");
            M_RES_H(z80, 5, z80->registers.BC); break;
        case RES5_C:      debug_opcode(z80, (char *)"RES5_C", (char *)"Reset bit 5 of C");
            M_RES_L(z80, 5, z80->registers.BC); break;
        case RES5_D:      debug_opcode(z80, (char *)"RES5_D", (char *)"Reset bit 5 of D");
            M_RES_H(z80, 5, z80->registers.DE); break;
        case RES5_E:      debug_opcode(z80, (char *)"RES5_E", (char *)"Reset bit 5 of E");
            M_RES_L(z80, 5, z80->registers.DE); break;
        case RES5_H:      debug_opcode(z80, (char *)"RES5_H", (char *)"Reset bit 5 of H");
            M_RES_H(z80, 5, z80->registers.HL); break;
        case RES5_L:      debug_opcode(z80, (char *)"RES5_L", (char *)"Reset bit 5 of L");
            M_RES_L(z80, 5, z80->registers.HL); break;
        case RES5_xHL:      debug_opcode(z80, (char *)"RES5_xHL", (char *)"Reset bit 5 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 5, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES6_A:      debug_opcode(z80, (char *)"RES6_A", (char *)"Reset bit 6 of A");
            M_RES_H(z80, 6, z80->registers.AF); break;
        case RES6_B:      debug_opcode(z80, (char *)"RES6_B", (char *)"Reset bit 6 of B");
            M_RES_H(z80, 6, z80->registers.BC); break;
        case RES6_C:      debug_opcode(z80, (char *)"RES6_C", (char *)"Reset bit 6 of C");
            M_RES_L(z80, 6, z80->registers.BC); break;
        case RES6_D:      debug_opcode(z80, (char *)"RES6_D", (char *)"Reset bit 6 of D");
            M_RES_H(z80, 6, z80->registers.DE); break;
        case RES6_E:      debug_opcode(z80, (char *)"RES6_E", (char *)"Reset bit 6 of E");
            M_RES_L(z80, 6, z80->registers.DE); break;
        case RES6_H:      debug_opcode(z80, (char *)"RES6_H", (char *)"Reset bit 6 of H");
            M_RES_H(z80, 6, z80->registers.HL); break;
        case RES6_L:      debug_opcode(z80, (char *)"RES6_L", (char *)"Reset bit 6 of L");
            M_RES_L(z80, 6, z80->registers.HL); break;
        case RES6_xHL:      debug_opcode(z80, (char *)"RES6_xHL", (char *)"Reset bit 6 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 6, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
        case RES7_A:      debug_opcode(z80, (char *)"RES7_A", (char *)"Reset bit 7 of A");
            M_RES_H(z80, 7, z80->registers.AF); break;
        case RES7_B:      debug_opcode(z80, (char *)"RES7_B", (char *)"Reset bit 7 of B");
            M_RES_H(z80, 7, z80->registers.BC); break;
        case RES7_C:      debug_opcode(z80, (char *)"RES7_C", (char *)"Reset bit 7 of C");
            M_RES_L(z80, 7, z80->registers.BC); break;
        case RES7_D:      debug_opcode(z80, (char *)"RES7_D", (char *)"Reset bit 7 of D");
            M_RES_H(z80, 7, z80->registers.DE); break;
        case RES7_E:      debug_opcode(z80, (char *)"RES7_E", (char *)"Reset bit 7 of E");
            M_RES_L(z80, 7, z80->registers.DE); break;
        case RES7_H:      debug_opcode(z80, (char *)"RES7_H", (char *)"Reset bit 7 of H");
            M_RES_H(z80, 7, z80->registers.HL); break;
        case RES7_L:      debug_opcode(z80, (char *)"RES7_L", (char *)"Reset bit 7 of L");
            M_RES_L(z80, 7, z80->registers.HL); break;
        case RES7_xHL:      debug_opcode(z80, (char *)"RES7_xHL", (char *)"Reset bit 7 of (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_RES(z80, 7, I); WrZ80(z80cpm_memory, z80->registers.HL, I); break; 
        
	

        default:{
            char str2[20];
            sprintf(str2,"unknown 0x%x",opcode);
            debug_opcode(z80, str2, (char*)"");
             if(z80->TrapBadOps)
            printf
            (
                "[Z80 %lX] Unrecognized instruction: CB %02X at PC=%04X\n",
                (long)z80->User,OpZ80(z80, z80cpm_memory, z80->registers.PC-1),z80->registers.PC-2
            );
        }
    }
}
