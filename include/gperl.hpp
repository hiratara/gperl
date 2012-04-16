#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>

#define EOL '\0'
#define MAX_LINE_SIZE 128
#define MAX_TOKEN_SIZE 4096
#define MAX_SCRIPT_SIZE 4096 * 10

#define cstr(s) s.c_str()

#ifdef DEBUG_MODE
#define DBG_P(fmt, ...) {\
	fprintf(stderr, fmt, ## __VA_ARGS__);	\
	fprintf(stderr, "\n");						\
	}
#else
#define DBG_P(fmt, ...) {}
#endif

typedef enum {
	Undefined = -1,
	Return,
	Add,
	Sub,
	Mul,
	Div,
	Greater,
	Less,
	GreaterEqual,
	LessEqual,
	EqualEqual,
	FunctionDecl,
	FieldDecl,
	TypeRef,
	LabelRef,
	Assign,
	LocalVarDecl,
	VarDecl,
	PrintDecl,
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
	Var,
	Int,
	Float,
	String,
	Object,
	Operator,
	LocalVar,
	GlobalVar,
} GPerlTypes;

typedef enum {
	OPMOV,
	OPiMOV,
	OPsMOV,
	OPOMOV,
	OPOiMOV,
	OPADD,
	OPiADD,
	OPSUB,
	OPiSUB,
	OPMUL,
	OPiMUL,
	OPDIV,
	OPiDIV,
	OPJG,
	OPiJG,
	OPJL,
	OPiJL,
	OPJGE,
	OPiJGE,
	OPJLE,
	OPiJLE,
	OPJE,
	OPiJE,
	OPRET,
	OPTHCODE,
	OPNOP,
	OPiWRITE,
	OPsWRITE,
	OPPRINT,
	OPJMP,
	OPLET,
	OPSET,
} GPerlOpCodes;

class GPerl {
public:
	GPerl(int argc, char **argv);
};

class Token {
public:
	std::string data;
	int type;
	int idx;
	Token(std::string data_, int idx_ = 0);
};

class GPerlTokenizer {
public:
	GPerlTokenizer(void);
	std::vector<Token *> *tokenize(char *script);
	void annotateTokens(std::vector<Token *> *tokens);
	void dump(std::vector<Token *> *tokens);
	void dumpType(Token *token);
	const char *getTypeName(GPerlTypes type);
	bool search(std::vector<std::string> &list, std::string str);
};

class GPerlAST;
typedef GPerlAST GPerlScope;

class GPerlCell {
public:
	GPerlCell *parent;
	union {
		GPerlCell *left;
		GPerlCell *cond;
	};
	GPerlScope *true_stmt;/* for if stmt */
	union {
		GPerlCell *right;
		GPerlScope *false_stmt;
	};
	GPerlCell *next;/* for next stmt */
	GPerlCell *vargs; /* for print */
	GPerlTypes type;
	std::string vname;/* variable name */
	std::string rawstr;
	union {
		int idata;
		float fdata;
		bool bdata;
		char *sdata;
		void *pdata; /* other Object */
	} data;
	GPerlCell(GPerlTypes type_);
};

#ifdef USING_GRAPH_DEBUG
class GraphvizContext;
class GraphvizGraph;
class GraphvizNode;
class GraphvizEdge;
#endif

class GPerlAST {
public:
	int size;
	int cluster_num;
	GPerlCell *root;
	GPerlCell *cur;
#ifdef USING_GRAPH_DEBUG
	GraphvizNode *root_node;
#else
	void *root_node;
#endif

	GPerlAST(void);
	void add(GPerlCell *root);
#ifdef USING_GRAPH_DEBUG
	void show(void);
	void draw(GraphvizGraph *graph, GPerlCell *c, GraphvizNode *node);
	GraphvizNode *createNode(GraphvizGraph *graph, const char *name);
	void drawEdge(GraphvizGraph *graph, GraphvizNode *from, GraphvizNode *to, const char *label);
#endif
};

