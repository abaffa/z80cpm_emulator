
//Main instructions
enum Codes
{
 NOP,		     LD_BC_WORD,		LD_xBC_A,	  	INC_BC,		  INC_B,		DEC_B,		LD_B_BYTE,		RLCA,		  EX_AF_AFl,	ADD_HL_BC,		LD_A_xBC,		  DEC_BC,		INC_C,		DEC_C,		LD_C_BYTE,	RRCA,		
 DJNZ,		    LD_DE_WORD,		LD_xDE_A,		  INC_DE,		  INC_D,		DEC_D,		LD_D_BYTE,		RLA,		  JR,				  ADD_HL_DE,		LD_A_xDE,		  DEC_DE,		INC_E,		DEC_E,		LD_E_BYTE,	RRA,		
 JR_NZ,		    LD_HL_WORD,		LD_xWORD_HL,	INC_HL,		  INC_H,		DEC_H,		LD_H_BYTE,		DAA,		  JR_Z,	    	ADD_HL_HL,		LD_HL_xWORD,	DEC_HL,		INC_L,		DEC_L,		LD_L_BYTE,	CPL,		
 JR_NC,		    LD_SP_WORD,		LD_xWORD_A,		INC_SP,		  INC_xHL,	DEC_xHL,	LD_xHL_BYTE,	SCF,		  JR_C,		  	ADD_HL_SP,		LD_A_xWORD,		DEC_SP,		INC_A,		DEC_A,		LD_A_BYTE,	CCF,		
 LD_B_B,	  	LD_B_C,		    LD_B_D,		    LD_B_E,		  LD_B_H,		LD_B_L,		LD_B_xHL,		  LD_B_A,		LD_C_B,			LD_C_C,		    LD_C_D,	    	LD_C_E,		LD_C_H,		LD_C_L,		LD_C_xHL,		LD_C_A,		
 LD_D_B,	  	LD_D_C,		    LD_D_D,	    	LD_D_E,		  LD_D_H,		LD_D_L,		LD_D_xHL,		  LD_D_A,		LD_E_B,			LD_E_C,		    LD_E_D,	    	LD_E_E,		LD_E_H,		LD_E_L,		LD_E_xHL,		LD_E_A,		
 LD_H_B,		  LD_H_C,		    LD_H_D,	    	LD_H_E,		  LD_H_H,		LD_H_L,		LD_H_xHL,		  LD_H_A,		LD_L_B,			LD_L_C,		    LD_L_D,		    LD_L_E,		LD_L_H,		LD_L_L,		LD_L_xHL,		LD_L_A,		
 LD_xHL_B,		LD_xHL_C,	  	LD_xHL_D,	  	LD_xHL_E,	  LD_xHL_H,	LD_xHL_L,	HALT,		      LD_xHL_A,	LD_A_B,			LD_A_C,	    	LD_A_D,	    	LD_A_E,		LD_A_H,		LD_A_L,		LD_A_xHL,		LD_A_A,		
 ADD_B,		    ADD_C,		    ADD_D,	    	ADD_E,		  ADD_H,		ADD_L,		ADD_xHL,		  ADD_A,		ADC_B,			ADC_C,	    	ADC_D,	    	ADC_E,		ADC_H,		ADC_L,		ADC_xHL,		ADC_A,		
 SUB_B,		    SUB_C,	    	SUB_D,	    	SUB_E,		  SUB_H,		SUB_L,		SUB_xHL,		  SUB_A,		SBC_B,			SBC_C,	    	SBC_D,	    	SBC_E,		SBC_H,		SBC_L,		SBC_xHL,		SBC_A,		
 AND_B,		    AND_C,		    AND_D,		    AND_E,		  AND_H,		AND_L,		AND_xHL,		  AND_A,		XOR_B,			XOR_C,		    XOR_D,		    XOR_E,		XOR_H,		XOR_L,		XOR_xHL,		XOR_A,		
 OR_B,		    OR_C,		      OR_D,		      OR_E,		    OR_H,		  OR_L,		  OR_xHL,		    OR_A,		  CP_B,			  CP_C,		      CP_D,	    	  CP_E,		  CP_H,		  CP_L,		  CP_xHL,		  CP_A,		
 RET_NZ,	  	POP_BC,		    JP_NZ,	    	JP,		      CALL_NZ,	PUSH_BC,	ADD_BYTE,		  RST00,		RET_Z,			RET,		      JP_Z,		      PFX_CB,		CALL_Z,		CALL,		  ADC_BYTE,		RST08,		
 RET_NC,	  	POP_DE,		    JP_NC,		    OUTA,		    CALL_NC,	PUSH_DE,	SUB_BYTE,		  RST10,		RET_C,			EXX,		      JP_C,		      INA,		  CALL_C,		PFX_DD,		SBC_BYTE,		RST18,		
 RET_PO,	  	POP_HL,		    JP_PO,		    EX_xSP_HL, CALL_PO,	PUSH_HL,	AND_BYTE,		  RST20,		RET_PE,			LD_PC_HL,		  JP_PE,	    	EX_DE_HL,	CALL_PE,	PFX_ED,		XOR_BYTE,		RST28,		
 RET_P,	    	POP_AF,		    JP_P,	      	DI,		      CALL_P,		PUSH_AF,	OR_BYTE,		  RST30,		RET_M,			LD_SP_HL,		  JP_M,	    	  EI,		    CALL_M,		PFX_FD,		CP_BYTE,		RST38
};  

