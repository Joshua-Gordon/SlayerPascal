#include "symboltable.h"

/*
 * Does not define address for symbol
 */ 
Symbol* mkSymbol(char* name, SymbolType type, ...) {
    SymbolAttribute* sa = (SymbolAttribute*)malloc(sizeof(SymbolAttribute));
    assert(sa);
    va_list varargs;
    va_start(varargs,type); //type is the last named parameter of mkSymbol
    int start,stop,numArgs;
    if(type == S_INTARR || type == S_REALARR) {
        start = va_arg(varargs,int);
        stop = va_arg(varargs,int);
        fprintf(stderr,"Start: %d, Stop: %d",start,stop);
        assert(start < stop);
    } else if(type == S_PROCEDURE || type == S_INTFUN || type == S_REALFUN) {
        numArgs = va_arg(varargs,int);
        sa->args = va_arg(varargs,ArgList*);
    }
    switch(type) {
        case S_INT:
            sa->bytes = 4;
            break;
        case S_REAL:
            sa->bytes = 8;
            break;
        case S_PROCEDURE:
        case S_INTFUN:
        case S_REALFUN:
            sa->bytes = 4;
            sa->numArgs = numArgs;
            break;
        case S_INTARR:
            sa->bytes = 4*(stop-start);
            sa->arrStart = start;
            sa->arrStop = stop;
            break;
        case S_REALARR:
            sa->bytes = 8*(stop-start);
            sa->arrStart = start;
            sa->arrStop = stop;
            break;
        case S_INVALID:
            fprintf(stderr,"Symbol [%s] with invalid type added to table!",name);
            break;
    }
    Symbol* s = (Symbol*)malloc(sizeof(Symbol));
    s->name = name;
    s->type = type;
    s->attr = sa;
    return s;
}

//returns 1 if o1 < o2, 0 if o1 == o2, -1 if o1 > o2
int lexicStrCmp(char* o1, char* o2) {
    int i = 0;
    while(o1[i] && o2[i]) {
        //fprintf(stderr,"i is %d\n",i);
        if(o1[i]<o2[i]) {
            return 1;
        } else if(o1[i] > o2[i]) {
            return -1;
        }
        ++i;
    }
    //print("Strings ended\n");
    if(o2[i]) { //o2 is longer
        return 1;
    }
    if(o1[i]) { //o2 is shorter
        return -1;
    }
    return 0;
}

SymbolBinaryTree* mkBinTree(Symbol* s, SymbolBinaryTree* left, SymbolBinaryTree* right) {
    SymbolBinaryTree* node = (SymbolBinaryTree*)malloc(sizeof(SymbolBinaryTree));
    node->value = s;
    node->left = left;
    node->right = right;
    return node;
}

void symbolBinaryTreeInsert(SymbolBinaryTree* bt, Symbol* s) {
    int cmp = lexicStrCmp(bt->value->name,s->name);
    if(cmp >= 0) { //right
        if(bt->right) {
            symbolBinaryTreeInsert(bt->right,s);
        } else {
            bt->right = mkBinTree(s,NULL,NULL);
        }
    } else { //left
        if(bt->left) {
            symbolBinaryTreeInsert(bt->left,s);
        } else {
            bt->left = mkBinTree(s,NULL,NULL);
        }
    }
}

#define TABLE_SIZE	211
#define EOS		'\0'

/* ----------------------------------------------------------------------------- 
 * hashpjw
 * Peter J. Weinberger's hash function 
 * Source: Aho, Sethi, and Ullman, "Compilers", Addison-Wesley, 1986 (page 436).
 */
int hashpjw( char *s )
{
	char *p; 
	unsigned h = 0, g; 
	
	for ( p = s; *p != EOS; p++ ) 
	{ 
		h = (h << 4) + (*p); 
		if (( g = h & 0xf0000000 )) 
		{ 
			h = h ^ ( g >> 24 ); 
			h = h ^ g; 
		} 
	} 
	return h % TABLE_SIZE; 
}

void symbolTableInsert(SymbolTable* st, Symbol* s) {
    int symbolSize = s->attr->bytes;
    st->byteSize += symbolSize;
    s->offset = st->byteSize;
    int hashValue = hashpjw(s->name);
    if(st->buckets[hashValue] == NULL) {
        st->buckets[hashValue] = mkBinTree(s,NULL,NULL);
    } else {
        symbolBinaryTreeInsert(st->buckets[hashValue],s);
    }
}

Symbol* treeBinarySearch(SymbolBinaryTree* bt, char* name) {
    if(bt == NULL) {
        return NULL;
    }
    int cmp = lexicStrCmp(bt->value->name,name);
    if(cmp == 0) {
        return bt->value;
    }
    if(cmp == -1) { //left
        return treeBinarySearch(bt->left,name);
    }
    if(cmp == 1) { //right
        return treeBinarySearch(bt->right,name);
    }
    assert(0); //what?
    return NULL;
}

Symbol* symbolTableLookup(SymbolTable* st,char* name) {
    int hashValue = hashpjw(name);
    return treeBinarySearch(st->buckets[hashValue],name);
}

