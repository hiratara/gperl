typedef enum {
	Return,
	Add,
	Sub,
	Mul,
	Div,
	Greater,
	Less,
	AddEqual,
	SubEqual,
	MulEqual,
	DivEqual,
	StringAdd,
	GreaterEqual,
	LessEqual,
	EqualEqual,
	NotEqual,
	Inc,
	Dec,
	LeftShift,
	RightShift,
	VarDecl,
	FunctionDecl,
	Assign,
	IsNot,
	BuiltinFunc,
	IfStmt,
	ElseStmt,
	Comma,
	SemiColon,
	LeftParenthesis,
	RightParenthesis,
	LeftBrace,
	RightBrace,
	LeftBracket,
	RightBracket,
	ArrayDereference,
	Shift,
	CallDecl,
	WhileStmt,
	ForStmt,
	ForeachStmt,
	ArgumentArray,
	SpecificValue,
	ProgramArgument,
	FieldDecl,
	TypeRef,
	LabelRef,
	LocalVarDecl,
	GlobalVarDecl,
	Var,
	ArrayVar,
	Int,
	Double,
	String,
	Object,
	Array,
	Operator,
	LocalVar,
	LocalArrayVar,
	GlobalVar,
	GlobalArrayVar,
	ArrayRef,
	ArrayAt,
	Function,
	Call,
	Argument,
	List,
	Undefined,
} GPerlT;

typedef struct _GPerlTokenInfo {
	GPerlT type;
	const char *name;
	const char *data;
} GPerlTokenInfo;