//Bit instructions (CB)
enum CodesCB
{
 RLC_B,		    RLC_C,		RLC_D,		RLC_E,		RLC_H,		RLC_L,		RLC_xHL,		RLC_A,		
 RRC_B,		    RRC_C,		RRC_D,		RRC_E,		RRC_H,		RRC_L,		RRC_xHL,		RRC_A,		
 RL_B,		    RL_C,		RL_D,		RL_E,		RL_H,		RL_L,		RL_xHL,		    RL_A,		
 RR_B,		    RR_C,		RR_D,		RR_E,		RR_H,		RR_L,		RR_xHL,		    RR_A,		
 SLA_B,		    SLA_C,		SLA_D,		SLA_E,		SLA_H,		SLA_L,		SLA_xHL,		SLA_A,		
 SRA_B,		    SRA_C,		SRA_D,		SRA_E,		SRA_H,		SRA_L,		SRA_xHL,		SRA_A,		
 SLL_B,	    	SLL_C,		SLL_D,		SLL_E,		SLL_H,		SLL_L,		SLL_xHL,		SLL_A,		
 SRL_B,		    SRL_C,		SRL_D,		SRL_E,		SRL_H,		SRL_L,		SRL_xHL,		SRL_A,		
 BIT0_B,		BIT0_C,		BIT0_D,		BIT0_E,		BIT0_H,		BIT0_L,		BIT0_xHL,		BIT0_A,		
 BIT1_B,		BIT1_C,		BIT1_D,		BIT1_E,		BIT1_H,		BIT1_L,		BIT1_xHL,		BIT1_A,		
 BIT2_B,		BIT2_C,		BIT2_D,		BIT2_E,		BIT2_H,		BIT2_L,		BIT2_xHL,		BIT2_A,		
 BIT3_B,		BIT3_C,		BIT3_D,		BIT3_E,		BIT3_H,		BIT3_L,		BIT3_xHL,		BIT3_A,		
 BIT4_B,		BIT4_C,		BIT4_D,		BIT4_E,		BIT4_H,		BIT4_L,		BIT4_xHL,		BIT4_A,		
 BIT5_B,		BIT5_C,		BIT5_D,		BIT5_E,		BIT5_H,		BIT5_L,		BIT5_xHL,		BIT5_A,		
 BIT6_B,		BIT6_C,		BIT6_D,		BIT6_E,		BIT6_H,		BIT6_L,		BIT6_xHL,		BIT6_A,		
 BIT7_B,		BIT7_C,		BIT7_D,		BIT7_E,		BIT7_H,		BIT7_L,		BIT7_xHL,		BIT7_A,		
 RES0_B,		RES0_C,		RES0_D,		RES0_E,		RES0_H,		RES0_L,		RES0_xHL,		RES0_A,		
 RES1_B,		RES1_C,		RES1_D,		RES1_E,		RES1_H,		RES1_L,		RES1_xHL,		RES1_A,		
 RES2_B,		RES2_C,		RES2_D,		RES2_E,		RES2_H,		RES2_L,		RES2_xHL,		RES2_A,		
 RES3_B,		RES3_C,		RES3_D,		RES3_E,		RES3_H,		RES3_L,		RES3_xHL,		RES3_A,		
 RES4_B,		RES4_C,		RES4_D,		RES4_E,		RES4_H,		RES4_L,		RES4_xHL,		RES4_A,		
 RES5_B,		RES5_C,		RES5_D,		RES5_E,		RES5_H,		RES5_L,		RES5_xHL,		RES5_A,		
 RES6_B,		RES6_C,		RES6_D,		RES6_E,		RES6_H,		RES6_L,		RES6_xHL,		RES6_A,		
 RES7_B,		RES7_C,		RES7_D,		RES7_E,		RES7_H,		RES7_L,		RES7_xHL,		RES7_A,		 
 SET0_B,		SET0_C,		SET0_D,		SET0_E,		SET0_H,		SET0_L,		SET0_xHL,		SET0_A,		
 SET1_B,		SET1_C,		SET1_D,		SET1_E,		SET1_H,		SET1_L,		SET1_xHL,		SET1_A,		
 SET2_B,		SET2_C,		SET2_D,		SET2_E,		SET2_H,		SET2_L,		SET2_xHL,		SET2_A,		
 SET3_B,		SET3_C,		SET3_D,		SET3_E,		SET3_H,		SET3_L,		SET3_xHL,		SET3_A,		
 SET4_B,		SET4_C,		SET4_D,		SET4_E,		SET4_H,		SET4_L,		SET4_xHL,		SET4_A,		
 SET5_B,		SET5_C,		SET5_D,		SET5_E,		SET5_H,		SET5_L,		SET5_xHL,		SET5_A,		
 SET6_B,		SET6_C,		SET6_D,		SET6_E,		SET6_H,		SET6_L,		SET6_xHL,		SET6_A,		
 SET7_B,		SET7_C,		SET7_D,		SET7_E,		SET7_H,		SET7_L,		SET7_xHL,		SET7_A
};
 
 //Extended instructions (ED)
