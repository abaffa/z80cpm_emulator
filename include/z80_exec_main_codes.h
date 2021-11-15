        case NOP:           debug_opcode(z80, (char *)"NOP", (char *)"No operation is performed"); break;

        // LD

        case LD_A_A:        debug_opcode(z80, (char *)"LD_A_A", (char *)"The content of A is loaded into A");
            SET_MSB(z80->registers.AF, MSB(z80->registers.AF));break;
        case LD_A_B:        debug_opcode(z80, (char *)"LD_A_B", (char *)"The content of B is loaded into A");
            SET_MSB(z80->registers.AF, MSB(z80->registers.BC));break;
        case LD_A_C:        debug_opcode(z80, (char *)"LD_A_C", (char *)"The content of C is loaded into A");
            SET_MSB(z80->registers.AF, LSB(z80->registers.BC));break;
        case LD_A_D:        debug_opcode(z80, (char *)"LD_A_D", (char *)"The content of D is loaded into A");
            SET_MSB(z80->registers.AF, MSB(z80->registers.DE));break;
        case LD_A_E:        debug_opcode(z80, (char *)"LD_A_E", (char *)"The content of E is loaded into A");
            SET_MSB(z80->registers.AF, LSB(z80->registers.DE));break;
        case LD_A_H:        debug_opcode(z80, (char *)"LD_A_H", (char *)"The content of H is loaded into A");
            SET_MSB(z80->registers.AF, MSB(z80->registers.HL));break;
        case LD_A_L:        debug_opcode(z80, (char *)"LD_A_L", (char *)"The content of L is loaded into A");
            SET_MSB(z80->registers.AF, LSB(z80->registers.HL));break;
        
        // 8

        case LD_B_A:        debug_opcode(z80, (char *)"LD_B_A", (char *)"The content of A is loaded into B");
            SET_MSB(z80->registers.BC, MSB(z80->registers.AF));break;
        case LD_B_B:        debug_opcode(z80, (char *)"LD_B_B", (char *)"The content of B is loaded into B");
            SET_MSB(z80->registers.BC, MSB(z80->registers.BC));break;
        case LD_B_C:        debug_opcode(z80, (char *)"LD_B_C", (char *)"The content of C is loaded into B");
            SET_MSB(z80->registers.BC, LSB(z80->registers.BC));break;
        case LD_B_D:        debug_opcode(z80, (char *)"LD_B_D", (char *)"The content of D is loaded into B");
            SET_MSB(z80->registers.BC, MSB(z80->registers.DE));break;
        case LD_B_E:        debug_opcode(z80, (char *)"LD_B_E", (char *)"The content of E is loaded into B");
            SET_MSB(z80->registers.BC, LSB(z80->registers.DE));break;
        case LD_B_H:        debug_opcode(z80, (char *)"LD_B_H", (char *)"The content of H is loaded into B");
            SET_MSB(z80->registers.BC, MSB(z80->registers.HL));break;
        case LD_B_L:        debug_opcode(z80, (char *)"LD_B_L", (char *)"The content of L is loaded into B");
            SET_MSB(z80->registers.BC, LSB(z80->registers.HL));break;

        //15

        case LD_C_A:        debug_opcode(z80, (char *)"LD_C_A", (char *)"The content of A is loaded into C");
            SET_LSB(z80->registers.BC, MSB(z80->registers.AF));break;
        case LD_C_B:        debug_opcode(z80, (char *)"LD_C_B", (char *)"The content of B is loaded into C");
            SET_LSB(z80->registers.BC, MSB(z80->registers.BC));break;
        case LD_C_C:        debug_opcode(z80, (char *)"LD_C_C", (char *)"The content of C is loaded into C");
            SET_LSB(z80->registers.BC, LSB(z80->registers.BC));break;
        case LD_C_D:        debug_opcode(z80, (char *)"LD_C_D", (char *)"The content of D is loaded into C");
            SET_LSB(z80->registers.BC, MSB(z80->registers.DE));break;
        case LD_C_E:        debug_opcode(z80, (char *)"LD_C_E", (char *)"The content of E is loaded into C");
            SET_LSB(z80->registers.BC, LSB(z80->registers.DE));break;
        case LD_C_H:        debug_opcode(z80, (char *)"LD_C_H", (char *)"The content of H is loaded into C");
            SET_LSB(z80->registers.BC, MSB(z80->registers.HL));break;
        case LD_C_L:        debug_opcode(z80, (char *)"LD_C_L", (char *)"The content of L is loaded into C");
            SET_LSB(z80->registers.BC, LSB(z80->registers.HL));break;

        //22

        case LD_D_A:        debug_opcode(z80, (char *)"LD_D_A", (char *)"The content of A is loaded into D");
            SET_MSB(z80->registers.DE, MSB(z80->registers.AF));break;
        case LD_D_B:        debug_opcode(z80, (char *)"LD_D_B", (char *)"The content of B is loaded into D");
            SET_MSB(z80->registers.DE, MSB(z80->registers.BC));break;
        case LD_D_C:        debug_opcode(z80, (char *)"LD_D_C", (char *)"The content of C is loaded into D");
            SET_MSB(z80->registers.DE, LSB(z80->registers.BC));break;
        case LD_D_D:        debug_opcode(z80, (char *)"LD_D_D", (char *)"The content of D is loaded into D");
            SET_MSB(z80->registers.DE, MSB(z80->registers.DE));break;
        case LD_D_E:        debug_opcode(z80, (char *)"LD_D_E", (char *)"The content of E is loaded into D");
            SET_MSB(z80->registers.DE, LSB(z80->registers.DE));break;
        case LD_D_H:        debug_opcode(z80, (char *)"LD_D_H", (char *)"The content of H is loaded into D");
            SET_MSB(z80->registers.DE, MSB(z80->registers.HL));break;
        case LD_D_L:        debug_opcode(z80, (char *)"LD_D_L", (char *)"The content of L is loaded into D");
            SET_MSB(z80->registers.DE, LSB(z80->registers.HL));break;

        //29

        case LD_E_A:        debug_opcode(z80, (char *)"LD_E_A", (char *)"The content of A is loaded into E");
            SET_LSB(z80->registers.DE, MSB(z80->registers.AF));break;
        case LD_E_B:        debug_opcode(z80, (char *)"LD_E_B", (char *)"The content of B is loaded into E");
            SET_LSB(z80->registers.DE, MSB(z80->registers.BC));break;
        case LD_E_C:        debug_opcode(z80, (char *)"LD_E_C", (char *)"The content of C is loaded into E");
            SET_LSB(z80->registers.DE, LSB(z80->registers.BC));break;
        case LD_E_D:        debug_opcode(z80, (char *)"LD_E_D", (char *)"The content of D is loaded into E");
            SET_LSB(z80->registers.DE, MSB(z80->registers.DE));break;
        case LD_E_E:        debug_opcode(z80, (char *)"LD_E_E", (char *)"The content of E is loaded into E");
            SET_LSB(z80->registers.DE, LSB(z80->registers.DE));break;
        case LD_E_H:        debug_opcode(z80, (char *)"LD_E_H", (char *)"The content of H is loaded into E");
            SET_LSB(z80->registers.DE, MSB(z80->registers.HL));break;
        case LD_E_L:        debug_opcode(z80, (char *)"LD_E_L", (char *)"The content of L is loaded into E");
            SET_LSB(z80->registers.DE, LSB(z80->registers.HL));break;

        //36

        case LD_H_A:        debug_opcode(z80, (char *)"LD_H_A", (char *)"The content of A is loaded into H");
            SET_MSB(z80->registers.HL, MSB(z80->registers.AF));break;
        case LD_H_B:        debug_opcode(z80, (char *)"LD_H_B", (char *)"The content of B is loaded into H");
            SET_MSB(z80->registers.HL, MSB(z80->registers.BC));break;
        case LD_H_C:        debug_opcode(z80, (char *)"LD_H_C", (char *)"The content of C is loaded into H");
            SET_MSB(z80->registers.HL, LSB(z80->registers.BC));break;
        case LD_H_D:        debug_opcode(z80, (char *)"LD_H_D", (char *)"The content of D is loaded into H");
            SET_MSB(z80->registers.HL, MSB(z80->registers.DE));break;
        case LD_H_E:        debug_opcode(z80, (char *)"LD_H_E", (char *)"The content of E is loaded into H");
            SET_MSB(z80->registers.HL, LSB(z80->registers.DE));break;
        case LD_H_H:        debug_opcode(z80, (char *)"LD_H_H", (char *)"The content of H is loaded into H");
            SET_MSB(z80->registers.HL, MSB(z80->registers.HL));break;
        case LD_H_L:        debug_opcode(z80, (char *)"LD_H_L", (char *)"The content of L is loaded into H");
            SET_MSB(z80->registers.HL, LSB(z80->registers.HL));break;

        //43

        case LD_L_A:        debug_opcode(z80, (char *)"LD_L_A", (char *)"The content of A is loaded into L");
            SET_LSB(z80->registers.HL, MSB(z80->registers.AF));break;
        case LD_L_B:        debug_opcode(z80, (char *)"LD_L_B", (char *)"The content of B is loaded into L");
            SET_LSB(z80->registers.HL, MSB(z80->registers.BC));break;
        case LD_L_C:        debug_opcode(z80, (char *)"LD_L_C", (char *)"The content of C is loaded into L");
            SET_LSB(z80->registers.HL, LSB(z80->registers.BC));break;
        case LD_L_D:        debug_opcode(z80, (char *)"LD_L_D", (char *)"The content of D is loaded into L");
            SET_LSB(z80->registers.HL, MSB(z80->registers.DE));break;
        case LD_L_E:        debug_opcode(z80, (char *)"LD_L_E", (char *)"The content of E is loaded into L");
            SET_LSB(z80->registers.HL, LSB(z80->registers.DE));break;
        case LD_L_H:        debug_opcode(z80, (char *)"LD_L_H", (char *)"The content of H is loaded into L");
            SET_LSB(z80->registers.HL, MSB(z80->registers.HL));break;
        case LD_L_L:        debug_opcode(z80, (char *)"LD_L_L", (char *)"The content of L is loaded into L");
            SET_LSB(z80->registers.HL, LSB(z80->registers.HL));break;

        //50

        case LD_BC_WORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_BC_WORD", (char *)"Loads ** into BC"); 
            M_LDWORD(z80, z80cpm_memory, z80->registers.BC); break;
        case LD_DE_WORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_DE_WORD", (char *)"Loads ** into DE"); 
            M_LDWORD(z80, z80cpm_memory, z80->registers.DE); break;
        case LD_HL_WORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_HL_WORD", (char *)"Loads ** into HL"); 
            M_LDWORD(z80, z80cpm_memory, z80->registers.HL); break;
        case LD_SP_WORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_SP_WORD", (char *)"Loads ** into SP"); 
            M_LDWORD(z80, z80cpm_memory, z80->registers.SP); break;

        case LD_A_xBC:      debug_opcode(z80, (char *)"LD_A_xBC", (char *)"The contents of BC are loaded into A");
            SET_MSB(z80->registers.AF, RdZ80(z80cpm_memory, z80->registers.BC));break;
        case LD_A_xDE:      debug_opcode(z80, (char *)"LD_A_xDE", (char *)"The contents of DE are loaded into A");
            SET_MSB(z80->registers.AF, RdZ80(z80cpm_memory, z80->registers.DE));break;

        case LD_xBC_A:      debug_opcode(z80, (char *)"LD_xBC_A", (char *)"Stores A into the memory location pointed to by BC");
            WrZ80(z80cpm_memory, z80->registers.BC, MSB(z80->registers.AF)); break;
        case LD_xDE_A:      debug_opcode(z80, (char *)"LD_xDE_A", (char *)"Stores A into the memory location pointed to by DE");
            WrZ80(z80cpm_memory, z80->registers.DE, MSB(z80->registers.AF)); break;

        case LD_A_xHL:      debug_opcode(z80, (char *)"LD_A_xHL", (char *)"The contents of (HL) are loaded into A");
            SET_MSB(z80->registers.AF, RdZ80(z80cpm_memory, z80->registers.HL));break;
        case LD_B_xHL:      debug_opcode(z80, (char *)"LD_B_xHL", (char *)"The contents of (HL) are loaded into B");
            SET_MSB(z80->registers.BC, RdZ80(z80cpm_memory, z80->registers.HL));break;
        case LD_C_xHL:      debug_opcode(z80, (char *)"LD_C_xHL", (char *)"The contents of (HL) are loaded into C");
            SET_LSB(z80->registers.BC, RdZ80(z80cpm_memory, z80->registers.HL));break;
        case LD_D_xHL:      debug_opcode(z80, (char *)"LD_D_xHL", (char *)"The contents of (HL) are loaded into D");
            SET_MSB(z80->registers.DE, RdZ80(z80cpm_memory, z80->registers.HL));break;
        case LD_E_xHL:      debug_opcode(z80, (char *)"LD_E_xHL", (char *)"The contents of (HL) are loaded into E");
            SET_LSB(z80->registers.DE, RdZ80(z80cpm_memory, z80->registers.HL));break;
        case LD_H_xHL:      debug_opcode(z80, (char *)"LD_H_xHL", (char *)"The contents of (HL) are loaded into H");
            SET_MSB(z80->registers.HL, RdZ80(z80cpm_memory, z80->registers.HL));break;
        case LD_L_xHL:      debug_opcode(z80, (char *)"LD_L_xHL", (char *)"The contents of (HL) are loaded into L");
            SET_LSB(z80->registers.HL, RdZ80(z80cpm_memory, z80->registers.HL));break;

        case LD_xHL_A:      debug_opcode(z80, (char *)"LD_xHL_A", (char *)"The contents of A are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, MSB(z80->registers.AF));break;
        case LD_xHL_B:      debug_opcode(z80, (char *)"LD_xHL_B", (char *)"The contents of B are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, MSB(z80->registers.BC));break;
        case LD_xHL_C:      debug_opcode(z80, (char *)"LD_xHL_C", (char *)"The contents of C are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, LSB(z80->registers.BC));break;
        case LD_xHL_D:      debug_opcode(z80, (char *)"LD_xHL_D", (char *)"The contents of D are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, MSB(z80->registers.DE));break;
        case LD_xHL_E:      debug_opcode(z80, (char *)"LD_xHL_E", (char *)"The contents of E are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, LSB(z80->registers.DE));break;
        case LD_xHL_H:      debug_opcode(z80, (char *)"LD_xHL_H", (char *)"The contents of H are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, MSB(z80->registers.HL));break;
        case LD_xHL_L:      debug_opcode(z80, (char *)"LD_xHL_L", (char *)"The contents of L are loaded into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, LSB(z80->registers.HL));break;
        
        //72

        case LD_xWORD_A:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_xWORD_A", (char *)"Stores A into the memory location pointed to by WORD");
            M_LDWORD(z80, z80cpm_memory, J); 
            WrZ80(z80cpm_memory, J, MSB(z80->registers.AF));
            break;        
        case LD_xWORD_HL:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_xWORD_HL", (char *)"Stores HL into the memory location pointed to by WORD");
            M_LDWORD(z80, z80cpm_memory, J); 
            WrZ80(z80cpm_memory, J, LSB(z80->registers.HL)); // ???
            J += 1;
            WrZ80(z80cpm_memory, J, MSB(z80->registers.HL));
            break;      
        case LD_A_xWORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_A_xWORD", (char *)"Load value pointed to by WORD into A");
            M_LDWORD(z80, z80cpm_memory, J); 
            SET_MSB(z80->registers.AF, RdZ80(z80cpm_memory, J));
            break;
        case LD_HL_xWORD:    debug_opcode_reg_word(z80, z80cpm_memory, (char *)"LD_HL_xWORD", (char *)"Load value pointed to by WORD into HL");
            M_LDWORD(z80, z80cpm_memory, J); 
            SET_LSB(z80->registers.HL, RdZ80(z80cpm_memory, J));
            J += 1;
            SET_MSB(z80->registers.HL, RdZ80(z80cpm_memory, J));
            break;

        //76
        
        case LD_PC_HL:      debug_opcode(z80, (char *)"LD_PC_HL", (char *)"Load value of HL into PC");
            z80->registers.PC = z80->registers.HL; JumpZ80(z80, z80->registers.PC); break;
        case LD_SP_HL:      debug_opcode(z80, (char *)"LD_SP_HL", (char *)"Load value of HL into SP");
            z80->registers.SP = z80->registers.HL; break;

        case LD_A_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_A_BYTE", (char *)"Load BYTE into A");
            SET_MSB(z80->registers.AF, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_B_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_B_BYTE", (char *)"Load BYTE into B");
            SET_MSB(z80->registers.BC, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_C_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_C_BYTE", (char *)"Load BYTE into C");
            SET_LSB(z80->registers.BC, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_D_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_D_BYTE", (char *)"Load BYTE into D");
            SET_MSB(z80->registers.DE, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_E_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_E_BYTE", (char *)"Load BYTE into E");
            SET_LSB(z80->registers.DE, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_H_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_H_BYTE", (char *)"Load BYTE into H");
            SET_MSB(z80->registers.HL, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_L_BYTE:     debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_L_BYTE", (char *)"Load BYTE into L");
            SET_LSB(z80->registers.HL, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        case LD_xHL_BYTE:   debug_opcode_reg_byte(z80, z80cpm_memory, (char *)"LD_xHL_BYTE", (char *)"Load BYTE into (HL)");
            WrZ80(z80cpm_memory, z80->registers.HL, OpZ80(z80, z80cpm_memory, z80->registers.PC)); break;
        
        //INC 86

        case INC_A:         debug_opcode(z80, (char *)"INC_A", (char *)"Adds one to A");
            M_INC_H(z80, z80->registers.AF);break;
        case INC_B:         debug_opcode(z80, (char *)"INC_B", (char *)"Adds one to B");    
            M_INC_H(z80, z80->registers.BC);break;
        case INC_C:         debug_opcode(z80, (char *)"INC_C", (char *)"Adds one to C");    
            M_INC_L(z80, z80->registers.BC);break;
        case INC_D:         debug_opcode(z80, (char *)"INC_D", (char *)"Adds one to D");    
            M_INC_H(z80, z80->registers.DE);break;
        case INC_E:         debug_opcode(z80, (char *)"INC_E", (char *)"Adds one to E");    
            M_INC_L(z80, z80->registers.DE);break;
        case INC_H:         debug_opcode(z80, (char *)"INC_H", (char *)"Adds one to H");    
            M_INC_H(z80, z80->registers.HL);break;
        case INC_L:         debug_opcode(z80, (char *)"INC_L", (char *)"Adds one to L");    
            M_INC_L(z80, z80->registers.HL);break;

        case INC_BC:        debug_opcode(z80, (char *)"INC_BC", (char *)"Adds one to BC");
            z80->registers.BC++; break;
        case INC_DE:        debug_opcode(z80, (char *)"INC_DE", (char *)"Adds one to DE");
            z80->registers.DE++;break;
        case INC_HL:        debug_opcode(z80, (char *)"INC_HL", (char *)"Adds one to HL");
            z80->registers.HL++;break;
        case INC_SP:        debug_opcode(z80, (char *)"INC_SP", (char *)"Adds one to SP");
            z80->registers.SP++;break;
        case INC_xHL:       debug_opcode(z80, (char *)"INC_xHL", (char *)"Adds one to (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_INC_L(z80, I); WrZ80(z80cpm_memory, z80->registers.HL,I); break;

        //DEC 98

        case DEC_A:         debug_opcode(z80, (char *)"DEC_A", (char *)"Subtracts one from A");
            M_DEC_H(z80, z80->registers.AF);break;
        case DEC_B:         debug_opcode(z80, (char *)"DEC_B", (char *)"Subtracts one from B");
            M_DEC_H(z80, z80->registers.BC);break;
        case DEC_C:         debug_opcode(z80, (char *)"DEC_C", (char *)"Subtracts one from C");
            M_DEC_L(z80, z80->registers.BC);break;
        case DEC_D:         debug_opcode(z80, (char *)"DEC_D", (char *)"Subtracts one from D");
            M_DEC_H(z80, z80->registers.DE);break;
        case DEC_E:         debug_opcode(z80, (char *)"DEC_E", (char *)"Subtracts one from E");
            M_DEC_L(z80, z80->registers.DE);break;
        case DEC_H:         debug_opcode(z80, (char *)"DEC_H", (char *)"Subtracts one from H");
            M_DEC_H(z80, z80->registers.HL);break;
        case DEC_L:         debug_opcode(z80, (char *)"DEC_L", (char *)"Subtracts one from L");
            M_DEC_L(z80, z80->registers.HL);break;

        case DEC_BC:        debug_opcode(z80, (char *)"DEC_BC", (char *)"Subtracts one from BC");
            z80->registers.BC--; break;
        case DEC_DE:        debug_opcode(z80, (char *)"DEC_BC", (char *)"Subtracts one from DE");
            z80->registers.DE--;break;
        case DEC_HL:        debug_opcode(z80, (char *)"DEC_BC", (char *)"Subtracts one from HL");
            z80->registers.HL--;break;
        case DEC_SP:        debug_opcode(z80, (char *)"DEC_BC", (char *)"Subtracts one from SP");
            z80->registers.SP--;break;
        case DEC_xHL:       debug_opcode(z80, (char *)"DEC_BC", (char *)"Subtracts one from (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_DEC_L(z80, I); WrZ80(z80cpm_memory, z80->registers.HL,I); break;

        //110

        case ADD_A:         debug_opcode(z80, (char *)"ADD_A", (char *)"Adds A to A");
            M_ADD(z80, MSB(z80->registers.AF)); break;
        case ADD_B:         debug_opcode(z80, (char *)"ADD_B", (char *)"Adds B to A");
            M_ADD(z80, MSB(z80->registers.BC)); break;
        case ADD_C:         debug_opcode(z80, (char *)"ADD_C", (char *)"Adds C to A");
            M_ADD(z80, LSB(z80->registers.BC));break;
        case ADD_D:         debug_opcode(z80, (char *)"ADD_D", (char *)"Adds D to A");
            M_ADD(z80, MSB(z80->registers.DE));break;
        case ADD_E:         debug_opcode(z80, (char *)"ADD_E", (char *)"Adds E to A");
            M_ADD(z80, LSB(z80->registers.DE));break;
        case ADD_H:         debug_opcode(z80, (char *)"ADD_H", (char *)"Adds H to A");
            M_ADD(z80, MSB(z80->registers.HL));break;
        case ADD_L:         debug_opcode(z80, (char *)"ADD_L", (char *)"Adds L to A");
            M_ADD(z80, LSB(z80->registers.HL));break;
        case ADD_xHL:       debug_opcode(z80, (char *)"ADD_xHL", (char *)"Adds (HL) to A");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_ADD(z80, I); break;
        case ADD_BYTE:      debug_opcode(z80, (char *)"ADD_BYTE", (char *)"Adds BYTE to A");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC); M_ADD(z80, I); break;

        case ADD_HL_BC:     debug_opcode(z80, (char *)"ADD_HL_BC", (char *)"The value of BC is added to HL");
            M_ADDW(z80, HL, BC);break; 
        case ADD_HL_DE:     debug_opcode(z80, (char *)"ADD_HL_DE", (char *)"The value of DE is added to HL");
            M_ADDW(z80, HL, DE);break;
        case ADD_HL_HL:     debug_opcode(z80, (char *)"ADD_HL_HL", (char *)"The value of HL is added to HL");
            M_ADDW(z80, HL, HL);break;
        case ADD_HL_SP:     debug_opcode(z80, (char *)"ADD_HL_SP", (char *)"The value of SP is added to HL");
            M_ADDW(z80, HL, SP);break;

        case ADC_A:         debug_opcode(z80, (char *)"ADC_A", (char *)"Adds A and the carry flag to A");
            M_ADC(z80, MSB(z80->registers.AF));break;
        case ADC_B:         debug_opcode(z80, (char *)"ADC_B", (char *)"Adds B and the carry flag to A");
            M_ADC(z80, MSB(z80->registers.BC));break;
        case ADC_C:         debug_opcode(z80, (char *)"ADC_C", (char *)"Adds C and the carry flag to A");
            M_ADC(z80, LSB(z80->registers.BC));break;
        case ADC_D:         debug_opcode(z80, (char *)"ADC_D", (char *)"Adds D and the carry flag to A");
            M_ADC(z80, MSB(z80->registers.DE));break;
        case ADC_E:         debug_opcode(z80, (char *)"ADC_E", (char *)"Adds E and the carry flag to A");
            M_ADC(z80, LSB(z80->registers.DE));break;
        case ADC_H:         debug_opcode(z80, (char *)"ADC_H", (char *)"Adds H and the carry flag to A");
            M_ADC(z80, MSB(z80->registers.HL));break;
        case ADC_L:         debug_opcode(z80, (char *)"ADC_L", (char *)"Adds L and the carry flag to A");
            M_ADC(z80, LSB(z80->registers.HL));break;
        case ADC_xHL:       debug_opcode(z80, (char *)"ADC_xHL", (char *)"Adds (HL) and the carry flag to A");
            I = RdZ80(z80cpm_memory, z80->registers.HL); M_ADC(z80, I); break;
        case ADC_BYTE:      debug_opcode(z80, (char *)"ADC_xHL", (char *)"Adds BYTE and the carry flag to A");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC); M_ADC(z80, I); break;
  
        //132

        case SUB_A:      debug_opcode(z80, (char *)"SUB_A", (char *)"Subtracts A from A");    
            SET_MSB(z80->registers.AF, 0);
            SET_LSB(z80->registers.AF, N_FLAG | Z_FLAG);
            break;
        case SUB_B:      debug_opcode(z80, (char *)"SUB_B", (char *)"Subtracts B from A");    
            M_SUB(z80, MSB(z80->registers.BC));break;
        case SUB_C:      debug_opcode(z80, (char *)"SUB_C", (char *)"Subtracts C from A");    
            M_SUB(z80, LSB(z80->registers.BC));break;
        case SUB_D:      debug_opcode(z80, (char *)"SUB_D", (char *)"Subtracts D from A");    
            M_SUB(z80, MSB(z80->registers.DE));break;
        case SUB_E:      debug_opcode(z80, (char *)"SUB_E", (char *)"Subtracts E from A");    
            M_SUB(z80, LSB(z80->registers.DE));break;
        case SUB_H:      debug_opcode(z80, (char *)"SUB_H", (char *)"Subtracts H from A");    
            M_SUB(z80, MSB(z80->registers.HL));break;
        case SUB_L:      debug_opcode(z80, (char *)"SUB_L", (char *)"Subtracts L from A");    
            M_SUB(z80, LSB(z80->registers.HL));break;
        case SUB_xHL:       debug_opcode(z80, (char *)"SUB_xHL", (char *)"Subtracts (HL) from A");
            I = RdZ80(z80cpm_memory, z80->registers.HL);M_SUB(z80, I);break;
        case SUB_BYTE:      debug_opcode(z80, (char *)"SUB_BYTE", (char *)"Subtracts BYTE from A");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);M_SUB(z80, I);break;

        case SBC_A:      debug_opcode(z80, (char *)"SBC_A", (char *)"Subtracts A and the carry flag from A");    
            M_SBC(z80, MSB(z80->registers.AF));break;
        case SBC_B:      debug_opcode(z80, (char *)"SBC_B", (char *)"Subtracts B and the carry flag from A");    
            M_SBC(z80, MSB(z80->registers.BC));break;
        case SBC_C:      debug_opcode(z80, (char *)"SBC_C", (char *)"Subtracts C and the carry flag from A");    
            M_SBC(z80, LSB(z80->registers.BC));break;
        case SBC_D:      debug_opcode(z80, (char *)"SBC_D", (char *)"Subtracts D and the carry flag from A");    
            M_SBC(z80, MSB(z80->registers.DE));break;
        case SBC_E:      debug_opcode(z80, (char *)"SBC_E", (char *)"Subtracts E and the carry flag from A");    
            M_SBC(z80, LSB(z80->registers.DE));break;
        case SBC_H:      debug_opcode(z80, (char *)"SBC_H", (char *)"Subtracts H and the carry flag from A");    
            M_SBC(z80, MSB(z80->registers.HL));break;
        case SBC_L:      debug_opcode(z80, (char *)"SBC_L", (char *)"Subtracts L and the carry flag from A");    
            M_SBC(z80, LSB(z80->registers.HL));break;
        case SBC_xHL:       debug_opcode(z80, (char *)"SBC_xHL", (char *)"Subtracts (HL) and the carry flag from A");
            I = RdZ80(z80cpm_memory, z80->registers.HL);M_SBC(z80, I);break;
        case SBC_BYTE:      debug_opcode(z80, (char *)"SBC_BYTE", (char *)"Subtracts BYTE and the carry flag from A");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);M_SBC(z80, I);break;

        //150

        case AND_A:      debug_opcode(z80, (char *)"AND_A", (char *)"Bitwise AND on A with A");    
            M_AND(z80, MSB(z80->registers.AF));break;
        case AND_B:      debug_opcode(z80, (char *)"AND_B", (char *)"Bitwise AND on A with B");    
            M_AND(z80, MSB(z80->registers.BC));break;
        case AND_C:      debug_opcode(z80, (char *)"AND_C", (char *)"Bitwise AND on A with C");    
            M_AND(z80, LSB(z80->registers.BC));break;
        case AND_D:      debug_opcode(z80, (char *)"AND_D", (char *)"Bitwise AND on A with D");    
            M_AND(z80, MSB(z80->registers.DE));break;
        case AND_E:      debug_opcode(z80, (char *)"AND_E", (char *)"Bitwise AND on A with E");    
            M_AND(z80, LSB(z80->registers.DE));break;
        case AND_H:      debug_opcode(z80, (char *)"AND_H", (char *)"Bitwise AND on A with H");    
            M_AND(z80, MSB(z80->registers.HL));break;
        case AND_L:      debug_opcode(z80, (char *)"AND_L", (char *)"Bitwise AND on A with L");    
            M_AND(z80, LSB(z80->registers.HL));break;
        case AND_xHL:       debug_opcode(z80, (char *)"AND_xHL", (char *)"Bitwise AND on A with (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL);M_AND(z80, I);break;
        case AND_BYTE:      debug_opcode(z80, (char *)"AND_BYTE", (char *)"Bitwise AND on A with BYTE");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);M_AND(z80, I);break;

        case OR_A:      debug_opcode(z80, (char *)"OR_A", (char *)"Bitwise OR on A with A");    
            M_OR(z80, MSB(z80->registers.AF));break;
        case OR_B:      debug_opcode(z80, (char *)"OR_B", (char *)"Bitwise OR on A with B");    
            M_OR(z80, MSB(z80->registers.BC));break;
        case OR_C:      debug_opcode(z80, (char *)"OR_C", (char *)"Bitwise OR on A with C");    
            M_OR(z80, LSB(z80->registers.BC));break;
        case OR_D:      debug_opcode(z80, (char *)"OR_D", (char *)"Bitwise OR on A with D");    
            M_OR(z80, MSB(z80->registers.DE));break;
        case OR_E:      debug_opcode(z80, (char *)"OR_E", (char *)"Bitwise OR on A with E");    
            M_OR(z80, LSB(z80->registers.DE));break;
        case OR_H:      debug_opcode(z80, (char *)"OR_H", (char *)"Bitwise OR on A with H");    
            M_OR(z80, MSB(z80->registers.HL));break;
        case OR_L:      debug_opcode(z80, (char *)"OR_L", (char *)"Bitwise OR on A with L");    
            M_OR(z80, LSB(z80->registers.HL));break;
        case OR_xHL:       debug_opcode(z80, (char *)"OR_xHL", (char *)"Bitwise OR on A with (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL);M_OR(z80, I);break;
        case OR_BYTE:      debug_opcode(z80, (char *)"OR_BYTE", (char *)"Bitwise OR on A with BYTE");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);M_OR(z80, I);break;

        case XOR_A:      debug_opcode(z80, (char *)"XOR_A", (char *)"Bitwise XOR on A with A");    
            SET_MSB(z80->registers.AF, 0);
            SET_LSB(z80->registers.AF, P_FLAG | Z_FLAG);        
            break;
        case XOR_B:      debug_opcode(z80, (char *)"XOR_B", (char *)"Bitwise XOR on A with B");    
            M_XOR(z80, MSB(z80->registers.BC));break;
        case XOR_C:      debug_opcode(z80, (char *)"XOR_C", (char *)"Bitwise XOR on A with C");    
            M_XOR(z80, LSB(z80->registers.BC));break;
        case XOR_D:      debug_opcode(z80, (char *)"XOR_D", (char *)"Bitwise XOR on A with D");    
            M_XOR(z80, MSB(z80->registers.DE));break;
        case XOR_E:      debug_opcode(z80, (char *)"XOR_E", (char *)"Bitwise XOR on A with E");    
            M_XOR(z80, LSB(z80->registers.DE));break;
        case XOR_H:      debug_opcode(z80, (char *)"XOR_H", (char *)"Bitwise XOR on A with H");    
            M_XOR(z80, MSB(z80->registers.HL));break;
        case XOR_L:      debug_opcode(z80, (char *)"XOR_L", (char *)"Bitwise XOR on A with L");    
            M_XOR(z80, LSB(z80->registers.HL));break;
        case XOR_xHL:       debug_opcode(z80, (char *)"XOR_xHL", (char *)"Bitwise XOR on A with (HL)");
            I = RdZ80(z80cpm_memory, z80->registers.HL);M_XOR(z80, I);break;
        case XOR_BYTE:      debug_opcode(z80, (char *)"XOR_BYTE", (char *)"Bitwise XOR on A with BYTE");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);M_XOR(z80, I);break;
   
        case CP_A:      debug_opcode(z80, (char *)"CP_A", (char *)"Subtracts A from A and affects flags according to the result. A is not modified.");    
            SET_LSB(z80->registers.AF, N_FLAG | Z_FLAG);        
            break;
        case CP_B:      debug_opcode(z80, (char *)"CP_B", (char *)"Subtracts B from A and affects flags according to the result. A is not modified.");    
            M_CP(z80, MSB(z80->registers.BC));break;
        case CP_C:      debug_opcode(z80, (char *)"CP_C", (char *)"Subtracts C from A and affects flags according to the result. A is not modified.");    
            M_CP(z80, LSB(z80->registers.BC));break;
        case CP_D:      debug_opcode(z80, (char *)"CP_D", (char *)"Subtracts D from A and affects flags according to the result. A is not modified.");    
            M_CP(z80, MSB(z80->registers.DE));break;
        case CP_E:      debug_opcode(z80, (char *)"CP_E", (char *)"Subtracts E from A and affects flags according to the result. A is not modified.");    
            M_CP(z80, LSB(z80->registers.DE));break;
        case CP_H:      debug_opcode(z80, (char *)"CP_H", (char *)"Subtracts H from A and affects flags according to the result. A is not modified.");    
            M_CP(z80, MSB(z80->registers.HL));break;
        case CP_L:      debug_opcode(z80, (char *)"CP_L", (char *)"Subtracts J from A and affects flags according to the result. A is not modified.");    
            M_CP(z80, LSB(z80->registers.HL));break;
        case CP_xHL:       debug_opcode(z80, (char *)"CP_xHL", (char *)"Subtracts (HL) from A and affects flags according to the result. A is not modified.");
            I = RdZ80(z80cpm_memory, z80->registers.HL);M_CP(z80, I);break;
        case CP_BYTE:      debug_opcode(z80, (char *)"CP_BYTE", (char *)"Subtracts BYTE from A and affects flags according to the result. A is not modified.");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);M_CP(z80, I);break;

        //186

        case CALL:       debug_opcode(z80, (char *)"CALL", (char *)"The current PC value +3 is pushed onto stack, then is loaded with WORD");
            M_CALL(z80, z80cpm_memory); break;
        case CALL_NZ:       debug_opcode(z80, (char *)"CALL_NZ", (char *)"If condition Z is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if((LSB(z80->registers.AF) & Z_FLAG) == 0x0) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        case CALL_NC:       debug_opcode(z80, (char *)"CALL_NC", (char *)"If condition C is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if((LSB(z80->registers.AF) & C_FLAG) == 0x0) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        case CALL_PO:       debug_opcode(z80, (char *)"CALL_PO", (char *)"If condition P is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if((LSB(z80->registers.AF) & P_FLAG) == 0x0) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        case CALL_P:       debug_opcode(z80, (char *)"CALL_P", (char *)"If condition S is false, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if((LSB(z80->registers.AF) & S_FLAG) == 0x0) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        
        case CALL_Z:       debug_opcode(z80, (char *)"CALL_Z", (char *)"If condition Z is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if(LSB(z80->registers.AF) & Z_FLAG) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        case CALL_C:       debug_opcode(z80, (char *)"CALL_C", (char *)"If condition C is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if(LSB(z80->registers.AF) & C_FLAG) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        case CALL_PE:       debug_opcode(z80, (char *)"CALL_PE", (char *)"If condition P is true, the current PC value +3 is pushed onto stack, then is loaded with WORD"); 
            if(LSB(z80->registers.AF) & P_FLAG) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        case CALL_M:       debug_opcode(z80, (char *)"CALL_M", (char *)"If condition S is true, the current PC value +3 is pushed onto stack, then is loaded with WORD");
            if(LSB(z80->registers.AF) & S_FLAG) {M_CALL(z80, z80cpm_memory); } else z80->registers.PC += 2; break;        
        

        case RET:        debug_opcode(z80, (char *)"RET", (char *)"The top stack entry is popped into PC");
            M_RET(z80, z80cpm_memory); break;
        case RET_NZ:        debug_opcode(z80, (char *)"RET_NZ", (char *)"If condition Z is false, the top stack entry is popped into PC");
            if((LSB(z80->registers.AF) & Z_FLAG) == 0x0) {M_RET(z80, z80cpm_memory); } break;
        case RET_NC:        debug_opcode(z80, (char *)"RET_NC", (char *)"If condition C is false, the top stack entry is popped into PC");
            if((LSB(z80->registers.AF) & C_FLAG) == 0x0) {M_RET(z80, z80cpm_memory); } break;
        case RET_PO:        debug_opcode(z80, (char *)"RET_PO", (char *)"If condition P is false, the top stack entry is popped into PC");
            if((LSB(z80->registers.AF) & P_FLAG) == 0x0) {M_RET(z80, z80cpm_memory); } break;
        case RET_P:        debug_opcode(z80, (char *)"RET_P", (char *)"If condition S is false, the top stack entry is popped into PC");
            if((LSB(z80->registers.AF) & S_FLAG) == 0x0) {M_RET(z80, z80cpm_memory); } break;
        
        case RET_Z:        debug_opcode(z80, (char *)"RET_Z", (char *)"If condition Z is true, the top stack entry is popped into PC");
            if(LSB(z80->registers.AF) & Z_FLAG) {M_RET(z80, z80cpm_memory); } break;
        case RET_C:        debug_opcode(z80, (char *)"RET_C", (char *)"If condition C is true, the top stack entry is popped into PC");
            if(LSB(z80->registers.AF) & C_FLAG) {M_RET(z80, z80cpm_memory); } break;
        case RET_PE:        debug_opcode(z80, (char *)"RET_PE", (char *)"If condition P is true, the top stack entry is popped into PC");
            if(LSB(z80->registers.AF) & P_FLAG) {M_RET(z80, z80cpm_memory); } break;
        case RET_M:        debug_opcode(z80, (char *)"RET_M", (char *)"If condition S is true, the top stack entry is popped into PC");
            if(LSB(z80->registers.AF) & S_FLAG) {M_RET(z80, z80cpm_memory); } break;

        case JR:        debug_opcode(z80, (char *)"JR", (char *)"The signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
            M_JR(z80, z80cpm_memory); break;
        case JR_NZ:        debug_opcode(z80, (char *)"JR_NZ", (char *)"If condition Z is false, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
            if((LSB(z80->registers.AF) & Z_FLAG) == 0x0) { M_JR(z80, z80cpm_memory); } else z80->registers.PC++; break;
        case JR_NC:        debug_opcode(z80, (char *)"JR_NC", (char *)"If condition C is false, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
            if((LSB(z80->registers.AF) & C_FLAG) == 0x0) { M_JR(z80, z80cpm_memory); } else z80->registers.PC++; break;
        
        case JR_Z:        debug_opcode(z80, (char *)"JR_Z", (char *)"If condition Z is true, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
            if(LSB(z80->registers.AF) & Z_FLAG) { M_JR(z80, z80cpm_memory); } else z80->registers.PC++; break;
        case JR_C:        debug_opcode(z80, (char *)"JR_C", (char *)"If condition C is true, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
            if(LSB(z80->registers.AF) & C_FLAG) { M_JR(z80, z80cpm_memory); } else z80->registers.PC++; break;

        case JP:        debug_opcode(z80, (char *)"JP", (char *)"WORD is copied to PC");
            M_JP(z80, z80cpm_memory); break;
        case JP_NZ:        debug_opcode(z80, (char *)"JP_NZ", (char *)"If condition Z is false, WORD is copied to PC");
            if((LSB(z80->registers.AF) & Z_FLAG) == 0x0) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        case JP_NC:        debug_opcode(z80, (char *)"JP_NC", (char *)"If condition C is false, WORD is copied to PC");
            if((LSB(z80->registers.AF) & C_FLAG) == 0x0) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        case JP_PO:        debug_opcode(z80, (char *)"JP_PO", (char *)"If condition P is false, WORD is copied to PC");
            if((LSB(z80->registers.AF) & P_FLAG) == 0x0) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        case JP_P:        debug_opcode(z80, (char *)"JP_P", (char *)"If condition S is false, WORD is copied to PC");
            if((LSB(z80->registers.AF) & S_FLAG) == 0x0) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        
        case JP_Z:        debug_opcode(z80, (char *)"JP_Z", (char *)"If condition Z is true, WORD is copied to PC");
            if(LSB(z80->registers.AF) & Z_FLAG) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        case JP_C:        debug_opcode(z80, (char *)"JP_C", (char *)"If condition C is true, WORD is copied to PC");
            if(LSB(z80->registers.AF) & C_FLAG) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        case JP_PE:        debug_opcode(z80, (char *)"JP_PE", (char *)"If condition P is true, WORD is copied to PC");
            if(LSB(z80->registers.AF) & P_FLAG) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;
        case JP_M:        debug_opcode(z80, (char *)"JP_M", (char *)"If condition S is true, WORD is copied to PC");
            if(LSB(z80->registers.AF) & S_FLAG) { M_JP(z80, z80cpm_memory); } else z80->registers.PC += 2; break;

        //214
        
        case DJNZ:        debug_opcode(z80, (char *)"DJNZ", (char *)"The B register is decremented, and if not zero, the signed value BYTE is added to PC. The jump is measured from the start of the instruction opcode.");
            SET_MSB(z80->registers.BC, MSB(z80->registers.BC)-1);
            if(MSB(z80->registers.BC) > 0) { 
                M_JR(z80, z80cpm_memory); 
            } 
                else z80->registers.PC++;
            break;
        
        case SCF:        debug_opcode(z80, (char *)"SCF", (char *)"Sets the carry flag");
            S(z80, C_FLAG); R(z80, N_FLAG | H_FLAG);break;
            
        case CCF:      debug_opcode(z80, (char *)"CCF", (char*)"Inverts the carry flag");
            SET_LSB(z80->registers.AF, LSB(z80->registers.AF) ^ C_FLAG);
            R(z80, N_FLAG | H_FLAG);
            SET_LSB(z80->registers.AF, LSB(z80->registers.AF) | ((LSB(z80->registers.AF) & C_FLAG) ? 0 : H_FLAG));
            break;

        case CPL:        debug_opcode(z80, (char *)"CPL", (char *)"The contents of A are inverted (one's complement)");
            SET_MSB(z80->registers.AF, ~MSB(z80->registers.AF));
            S(z80, N_FLAG | H_FLAG);
            break;


        case OUTA:        debug_opcode(z80, (char *)"OUTA", (char *)"The value of A is written on port BYTE");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);
            OutZ80(z80, z80cpm_memory, I | (z80->registers.AF & 0xFF00), MSB(z80->registers.AF));
            break;

        case INA:        debug_opcode(z80, (char *)"INA", (char *)"A byte from port BYTE is written to A");
            I = OpZ80(z80, z80cpm_memory, z80->registers.PC);
            SET_MSB(z80->registers.AF, InZ80(z80, I | (z80->registers.AF & 0xFF00)));
            break;

        //223
              
        case RLCA:          debug_opcode(z80, (char *)"RLCA", (char *)"The contents of A are rotated left one bit position. The content of bit 7 are copied to the carry flag and bit 0"); 
            I = MSB(z80->registers.AF) & 0x80 ? C_FLAG : 0;
            SET_MSB(z80->registers.AF, (MSB(z80->registers.AF) << 1) | I);
            SET_LSB(z80->registers.AF, (LSB(z80->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
            break;
 
        case RLA:           debug_opcode(z80, (char *)"RLA", (char *)"The contents of A are rotated left one bit position. The contents of bit 7 are copied to the carry flag and the previous contents of the carry flag are copied to bit 0");
            I = MSB(z80->registers.AF) & 0x80 ? C_FLAG : 0;
            SET_MSB(z80->registers.AF, (MSB(z80->registers.AF) << 1) | (LSB(z80->registers.AF) & C_FLAG));
            SET_LSB(z80->registers.AF, (LSB(z80->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
            break;
        case RRCA:          debug_opcode(z80, (char *)"RRCA", (char *)"The contents of A are rotated right one bit position. The contents of bit 0 are copied to the carry flag and bit 7");
            I = MSB(z80->registers.AF) & 0x01;
            SET_MSB(z80->registers.AF, (MSB(z80->registers.AF) >> 1) | (I ? 0x80 : 0));
            SET_LSB(z80->registers.AF, (LSB(z80->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I); 
            break;
        case RRA:           debug_opcode(z80, (char *)"RRA", (char *)"The contents of A are rotated right one bit position. The contents of bit 0 are copied to the carry flag and the previous contents of the carry flag are copied to bit 7");
            I = MSB(z80->registers.AF) & 0x01;
            SET_MSB(z80->registers.AF, (MSB(z80->registers.AF) >> 1) | (LSB(z80->registers.AF) & C_FLAG ? 0x80 : 0));
            SET_LSB(z80->registers.AF, (LSB(z80->registers.AF) & ~(C_FLAG | N_FLAG | H_FLAG)) | I);
            break;

        case RST00:       debug_opcode(z80, (char *)"RST00", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 00h"); 
            M_RST(z80, z80cpm_memory, 0x0000);break;      
        case RST08:       debug_opcode(z80, (char *)"RST08", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 08h"); 
            M_RST(z80, z80cpm_memory, 0x0008);break;
        case RST10:       debug_opcode(z80, (char *)"RST10", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 10h"); 
            M_RST(z80, z80cpm_memory, 0x0010);break;
        case RST18:       debug_opcode(z80, (char *)"RST18", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 18h"); 
            M_RST(z80, z80cpm_memory, 0x0018);break;
        case RST20:       debug_opcode(z80, (char *)"RST20", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 20h"); 
            M_RST(z80, z80cpm_memory, 0x0020);break;
        case RST28:       debug_opcode(z80, (char *)"RST28", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 28h");
            M_RST(z80, z80cpm_memory, 0x0028);break;
        case RST30:       debug_opcode(z80, (char *)"RST30", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 30h");
            M_RST(z80, z80cpm_memory, 0x0030);break;
        case RST38:       debug_opcode(z80, (char *)"RST38", (char *)"The current PC value plus one is pushed onto the stack, then is loaded with 38h"); 
            M_RST(z80, z80cpm_memory, 0x0038);break;
          
        case PUSH_AF:       debug_opcode(z80, (char *)"PUSH_AF", (char *)"SP is decremented and A is stored into the memory location pointed to by SP. SP is decremented again and F is stored pointed to by SP"); 
            M_PUSH(z80, z80cpm_memory,AF);break;
        case PUSH_BC:       debug_opcode(z80, (char *)"PUSH_BC", (char *)"SP is decremented and B is stored into the memory location pointed to by SP. SP is decremented again and C is stored pointed to by SP"); 
            M_PUSH(z80, z80cpm_memory,BC);break;
        case PUSH_DE:       debug_opcode(z80, (char *)"PUSH_DE", (char *)"SP is decremented and D is stored into the memory location pointed to by SP. SP is decremented again and E is stored pointed to by SP"); 
            M_PUSH(z80, z80cpm_memory,DE);break;
        case PUSH_HL:       debug_opcode(z80, (char *)"PUSH_HL", (char *)"SP is decremented and H is stored into the memory location pointed to by SP. SP is decremented again and L is stored pointed to by SP"); 
            M_PUSH(z80, z80cpm_memory,HL);break;
            
        //239

        case POP_AF:       debug_opcode(z80, (char *)"POP_AF", (char *)"The memory location pointed to by SP is stored into F and SP is incremented. The memory location pointed to by SP is stored into A and SP is incremented again"); 
           M_POP(z80, z80cpm_memory,AF);break;
        case POP_BC:       debug_opcode(z80, (char *)"POP_BC", (char *)"The memory location pointed to by SP is stored into C and SP is incremented. The memory location pointed to by SP is stored into B and SP is incremented again"); 
           M_POP(z80, z80cpm_memory,BC);break;
        case POP_DE:       debug_opcode(z80, (char *)"POP_DE", (char *)"The memory location pointed to by SP is stored into E and SP is incremented. The memory location pointed to by SP is stored into D and SP is incremented again"); 
           M_POP(z80, z80cpm_memory,DE);break;
        case POP_HL:       debug_opcode(z80, (char *)"POP_HL", (char *)"The memory location pointed to by SP is stored into L and SP is incremented. The memory location pointed to by SP is stored into H and SP is incremented again"); 
           M_POP(z80, z80cpm_memory,HL);break;

        case EX_AF_AFl:      debug_opcode(z80, (char *)"EX_AF_AFl", (char*)"Exchanges the 16bit contents of AF and AFl"); 
            J = z80->registers.AF;
            z80->registers.AF = z80->registers.AFl;
            z80->registers.AFl = J;
            break;  
        case EX_DE_HL:      debug_opcode(z80, (char *)"EX_DE_HL", (char*)"Exchanges the 16bit contents of DE and HL");
            J = z80->registers.DE;
            z80->registers.DE = z80->registers.HL;
            z80->registers.HL = J;
            break;
        case EX_xSP_HL:      debug_opcode(z80, (char *)"EX_xSP_HL", (char*)"Exchanges (SP) with L, and (SP+1) with H");
            J = z80->registers.HL;
            SET_WORD(z80->registers.HL, RdZ80(z80cpm_memory, z80->registers.SP), 
                                        RdZ80(z80cpm_memory, z80->registers.SP + 1)); 
            
            WrZ80(z80cpm_memory, z80->registers.SP, LSB(J));
            WrZ80(z80cpm_memory, z80->registers.SP+1, MSB(J));
            
            break;
        case EXX:      debug_opcode(z80, (char *)"EXX", (char*)"Exchanges the 16bit contents of BC, DE and HL with BC', DE' and HL'"); 
            J = z80->registers.BC;
            z80->registers.BC =z80->registers.BCl;
            z80->registers.BCl = J;

            J = z80->registers.DE;
            z80->registers.DE = z80->registers.DEl;
            z80->registers.DEl = J;
            
            J = z80->registers.HL;
            z80->registers.HL = z80->registers.HLl;
            z80->registers.HLl = J;
            break;



        case DI:      debug_opcode(z80, (char *)"DI", (char*)"Resets both interrupt flip-flops, thus prenting maskable interrups from triggering");
            if(z80->registers.IFF & IFF_EI) z80->registers.PC += z80->IBackup-1;
            z80->registers.IFF &= ~(IFF_1 | IFF_2 | IFF_EI);
            break;
        case EI:      debug_opcode(z80, (char *)"EI", (char*)"Sets both interrupt flip-flops, thus allowing maskable interrupts to occur. An interrupt will not occur. An interrupts will not occur until after the immediatedly following instruction.");
            if((z80->registers.IFF & (IFF_1 | IFF_EI)) == 0x0)
            {
                z80->registers.IFF |= IFF_2 | IFF_EI;
                z80->IBackup = z80->ICount;
                z80->ICount = 1;
            }
              break;

        case DAA:      debug_opcode(z80, (char *)"DAA", (char*)"Adjusts a for BCD addition and subtraction operations");
            J = MSB(z80->registers.AF);
            if(LSB(z80->registers.AF) & C_FLAG) J |= 256;
            if(LSB(z80->registers.AF) & H_FLAG) J |= 512;
            if(LSB(z80->registers.AF) & N_FLAG) J |= 1024;
            z80->registers.AF = DAATable[J];
            break;


        case HALT:      debug_opcode(z80, (char *)"HALT", (char*)"Suspends CPU operation until an interrupt or reset occurs");
            z80->registers.PC--;
            z80->registers.IFF |= IFF_HALT;
            z80->IBackup = 0;
            break;

        //253
