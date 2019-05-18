#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifndef PRINT_MACRO
#define PRINT_MACRO
#define print(x) { fprintf(stderr,x); }
#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <time.h>

typedef enum {
    S_INT,
    S_REAL,
    S_PROCEDURE,
    S_INTFUN,
    S_REALFUN,
    S_INTARR,
    S_REALARR,
    S_INVALID
} SymbolType;

typedef struct arglist_s {
    SymbolType type;
    char* name;
    struct arglist_s* next;
} ArgList;

typedef struct attribute_s {
    //int scopeDepth;
    int bytes;
    int arrStart;
    int arrStop;
    ArgList* args;
    int numArgs;
    int addr;
} SymbolAttribute;

typedef struct symbol_s {
    SymbolType type;
    char _unused[4];
    char* name;
    SymbolAttribute* attr; 
    int offset;
} Symbol;

typedef struct binaryTree_s {
    Symbol* value;
    struct binaryTree_s* left;
    struct binaryTree_s* right;
} SymbolBinaryTree;

typedef struct symbolTable_s {
   SymbolBinaryTree* buckets[211];
   Symbol* compileTimeParent;
   int isFunctionScope;
   int byteSize;
} SymbolTable;

typedef struct tableStack_s {
    SymbolTable* st;
    struct tableStack_s* next;
} TableStack;


Symbol* mkSymbol(char* name, SymbolType type, ...);

int lexicStrCmp(char*,char*);

SymbolBinaryTree* mkBinTree(Symbol*,SymbolBinaryTree*,SymbolBinaryTree*);

void symbolBinaryTreeInsert(SymbolBinaryTree*,Symbol*);

int hashpjw(char*);

void symbolTableInsert(SymbolTable*,Symbol*);

Symbol* symbolTableLookup(SymbolTable*,char*);

SymbolTable* mkSymbolTable(Symbol*);

TableStack* mkTableStack(TableStack* ts, SymbolTable* st);

void pushTableStack(TableStack* ts, SymbolTable* st);

void popTableStack(TableStack* ts);

Symbol* searchTableStack(TableStack* ts, char* name);
Symbol* seachTableStackFunction(TableStack* ts, char* name);

ArgList* mkArgList(ArgList*,SymbolType,char*);
ArgList* reverseArgList(ArgList*);

void printSymbol(Symbol*);

void printSymbolType(SymbolType);

void printBinaryTree(SymbolBinaryTree*);

void printArgs(int,ArgList*);

void printSymbolTable(SymbolTable*);

#endif