enum CodesED
{
 DB_00,			DB_01,			DB_02,			DB_03,			DB_04,			DB_05,			DB_06,			DB_07,			 DB_08,			DB_09,			DB_0A,			DB_0B,			DB_0C,			DB_0D,			DB_0E,			DB_0F,			
 DB_10,			DB_11,			DB_12,			DB_13,			DB_14,			DB_15,			DB_16,			DB_17,			 DB_18,			DB_19,			DB_1A,			DB_1B,			DB_1C,			DB_1D,			DB_1E,			DB_1F,			
 DB_20,			DB_21,			DB_22,			DB_23,			DB_24,			DB_25,			DB_26,			DB_27,			 DB_28,			DB_29,			DB_2A,			DB_2B,			DB_2C,			DB_2D,			DB_2E,			DB_2F,			
 DB_30,			DB_31,			DB_32,			DB_33,			DB_34,			DB_35,			DB_36,			DB_37,			 DB_38,			DB_39,			DB_3A,			DB_3B,			DB_3C,			DB_3D,			DB_3E,			DB_3F,			
 IN_B_xC,		OUT_xC_B,		SBC_HL_BC,		LD_xWORDe_BC,	NEG,			RETN,			IM_0,			LD_I_A,			 IN_C_xC,		OUT_xC_C,		ADC_HL_BC,		LD_BC_xWORDe,	DB_4C,			RETI,			DB_,			LD_R_A,			
 IN_D_xC,		OUT_xC_D,		SBC_HL_DE,		LD_xWORDe_DE,	DB_54,			DB_55,			IM_1,			LD_A_I,			 IN_E_xC,		OUT_xC_E,		ADC_HL_DE,		LD_DE_xWORDe,	DB_5C,			DB_5D,			IM_2,			LD_A_R,			
 IN_H_xC,		OUT_xC_H,		SBC_HL_HL,		LD_xWORDe_HL,	DB_64,			DB_65,			DB_66,			RRD,			 IN_L_xC,		OUT_xC_L,		ADC_HL_HL,		LD_HL_xWORDe,	DB_6C,			DB_6D,			DB_6E,			RLD,			
 IN_F_xC,		DB_71,			SBC_HL_SP,		LD_xWORDe_SP,	DB_74,			DB_75,			DB_76,			DB_77,			 IN_A_xC,		OUT_xC_A,		ADC_HL_SP,		LD_SP_xWORDe,	DB_7C,			DB_7D,			DB_7E,			DB_7F,			
 DB_80,			DB_81,			DB_82,			DB_83,			DB_84,			DB_85,			DB_86,			DB_87,			 DB_88,			DB_89,			DB_8A,			DB_8B,			DB_8C,			DB_8D,			DB_8E,			DB_8F,			
 DB_90,			DB_91,			DB_92,			DB_93,			DB_94,			DB_95,			DB_96,			DB_97,			 DB_98,			DB_99,			DB_9A,			DB_9B,			DB_9C,			DB_9D,			DB_9E,			DB_9F,			
 LDI,			CPI,			INI,			OUTI,			DB_A4,			DB_A5,			DB_A6,			DB_A7,			 LDD,			CPD,			IND,			OUTD,			DB_AC,			DB_AD,			DB_AE,			DB_AF,			
 LDIR,			CPIR,			INIR,			OTIR,			DB_B4,			DB_B5,			DB_B6,			DB_B7,			 LDDR,			CPDR,			INDR,			OTDR,			DB_BC,			DB_BD,			DB_BE,			DB_BF,			
 DB_C0,			DB_C1,			DB_C2,			DB_C3,			DB_C4,			DB_C5,			DB_C6,			DB_C7,			 DB_C8,			DB_C9,			DB_CA,			DB_CB,			DB_CC,			DB_CD,			DB_CE,			DB_CF,			
 DB_D0,			DB_D1,			DB_D2,			DB_D3,			DB_D4,			DB_D5,			DB_D6,			DB_D7,			 DB_D8,			DB_D9,			DB_DA,			DB_DB,			DB_DC,			DB_DD,			DB_DE,			DB_DF,			
 DB_E0,			DB_E1,			DB_E2,			DB_E3,			DB_E4,			DB_E5,			DB_E6,			DB_E7,			 DB_E8,			DB_E9,			DB_EA,			DB_EB,			DB_EC,			DB_ED,			DB_EE,			DB_EF,			
 DB_F0,			DB_F1,			DB_F2,			DB_F3,			DB_F4,			DB_F5,			DB_F6,			DB_F7,			 DB_F8,			DB_F9,			DB_FA,			DB_FB,			DB_FC,			DB_FD,			DB_FE,			DB_FF
};



