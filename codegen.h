#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symboltable.h"

#ifndef PRINT_MACRO
#define PRINT_MACRO
#define print(x) {fprintf(stderr,x);}
#endif

char* filename;
FILE* output;

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
void genFunction(TableStack* ts,tree* ast);
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

void pushStatementStack(StatementStack* ss,tree* ast);
tree* popStatementStack(StatementStack* ss);

ExpressionTree* mkExprTree(int op,tree* factor,ExpressionTree* left, ExpressionTree* right, Bool leftChild);