SymbolTable* mkSymbolTable(Symbol* compileTimeParent) {
    SymbolTable* st = (SymbolTable*)malloc(sizeof(SymbolTable));
    st->isFunctionScope = 0;
    st->compileTimeParent = compileTimeParent;
    st->byteSize = 0;
    return st;
}

TableStack* mkTableStack(TableStack* ts, SymbolTable* st) {
    TableStack* newts = (TableStack*)malloc(sizeof(TableStack));
    newts->st=st;
    newts->next=ts;
    return newts;
}

void pushTableStack(TableStack* ts, SymbolTable* st) {
    TableStack* newts = (TableStack*)malloc(sizeof(TableStack));
    newts->st = st;
    newts->next = ts;
    ts = newts;
}

void popTableStack(TableStack* ts) {
    assert(ts);
    TableStack* old = ts;
    ts = ts->next;
    free(old->st->buckets);
    free(old->st);
    free(old);
}

Symbol* searchTableStack(TableStack* ts, char* name) {
    if(ts == NULL) {
        return NULL;
    }
    TableStack* p = ts;
    while(p) {
        Symbol* s = symbolTableLookup(p->st,name);
        if(s != NULL)
            return s;
        p = p->next;
    }
    return NULL;
}
Symbol* searchTableStackFunction(TableStack* ts, char*name) {
    if(ts == NULL || ts->st->isFunctionScope){
        return NULL;
    }
    TableStack* p = ts;
    while(p) {
        Symbol* s = symbolTableLookup(p->st,name);
        if(s != NULL)
            return s;
        if(p->st->isFunctionScope) {
            return NULL;    
        }
        p = p->next;
    }
    return NULL;
}

ArgList* mkArgList(ArgList* al, SymbolType type, char* name) {
    ArgList* newnode = (ArgList*)malloc(sizeof(ArgList));
    newnode->type = type;
    newnode->name = name;
    newnode->next = al;
    return newnode;
}
ArgList* reverseArgList(ArgList* args) {
    if(args == NULL) {
        return NULL;
    }
    ArgList* prev = NULL;
    ArgList* cur = args;
    ArgList* nex = cur->next;
    int i = 0;
    while(cur != NULL) {
        cur->next = prev;
        prev = cur;
        cur = nex;
        if(nex) {
            nex = nex->next;
        }
        i++;
    }
    printArgs(i,prev);
    return prev;
}

void printSymbol(Symbol* s) {
    fprintf(stderr,"[%s]:",s->name);
    switch(s->type) {
        case S_INT:
            print("INT");
            break;
        case S_REAL:
            print("REAL");
            break;
        case S_PROCEDURE:
            print("PROCEDURE");
            printArgs(s->attr->numArgs,s->attr->args);
            break;
        case S_INTFUN:
            print("INTFUN");
            printArgs(s->attr->numArgs,s->attr->args);
            break;
        case S_REALFUN:
            print("REALFUN");
            printArgs(s->attr->numArgs,s->attr->args);
            break;
        case S_INTARR:
            fprintf(stderr,"INTARR[%d..%d]",s->attr->arrStart,s->attr->arrStop);
            break;
        case S_REALARR:
            fprintf(stderr,"REALARR[%d..%d]",s->attr->arrStart,s->attr->arrStop);
            break;
        case S_INVALID:
            print("Invald symbol type");
    }
}

void printSymbolType(SymbolType s) {
    switch(s) {
        case S_INT:
            print("INT");
            break;
        case S_REAL:
            print("REAL");
            break;
        case S_PROCEDURE:
            print("PROCEDURE");
            break;
        case S_INTFUN:
            print("INTFUN");
            break;
        case S_REALFUN:
            print("REALFUN");
            break;
        case S_INTARR:
            print("INTARR");
            break;
        case S_REALARR:
            print("REALARR");
            break;
        case S_INVALID:
            print("Invald symbol type");
    }
}

void printBinaryTreeHelper(SymbolBinaryTree* bt, int spaces) {
    for(int i = 0; i < spaces; ++i) {
        print(" ");
    }
    printSymbol(bt->value);
    print("\n");
    if(bt->left)
        printBinaryTreeHelper(bt->left,spaces+2);
    if(bt->right)
        printBinaryTreeHelper(bt->right,spaces+2);
}

void printBinaryTree(SymbolBinaryTree* bt) {
    printBinaryTreeHelper(bt,0);
}

//prints arguments
void printArgs(int numArgs,ArgList* sa) {
    print("\nNum args: \n");
    fprintf(stderr,"[%d] {\n",numArgs);
    while(sa->next) {
        fprintf(stderr,"%s",sa->name);
        print(" : ");
        printSymbolType(sa->type);
        print("\n");
        sa = sa->next;
    }
    fprintf(stderr,"%s",sa->name);
    print(" : ");
    printSymbolType(sa->type);
    print("\n}\n");
}

void printSymbolTable(SymbolTable* st) {
    for(int i = 0; i < TABLE_SIZE; ++i) {
        if(st->buckets[i]) {
            print("-----------------------------\n");
            printBinaryTree(st->buckets[i]);
        }
    }
}

//TEST CODE

char* randomString(unsigned long length) {
    char* s = (char*)malloc(sizeof(char)*length);
    for(unsigned long i = 0ul; i < length; ++i) {
        s[i] = 'a' + rand()%25;
    }
    return s;
}