#define M_ADD(cpu, b)      \
  J = MSB(cpu->registers.AF) + b;     \
  SET_LSB(cpu->registers.AF,          \
    (~(MSB(cpu->registers.AF) ^ b) & (b ^ LSB(J)) & 0x80 ? V_FLAG : 0) | \
    MSB(J) | ZSTable[LSB(J)] |                        \
    ((MSB(cpu->registers.AF) ^ b ^ LSB(J)) & H_FLAG));               \
    SET_MSB(cpu->registers.AF, LSB(J))

#define M_ADC(cpu, Rg)      \
  J = MSB(cpu->registers.AF) + Rg + (LSB(cpu->registers.AF) & C_FLAG); \
  SET_LSB(cpu->registers.AF,                           \
    (~(MSB(cpu->registers.AF) ^ Rg) & (Rg ^ LSB(J)) & 0x80 ? V_FLAG : 0) | \
    MSB(J) | ZSTable[LSB(J)] |              \
    ((MSB(cpu->registers.AF) ^ Rg ^ LSB(J)) & H_FLAG));     \
  SET_MSB(cpu->registers.AF, LSB(J))

#define M_ADDW(cpu, Rg1, Rg2) \
  J = (cpu->registers.Rg1 + cpu->registers.Rg2) & 0xFFFF; \
  SET_LSB(cpu->registers.AF,                             \
    (LSB(cpu->registers.AF) & ~(H_FLAG | N_FLAG | C_FLAG)) |                 \
    ((cpu->registers.Rg1 ^ cpu->registers.Rg2 ^ J) & 0x1000? H_FLAG : 0)|          \
    (((long)cpu->registers.Rg1 + (long)cpu->registers.Rg2) & 0x10000 ? C_FLAG : 0)); \
  cpu->registers.Rg1 = J