class GPerlParser {
public:
	int iterate_count;

	GPerlParser(void);
	GPerlAST *parse(std::vector<Token *> *tokens, std::vector<Token *>::iterator it);
};

#ifdef USING_GRAPH_DEBUG
#include <graphviz/gvc.h>
#include <graphviz/graph.h>

class GraphvizContext {
public:
	GVC_t *gvc;
	GraphvizContext(void);
	void parseArgs(const char *format, const char *filename);
	void layoutJobs(GraphvizGraph *g);
	void renderJobs(GraphvizGraph *g);
	void freeLayout(GraphvizGraph *g);
	~GraphvizContext(void);
};

class GraphvizGraph {
public:
	Agraph_t *g;
	GraphvizGraph(const char *name, int kind);
	GraphvizGraph(void);
	GraphvizGraph *makeSubGraph(const char *name);
	void set(const char *name, const char *value);
	GraphvizNode *newNode(const char *name);
	GraphvizEdge *newEdge(GraphvizNode *start, GraphvizNode *end);
	~GraphvizGraph(void);
};

class GraphvizNode {
public:
	Agnode_t *node;
	GraphvizNode(void);
	void set(const char *name, const char *value);
	void copyAttributeTo(void *oldobj, void *newobj);
	void free(GraphvizGraph *g);
};

class GraphvizEdge {
public:
	Agedge_t *edge;
	GraphvizEdge(void);
	void set(const char *name, const char *value);
	void copyAttributeTo(void *oldobj, void *newobj);
	void free(GraphvizGraph *g);
};
#endif

typedef struct _GPerlVirtualMachineCode {
	GPerlOpCodes op; /* operation code */
	int dst;   /* register number */
	int src;   /* src value or register number */
	int code_num;
	union {
		void (*code)(void);/* selective inlining code */
		int jmp;   /* jmp register number */
	};
	const char *name; /* variable or function name */
	void *opnext; /* for direct threading */
} GPerlVirtualMachineCode;

#define MAX_REG_SIZE 32
#define MAX_VARIABLE_NUM 128

class GPerlCompiler {
public:
	int dst;
	int src;
	int code_num;
	GPerlTypes reg_type[MAX_REG_SIZE];
	std::vector<GPerlVirtualMachineCode *> *codes;
	const char *variable_names[MAX_VARIABLE_NUM];
	int variable_types[MAX_VARIABLE_NUM];
	const char *declared_vname;
	int variable_index;

	GPerlCompiler(void);
	GPerlVirtualMachineCode *compile(GPerlAST *ast);
	GPerlVirtualMachineCode *getPureCodes(void);
	void compile_(GPerlCell *path, bool isRecursive);
	void setToVariableNames(const char *name);
	int getVariableIndex(const char *name);
	GPerlVirtualMachineCode *createVMCode(GPerlCell *c);
	GPerlVirtualMachineCode *createTHCODE(void);
	GPerlVirtualMachineCode *createRET(void);
	GPerlVirtualMachineCode *createiWRITE(void);
	GPerlVirtualMachineCode *createsWRITE(void);
	GPerlVirtualMachineCode *createJMP(int jmp_num);
	void addVMCode(GPerlVirtualMachineCode *code);
	void dumpVMCode(GPerlVirtualMachineCode *code);
	void dumpPureVMCode(GPerlVirtualMachineCode *codes);
};

typedef struct _GPerlObject {
	union {
		int idata;
		float fdata;
		bool bdata;
		char *sdata;
		void *pdata; /* other Object */
	} data;
	const char *name;
} GPerlObject;

class GPerlVirtualMachine {
public:
	GPerlVirtualMachine();
	void setToVariableMemory(const char *name, int idx);
	GPerlObject *getFromVariableMemory(int idx);
	void createDirectThreadingCode(GPerlVirtualMachineCode *codes, void **jmp_tbl);
	int run(GPerlVirtualMachineCode *codes);
};

extern GPerlObject *variable_memory[MAX_VARIABLE_NUM];