


void Z80::z80_exec_main_code(unsigned char opcode, struct z80cpm_memory* z80cpm_memory) {

	unsigned char I; //register
	unsigned short J; //register

	switch (opcode)
	{


	case NOP:           this->debug_opcode((char *)"NOP", (char *)"No operation is performed"); break;

		// LD

	case LD_A_A:        this->debug_opcode((char *)"LD_A_A", (char *)"The content of A is loaded into A");
		SET_MSB(this->registers.AF, MSB(this->registers.AF)); break;
	case LD_A_B:        this->debug_opcode((char *)"LD_A_B", (char *)"The content of B is loaded into A");
		SET_MSB(this->registers.AF, MSB(this->registers.BC)); break;
	case LD_A_C:        this->debug_opcode((char *)"LD_A_C", (char *)"The content of C is loaded into A");
		SET_MSB(this->registers.AF, LSB(this->registers.BC)); break;
	case LD_A_D:        this->debug_opcode((char *)"LD_A_D", (char *)"The content of D is loaded into A");
		SET_MSB(this->registers.AF, MSB(this->registers.DE)); break;
	case LD_A_E:        this->debug_opcode((char *)"LD_A_E", (char *)"The content of E is loaded into A");
		SET_MSB(this->registers.AF, LSB(this->registers.DE)); break;
	case LD_A_H:        this->debug_opcode((char *)"LD_A_H", (char *)"The content of H is loaded into A");
		SET_MSB(this->registers.AF, MSB(this->registers.HL)); break;
	case LD_A_L:        this->debug_opcode((char *)"LD_A_L", (char *)"The content of L is loaded into A");
		SET_MSB(this->registers.AF, LSB(this->registers.HL)); break;

		// 8

	case LD_B_A:        this->debug_opcode((char *)"LD_B_A", (char *)"The content of A is loaded into B");
		SET_MSB(this->registers.BC, MSB(this->registers.AF)); break;
	case LD_B_B:        this->debug_opcode((char *)"LD_B_B", (char *)"The content of B is loaded into B");
		SET_MSB(this->registers.BC, MSB(this->registers.BC)); break;
	case LD_B_C:        this->debug_opcode((char *)"LD_B_C", (char *)"The content of C is loaded into B");
		SET_MSB(this->registers.BC, LSB(this->registers.BC)); break;
	case LD_B_D:        this->debug_opcode((char *)"LD_B_D", (char *)"The content of D is loaded into B");
		SET_MSB(this->registers.BC, MSB(this->registers.DE)); break;
	case LD_B_E:        this->debug_opcode((char *)"LD_B_E", (char *)"The content of E is loaded into B");
		SET_MSB(this->registers.BC, LSB(this->registers.DE)); break;
	case LD_B_H:        this->debug_opcode((char *)"LD_B_H", (char *)"The content of H is loaded into B");
		SET_MSB(this->registers.BC, MSB(this->registers.HL)); break;
	case LD_B_L:        this->debug_opcode((char *)"LD_B_L", (char *)"The content of L is loaded into B");
		SET_MSB(this->registers.BC, LSB(this->registers.HL)); break;

		//15

	case LD_C_A:        this->debug_opcode((char *)"LD_C_A", (char *)"The content of A is loaded into C");
		SET_LSB(this->registers.BC, MSB(this->registers.AF)); break;
	case LD_C_B:        this->debug_opcode((char *)"LD_C_B", (char *)"The content of B is loaded into C");
		SET_LSB(this->registers.BC, MSB(this->registers.BC)); break;
	case LD_C_C:        this->debug_opcode((char *)"LD_C_C", (char *)"The content of C is loaded into C");
		SET_LSB(this->registers.BC, LSB(this->registers.BC)); break;
	case LD_C_D:        this->debug_opcode((char *)"LD_C_D", (char *)"The content of D is loaded into C");
		SET_LSB(this->registers.BC, MSB(this->registers.DE)); break;
	case LD_C_E:        this->debug_opcode((char *)"LD_C_E", (char *)"The content of E is loaded into C");
		SET_LSB(this->registers.BC, LSB(this->registers.DE)); break;
	case LD_C_H:        this->debug_opcode((char *)"LD_C_H", (char *)"The content of H is loaded into C");
		SET_LSB(this->registers.BC, MSB(this->registers.HL)); break;
	case LD_C_L:        this->debug_opcode((char *)"LD_C_L", (char *)"The content of L is loaded into C");
		SET_LSB(this->registers.BC, LSB(this->registers.HL)); break;

		//22

	case LD_D_A:        this->debug_opcode((char *)"LD_D_A", (char *)"The content of A is loaded into D");
		SET_MSB(this->registers.DE, MSB(this->registers.AF)); break;
	case LD_D_B:        this->debug_opcode((char *)"LD_D_B", (char *)"The content of B is loaded into D");
		SET_MSB(this->registers.DE, MSB(this->registers.BC)); break;
	case LD_D_C:        this->debug_opcode((char *)"LD_D_C", (char *)"The content of C is loaded into D");
		SET_MSB(this->registers.DE, LSB(this->registers.BC)); break;
	case LD_D_D:        this->debug_opcode((char *)"LD_D_D", (char *)"The content of D is loaded into D");
		SET_MSB(this->registers.DE, MSB(this->registers.DE)); break;
	case LD_D_E:        this->debug_opcode((char *)"LD_D_E", (char *)"The content of E is loaded into D");
		SET_MSB(this->registers.DE, LSB(this->registers.DE)); break;
	case LD_D_H:        this->debug_opcode((char *)"LD_D_H", (char *)"The content of H is loaded into D");
		SET_MSB(this->registers.DE, MSB(this->registers.HL)); break;
	case LD_D_L:        this->debug_opcode((char *)"LD_D_L", (char *)"The content of L is loaded into D");
		SET_MSB(this->registers.DE, LSB(this->registers.HL)); break;

		//29

	case LD_E_A:        this->debug_opcode((char *)"LD_E_A", (char *)"The content of A is loaded into E");
		SET_LSB(this->registers.DE, MSB(this->registers.AF)); break;
	case LD_E_B:        this->debug_opcode((char *)"LD_E_B", (char *)"The content of B is loaded into E");
		SET_LSB(this->registers.DE, MSB(this->registers.BC)); break;
	case LD_E_C:        this->debug_opcode((char *)"LD_E_C", (char *)"The content of C is loaded into E");
		SET_LSB(this->registers.DE, LSB(this->registers.BC)); break;
	case LD_E_D:        this->debug_opcode((char *)"LD_E_D", (char *)"The content of D is loaded into E");
		SET_LSB(this->registers.DE, MSB(this->registers.DE)); break;
	case LD_E_E:        this->debug_opcode((char *)"LD_E_E", (char *)"The content of E is loaded into E");
		SET_LSB(this->registers.DE, LSB(this->registers.DE)); break;
	case LD_E_H:        this->debug_opcode((char *)"LD_E_H", (char *)"The content of H is loaded into E");
		SET_LSB(this->registers.DE, MSB(this->registers.HL)); break;
	case LD_E_L:        this->debug_opcode((char *)"LD_E_L", (char *)"The content of L is loaded into E");
		SET_LSB(this->registers.DE, LSB(this->registers.HL)); break;

		//36

	case LD_H_A:        this->debug_opcode((char *)"LD_H_A", (char *)"The content of A is loaded into H");
		SET_MSB(this->registers.HL, MSB(this->registers.AF)); break;
	case LD_H_B:        this->debug_opcode((char *)"LD_H_B", (char *)"The content of B is loaded into H");
		SET_MSB(this->registers.HL, MSB(this->registers.BC)); break;
	case LD_H_C:        this->debug_opcode((char *)"LD_H_C", (char *)"The content of C is loaded into H");
		SET_MSB(this->registers.HL, LSB(this->registers.BC)); break;
	case LD_H_D:        this->debug_opcode((char *)"LD_H_D", (char *)"The content of D is loaded into H");
		SET_MSB(this->registers.HL, MSB(this->registers.DE)); break;
	case LD_H_E:        this->debug_opcode((char *)"LD_H_E", (char *)"The content of E is loaded into H");
		SET_MSB(this->registers.HL, LSB(this->registers.DE)); break;
	case LD_H_H:        this->debug_opcode((char *)"LD_H_H", (char *)"The content of H is loaded into H");
		SET_MSB(this->registers.HL, MSB(this->registers.HL)); break;
	case LD_H_L:        this->debug_opcode((char *)"LD_H_L", (char *)"The content of L is loaded into H");
		SET_MSB(this->registers.HL, LSB(this->registers.HL)); break;

		//43

	case LD_L_A:        this->debug_opcode((char *)"LD_L_A", (char *)"The content of A is loaded into L");
		SET_LSB(this->registers.HL, MSB(this->registers.AF)); break;
	case LD_L_B:        this->debug_opcode((char *)"LD_L_B", (char *)"The content of B is loaded into L");
		SET_LSB(this->registers.HL, MSB(this->registers.BC)); break;
	case LD_L_C:        this->debug_opcode((char *)"LD_L_C", (char *)"The content of C is loaded into L");
		SET_LSB(this->registers.HL, LSB(this->registers.BC)); break;
	case LD_L_D:        this->debug_opcode((char *)"LD_L_D", (char *)"The content of D is loaded into L");
		SET_LSB(this->registers.HL, MSB(this->registers.DE)); break;
	case LD_L_E:        this->debug_opcode((char *)"LD_L_E", (char *)"The content of E is loaded into L");
		SET_LSB(this->registers.HL, LSB(this->registers.DE)); break;
	case LD_L_H:        this->debug_opcode((char *)"LD_L_H", (char *)"The content of H is loaded into L");
		SET_LSB(this->registers.HL, MSB(this->registers.HL)); break;
	case LD_L_L:        this->debug_opcode((char *)"LD_L_L", (char *)"The content of L is loaded into L");
		SET_LSB(this->registers.HL, LSB(this->registers.HL)); break;

		//50

	case LD_BC_WORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_BC_WORD", (char *)"Loads ** into BC");
		M_LDWORD(this, z80cpm_memory, this->registers.BC); break;
	case LD_DE_WORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_DE_WORD", (char *)"Loads ** into DE");
		M_LDWORD(this, z80cpm_memory, this->registers.DE); break;
	case LD_HL_WORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_HL_WORD", (char *)"Loads ** into HL");
		M_LDWORD(this, z80cpm_memory, this->registers.HL); break;
	case LD_SP_WORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_SP_WORD", (char *)"Loads ** into SP");
		M_LDWORD(this, z80cpm_memory, this->registers.SP); break;

	case LD_A_xBC:      this->debug_opcode((char *)"LD_A_xBC", (char *)"The contents of BC are loaded into A");
		SET_MSB(this->registers.AF, RdZ80(z80cpm_memory, this->registers.BC)); break;
	case LD_A_xDE:      this->debug_opcode((char *)"LD_A_xDE", (char *)"The contents of DE are loaded into A");
		SET_MSB(this->registers.AF, RdZ80(z80cpm_memory, this->registers.DE)); break;

	case LD_xBC_A:      this->debug_opcode((char *)"LD_xBC_A", (char *)"Stores A into the memory location pointed to by BC");
		WrZ80(z80cpm_memory, this->registers.BC, MSB(this->registers.AF)); break;
	case LD_xDE_A:      this->debug_opcode((char *)"LD_xDE_A", (char *)"Stores A into the memory location pointed to by DE");
		WrZ80(z80cpm_memory, this->registers.DE, MSB(this->registers.AF)); break;

	case LD_A_xHL:      this->debug_opcode((char *)"LD_A_xHL", (char *)"The contents of (HL) are loaded into A");
		SET_MSB(this->registers.AF, RdZ80(z80cpm_memory, this->registers.HL)); break;
	case LD_B_xHL:      this->debug_opcode((char *)"LD_B_xHL", (char *)"The contents of (HL) are loaded into B");
		SET_MSB(this->registers.BC, RdZ80(z80cpm_memory, this->registers.HL)); break;
	case LD_C_xHL:      this->debug_opcode((char *)"LD_C_xHL", (char *)"The contents of (HL) are loaded into C");
		SET_LSB(this->registers.BC, RdZ80(z80cpm_memory, this->registers.HL)); break;
	case LD_D_xHL:      this->debug_opcode((char *)"LD_D_xHL", (char *)"The contents of (HL) are loaded into D");
		SET_MSB(this->registers.DE, RdZ80(z80cpm_memory, this->registers.HL)); break;
	case LD_E_xHL:      this->debug_opcode((char *)"LD_E_xHL", (char *)"The contents of (HL) are loaded into E");
		SET_LSB(this->registers.DE, RdZ80(z80cpm_memory, this->registers.HL)); break;
	case LD_H_xHL:      this->debug_opcode((char *)"LD_H_xHL", (char *)"The contents of (HL) are loaded into H");
		SET_MSB(this->registers.HL, RdZ80(z80cpm_memory, this->registers.HL)); break;
	case LD_L_xHL:      this->debug_opcode((char *)"LD_L_xHL", (char *)"The contents of (HL) are loaded into L");
		SET_LSB(this->registers.HL, RdZ80(z80cpm_memory, this->registers.HL)); break;

	case LD_xHL_A:      this->debug_opcode((char *)"LD_xHL_A", (char *)"The contents of A are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, MSB(this->registers.AF)); break;
	case LD_xHL_B:      this->debug_opcode((char *)"LD_xHL_B", (char *)"The contents of B are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, MSB(this->registers.BC)); break;
	case LD_xHL_C:      this->debug_opcode((char *)"LD_xHL_C", (char *)"The contents of C are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, LSB(this->registers.BC)); break;
	case LD_xHL_D:      this->debug_opcode((char *)"LD_xHL_D", (char *)"The contents of D are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, MSB(this->registers.DE)); break;
	case LD_xHL_E:      this->debug_opcode((char *)"LD_xHL_E", (char *)"The contents of E are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, LSB(this->registers.DE)); break;
	case LD_xHL_H:      this->debug_opcode((char *)"LD_xHL_H", (char *)"The contents of H are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, MSB(this->registers.HL)); break;
	case LD_xHL_L:      this->debug_opcode((char *)"LD_xHL_L", (char *)"The contents of L are loaded into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, LSB(this->registers.HL)); break;

		//72

	case LD_xWORD_A:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_xWORD_A", (char *)"Stores A into the memory location pointed to by WORD");
		M_LDWORD(this, z80cpm_memory, J);
		WrZ80(z80cpm_memory, J, MSB(this->registers.AF));
		break;
	case LD_xWORD_HL:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_xWORD_HL", (char *)"Stores HL into the memory location pointed to by WORD");
		M_LDWORD(this, z80cpm_memory, J);
		WrZ80(z80cpm_memory, J, LSB(this->registers.HL)); // ???
		J += 1;
		WrZ80(z80cpm_memory, J, MSB(this->registers.HL));
		break;
	case LD_A_xWORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_A_xWORD", (char *)"Load value pointed to by WORD into A");
		M_LDWORD(this, z80cpm_memory, J);
		SET_MSB(this->registers.AF, RdZ80(z80cpm_memory, J));
		break;
	case LD_HL_xWORD:    this->debug_opcode_reg_word(z80cpm_memory, (char *)"LD_HL_xWORD", (char *)"Load value pointed to by WORD into HL");
		M_LDWORD(this, z80cpm_memory, J);
		SET_LSB(this->registers.HL, RdZ80(z80cpm_memory, J));
		J += 1;
		SET_MSB(this->registers.HL, RdZ80(z80cpm_memory, J));
		break;

		//76

	case LD_PC_HL:      this->debug_opcode((char *)"LD_PC_HL", (char *)"Load value of HL into PC");
		this->registers.PC = this->registers.HL; this->JumpZ80(this->registers.PC); break;
	case LD_SP_HL:      this->debug_opcode((char *)"LD_SP_HL", (char *)"Load value of HL into SP");
		this->registers.SP = this->registers.HL; break;

	case LD_A_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_A_BYTE", (char *)"Load BYTE into A");
		SET_MSB(this->registers.AF, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_B_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_B_BYTE", (char *)"Load BYTE into B");
		SET_MSB(this->registers.BC, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_C_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_C_BYTE", (char *)"Load BYTE into C");
		SET_LSB(this->registers.BC, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_D_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_D_BYTE", (char *)"Load BYTE into D");
		SET_MSB(this->registers.DE, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_E_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_E_BYTE", (char *)"Load BYTE into E");
		SET_LSB(this->registers.DE, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_H_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_H_BYTE", (char *)"Load BYTE into H");
		SET_MSB(this->registers.HL, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_L_BYTE:     this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_L_BYTE", (char *)"Load BYTE into L");
		SET_LSB(this->registers.HL, this->OpZ80(z80cpm_memory, this->registers.PC)); break;
	case LD_xHL_BYTE:   this->debug_opcode_reg_byte(z80cpm_memory, (char *)"LD_xHL_BYTE", (char *)"Load BYTE into (HL)");
		WrZ80(z80cpm_memory, this->registers.HL, this->OpZ80(z80cpm_memory, this->registers.PC)); break;

		//INC 86

	case INC_A:         this->debug_opcode((char *)"INC_A", (char *)"Adds one to A");
		M_INC_H(this, this->registers.AF); break;
	case INC_B:         this->debug_opcode((char *)"INC_B", (char *)"Adds one to B");
		M_INC_H(this, this->registers.BC); break;
	case INC_C:         this->debug_opcode((char *)"INC_C", (char *)"Adds one to C");
		M_INC_L(this, this->registers.BC); break;
	case INC_D:         this->debug_opcode((char *)"INC_D", (char *)"Adds one to D");
		M_INC_H(this, this->registers.DE); break;
	case INC_E:         this->debug_opcode((char *)"INC_E", (char *)"Adds one to E");
		M_INC_L(this, this->registers.DE); break;
	case INC_H:         this->debug_opcode((char *)"INC_H", (char *)"Adds one to H");
		M_INC_H(this, this->registers.HL); break;
	case INC_L:         this->debug_opcode((char *)"INC_L", (char *)"Adds one to L");
		M_INC_L(this, this->registers.HL); break;

	case INC_BC:        this->debug_opcode((char *)"INC_BC", (char *)"Adds one to BC");
		this->registers.BC++; break;
	case INC_DE:        this->debug_opcode((char *)"INC_DE", (char *)"Adds one to DE");
		this->registers.DE++; break;
	case INC_HL:        this->debug_opcode((char *)"INC_HL", (char *)"Adds one to HL");
		this->registers.HL++; break;
	case INC_SP:        this->debug_opcode((char *)"INC_SP", (char *)"Adds one to SP");
		this->registers.SP++; break;
	case INC_xHL:       this->debug_opcode((char *)"INC_xHL", (char *)"Adds one to (HL)");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_INC_L(this, I); WrZ80(z80cpm_memory, this->registers.HL, I); break;

		//DEC 98

	case DEC_A:         this->debug_opcode((char *)"DEC_A", (char *)"Subtracts one from A");
		M_DEC_H(this, this->registers.AF); break;
	case DEC_B:         this->debug_opcode((char *)"DEC_B", (char *)"Subtracts one from B");
		M_DEC_H(this, this->registers.BC); break;
	case DEC_C:         this->debug_opcode((char *)"DEC_C", (char *)"Subtracts one from C");
		M_DEC_L(this, this->registers.BC); break;
	case DEC_D:         this->debug_opcode((char *)"DEC_D", (char *)"Subtracts one from D");
		M_DEC_H(this, this->registers.DE); break;
	case DEC_E:         this->debug_opcode((char *)"DEC_E", (char *)"Subtracts one from E");
		M_DEC_L(this, this->registers.DE); break;
	case DEC_H:         this->debug_opcode((char *)"DEC_H", (char *)"Subtracts one from H");
		M_DEC_H(this, this->registers.HL); break;
	case DEC_L:         this->debug_opcode((char *)"DEC_L", (char *)"Subtracts one from L");
		M_DEC_L(this, this->registers.HL); break;

	case DEC_BC:        this->debug_opcode((char *)"DEC_BC", (char *)"Subtracts one from BC");
		this->registers.BC--; break;
	case DEC_DE:        this->debug_opcode((char *)"DEC_BC", (char *)"Subtracts one from DE");
		this->registers.DE--; break;
	case DEC_HL:        this->debug_opcode((char *)"DEC_BC", (char *)"Subtracts one from HL");
		this->registers.HL--; break;
	case DEC_SP:        this->debug_opcode((char *)"DEC_BC", (char *)"Subtracts one from SP");
		this->registers.SP--; break;
	case DEC_xHL:       this->debug_opcode((char *)"DEC_BC", (char *)"Subtracts one from (HL)");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_DEC_L(this, I); WrZ80(z80cpm_memory, this->registers.HL, I); break;

		//110

	case ADD_A:         this->debug_opcode((char *)"ADD_A", (char *)"Adds A to A");
		M_ADD(this, MSB(this->registers.AF)); break;
	case ADD_B:         this->debug_opcode((char *)"ADD_B", (char *)"Adds B to A");
		M_ADD(this, MSB(this->registers.BC)); break;
	case ADD_C:         this->debug_opcode((char *)"ADD_C", (char *)"Adds C to A");
		M_ADD(this, LSB(this->registers.BC)); break;
	case ADD_D:         this->debug_opcode((char *)"ADD_D", (char *)"Adds D to A");
		M_ADD(this, MSB(this->registers.DE)); break;
	case ADD_E:         this->debug_opcode((char *)"ADD_E", (char *)"Adds E to A");
		M_ADD(this, LSB(this->registers.DE)); break;
	case ADD_H:         this->debug_opcode((char *)"ADD_H", (char *)"Adds H to A");
		M_ADD(this, MSB(this->registers.HL)); break;
	case ADD_L:         this->debug_opcode((char *)"ADD_L", (char *)"Adds L to A");
		M_ADD(this, LSB(this->registers.HL)); break;
	case ADD_xHL:       this->debug_opcode((char *)"ADD_xHL", (char *)"Adds (HL) to A");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_ADD(this, I); break;
	case ADD_BYTE:      this->debug_opcode((char *)"ADD_BYTE", (char *)"Adds BYTE to A");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_ADD(this, I); break;

	case ADD_HL_BC:     this->debug_opcode((char *)"ADD_HL_BC", (char *)"The value of BC is added to HL");
		M_ADDW(this, HL, BC); break;
	case ADD_HL_DE:     this->debug_opcode((char *)"ADD_HL_DE", (char *)"The value of DE is added to HL");
		M_ADDW(this, HL, DE); break;
	case ADD_HL_HL:     this->debug_opcode((char *)"ADD_HL_HL", (char *)"The value of HL is added to HL");
		M_ADDW(this, HL, HL); break;
	case ADD_HL_SP:     this->debug_opcode((char *)"ADD_HL_SP", (char *)"The value of SP is added to HL");
		M_ADDW(this, HL, SP); break;

	case ADC_A:         this->debug_opcode((char *)"ADC_A", (char *)"Adds A and the carry flag to A");
		M_ADC(this, MSB(this->registers.AF)); break;
	case ADC_B:         this->debug_opcode((char *)"ADC_B", (char *)"Adds B and the carry flag to A");
		M_ADC(this, MSB(this->registers.BC)); break;
	case ADC_C:         this->debug_opcode((char *)"ADC_C", (char *)"Adds C and the carry flag to A");
		M_ADC(this, LSB(this->registers.BC)); break;
	case ADC_D:         this->debug_opcode((char *)"ADC_D", (char *)"Adds D and the carry flag to A");
		M_ADC(this, MSB(this->registers.DE)); break;
	case ADC_E:         this->debug_opcode((char *)"ADC_E", (char *)"Adds E and the carry flag to A");
		M_ADC(this, LSB(this->registers.DE)); break;
	case ADC_H:         this->debug_opcode((char *)"ADC_H", (char *)"Adds H and the carry flag to A");
		M_ADC(this, MSB(this->registers.HL)); break;
	case ADC_L:         this->debug_opcode((char *)"ADC_L", (char *)"Adds L and the carry flag to A");
		M_ADC(this, LSB(this->registers.HL)); break;
	case ADC_xHL:       this->debug_opcode((char *)"ADC_xHL", (char *)"Adds (HL) and the carry flag to A");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_ADC(this, I); break;
	case ADC_BYTE:      this->debug_opcode((char *)"ADC_xHL", (char *)"Adds BYTE and the carry flag to A");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_ADC(this, I); break;

		//132

	case SUB_A:      this->debug_opcode((char *)"SUB_A", (char *)"Subtracts A from A");
		SET_MSB(this->registers.AF, 0);
		SET_LSB(this->registers.AF, N_FLAG | Z_FLAG);
		break;
	case SUB_B:      this->debug_opcode((char *)"SUB_B", (char *)"Subtracts B from A");
		M_SUB(this, MSB(this->registers.BC)); break;
	case SUB_C:      this->debug_opcode((char *)"SUB_C", (char *)"Subtracts C from A");
		M_SUB(this, LSB(this->registers.BC)); break;
	case SUB_D:      this->debug_opcode((char *)"SUB_D", (char *)"Subtracts D from A");
		M_SUB(this, MSB(this->registers.DE)); break;
	case SUB_E:      this->debug_opcode((char *)"SUB_E", (char *)"Subtracts E from A");
		M_SUB(this, LSB(this->registers.DE)); break;
	case SUB_H:      this->debug_opcode((char *)"SUB_H", (char *)"Subtracts H from A");
		M_SUB(this, MSB(this->registers.HL)); break;
	case SUB_L:      this->debug_opcode((char *)"SUB_L", (char *)"Subtracts L from A");
		M_SUB(this, LSB(this->registers.HL)); break;
	case SUB_xHL:       this->debug_opcode((char *)"SUB_xHL", (char *)"Subtracts (HL) from A");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SUB(this, I); break;
	case SUB_BYTE:      this->debug_opcode((char *)"SUB_BYTE", (char *)"Subtracts BYTE from A");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_SUB(this, I); break;

	case SBC_A:      this->debug_opcode((char *)"SBC_A", (char *)"Subtracts A and the carry flag from A");
		M_SBC(this, MSB(this->registers.AF)); break;
	case SBC_B:      this->debug_opcode((char *)"SBC_B", (char *)"Subtracts B and the carry flag from A");
		M_SBC(this, MSB(this->registers.BC)); break;
	case SBC_C:      this->debug_opcode((char *)"SBC_C", (char *)"Subtracts C and the carry flag from A");
		M_SBC(this, LSB(this->registers.BC)); break;
	case SBC_D:      this->debug_opcode((char *)"SBC_D", (char *)"Subtracts D and the carry flag from A");
		M_SBC(this, MSB(this->registers.DE)); break;
	case SBC_E:      this->debug_opcode((char *)"SBC_E", (char *)"Subtracts E and the carry flag from A");
		M_SBC(this, LSB(this->registers.DE)); break;
	case SBC_H:      this->debug_opcode((char *)"SBC_H", (char *)"Subtracts H and the carry flag from A");
		M_SBC(this, MSB(this->registers.HL)); break;
	case SBC_L:      this->debug_opcode((char *)"SBC_L", (char *)"Subtracts L and the carry flag from A");
		M_SBC(this, LSB(this->registers.HL)); break;
	case SBC_xHL:       this->debug_opcode((char *)"SBC_xHL", (char *)"Subtracts (HL) and the carry flag from A");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_SBC(this, I); break;
	case SBC_BYTE:      this->debug_opcode((char *)"SBC_BYTE", (char *)"Subtracts BYTE and the carry flag from A");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_SBC(this, I); break;

		//150

	case AND_A:      this->debug_opcode((char *)"AND_A", (char *)"Bitwise AND on A with A");
		M_AND(this, MSB(this->registers.AF)); break;
	case AND_B:      this->debug_opcode((char *)"AND_B", (char *)"Bitwise AND on A with B");
		M_AND(this, MSB(this->registers.BC)); break;
	case AND_C:      this->debug_opcode((char *)"AND_C", (char *)"Bitwise AND on A with C");
		M_AND(this, LSB(this->registers.BC)); break;
	case AND_D:      this->debug_opcode((char *)"AND_D", (char *)"Bitwise AND on A with D");
		M_AND(this, MSB(this->registers.DE)); break;
	case AND_E:      this->debug_opcode((char *)"AND_E", (char *)"Bitwise AND on A with E");
		M_AND(this, LSB(this->registers.DE)); break;
	case AND_H:      this->debug_opcode((char *)"AND_H", (char *)"Bitwise AND on A with H");
		M_AND(this, MSB(this->registers.HL)); break;
	case AND_L:      this->debug_opcode((char *)"AND_L", (char *)"Bitwise AND on A with L");
		M_AND(this, LSB(this->registers.HL)); break;
	case AND_xHL:       this->debug_opcode((char *)"AND_xHL", (char *)"Bitwise AND on A with (HL)");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_AND(this, I); break;
	case AND_BYTE:      this->debug_opcode((char *)"AND_BYTE", (char *)"Bitwise AND on A with BYTE");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_AND(this, I); break;

	case OR_A:      this->debug_opcode((char *)"OR_A", (char *)"Bitwise OR on A with A");
		M_OR(this, MSB(this->registers.AF)); break;
	case OR_B:      this->debug_opcode((char *)"OR_B", (char *)"Bitwise OR on A with B");
		M_OR(this, MSB(this->registers.BC)); break;
	case OR_C:      this->debug_opcode((char *)"OR_C", (char *)"Bitwise OR on A with C");
		M_OR(this, LSB(this->registers.BC)); break;
	case OR_D:      this->debug_opcode((char *)"OR_D", (char *)"Bitwise OR on A with D");
		M_OR(this, MSB(this->registers.DE)); break;
	case OR_E:      this->debug_opcode((char *)"OR_E", (char *)"Bitwise OR on A with E");
		M_OR(this, LSB(this->registers.DE)); break;
	case OR_H:      this->debug_opcode((char *)"OR_H", (char *)"Bitwise OR on A with H");
		M_OR(this, MSB(this->registers.HL)); break;
	case OR_L:      this->debug_opcode((char *)"OR_L", (char *)"Bitwise OR on A with L");
		M_OR(this, LSB(this->registers.HL)); break;
	case OR_xHL:       this->debug_opcode((char *)"OR_xHL", (char *)"Bitwise OR on A with (HL)");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_OR(this, I); break;
	case OR_BYTE:      this->debug_opcode((char *)"OR_BYTE", (char *)"Bitwise OR on A with BYTE");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_OR(this, I); break;

	case XOR_A:      this->debug_opcode((char *)"XOR_A", (char *)"Bitwise XOR on A with A");
		SET_MSB(this->registers.AF, 0);
		SET_LSB(this->registers.AF, P_FLAG | Z_FLAG);
		break;
	case XOR_B:      this->debug_opcode((char *)"XOR_B", (char *)"Bitwise XOR on A with B");
		M_XOR(this, MSB(this->registers.BC)); break;
	case XOR_C:      this->debug_opcode((char *)"XOR_C", (char *)"Bitwise XOR on A with C");
		M_XOR(this, LSB(this->registers.BC)); break;
	case XOR_D:      this->debug_opcode((char *)"XOR_D", (char *)"Bitwise XOR on A with D");
		M_XOR(this, MSB(this->registers.DE)); break;
	case XOR_E:      this->debug_opcode((char *)"XOR_E", (char *)"Bitwise XOR on A with E");
		M_XOR(this, LSB(this->registers.DE)); break;
	case XOR_H:      this->debug_opcode((char *)"XOR_H", (char *)"Bitwise XOR on A with H");
		M_XOR(this, MSB(this->registers.HL)); break;
	case XOR_L:      this->debug_opcode((char *)"XOR_L", (char *)"Bitwise XOR on A with L");
		M_XOR(this, LSB(this->registers.HL)); break;
	case XOR_xHL:       this->debug_opcode((char *)"XOR_xHL", (char *)"Bitwise XOR on A with (HL)");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_XOR(this, I); break;
	case XOR_BYTE:      this->debug_opcode((char *)"XOR_BYTE", (char *)"Bitwise XOR on A with BYTE");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_XOR(this, I); break;

	case CP_A:      this->debug_opcode((char *)"CP_A", (char *)"Subtracts A from A and affects flags according to the result. A is not modified.");
		SET_LSB(this->registers.AF, N_FLAG | Z_FLAG);
		break;
	case CP_B:      this->debug_opcode((char *)"CP_B", (char *)"Subtracts B from A and affects flags according to the result. A is not modified.");
		M_CP(this, MSB(this->registers.BC)); break;
	case CP_C:      this->debug_opcode((char *)"CP_C", (char *)"Subtracts C from A and affects flags according to the result. A is not modified.");
		M_CP(this, LSB(this->registers.BC)); break;
	case CP_D:      this->debug_opcode((char *)"CP_D", (char *)"Subtracts D from A and affects flags according to the result. A is not modified.");
		M_CP(this, MSB(this->registers.DE)); break;
	case CP_E:      this->debug_opcode((char *)"CP_E", (char *)"Subtracts E from A and affects flags according to the result. A is not modified.");
		M_CP(this, LSB(this->registers.DE)); break;
	case CP_H:      this->debug_opcode((char *)"CP_H", (char *)"Subtracts H from A and affects flags according to the result. A is not modified.");
		M_CP(this, MSB(this->registers.HL)); break;
	case CP_L:      this->debug_opcode((char *)"CP_L", (char *)"Subtracts J from A and affects flags according to the result. A is not modified.");
		M_CP(this, LSB(this->registers.HL)); break;
	case CP_xHL:       this->debug_opcode((char *)"CP_xHL", (char *)"Subtracts (HL) from A and affects flags according to the result. A is not modified.");
		I = this->RdZ80(z80cpm_memory, this->registers.HL); M_CP(this, I); break;
	case CP_BYTE:      this->debug_opcode((char *)"CP_BYTE", (char *)"Subtracts BYTE from A and affects flags according to the result. A is not modified.");
		I = this->OpZ80(z80cpm_memory, this->registers.PC); M_CP(this, I); break;

		//186

	case CALL:       this->debug_opcode((char *)"CALL", (char *)"The current PC value +3 is pushed onto stack, then is loaded with WORD");
		M_CALL(this, z80cpm_memory); break;
	case CALL_NZ:       this->debug_opcode((char *)"CALL_NZ", (char *)"If condition Z is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if ((LSB(this->registers.AF) & Z_FLAG) == 0x0) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case CALL_NC:       this->debug_opcode((char *)"CALL_NC", (char *)"If condition C is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if ((LSB(this->registers.AF) & C_FLAG) == 0x0) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case CALL_PO:       this->debug_opcode((char *)"CALL_PO", (char *)"If condition P is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if ((LSB(this->registers.AF) & P_FLAG) == 0x0) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case CALL_P:       this->debug_opcode((char *)"CALL_P", (char *)"If condition S is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if ((LSB(this->registers.AF) & S_FLAG) == 0x0) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;

	case CALL_Z:       this->debug_opcode((char *)"CALL_Z", (char *)"If condition Z is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if (LSB(this->registers.AF) & Z_FLAG) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case CALL_C:       this->debug_opcode((char *)"CALL_C", (char *)"If condition C is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if (LSB(this->registers.AF) & C_FLAG) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case CALL_PE:       this->debug_opcode((char *)"CALL_PE", (char *)"If condition P is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if (LSB(this->registers.AF) & P_FLAG) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case CALL_M:       this->debug_opcode((char *)"CALL_M", (char *)"If condition S is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
		if (LSB(this->registers.AF) & S_FLAG) { M_CALL(this, z80cpm_memory); }
		else this->registers.PC += 2; break;


	case RET:        this->debug_opcode((char *)"RET", (char *)"The top stack entry is popped into PC");
		M_RET(this, z80cpm_memory); break;
	case RET_NZ:        this->debug_opcode((char *)"RET_NZ", (char *)"If condition Z is false, the top stack entry is popped into PC");
		if ((LSB(this->registers.AF) & Z_FLAG) == 0x0) { M_RET(this, z80cpm_memory); } break;
	case RET_NC:        this->debug_opcode((char *)"RET_NC", (char *)"If condition C is false, the top stack entry is popped into PC");
		if ((LSB(this->registers.AF) & C_FLAG) == 0x0) { M_RET(this, z80cpm_memory); } break;
	case RET_PO:        this->debug_opcode((char *)"RET_PO", (char *)"If condition P is false, the top stack entry is popped into PC");
		if ((LSB(this->registers.AF) & P_FLAG) == 0x0) { M_RET(this, z80cpm_memory); } break;
	case RET_P:        this->debug_opcode((char *)"RET_P", (char *)"If condition S is false, the top stack entry is popped into PC");
		if ((LSB(this->registers.AF) & S_FLAG) == 0x0) { M_RET(this, z80cpm_memory); } break;

	case RET_Z:        this->debug_opcode((char *)"RET_Z", (char *)"If condition Z is true, the top stack entry is popped into PC");
		if (LSB(this->registers.AF) & Z_FLAG) { M_RET(this, z80cpm_memory); } break;
	case RET_C:        this->debug_opcode((char *)"RET_C", (char *)"If condition C is true, the top stack entry is popped into PC");
		if (LSB(this->registers.AF) & C_FLAG) { M_RET(this, z80cpm_memory); } break;
	case RET_PE:        this->debug_opcode((char *)"RET_PE", (char *)"If condition P is true, the top stack entry is popped into PC");
		if (LSB(this->registers.AF) & P_FLAG) { M_RET(this, z80cpm_memory); } break;
	case RET_M:        this->debug_opcode((char *)"RET_M", (char *)"If condition S is true, the top stack entry is popped into PC");
		if (LSB(this->registers.AF) & S_FLAG) { M_RET(this, z80cpm_memory); } break;

	case JR:        this->debug_opcode((char *)"JR", (char *)"The signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
		M_JR(this, z80cpm_memory); break;
	case JR_NZ:        this->debug_opcode((char *)"JR_NZ", (char *)"If condition Z is false, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
		if ((LSB(this->registers.AF) & Z_FLAG) == 0x0) { M_JR(this, z80cpm_memory); }
		else this->registers.PC++; break;
	case JR_NC:        this->debug_opcode((char *)"JR_NC", (char *)"If condition C is false, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
		if ((LSB(this->registers.AF) & C_FLAG) == 0x0) { M_JR(this, z80cpm_memory); }
		else this->registers.PC++; break;

	case JR_Z:        this->debug_opcode((char *)"JR_Z", (char *)"If condition Z is true, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
		if (LSB(this->registers.AF) & Z_FLAG) { M_JR(this, z80cpm_memory); }
		else this->registers.PC++; break;
	case JR_C:        this->debug_opcode((char *)"JR_C", (char *)"If condition C is true, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
		if (LSB(this->registers.AF) & C_FLAG) { M_JR(this, z80cpm_memory); }
		else this->registers.PC++; break;

	case JP:        this->debug_opcode((char *)"JP", (char *)"WORD is copied to PC");
		M_JP(this, z80cpm_memory); break;
	case JP_NZ:        this->debug_opcode((char *)"JP_NZ", (char *)"If condition Z is false, WORD is copied to PC");
		if ((LSB(this->registers.AF) & Z_FLAG) == 0x0) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case JP_NC:        this->debug_opcode((char *)"JP_NC", (char *)"If condition C is false, WORD is copied to PC");
		if ((LSB(this->registers.AF) & C_FLAG) == 0x0) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case JP_PO:        this->debug_opcode((char *)"JP_PO", (char *)"If condition P is false, WORD is copied to PC");
		if ((LSB(this->registers.AF) & P_FLAG) == 0x0) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case JP_P:        this->debug_opcode((char *)"JP_P", (char *)"If condition S is false, WORD is copied to PC");
		if ((LSB(this->registers.AF) & S_FLAG) == 0x0) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;

	case JP_Z:        this->debug_opcode((char *)"JP_Z", (char *)"If condition Z is true, WORD is copied to PC");
		if (LSB(this->registers.AF) & Z_FLAG) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case JP_C:        this->debug_opcode((char *)"JP_C", (char *)"If condition C is true, WORD is copied to PC");
		if (LSB(this->registers.AF) & C_FLAG) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case JP_PE:        this->debug_opcode((char *)"JP_PE", (char *)"If condition P is true, WORD is copied to PC");
		if (LSB(this->registers.AF) & P_FLAG) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;
	case JP_M:        this->debug_opcode((char *)"JP_M", (char *)"If condition S is true, WORD is copied to PC");
		if (LSB(this->registers.AF) & S_FLAG) { M_JP(this, z80cpm_memory); }
		else this->registers.PC += 2; break;

		//214

	case DJNZ:        this->debug_opcode((char *)"DJNZ", (char *)"The B register is decremented, and if not zero, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
		SET_MSB(this->registers.BC, MSB(this->registers.BC) - 1);
		if (MSB(this->registers.BC) > 0) {
			M_JR(this, z80cpm_memory);
		}
		else this->registers.PC++;
		break;

	case SCF:        this->debug_opcode((char *)"SCF", (char *)"Sets the carry flag");
		S(this, C_FLAG); R(this, N_FLAG | H_FLAG); break;

	case CCF:      this->debug_opcode((char *)"CCF", (char*)"Inverts the carry flag");
		SET_LSB(this->registers.AF, LSB(this->registers.AF) ^ C_FLAG);
		R(this, N_FLAG | H_FLAG);
		SET_LSB(this->registers.AF, LSB(this->registers.AF) | ((LSB(this->registers.AF) & C_FLAG) ? 0 : H_FLAG));
		break;

	case CPL:        this->debug_opcode((char *)"CPL", (char *)"The contents of A are inverted (one's complement)");
		SET_MSB(this->registers.AF, ~MSB(this->registers.AF));
		S(this, N_FLAG | H_FLAG);
		break;


	case OUTA:        this->debug_opcode((char *)"OUTA", (char *)"The value of A is written on port BYTE");
		I = this->OpZ80(z80cpm_memory, this->registers.PC);
		this->OutZ80(z80cpm_memory, I | (this->registers.AF & 0xFF00), MSB(this->registers.AF));
		break;

	case INA:        this->debug_opcode((char *)"INA", (char *)"A byte from port BYTE is written to A");
		I = this->OpZ80(z80cpm_memory, this->registers.PC);
		SET_MSB(this->registers.AF, this->InZ80(I | (this->registers.AF & 0xFF00)));
		break;

		//223

	case RLCA:          this->debug_opcode((char *)"RLCA", (char *)"The contents of A are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0");
		I = MSB(this->registers.AF) & 0x80 ? C_FLAG : 0;
		SET_MSB(this->registers.AF, (MSB(this->registers.AF) << 1) | I);
		SET_LSB(this->registers.AF, (LSB(this->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
		break;

	case RLA:           this->debug_opcode((char *)"RLA", (char *)"The contents of A are rotated left one bit position. The contents of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0");
		I = MSB(this->registers.AF) & 0x80 ? C_FLAG : 0;
		SET_MSB(this->registers.AF, (MSB(this->registers.AF) << 1) | (LSB(this->registers.AF) & C_FLAG));
		SET_LSB(this->registers.AF, (LSB(this->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
		break;
	case RRCA:          this->debug_opcode((char *)"RRCA", (char *)"The contents of A are rotated right one bit position. The contents of bit 0 are copied to the carry flag and bit 7");
		I = MSB(this->registers.AF) & 0x01;
		SET_MSB(this->registers.AF, (MSB(this->registers.AF) >> 1) | (I ? 0x80 : 0));
		SET_LSB(this->registers.AF, (LSB(this->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
		break;
	case RRA:           this->debug_opcode((char *)"RRA", (char *)"The contents of A are rotated right one bit position. The contents of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7");
		I = MSB(this->registers.AF) & 0x01;
		SET_MSB(this->registers.AF, (MSB(this->registers.AF) >> 1) | (LSB(this->registers.AF) & C_FLAG ? 0x80 : 0));
		SET_LSB(this->registers.AF, (LSB(this->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
		break;

	case RST00:       this->debug_opcode((char *)"RST00", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 00h");
		M_RST(this, z80cpm_memory, 0x0000); break;
	case RST08:       this->debug_opcode((char *)"RST08", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 08h");
		M_RST(this, z80cpm_memory, 0x0008); break;
	case RST10:       this->debug_opcode((char *)"RST10", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 10h");
		M_RST(this, z80cpm_memory, 0x0010); break;
	case RST18:       this->debug_opcode((char *)"RST18", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 18h");
		M_RST(this, z80cpm_memory, 0x0018); break;
	case RST20:       this->debug_opcode((char *)"RST20", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 20h");
		M_RST(this, z80cpm_memory, 0x0020); break;
	case RST28:       this->debug_opcode((char *)"RST28", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 28h");
		M_RST(this, z80cpm_memory, 0x0028); break;
	case RST30:       this->debug_opcode((char *)"RST30", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 30h");
		M_RST(this, z80cpm_memory, 0x0030); break;
	case RST38:       this->debug_opcode((char *)"RST38", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 38h");
		M_RST(this, z80cpm_memory, 0x0038); break;

	case PUSH_AF:       this->debug_opcode((char *)"PUSH_AF", (char *)"SP is decremented and A is stored into the memory location pointed to by SP. SP is decremented again and F is stored pointed to by SP");
		M_PUSH(this, z80cpm_memory, AF); break;
	case PUSH_BC:       this->debug_opcode((char *)"PUSH_BC", (char *)"SP is decremented and B is stored into the memory location pointed to by SP. SP is decremented again and C is stored pointed to by SP");
		M_PUSH(this, z80cpm_memory, BC); break;
	case PUSH_DE:       this->debug_opcode((char *)"PUSH_DE", (char *)"SP is decremented and D is stored into the memory location pointed to by SP. SP is decremented again and E is stored pointed to by SP");
		M_PUSH(this, z80cpm_memory, DE); break;
	case PUSH_HL:       this->debug_opcode((char *)"PUSH_HL", (char *)"SP is decremented and H is stored into the memory location pointed to by SP. SP is decremented again and L is stored pointed to by SP");
		M_PUSH(this, z80cpm_memory, HL); break;

		//239

	case POP_AF:       this->debug_opcode((char *)"POP_AF", (char *)"The memory location pointed to by SP is stored into F and SP is incremented. The memory location pointed to by SP is stored into A and SP is incremented again");
		M_POP(this, z80cpm_memory, AF); break;
	case POP_BC:       this->debug_opcode((char *)"POP_BC", (char *)"The memory location pointed to by SP is stored into C and SP is incremented. The memory location pointed to by SP is stored into B and SP is incremented again");
		M_POP(this, z80cpm_memory, BC); break;
	case POP_DE:       this->debug_opcode((char *)"POP_DE", (char *)"The memory location pointed to by SP is stored into E and SP is incremented. The memory location pointed to by SP is stored into D and SP is incremented again");
		M_POP(this, z80cpm_memory, DE); break;
	case POP_HL:       this->debug_opcode((char *)"POP_HL", (char *)"The memory location pointed to by SP is stored into L and SP is incremented. The memory location pointed to by SP is stored into H and SP is incremented again");
		M_POP(this, z80cpm_memory, HL); break;

	case EX_AF_AFl:      this->debug_opcode((char *)"EX_AF_AFl", (char*)"Exchanges the 16bit contents of AF and AFl");
		J = this->registers.AF;
		this->registers.AF = this->registers.AFl;
		this->registers.AFl = J;
		break;
	case EX_DE_HL:      this->debug_opcode((char *)"EX_DE_HL", (char*)"Exchanges the 16bit contents of DE and HL");
		J = this->registers.DE;
		this->registers.DE = this->registers.HL;
		this->registers.HL = J;
		break;
	case EX_xSP_HL:      this->debug_opcode((char *)"EX_xSP_HL", (char*)"Exchanges (SP) with L, and (SP+1) with H");
		J = this->registers.HL;
		SET_WORD(this->registers.HL, this->RdZ80(z80cpm_memory, this->registers.SP),
			this->RdZ80(z80cpm_memory, this->registers.SP + 1));

		this->WrZ80(z80cpm_memory, this->registers.SP, LSB(J));
		this->WrZ80(z80cpm_memory, this->registers.SP + 1, MSB(J));

		break;
	case EXX:      this->debug_opcode((char *)"EXX", (char*)"Exchanges the 16bit contents of BC, DE and HL with BC', DE' and HL'");
		J = this->registers.BC;
		this->registers.BC = this->registers.BCl;
		this->registers.BCl = J;

		J = this->registers.DE;
		this->registers.DE = this->registers.DEl;
		this->registers.DEl = J;

		J = this->registers.HL;
		this->registers.HL = this->registers.HLl;
		this->registers.HLl = J;
		break;



	case DI:      this->debug_opcode((char *)"DI", (char*)"Resets both interrupt flip-flops, thus prenting maskable interrups from triggering");
		if (this->registers.IFF & IFF_EI) this->registers.PC += this->IBackup - 1;
		this->registers.IFF &= ~(IFF_1 | IFF_2 | IFF_EI);
		break;
	case EI:      this->debug_opcode((char *)"EI", (char*)"Sets both interrupt flip-flops, thus allowing maskable interrupts to occur. An interrupt will not occur. An interrupts will not occur until after the immediatedly following instruction.");
		if ((this->registers.IFF & (IFF_1 | IFF_EI)) == 0x0)
		{
			this->registers.IFF |= IFF_2 | IFF_EI;
			this->IBackup = this->ICount;
			this->ICount = 1;
		}
		break;

	case DAA:      this->debug_opcode((char *)"DAA", (char*)"Adjusts a for BCD addition and subtraction operations");
		J = MSB(this->registers.AF);
		if (LSB(this->registers.AF) & C_FLAG) J |= 256;
		if (LSB(this->registers.AF) & H_FLAG) J |= 512;
		if (LSB(this->registers.AF) & N_FLAG) J |= 1024;
		this->registers.AF = DAATable[J];
		break;


	case HALT:      this->debug_opcode((char *)"HALT", (char*)"Suspends CPU operation until an interrupt or reset occurs");
		this->registers.PC--;
		this->registers.IFF |= IFF_HALT;
		this->IBackup = 0;
		break;

		//253



	default: {
		char str2[20];
		sprintf(str2, "unknown 0x%x", opcode);
		this->debug_opcode(str2, (char*)"");
		if (this->TrapBadOps)
			printf
			(
				"[Z80 %lX] Unrecognized instruction: %02X at PC=%04X\n",
				(long)this->User, this->OpZ80(z80cpm_memory, this->registers.PC - 1), this->registers.PC - 1
			);
	}

			 /*
			 // CLS: Clear The Display
			 case 0x00E0:
				 z80_screen_clear(&this->screen);
			 break;

			 // RET: Return from subroutine
			 case 0x00EE:
				 this->registers.PC = z80_stack_pop(z80);
			 break;

			 default:
				 z80_exec_extended(z80, opcode);

				 */
	}
}