#define M_ADCW(cpu, Rg)      \
  I = LSB(cpu->registers.AF) & C_FLAG;  \
  J = (cpu->registers.HL + cpu->registers.Rg + I) & 0xFFFF;           \
  SET_LSB(cpu->registers.AF,                                                  \
    (((long)cpu->registers.HL + (long)cpu->registers.Rg + (long)I) & 0x10000 ? C_FLAG : 0) | \
    (~(cpu->registers.HL ^ cpu->registers.Rg) & (cpu->registers.Rg ^ J) & 0x8000 ? V_FLAG : 0) |      \
    ((cpu->registers.HL ^ cpu->registers.Rg ^ J) & 0x1000 ? H_FLAG : 0) |                  \
    (J ? 0 : Z_FLAG) | (MSB(J) & S_FLAG));        \
  cpu->registers.HL = J



#define M_SUB(cpu, Rg)      \
  J = MSB(cpu->registers.AF) - Rg;    \
  SET_LSB(cpu->registers.AF,           \
    ((MSB(cpu->registers.AF) ^ Rg) & ((MSB(cpu->registers.AF) ^ LSB(J)) & 0x80 ? V_FLAG : 0) | \
    N_FLAG | -MSB(J) | ZSTable[LSB(J)] |                      \
    ((MSB(cpu->registers.AF) ^ Rg ^ LSB(J)) & H_FLAG)));                     \
  SET_MSB(cpu->registers.AF, LSB(J))

#define M_SBC(cpu, Rg)      \
  J = MSB(cpu->registers.AF) - Rg - (LSB(cpu->registers.AF) & C_FLAG); \
  SET_LSB(cpu->registers.AF,                           \
    ((MSB(cpu->registers.AF) ^ Rg) & (MSB(cpu->registers.AF) ^ LSB(J)) & 0x80 ? V_FLAG : 0) | \
    N_FLAG | -MSB(J) | ZSTable[LSB(J)] |      \
    ((MSB(cpu->registers.AF) ^ Rg ^ LSB(J)) & H_FLAG));     \
  SET_MSB(cpu->registers.AF, LSB(J));

#define M_SBCW(cpu, Rg)      \
  I = LSB(cpu->registers.AF) & C_FLAG;               \
  J = (cpu->registers.HL - cpu->registers.Rg - I) & 0xFFFF;     \
  SET_LSB(cpu->registers.AF,                                   \
    N_FLAG |                                                    \
    (((long)cpu->registers.HL - (long)cpu->registers.Rg - (long)I) & 0x10000 ? C_FLAG : 0)| \
    ((cpu->registers.HL ^ cpu->registers.Rg) & (cpu->registers.HL ^ J) & 0x8000 ? V_FLAG : 0)|        \
    ((cpu->registers.HL ^ cpu->registers.Rg ^ J) & 0x1000 ? H_FLAG : 0)|                  \
    (J ? 0 : Z_FLAG) | (MSB(J) & S_FLAG));                            \
  cpu->registers.HL = J

/*
#define M_INC(cpu, Rg)       \
  Rg++;                 \
  SET_LSB(cpu->registers.AF,            \
            (LSB(cpu->registers.AF) & C_FLAG) | \
            ZSTable[Rg] | \
            (Rg == 0x80 ? V_FLAG : 0) | \
            (Rg & 0x0F ? 0 : H_FLAG))
*/

#define M_INC_H(cpu, Rg)    \
  SET_MSB(Rg, MSB(Rg)+1);                   \
  SET_LSB(cpu->registers.AF,            \
            (LSB(cpu->registers.AF) & C_FLAG) | \
            ZSTable[MSB(Rg)] | \
            (Rg == 0x80 ? V_FLAG : 0) | \
            (Rg & 0x0F ? 0 : H_FLAG))

#define M_INC_L(cpu, Rg)    \
  SET_LSB(Rg, LSB(Rg)+1);                   \
  SET_LSB(cpu->registers.AF,            \
            (LSB(cpu->registers.AF) & C_FLAG) | \
            ZSTable[LSB(Rg)] | \
            (Rg == 0x80 ? V_FLAG : 0) | \
            (Rg & 0x0F ? 0 : H_FLAG));

/*
#define M_DEC(cpu, Rg)       \
  Rg--;                 \
  SET_LSB(cpu->registers.AF,            \
    (N_FLAG | \
    (LSB(cpu->registers.AF) & C_FLAG) | \
    ZSTable[Rg] | \
    (Rg == 0x7F ? V_FLAG : 0) | \
    ((Rg & 0x0F) == 0x0F ? H_FLAG : 0)));
*/

