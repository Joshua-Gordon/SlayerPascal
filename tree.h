#ifndef TREE_H
#define TREE_H

typedef int Bool;
#define true 1
#define false 0

#include "symboltable.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>

typedef struct ab {
    int start;
    int stop;
} arrayBounds;

typedef union attr {
    int ival;
    double dval;
    int opval;
    char* sval;
    arrayBounds* ab;
} attr;

typedef struct tree {
    int type;
    int typeCase;
    int numChildren;
    attr* attribute;
    struct tree** children;
} tree;

typedef struct treeitr_s {
    tree* val;
    struct treeitr_s* next;
} TreeStack;

void printTree(tree* toPrint);

tree* mktree(int type, int typeCase, ...);

arrayBounds* mkArrayBounds(int start,int stop);

//Advances to semantic analysis; this function decides whether or not pc.y calls the code generator
Bool treeCheck(tree* ast);

Bool matchArgsExprList(TableStack*,ArgList*,tree*,char*);

Bool recursiveTreeCheck(TableStack*,tree*);

Bool recursiveTreeCheck(TableStack*,tree*);

SymbolType evalType(TableStack*,tree*);

Bool isBooleanValued(TableStack*,tree*);

//CODE GEN AREA

char* filename;
FILE* output;

int labelCounter;

typedef struct registerStack_s {
    char* topReg;
    struct registerStack_s* next;
} RegisterStack;

typedef struct statementStack_s {
    tree* statement;
    struct statementStack_s* next;
} StatementStack;

typedef struct expressionTree_s {
    int op; //-1 iff leaf
    tree* factor; //NULL if not leaf
    int label;
    struct expressionTree_s* left;
    struct expressionTree_s* right;
    Bool leftChild; //1 if left child, 0 if right child. root is left child
} ExpressionTree;

//Registers in use at runtime
RegisterStack* rs;

//emits an intstruction to output
void emit(char* i); 

//opens file for writing
//fills in empty program
//initializes register stack
void initCodeGen();

void generateCode(TableStack* ts,tree* ast);
void genFunction(TableStack* ts,tree* ast); //creates a function/procedure label
void genExpr(TableStack* ts, tree* ast);
void genFactor(TableStack* ts, tree* ast);
void genAssignment(TableStack* ts, tree* ast);
void genProcedureCall(TableStack* ts, tree* ast);
void genIfThen(TableStack* ts, tree* ast);
void genIfThenElse(TableStack* ts, tree* ast);
void genWhile(TableStack* ts, tree* ast);

int getNumRegisters(void);

char* topRegisterStack(void);
char* popRegisterStack(void);
void pushRegisterStack(char*);
void swapRegisterStack(void);

StatementStack* pushStatementStack(StatementStack* ss,tree* ast);
tree* popStatementStack(StatementStack* ss);

ExpressionTree* mkExprTree(int op,tree* factor,ExpressionTree* left, ExpressionTree* right, Bool leftChild);
void printExprTree(ExpressionTree*);

char* printOp(int op);

#endif
