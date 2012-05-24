typedef enum {
	UNDEF,
	MOV,
	iMOV,
	dMOV,
	sMOV,
	oMOV,
	ADD,
	iADD,
	dADD,
	sADD,
	oADD,
	iADDC,
	dADDC,
	SUB,
	iSUB,
	dSUB,
	sSUB,
	oSUB,
	iSUBC,
	dSUBC,
	MUL,
	iMUL,
	dMUL,
	sMUL,
	oMUL,
	iMULC,
	dMULC,
	DIV,
	iDIV,
	dDIV,
	sDIV,
	oDIV,
	iDIVC,
	dDIVC,
	JG,
	iJG,
	dJG,
	sJG,
	oJG,
	iJGC,
	dJGC,
	JL,
	iJL,
	dJL,
	sJL,
	oJL,
	iJLC,
	dJLC,
	JE,
	iJE,
	dJE,
	sJE,
	oJE,
	iJEC,
	dJEC,
	JNE,
	iJNE,
	dJNE,
	sJNE,
	oJNE,
	iJNEC,
	dJNEC,
	RET,
	iRET,
	dRET,
	sRET,
	oRET,
	THCODE,
	NOP,
	WRITE,
	iWRITE,
	dWRITE,
	sWRITE,
	oWRITE,
	FRUSH,
	JMP,
	LET,
	SET,
	FUNCSET,
	CALL,
	iCALL,
	dCALL,
	sCALL,
	oCALL,
	SELFCALL,
	iSELFCALL,
	dSELFCALL,
	sSELFCALL,
	oSELFCALL,
	SHIFT,
	iSHIFT,
	dSHIFT,
	sSHIFT,
	oSHIFT,
	PUSH,
	iPUSH,
	dPUSH,
	sPUSH,
	oPUSH,
	NEW,
	A_MOV,
	B_MOV,
	C_MOV,
	D_MOV,
	A_iMOV,
	A_dMOV,
	A_sMOV,
	A_oMOV,
	B_iMOV,
	B_dMOV,
	B_sMOV,
	B_oMOV,
	C_iMOV,
	C_dMOV,
	C_sMOV,
	C_oMOV,
	D_iMOV,
	D_dMOV,
	D_sMOV,
	D_oMOV,
	AB_ADD,
	AC_ADD,
	AD_ADD,
	BC_ADD,
	BD_ADD,
	CD_ADD,
	AB_iADD,
	AB_dADD,
	AB_sADD,
	AB_oADD,
	AC_iADD,
	AC_dADD,
	AC_sADD,
	AC_oADD,
	AD_iADD,
	AD_dADD,
	AD_sADD,
	AD_oADD,
	BC_iADD,
	BC_dADD,
	BC_sADD,
	BC_oADD,
	BD_iADD,
	BD_dADD,
	BD_sADD,
	BD_oADD,
	CD_iADD,
	CD_dADD,
	CD_sADD,
	CD_oADD,
	AB_iADDC,
	AB_dADDC,
	AB_sADDC,
	AB_oADDC,
	AC_iADDC,
	AC_dADDC,
	AC_sADDC,
	AC_oADDC,
	AD_iADDC,
	AD_dADDC,
	AD_sADDC,
	AD_oADDC,
	BC_iADDC,
	BC_dADDC,
	BC_sADDC,
	BC_oADDC,
	BD_iADDC,
	BD_dADDC,
	BD_sADDC,
	BD_oADDC,
	CD_iADDC,
	CD_dADDC,
	CD_sADDC,
	CD_oADDC,
	AB_SUB,
	AC_SUB,
	AD_SUB,
	BC_SUB,
	BD_SUB,
	CD_SUB,
	AB_iSUB,
	AB_dSUB,
	AB_sSUB,
	AB_oSUB,
	AC_iSUB,
	AC_dSUB,
	AC_sSUB,
	AC_oSUB,
	AD_iSUB,
	AD_dSUB,
	AD_sSUB,
	AD_oSUB,
	BC_iSUB,
	BC_dSUB,
	BC_sSUB,
	BC_oSUB,
	BD_iSUB,
	BD_dSUB,
	BD_sSUB,
	BD_oSUB,
	CD_iSUB,
	CD_dSUB,
	CD_sSUB,
	CD_oSUB,
	AB_iSUBC,
	AB_dSUBC,
	AB_sSUBC,
	AB_oSUBC,
	AC_iSUBC,
	AC_dSUBC,
	AC_sSUBC,
	AC_oSUBC,
	AD_iSUBC,
	AD_dSUBC,
	AD_sSUBC,
	AD_oSUBC,
	BC_iSUBC,
	BC_dSUBC,
	BC_sSUBC,
	BC_oSUBC,
	BD_iSUBC,
	BD_dSUBC,
	BD_sSUBC,
	BD_oSUBC,
	CD_iSUBC,
	CD_dSUBC,
	CD_sSUBC,
	CD_oSUBC,
	AB_MUL,
	AC_MUL,
	AD_MUL,
	BC_MUL,
	BD_MUL,
	CD_MUL,
	AB_iMUL,
	AB_dMUL,
	AB_sMUL,
	AB_oMUL,
	AC_iMUL,
	AC_dMUL,
	AC_sMUL,
	AC_oMUL,
	AD_iMUL,
	AD_dMUL,
	AD_sMUL,
	AD_oMUL,
	BC_iMUL,
	BC_dMUL,
	BC_sMUL,
	BC_oMUL,
	BD_iMUL,
	BD_dMUL,
	BD_sMUL,
	BD_oMUL,
	CD_iMUL,
	CD_dMUL,
	CD_sMUL,
	CD_oMUL,
	AB_iMULC,
	AB_dMULC,
	AB_sMULC,
	AB_oMULC,
	AC_iMULC,
	AC_dMULC,
	AC_sMULC,
	AC_oMULC,
	AD_iMULC,
	AD_dMULC,
	AD_sMULC,
	AD_oMULC,
	BC_iMULC,
	BC_dMULC,
	BC_sMULC,
	BC_oMULC,
	BD_iMULC,
	BD_dMULC,
	BD_sMULC,
	BD_oMULC,
	CD_iMULC,
	CD_dMULC,
	CD_sMULC,
	CD_oMULC,
	AB_DIV,
	AC_DIV,
	AD_DIV,
	BC_DIV,
	BD_DIV,
	CD_DIV,
	AB_iDIV,
	AB_dDIV,
	AB_sDIV,
	AB_oDIV,
	AC_iDIV,
	AC_dDIV,
	AC_sDIV,
	AC_oDIV,
	AD_iDIV,
	AD_dDIV,
	AD_sDIV,
	AD_oDIV,
	BC_iDIV,
	BC_dDIV,
	BC_sDIV,
	BC_oDIV,
	BD_iDIV,
	BD_dDIV,
	BD_sDIV,
	BD_oDIV,
	CD_iDIV,
	CD_dDIV,
	CD_sDIV,
	CD_oDIV,
	AB_iDIVC,
	AB_dDIVC,
	AB_sDIVC,
	AB_oDIVC,
	AC_iDIVC,
	AC_dDIVC,
	AC_sDIVC,
	AC_oDIVC,
	AD_iDIVC,
	AD_dDIVC,
	AD_sDIVC,
	AD_oDIVC,
	BC_iDIVC,
	BC_dDIVC,
	BC_sDIVC,
	BC_oDIVC,
	BD_iDIVC,
	BD_dDIVC,
	BD_sDIVC,
	BD_oDIVC,
	CD_iDIVC,
	CD_dDIVC,
	CD_sDIVC,
	CD_oDIVC,
	A_JG,
	B_JG,
	C_JG,
	D_JG,
	A_iJG,
	A_dJG,
	A_sJG,
	A_oJG,
	B_iJG,
	B_dJG,
	B_sJG,
	B_oJG,
	C_iJG,
	C_dJG,
	C_sJG,
	C_oJG,
	D_iJG,
	D_dJG,
	D_sJG,
	D_oJG,
	A_iJGC,
	A_dJGC,
	A_sJGC,
	A_oJGC,
	B_iJGC,
	B_dJGC,
	B_sJGC,
	B_oJGC,
	C_iJGC,
	C_dJGC,
	C_sJGC,
	C_oJGC,
	D_iJGC,
	D_dJGC,
	D_sJGC,
	D_oJGC,
	A_JL,
	B_JL,
	C_JL,
	D_JL,
	A_iJL,
	A_dJL,
	A_sJL,
	A_oJL,
	B_iJL,
	B_dJL,
	B_sJL,
	B_oJL,
	C_iJL,
	C_dJL,
	C_sJL,
	C_oJL,
	D_iJL,
	D_dJL,
	D_sJL,
	D_oJL,
	A_iJLC,
	A_dJLC,
	A_sJLC,
	A_oJLC,
	B_iJLC,
	B_dJLC,
	B_sJLC,
	B_oJLC,
	C_iJLC,
	C_dJLC,
	C_sJLC,
	C_oJLC,
	D_iJLC,
	D_dJLC,
	D_sJLC,
	D_oJLC,
	A_JE,
	B_JE,
	C_JE,
	D_JE,
	A_iJE,
	A_dJE,
	A_sJE,
	A_oJE,
	B_iJE,
	B_dJE,
	B_sJE,
	B_oJE,
	C_iJE,
	C_dJE,
	C_sJE,
	C_oJE,
	D_iJE,
	D_dJE,
	D_sJE,
	D_oJE,
	A_iJEC,
	A_dJEC,
	A_sJEC,
	A_oJEC,
	B_iJEC,
	B_dJEC,
	B_sJEC,
	B_oJEC,
	C_iJEC,
	C_dJEC,
	C_sJEC,
	C_oJEC,
	D_iJEC,
	D_dJEC,
	D_sJEC,
	D_oJEC,
	A_JNE,
	B_JNE,
	C_JNE,
	D_JNE,
	A_iJNE,
	A_dJNE,
	A_sJNE,
	A_oJNE,
	B_iJNE,
	B_dJNE,
	B_sJNE,
	B_oJNE,
	C_iJNE,
	C_dJNE,
	C_sJNE,
	C_oJNE,
	D_iJNE,
	D_dJNE,
	D_sJNE,
	D_oJNE,
	A_iJNEC,
	A_dJNEC,
	A_sJNEC,
	A_oJNEC,
	B_iJNEC,
	B_dJNEC,
	B_sJNEC,
	B_oJNEC,
	C_iJNEC,
	C_dJNEC,
	C_sJNEC,
	C_oJNEC,
	D_iJNEC,
	D_dJNEC,
	D_sJNEC,
	D_oJNEC,
	A_RET,
	B_RET,
	C_RET,
	D_RET,
	A_iRET,
	A_dRET,
	A_sRET,
	A_oRET,
	B_iRET,
	B_dRET,
	B_sRET,
	B_oRET,
	C_iRET,
	C_dRET,
	C_sRET,
	C_oRET,
	D_iRET,
	D_dRET,
	D_sRET,
	D_oRET,
	A_PUSH,
	B_PUSH,
	C_PUSH,
	D_PUSH,
	A_iPUSH,
	A_dPUSH,
	A_sPUSH,
	A_oPUSH,
	B_iPUSH,
	B_dPUSH,
	B_sPUSH,
	B_oPUSH,
	C_iPUSH,
	C_dPUSH,
	C_sPUSH,
	C_oPUSH,
	D_iPUSH,
	D_dPUSH,
	D_sPUSH,
	D_oPUSH,
} GPerlOpCode;

typedef struct _GPerlCodeInfo {
	GPerlOpCode code;
	const char *name;
} GPerlCodeInfo;