#define M_DEC_H(cpu, Rg)       \
  SET_MSB(Rg, MSB(Rg)-1);                 \
  SET_LSB(cpu->registers.AF,            \
    (N_FLAG | \
    (LSB(cpu->registers.AF) & C_FLAG) | \
    ZSTable[MSB(Rg)] | \
    (Rg == 0x7F ? V_FLAG : 0) | \
    ((Rg & 0x0F) == 0x0F ? H_FLAG : 0)));

#define M_DEC_L(cpu, Rg)       \
  SET_LSB(Rg, LSB(Rg)-1);                 \
  SET_LSB(cpu->registers.AF,            \
    (N_FLAG | (LSB(cpu->registers.AF) & C_FLAG) | ZSTable[LSB(Rg)] | \
    (Rg == 0x7F ? V_FLAG : 0) | ((Rg & 0x0F) == 0x0F ? H_FLAG : 0)))

#define M_AND(cpu, Rg)   \
    SET_MSB(cpu->registers.AF, MSB(cpu->registers.AF) & Rg);  \
    SET_LSB(cpu->registers.AF, H_FLAG | PZSTable[MSB(cpu->registers.AF)])

#define M_OR(cpu, Rg)    \
  SET_MSB(cpu->registers.AF, MSB(cpu->registers.AF) | Rg); \
  SET_LSB(cpu->registers.AF, PZSTable[MSB(cpu->registers.AF)])

#define M_XOR(cpu, Rg)    \
  SET_MSB(cpu->registers.AF, MSB(cpu->registers.AF) ^ Rg); \
  SET_LSB(cpu->registers.AF, PZSTable[MSB(cpu->registers.AF)])

#define M_CP(cpu, Rg)       \
  J = MSB(cpu->registers.AF) - Rg;    \
  SET_LSB(cpu->registers.AF,          \
    ((MSB(cpu->registers.AF) ^ Rg) & (MSB(cpu->registers.AF) ^ LSB(J)) & 0x80 ? V_FLAG : 0) | \
    N_FLAG | - MSB(J) | ZSTable[LSB(J)] |                       \
    ((MSB(cpu->registers.AF) ^ Rg ^ LSB(J)) & H_FLAG))

#define M_CALL(cpu, mem)         \
    SET_LSB(J, this->OpZ80(mem, cpu->registers.PC)); \
    SET_MSB(J, this->OpZ80(mem, cpu->registers.PC)); \
	this->WrZ80(mem, cpu->registers.SP - 1, MSB(cpu->registers.PC)); \
    this->WrZ80(mem, cpu->registers.SP - 2, LSB(cpu->registers.PC)); \
    cpu->registers.SP -= 2; \
    cpu->registers.PC = J; \
    this->JumpZ80(J)

#define M_RET(cpu, mem)         \
    SET_LSB(cpu->registers.PC, this->RdZ80(mem, cpu->registers.SP));  \
    SET_MSB(cpu->registers.PC, this->RdZ80(mem, cpu->registers.SP + 1));  \
    cpu->registers.SP += 2; \
    this->JumpZ80( cpu->registers.PC)


#define M_JR(cpu, mem)         \
    cpu->registers.PC += (signed char)this->RdZ80(mem, cpu->registers.PC) + 1;  \
    this->JumpZ80( cpu->registers.PC)

#define M_JP(cpu, mem)         \
    SET_LSB(J, this->OpZ80(mem, cpu->registers.PC));  \
    SET_MSB(J, this->OpZ80(mem, cpu->registers.PC));    \
    cpu->registers.PC = J;          \
    this->JumpZ80( cpu->registers.PC)

#define S(cpu, Fl) SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | LSB(Fl))
#define R(cpu, Fl) SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) & (~LSB(Fl)))

#define M_RST(cpu, mem, Ad)      \
  this->WrZ80(mem, cpu->registers.SP - 1, MSB(cpu->registers.PC)); \
  this->WrZ80(mem, cpu->registers.SP - 2, LSB(cpu->registers.PC)); \
  cpu->registers.SP -= 2; \
  cpu->registers.PC = Ad; \
  this->JumpZ80( Ad)



