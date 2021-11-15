static const unsigned char CyclesED[256] =
{
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  12,12,15,20, 8,14, 8, 9,12,12,15,20, 0,14, 0, 9,
  12,12,15,20, 0, 0, 8, 9,12,12,15,20, 0, 0, 8, 9,
  12,12,15,20, 0, 0, 0,18,12,12,15,20, 0, 0, 0,18,
  12, 0,15,20, 0, 0, 0, 0,12,12,15,20, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  16,16,16,16, 0, 0, 0, 0,16,16,16,16, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

#define M_IN(cpu, Rg)        \
  Rg = this->InZ80( cpu->registers.BC);  \
  SET_LSB(cpu->registers.AF, PZSTable[Rg] | (LSB(cpu->registers.AF) & C_FLAG))

  #define M_IN_H(cpu, Rg)        \
  SET_MSB(Rg, this->InZ80( cpu->registers.BC));  \
  SET_LSB(cpu->registers.AF, PZSTable[MSB(Rg)] | (LSB(cpu->registers.AF) & C_FLAG))
  
  #define M_IN_L(cpu, Rg)        \
  SET_LSB(Rg, this->InZ80( cpu->registers.BC));  \
  SET_LSB(cpu->registers.AF, PZSTable[LSB(Rg)] | (LSB(cpu->registers.AF) & C_FLAG))



void Z80::z80_exec_extended_ED(struct z80cpm_memory* z80cpm_memory)
{
    unsigned char I; //register
    unsigned short J; //register

    I = this->OpZ80(z80cpm_memory, this->registers.PC);
    unsigned char opcode = I;
    this->ICount -= CyclesED[I];

    switch(I)
    {
        //#include "CodesED.h"
        case IN_A_xC:      this->debug_opcode((char *)"IN_A_xC", (char *)"A byte from port C is written to A");
            M_IN_H(this, this->registers.AF);break;
        case IN_B_xC:      this->debug_opcode((char *)"IN_B_xC", (char *)"A byte from port C is written to B");
            M_IN_H(this, this->registers.BC);break;
        case IN_C_xC:      this->debug_opcode((char *)"IN_C_xC", (char *)"A byte from port C is written to C");
            M_IN_L(this, this->registers.BC);break;
        case IN_D_xC:      this->debug_opcode((char *)"IN_D_xC", (char *)"A byte from port C is written to D");
            M_IN_H(this, this->registers.DE);break;
        case IN_E_xC:      this->debug_opcode((char *)"IN_E_xC", (char *)"A byte from port C is written to E");
            M_IN_L(this, this->registers.DE);break;
        case IN_H_xC:      this->debug_opcode((char *)"IN_H_xC", (char *)"A byte from port C is written to H");
            M_IN_H(this, this->registers.HL);break;
        case IN_L_xC:      this->debug_opcode((char *)"IN_L_xC", (char *)"A byte from port C is written to L");
            M_IN_L(this, this->registers.HL);break;
        case IN_F_xC:      this->debug_opcode((char *)"IN_F_xC", (char *)"A byte from port C is and affects flags only");
            M_IN_L(this, J);break;

        case INI:      this->debug_opcode((char *)"INI", (char *)"A byte from port C is written to the memory pointed by HL. Then HL is incremented and B is decremented.");
            this->WrZ80(z80cpm_memory, this->registers.HL, this->InZ80(this->registers.BC));
            this->registers.HL += 1;
            SET_MSB(this->registers.BC, MSB(this->registers.BC)-1);
            SET_LSB(this->registers.AF, N_FLAG | (MSB(this->registers.BC) ? 0: Z_FLAG));
            break;

        case INIR:      this->debug_opcode((char *)"INIR", (char *)"A byte from port C is written to the memory pointed by HL. Then HL is incremented and B is decremented. If B is not zero, this operation is repeated. Interrupts can trigger while this instruction is processing.");
            do
            {
                this->WrZ80(z80cpm_memory, this->registers.HL, this->InZ80(this->registers.BC));
                this->registers.HL += 1;
                SET_MSB(this->registers.BC, MSB(this->registers.BC)-1);
                this->ICount -= 21;
            }
            while(MSB(this->registers.BC) != 0x0);//while(MSB(this->registers.BC) && (this->ICount > 0));
            
            if(MSB(this->registers.BC)) {
                SET_LSB(this->registers.AF, N_FLAG);
                // ???  this->registers.PC -= 2; 
            }
            else {
                SET_LSB(this->registers.AF, Z_FLAG | N_FLAG);
                this->ICount += 5; 
            }
            break;

        case IND:      this->debug_opcode((char *)"INI", (char *)"A byte from port C is written to the memory pointed by HL. Then HL and B are decremented.");
			this->WrZ80(z80cpm_memory, this->registers.HL, this->InZ80(this->registers.BC));
            this->registers.HL -= 1;
            SET_MSB(this->registers.BC, MSB(this->registers.BC)-1);
            SET_LSB(this->registers.AF, N_FLAG | (MSB(this->registers.BC) ? 0: Z_FLAG));

            break;

        case INDR:      this->debug_opcode((char *)"INDR", (char *)"A byte from port C is written to the memory pointed by HL. Then HL and B are decremented. If B is not zero, this operation is repeated. Interrupts can trigger while this instruction is processing.");
            do
            {
				this->WrZ80(z80cpm_memory, this->registers.HL, this->InZ80(this->registers.BC));
                this->registers.HL -= 1;
                SET_MSB(this->registers.BC, MSB(this->registers.BC)-1);
                this->ICount -= 21;
            }
            while(MSB(this->registers.BC) != 0x0);//while(MSB(this->registers.BC) && (this->ICount > 0));
            
            if(MSB(this->registers.BC)) {
                SET_LSB(this->registers.AF, N_FLAG);
                // ???  this->registers.PC -= 2; 
            }
            else {
                SET_LSB(this->registers.AF, Z_FLAG | N_FLAG);
                this->ICount += 5; 
            }
            break;


        case OUT_xC_A:      this->debug_opcode((char *)"OUT_xC_A", (char *)"The value of A is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, MSB(this->registers.AF));break;
        case OUT_xC_B:      this->debug_opcode((char *)"OUT_xC_B", (char *)"The value of B is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, MSB(this->registers.BC));break;
        case OUT_xC_C:      this->debug_opcode((char *)"OUT_xC_C", (char *)"The value of C is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, LSB(this->registers.BC));break;
        case OUT_xC_D:      this->debug_opcode((char *)"OUT_xC_D", (char *)"The value of D is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, MSB(this->registers.DE));break;
        case OUT_xC_E:      this->debug_opcode((char *)"OUT_xC_E", (char *)"The value of E is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, LSB(this->registers.DE));break;
        case OUT_xC_H:      this->debug_opcode((char *)"OUT_xC_H", (char *)"The value of H is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, MSB(this->registers.HL));break;
        case OUT_xC_L:      this->debug_opcode((char *)"OUT_xC_L", (char *)"The value of L is written to port C");
            this->OutZ80(z80cpm_memory, this->registers.BC, LSB(this->registers.HL));break;

        case OUTI:      this->debug_opcode((char *)"OUTI", (char *)"A byte from the memory location pointed to by HL is written to port C. Then HL is incremented and B is decremented.");
            SET_MSB(this->registers.BC, this->registers.BC - 1);
            I = this->RdZ80(z80cpm_memory, this->registers.HL);
            this->registers.HL += 1;
            this->OutZ80(z80cpm_memory, this->registers.BC, I);
            SET_LSB(this->registers.AF, N_FLAG | (MSB(this->registers.BC) ? 0: Z_FLAG) | (LSB(this->registers.HL) + I > 255 ? (C_FLAG | H_FLAG) : 0));
            break;

        case OUTD:      this->debug_opcode((char *)"OUTD", (char *)"A byte from the memory location pointed to by HL is written to port C. Then HL and B are decremented.");
            SET_MSB(this->registers.BC, this->registers.BC - 1);
            I = this->RdZ80(z80cpm_memory, this->registers.HL);
            this->registers.HL -= 1;
            this->OutZ80(z80cpm_memory, this->registers.BC, I);
            SET_LSB(this->registers.AF, N_FLAG | (MSB(this->registers.BC) ? 0: Z_FLAG) | (LSB(this->registers.HL) + I > 255 ? (C_FLAG | H_FLAG) : 0));
            break;
        
        case OTIR:      this->debug_opcode((char *)"OTIR", (char *)"A byte from the memory location pointed to by HL is written to port C. Then HL is incremented and B is decremented. If b is not zero, this operation is repeated. Interrupts can trigger while this instruction is processing.");
            do
            {
                SET_MSB(this->registers.BC, this->registers.BC - 1);
                I = this->RdZ80(z80cpm_memory, this->registers.HL);
                this->registers.HL += 1;
                this->OutZ80(z80cpm_memory, this->registers.BC, I);
                this->ICount -= 21;
            }
            while(MSB(this->registers.BC) != 0x0);//while(MSB(this->registers.BC) && (this->ICount > 0));

            if(MSB(this->registers.BC))
            {
                SET_LSB(this->registers.AF, N_FLAG | (LSB(this->registers.HL) + I > 255 ? (C_FLAG | H_FLAG) : 0));
                // ???  this->registers.PC -= 2;
            }
            else
            {
                SET_LSB(this->registers.AF, Z_FLAG | N_FLAG | (LSB(this->registers.HL) + I > 255 ? (C_FLAG | H_FLAG) : 0));
                this->ICount += 5;
            }
            break;

        case OTDR:      this->debug_opcode((char *)"OTDR", (char *)"A byte from the memory location pointed to by HL is written to port C. Then HL and B are decremented. If b is not zero, this operation is repeated. Interrupts can trigger while this instruction is processing.");
            do
            {
                SET_MSB(this->registers.BC, this->registers.BC - 1);
                I = this->RdZ80(z80cpm_memory, this->registers.HL);
                this->registers.HL -= 1;
                this->OutZ80(z80cpm_memory, this->registers.BC, I);
                this->ICount -= 21;
            }
            while(MSB(this->registers.BC) != 0x0);//while(MSB(this->registers.BC) && (this->ICount > 0));

            if(MSB(this->registers.BC))
            {
                SET_LSB(this->registers.AF, N_FLAG | (LSB(this->registers.HL) + I > 255 ? (C_FLAG | H_FLAG) : 0));
                // ???  this->registers.PC -= 2;
            }
            else
            {
                SET_LSB(this->registers.AF, Z_FLAG | N_FLAG | (LSB(this->registers.HL) + I > 255 ? (C_FLAG | H_FLAG) : 0));
                this->ICount += 5;
            }
            break;

        case NEG:      this->debug_opcode((char *)"NEG", (char *)"The contents of A are negated (two's complement). Operation is the same as subtracting A from zero.");
            I = MSB(this->registers.AF);
            SET_MSB(this->registers.AF, 0);
            M_SUB(this, I);
            break;

        case SBC_HL_BC:      this->debug_opcode((char *)"SBC_HL_BC", (char *)"Subtracts BC and carry flag from HL."); 
            M_SBCW(this, BC);break;
        case SBC_HL_DE:      this->debug_opcode((char *)"SBC_HL_DE", (char *)"Subtracts DE and carry flag from HL."); 
            M_SBCW(this, DE);break;
        case SBC_HL_HL:      this->debug_opcode((char *)"SBC_HL_HL", (char *)"Subtracts HL and carry flag from HL."); 
            M_SBCW(this, HL);break;
        case SBC_HL_SP:      this->debug_opcode((char *)"SBC_HL_SP", (char *)"Subtracts SP and carry flag from HL."); 
            M_SBCW(this, SP);break;

        case LD_A_I:      this->debug_opcode((char *)"LD_A_I", (char *)"Stores the value of register I or R into A"); 
            SET_MSB(this->registers.AF, this->registers.I);
            SET_LSB(this->registers.AF, (LSB(this->registers.AF) & C_FLAG) | (this->registers.IFF & IFF_2 ? P_FLAG : 0) | ZSTable[MSB(this->registers.AF)]);
        break;

        case LD_A_R:      this->debug_opcode((char *)"LD_A_R", (char *)"Stores the value of register I or R into A"); 
            
            //this->registers.R++;
            SET_MSB(this->registers.AF, this->registers.R);
            //SET_MSB(this->registers.AF, (unsigned char)(this->registers.R - this->ICount));
            SET_LSB(this->registers.AF, (LSB(this->registers.AF) & C_FLAG) | (this->registers.IFF & IFF_2 ? P_FLAG : 0) | ZSTable[MSB(this->registers.AF)]);
        break;

        case LD_I_A:      this->debug_opcode((char *)"LD_I_A", (char *)"Stores the value of A into register I or R"); 
            this->registers.I = MSB(this->registers.AF);
            break;
        case LD_R_A:      this->debug_opcode((char *)"LD_R_A", (char *)"Stores the value of A into register I or R"); 
            this->registers.R = MSB(this->registers.AF);
            break;


        case LD_BC_xWORDe:      this->debug_opcode((char *)"LD_BC_xWORDe", (char *)"Loads the value pointed to by WORD into BC."); 
            M_LDWORD(this, z80cpm_memory, J); 
            SET_LSB(this->registers.BC, RdZ80(z80cpm_memory, J));
            J += 1;
            SET_MSB(this->registers.BC, RdZ80(z80cpm_memory, J));
            break;
        case LD_DE_xWORDe:      this->debug_opcode((char *)"LD_DE_xWORDe", (char *)"Loads the value pointed to by WORD into DE."); 
            M_LDWORD(this, z80cpm_memory, J); 
            SET_LSB(this->registers.DE, RdZ80(z80cpm_memory, J));
            J += 1;
            SET_MSB(this->registers.DE, RdZ80(z80cpm_memory, J));
            break;
        case LD_HL_xWORDe:      this->debug_opcode((char *)"LD_HL_xWORDe", (char *)"Loads the value pointed to by WORD into HL."); 
            M_LDWORD(this, z80cpm_memory, J); 
            SET_LSB(this->registers.HL, RdZ80(z80cpm_memory, J));
            J += 1;
            SET_MSB(this->registers.HL, RdZ80(z80cpm_memory, J));
            break;
        case LD_SP_xWORDe:      this->debug_opcode((char *)"LD_SP_xWORDe", (char *)"Loads the value pointed to by WORD into SP."); 
            M_LDWORD(this, z80cpm_memory, J); 
            SET_LSB(this->registers.SP, RdZ80(z80cpm_memory, J));
            J += 1;
            SET_MSB(this->registers.SP, RdZ80(z80cpm_memory, J));
            break;


        case LD_xWORDe_BC:      this->debug_opcode((char *)"LD_xWORDe_BC", (char *)"Stores BC into the memory location pointed to by WORD."); 
            M_LDWORD(this, z80cpm_memory, J); 
            WrZ80(z80cpm_memory, J, LSB(this->registers.BC));
            J += 1;
            WrZ80(z80cpm_memory, J, MSB(this->registers.BC));
            break;
        case LD_xWORDe_DE:      this->debug_opcode((char *)"LD_xWORDe_DE", (char *)"Stores DE into the memory location pointed to by WORD."); 
            M_LDWORD(this, z80cpm_memory, J); 
            WrZ80(z80cpm_memory, J, LSB(this->registers.DE));
            J += 1;
            WrZ80(z80cpm_memory, J, MSB(this->registers.DE));
            break;
        case LD_xWORDe_HL:      this->debug_opcode((char *)"LD_xWORDe_HL", (char *)"Stores HL into the memory location pointed to by WORD."); 
            M_LDWORD(this, z80cpm_memory, J); 
            WrZ80(z80cpm_memory, J, LSB(this->registers.HL));
            J += 1;
            WrZ80(z80cpm_memory, J, MSB(this->registers.HL));
            break;
        case LD_xWORDe_SP:      this->debug_opcode((char *)"LD_xWORDe_SP", (char *)"Stores SP into the memory location pointed to by WORD."); 
            M_LDWORD(this, z80cpm_memory, J); 
            WrZ80(z80cpm_memory, J, LSB(this->registers.SP));
            J += 1;
            WrZ80(z80cpm_memory, J, MSB(this->registers.SP));
            break;


        case LDI:      this->debug_opcode((char *)"LDI", (char *)"Transfers a byte of data from the memory location pointed to by HL to the memory location pointed to by DE. Then HL and DE are incremented and BC is decremented."); 
            WrZ80(z80cpm_memory, this->registers.DE, RdZ80(z80cpm_memory, this->registers.HL));
            this->registers.DE += 1;
            this->registers.HL += 1;
            this->registers.BC -= 1;
            SET_LSB(this->registers.AF, (LSB(this->registers.AF) & ~(N_FLAG | H_FLAG | P_FLAG)) | (this->registers.BC ? P_FLAG:0));
            break;

        case LDD:      this->debug_opcode((char *)"LDD", (char *)"Transfers a byte of data from the memory location pointed to by HL to the memory location pointed to by DE. Then HL, DE and BC are decremented."); 
            WrZ80(z80cpm_memory, this->registers.DE, RdZ80(z80cpm_memory, this->registers.HL));
            this->registers.DE -= 1;
            this->registers.HL -= 1;
            this->registers.BC -= 1;
            SET_LSB(this->registers.AF, (LSB(this->registers.AF) & ~(N_FLAG | H_FLAG | P_FLAG)) | (this->registers.BC ? P_FLAG:0));
        break;

        case LDIR:      this->debug_opcode((char *)"LDIR", (char *)"Transfers a byte of data from the memory location pointed to by HL to the memory location pointed to by DE. Then HL and DE are incremented and BC is decremented. If BC is not zero, this operation is repeated. Interrupts can trigger while this instruction is processing."); 
            do
            {
                WrZ80(z80cpm_memory, this->registers.DE, RdZ80(z80cpm_memory, this->registers.HL));
                this->registers.DE += 1;
                this->registers.HL += 1;
                this->registers.BC -= 1;
                this->ICount -= 21;
            }
            while(this->registers.BC != 0x0);//while(this->registers.BC && (this->ICount > 0));

            SET_LSB(this->registers.AF, LSB(this->registers.AF) & ~(N_FLAG | H_FLAG | P_FLAG));
            if(this->registers.BC) 
            { 
                SET_LSB(this->registers.AF, LSB(this->registers.AF) | N_FLAG);
                this->registers.PC -= 2; 
            }
            else 
                this->ICount += 5;
            break;

        case LDDR:      this->debug_opcode((char *)"LDDR", (char *)"Transfers a byte of data from the memory location pointed to by HL to the memory location pointed to by DE. Then HL, DE and BC are decremented. If BC is not zero, this operation is repeated. Interrupts can trigger while this instruction is processing."); 
            do
            {
                WrZ80(z80cpm_memory, this->registers.DE, RdZ80(z80cpm_memory, this->registers.HL));
                this->registers.DE -= 1;
                this->registers.HL -= 1;
                this->registers.BC -= 1;
                this->ICount -= 21;
            }
            while(this->registers.BC != 0x0);//while(this->registers.BC && (this->ICount > 0));

            SET_LSB(this->registers.AF, LSB(this->registers.AF) & ~(N_FLAG | H_FLAG | P_FLAG));
            if(this->registers.BC) 
            { 
                SET_LSB(this->registers.AF, LSB(this->registers.AF) | N_FLAG);
                this->registers.PC -= 2; 
            }
            else 
                this->ICount += 5;
            break;


        case RLD:      this->debug_opcode((char *)"RLD", (char *)"The contents of the low-order nibble of (HL) are copied to the high-order nibble of (HL). The previous contents are copied to the low-order nibble of A. The previous contents are copied to the low-order nibble of (HL)."); 
            I = this->RdZ80(z80cpm_memory, this->registers.HL);
            SET_LSB(J, (I << 4) | (MSB(this->registers.AF) & 0x0F));
            WrZ80(z80cpm_memory, this->registers.HL, LSB(J));
            SET_MSB(this->registers.AF, (I >> 4) | (MSB(this->registers.AF) & 0xF0));
            SET_LSB(this->registers.AF, PZSTable[MSB(this->registers.AF)] | (LSB(this->registers.AF) & C_FLAG));
            break;
        
        case RRD:      this->debug_opcode((char *)"RRD", (char *)"The contents of the low-order nibble of (HL) are copied to the low-order nibble of A. The previous contents are copied to the high-order nibble of (HL). The previous contents are copied to the low-order nibble of (HL)."); 
            I = this->RdZ80(z80cpm_memory, this->registers.HL);
            SET_LSB(J, (I >> 4) | (MSB(this->registers.AF) << 4));
            WrZ80(z80cpm_memory, this->registers.HL, LSB(J));
            SET_MSB(this->registers.AF, (I & 0x0F) | (MSB(this->registers.AF) & 0xF0));
            SET_LSB(this->registers.AF, PZSTable[MSB(this->registers.AF)] | (LSB(this->registers.AF) & C_FLAG));
        break;


        case ADC_HL_BC:      this->debug_opcode((char *)"ADC_HL_BC", (char *)"Adds BC and the carry flag to HL"); 
            M_ADCW(this, BC);break;
        case ADC_HL_DE:      this->debug_opcode((char *)"ADC_HL_DE", (char *)"Adds DE and the carry flag to HL"); 
            M_ADCW(this, DE);break;
        case ADC_HL_HL:      this->debug_opcode((char *)"ADC_HL_HL", (char *)"Adds HL and the carry flag to HL"); 
            M_ADCW(this, HL);break;
        case ADC_HL_SP:      this->debug_opcode((char *)"ADC_HL_SP", (char *)"Adds SP and the carry flag to HL"); 
            M_ADCW(this, SP);break;


        case IM_0:      this->debug_opcode((char *)"IM_0", (char *)"Set interrupt of mode 0."); 
            this->registers.IFF &= ~(IFF_IM1 | IFF_IM2);
            break;
        case IM_1:      this->debug_opcode((char *)"IM_1", (char *)"Set interrupt of mode 1."); 
            this->registers.IFF = (this->registers.IFF & ~IFF_IM2) | IFF_IM1;
            break;
        case IM_2:      this->debug_opcode((char *)"IM_2", (char *)"Set interrupt of mode 2."); 
            this->registers.IFF = (this->registers.IFF & ~IFF_IM1) | IFF_IM2;
            break;

        case RETI:      this->debug_opcode((char *)"RETI", (char *)"used at the end of a maskable interrupt service routine. The top stack entry is popped into PC, and signals an I/O device that the interrupt has finished, allowing nested interrupts (not a consideration of the TI).");
        case RETN:      this->debug_opcode((char *)"RETN", (char *)"Used at the end of a non-maskable interrupt service routine (located at $0066) to pop stack entry into PC. The value of IFF2 is copied to IFF1 so that maskable interrupts are allowed to continue as before. NMIs are not enabled on the TI."); 
            if(this->registers.IFF & IFF_2)
                this->registers.IFF |= IFF_1;
            else
                this->registers.IFF &= ~IFF_1;
            M_RET(this, z80cpm_memory);
        break;


        case CPI:      this->debug_opcode((char *)"CPI", (char *)"Compares the value of the memory location pointed to by HL with A. Then HL is incremented and BC is decremented.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL);
            this->registers.HL += 1;
            SET_LSB(J, MSB(this->registers.AF) - I);
            this->registers.BC = this->registers.BC - 1;
            SET_LSB(this->registers.AF, 
                N_FLAG | (LSB(this->registers.AF) & C_FLAG) | ZSTable[LSB(J)] |
                ((MSB(this->registers.AF) ^ I ^ LSB(J)) & H_FLAG) | (this->registers.BC ? P_FLAG : 0));
            break;

        case CPD:      this->debug_opcode((char *)"CPD", (char *)"Compares the value of the memory location pointed to by HL with A. Then HL is decremented and BC is decremented.");
            I = this->RdZ80(z80cpm_memory, this->registers.HL);
            SET_LSB(J, MSB(this->registers.AF) - I);
            SET_LSB(this->registers.AF, 
                N_FLAG | (LSB(this->registers.AF) & C_FLAG) | ZSTable[LSB(J)] |
                ((MSB(this->registers.AF) ^ I ^ LSB(J)) & H_FLAG) | (this->registers.BC ? P_FLAG : 0));
            this->registers.HL -= 1;
            this->registers.BC = this->registers.BC - 1;
        break;

        case CPIR:      this->debug_opcode((char *)"CPIR", (char *)"Compares the value of the memory location pointed to by HL with A. Then HL is incremented and BC is decremented. If BC is not zero and Z is not set, this operation is repeated. Interrupts can trigger while this instruction is processing.");
            do
            {
                I = this->RdZ80(z80cpm_memory, this->registers.HL);
                SET_LSB(J, MSB(this->registers.AF) - I);
                SET_LSB(this->registers.AF, 
                                N_FLAG | (LSB(this->registers.AF) & C_FLAG) | ZSTable[LSB(J)] |
                                ((MSB(this->registers.AF) ^ I ^ LSB(J)) & H_FLAG) | (this->registers.BC ? P_FLAG : 0));
                
                this->registers.HL += 1;
                this->registers.BC = this->registers.BC - 1;
                this->ICount -= 21;
            }  
            while(this->registers.BC != 0x0 && (LSB(this->registers.AF) & Z_FLAG) == 0);//&& LSB(J) && (this->ICount > 0)); //while(this->registers.BC && LSB(J));

          /*
            
            if(this->registers.BC && LSB(J))
                this->registers.PC -= 2;
            else
                this->ICount += 5;
                */
            break; 
        
        case CPDR:      this->debug_opcode((char *)"CPDR", (char *)"Compares the value of the memory location pointed to by HL with A. Then HL and BC are decremented. If BC is not zero and Z is not set, this operation is repeated. Interrupts can trigger while this instruction is processing.");
            do
            {
                I = this->RdZ80(z80cpm_memory, this->registers.HL);                
                SET_LSB(J, MSB(this->registers.AF) - I);
                SET_LSB(this->registers.AF, 
                        N_FLAG | (LSB(this->registers.AF) & C_FLAG) | ZSTable[LSB(J)] |
                        ((MSB(this->registers.AF) ^ I ^ LSB(J)) & H_FLAG) | (this->registers.BC ? P_FLAG : 0));
                
                this->registers.HL -= 1;     
                this->registers.BC = this->registers.BC - 1;
                this->ICount -= 21;
            }
            while(this->registers.BC != 0x0 && (LSB(this->registers.AF) & Z_FLAG) == 0);//&& LSB(J) && (this->ICount > 0)); //while(this->registers.BC && LSB(J));

            
            
            if(this->registers.BC && LSB(J))
                this->registers.PC -= 2;
            else
                this->ICount += 5;
            break; 


        default:{
            char str2[20];
            sprintf(str2,"unknown 0x%x",opcode);
            this->debug_opcode(str2, (char*)"");
             if(this->TrapBadOps)
            printf
            (
                "[Z80 %lX] Unrecognized instruction: ED %02X at PC=%04X\n",
                (long)this->User, this->OpZ80(z80cpm_memory, this->registers.PC-1),this->registers.PC-2
            );
        }

    }
}