#define M_PUSH(cpu, mem, Rg)     \
  this->WrZ80(mem, cpu->registers.SP - 1, MSB(cpu->registers.Rg)); \
  this->WrZ80(mem, cpu->registers.SP - 2, LSB(cpu->registers.Rg)); \
  cpu->registers.SP -= 2


#define M_POP(cpu, mem, Rg)      \
  SET_LSB(cpu->registers.Rg, this->RdZ80(mem, cpu->registers.SP)); \
  SET_MSB(cpu->registers.Rg, this->RdZ80(mem, cpu->registers.SP + 1)); \
  cpu->registers.SP += 2 


#define M_RLC(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, Rg >> 7); \
    Rg = (Rg << 1) | LSB(cpu->registers.AF); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[Rg])

#define M_RLC_H(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, MSB(Rg) >> 7); \
    SET_MSB(Rg, (MSB(Rg) << 1) | LSB(cpu->registers.AF)); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[MSB(Rg)])

#define M_RLC_L(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, LSB(Rg) >> 7); \
    SET_LSB(Rg, (LSB(Rg) << 1) | LSB(cpu->registers.AF)); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[LSB(Rg)])


#define M_RRC(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, Rg & 0x01); \
    Rg = (Rg >> 1) | (LSB(cpu->registers.AF) << 7); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[Rg])

#define M_RRC_H(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, MSB(Rg) & 0x01); \
    SET_MSB(Rg, (MSB(Rg) >> 1) | (LSB(cpu->registers.AF) << 7)); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[MSB(Rg)])
    
#define M_RRC_L(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, LSB(Rg) & 0x01); \
    SET_LSB(Rg, (LSB(Rg) >> 1) | (LSB(cpu->registers.AF) << 7)); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[LSB(Rg)])

#define M_RL(cpu, Rg)       \
    if(Rg & 0x80)          \
    {                    \
        Rg = (Rg << 1) | (LSB(cpu->registers.AF) & C_FLAG); \
        SET_LSB(cpu->registers.AF, PZSTable[Rg] | C_FLAG); \
    }                    \
    else                 \
    {                    \
        Rg = (Rg << 1) | (LSB(cpu->registers.AF) & C_FLAG); \
        SET_LSB(cpu->registers.AF, PZSTable[Rg]);        \
    }

#define M_RL_H(cpu, Rg)       \
    if(MSB(Rg) & 0x80)          \
    {                    \
        SET_MSB(Rg, (MSB(Rg) << 1) | (LSB(cpu->registers.AF) & C_FLAG)); \
        SET_LSB(cpu->registers.AF, PZSTable[MSB(Rg)] | C_FLAG); \
    }                    \
    else                 \
    {                    \
        SET_MSB(Rg, (MSB(Rg) << 1) | (LSB(cpu->registers.AF) & C_FLAG)); \
        SET_LSB(cpu->registers.AF, PZSTable[MSB(Rg)]);        \
    }  

#define M_RL_L(cpu, Rg)       \
    if(LSB(Rg) & 0x80)          \
    {                    \
        SET_LSB(Rg, (LSB(Rg) << 1) | (LSB(cpu->registers.AF) & C_FLAG)); \
        SET_LSB(cpu->registers.AF, PZSTable[LSB(Rg)] | C_FLAG); \
    }                    \
    else                 \
    {                    \
        SET_LSB(Rg, (LSB(Rg) << 1) | (LSB(cpu->registers.AF) & C_FLAG)); \
        SET_LSB(cpu->registers.AF, PZSTable[LSB(Rg)]);        \
    }    

  
#define M_RR(cpu, Rg)       \
    if(Rg & 0x01)          \
    {                    \
        Rg = (Rg >> 1) | (LSB(cpu->registers.AF) << 7);     \
        SET_LSB(cpu->registers.AF, PZSTable[Rg] | C_FLAG); \
    }                    \
    else                 \
    {                    \
        Rg = (Rg >> 1) | (LSB(cpu->registers.AF) << 7);     \
        SET_LSB(cpu->registers.AF, PZSTable[Rg]);        \
    }

  
#define M_RR_H(cpu, Rg)       \
    if(MSB(Rg) & 0x01)          \
    {                    \
        SET_MSB(Rg, (MSB(Rg) >> 1) | (LSB(cpu->registers.AF) << 7));     \
        SET_LSB(cpu->registers.AF, PZSTable[MSB(Rg)] | C_FLAG); \
    }                    \
    else                 \
    {                    \
        SET_MSB(Rg, (MSB(Rg) >> 1) | (LSB(cpu->registers.AF) << 7));     \
        SET_LSB(cpu->registers.AF, PZSTable[MSB(Rg)]);        \
    }    
  

#define M_RR_L(cpu, Rg)       \
    if(LSB(Rg) & 0x01)          \
    {                    \
        SET_LSB(Rg, (LSB(Rg) >> 1) | (LSB(cpu->registers.AF) << 7));     \
        SET_LSB(cpu->registers.AF, PZSTable[LSB(Rg)] | C_FLAG); \
    }                    \
    else                 \
    {                    \
        SET_LSB(Rg, (LSB(Rg) >> 1) | (LSB(cpu->registers.AF) << 7));     \
        SET_LSB(cpu->registers.AF, PZSTable[LSB(Rg)]);        \
    }    


#define M_SLA(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, Rg >> 7); \
    Rg <<= 1; \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[Rg])
    
#define M_SLA_H(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, MSB(Rg) >> 7); \
    SET_MSB(Rg, MSB(Rg) << 1); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[MSB(Rg)])
        
#define M_SLA_L(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, LSB(Rg) >> 7); \
    SET_LSB(Rg, LSB(Rg) << 1); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[LSB(Rg)])
    

#define M_SRA(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, Rg & C_FLAG); \
    Rg= (Rg >> 1) | (Rg & 0x80); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[Rg])

#define M_SRA_H(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, MSB(Rg) & C_FLAG); \
    SET_MSB(Rg, (MSB(Rg) >> 1) | (MSB(Rg) & 0x80)); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[MSB(Rg)])
  
#define M_SRA_L(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, LSB(Rg) & C_FLAG); \
      SET_LSB(Rg, (LSB(Rg) >> 1) | (LSB(Rg) & 0x80)); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[LSB(Rg)])


#define M_SLL(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, Rg >> 7); \
    Rg = (Rg << 1) | 0x01; \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[Rg])

#define M_SLL_H(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, MSB(Rg) >> 7); \
    SET_MSB(Rg, (MSB(Rg) << 1) | 0x01); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[MSB(Rg)])  
  
#define M_SLL_L(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, LSB(Rg) >> 7); \
    SET_LSB(Rg, (LSB(Rg) << 1) | 0x01); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[LSB(Rg)])  


#define M_SRL(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, Rg & 0x01); \
    Rg >>= 1; \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[Rg])
  
#define M_SRL_H(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, MSB(Rg) & 0x01); \
    SET_MSB(Rg, MSB(Rg) >> 1); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[MSB(Rg)])
    
#define M_SRL_L(cpu, Rg)      \
    SET_LSB(cpu->registers.AF, LSB(Rg) & 0x01); \
    SET_LSB(Rg, LSB(Rg) >> 1); \
    SET_LSB(cpu->registers.AF, LSB(cpu->registers.AF) | PZSTable[LSB(Rg)])

#define M_BIT(cpu, Bit, Rg)  \
    SET_LSB(cpu->registers.AF, (LSB(cpu->registers.AF) & C_FLAG) | H_FLAG | PZSTable[Rg & (1 << Bit)])

#define M_SET(cpu, Bit, Rg) Rg |= (1 << Bit)
#define M_SET_H(cpu, Bit, Rg) SET_MSB(Rg, MSB(Rg) | (1 << Bit))
#define M_SET_L(cpu, Bit, Rg) SET_LSB(Rg, LSB(Rg) | (1 << Bit))

#define M_RES(cpu, Bit,Rg) Rg &= ~(1 << Bit)
#define M_RES_H(cpu, Bit,Rg) SET_MSB(Rg, MSB(Rg) & ~(1 << Bit))
#define M_RES_L(cpu, Bit,Rg) SET_LSB(Rg, LSB(Rg) & ~(1 << Bit))

#define M_LDWORD(cpu, mem, Rg)  \
    SET_WORD(Rg, this->RdZ80(mem, cpu->registers.PC),  \
     this->RdZ80(mem, cpu->registers.PC + 1)); \
     cpu->registers.PC += 2

      
