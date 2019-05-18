#include "tree.h"

void emit(char* i){
    fprintf(output,"%s",i); 
    fprintf(output,"\n"); 
}

void emitNoNewline(char* i) {
    fprintf(output,"%s",i);
}

//opens file for writing
//fills in empty program
//initializes register stack
void initCodeGen() {


    print("\nOpaque compiler\n");
    print("True nature revealed at last\n");
    print("Trees and suffering\n");

    char* sfile = filename;
    int l = strlen(sfile);
    print("Editing filename\n");
    sfile[l-1] = 's';
    output = (FILE*)fopen(sfile,"w+");

    print("File is set up\n"); 

    labelCounter = 0;

    fprintf(output,"    .file \"%s\"\n",filename);
    emit(".section      .rodata");
    emit(".LLC0:");
    emit("  .string \"%d\"");
    emit(".LLC1:");
    emit("  .string \"%d\"");
    emit(".LLD0:");
    emit("  .string \"%f\"");
    emit(".LLD1:");
    emit("  .string \"%f\n\"");
    emit(".section      \".text\"");
    emit("          .globl main");
    emit("          .type main,@function");
    emit("main:");
    emit("          pushl \%ebp");
    emit("          movl \%esp,\%ebp");
    emit("          subl $8,\%esp");
    emit("          andl $-16,\%esp");
    emit("          movl $0,\%eax");
    emit("          subl \%eax,\%esp");
    emit("          call bones");
    emit("          leave     ");
    emit("          ret       ");
    emit(".LLfe0:");
    emit("          .size main, .LLfe0-main");
    emit("bones:");
    //emit("    .ident    \"GCC: (Ubuntu 8.2.0-7ubuntu1) 8.2.0\""); 
    //emit("    .section    .note.GNU-stack,\"\",@progbits");

    print("Empty program is started\n");

    /* eax will be used for pointer chasing, and returns
     * eax will not be consumed for returns
     * stack space will be allocated for return values,
     * and will be loaded into eax just in time
     *
     * ebx, ecx, edx, esi, and edi will be 
     * for computation
     */
    
    rs = NULL;
    pushRegisterStack("%ebx");
    pushRegisterStack("%ecx");
    pushRegisterStack("%edx");
    pushRegisterStack("%esi");
    pushRegisterStack("%edi");
   
    /*
    RegisterStack* itr = rs = (RegisterStack*)malloc(sizeof(RegisterStack)); 
    itr->topReg = "%%ebx";
    itr->next = (RegisterStack*)malloc(sizeof(RegisterStack));
    itr = itr->next;
    itr->topReg = "%%ecx";
    itr->next = (RegisterStack*)malloc(sizeof(RegisterStack));
    itr = itr->next;
    itr->topReg = "%%edx";
    itr->next = (RegisterStack*)malloc(sizeof(RegisterStack));
    itr = itr->next;
    itr->topReg = "%%esi";
    itr->next = (RegisterStack*)malloc(sizeof(RegisterStack));
    itr = itr->next;
    itr->topReg = "%%edi";
    */

    print("Register stack is initialized\n");

}

int getNumRegisters() {
    int i = 1;
    RegisterStack* itr = rs;
    while(itr->next) {
        i++;
        itr = itr->next;
    }
    return i;
}

char* topRegisterStack() {
    return rs->topReg;
}

char* popRegisterStack() {
    char* reg = rs->topReg;
    RegisterStack* tmp = rs->next;
    free(rs);
    rs = tmp;
    return reg;
}

void pushRegisterStack(char* r) {
    RegisterStack* tmp = (RegisterStack*)malloc(sizeof(RegisterStack));
    tmp->topReg = r;
    tmp->next = rs;
    rs = tmp;
}

//assumes there are at least two registers left
void swapRegisterStack() {
    if(getNumRegisters() < 2) {
        print("Not enough registers.");
        exit(1);
    }
    char* r0 = popRegisterStack();
    char* r1 = popRegisterStack();
    pushRegisterStack(r0);
    pushRegisterStack(r1);
}

//routes codegen calls to appropriate functions based on tree type
void generateCode(TableStack* ts, tree* ast) {
    switch(ast->type) {
        case 10: { //compound statement
            //will iterate through statement list and generate code
            tree* optStatements = ast->children[0];
            if(optStatements->typeCase == 1) {
                return; //no statements. Cool.
            } else {
                tree* statementList = optStatements->children[0];
                //statements are stored in list backwards!
                //Need to build stack
                StatementStack* sts = NULL;
                while(statementList->typeCase == 1) {
                    print("Pushing statement\n");
                    sts=pushStatementStack(sts,statementList->children[1]);
                    statementList = statementList->children[0];
                }
                //also get the first statement
                print("Pushing statement\n");
                sts=pushStatementStack(sts,statementList->children[0]);
                print("Beginning popping\n");
                if(sts == NULL) {
                    print("DEBUG: sts is null\n");
                }
                while(sts != NULL) {
                    print("Popping statement\n");
                    tree* s = popStatementStack(sts);
                    sts = sts->next;
                    switch(s->typeCase) {
                        case 0:
                            genAssignment(ts,s);
                            break;
                        case 1:
                            genProcedureCall(ts,s);
                            break;
                        case 2:
                            generateCode(ts,s);
                            break;
                        case 3:
                            genIfThen(ts,s);
                            break;
                        case 4:
                            genIfThenElse(ts,s);
                            break;
                        case 5:
                            genWhile(ts,s);
                            break;
                    }
                }
                //All statements generated
            }
            break;
        }
        case 17:
        case 18:
        case 19:
        case 20:{ //expression
            genExpr(ts,ast);
            break;
        }

    }
}

StatementStack* pushStatementStack(StatementStack* ss,tree* ast) {
    StatementStack* old = ss;
    ss = (StatementStack*)malloc(sizeof(StatementStack));
    ss->statement = ast;
    ss->next = old;
    print("Pushed\n");
    return ss;
}

tree* popStatementStack(StatementStack* ss) {
    StatementStack* bottom = ss->next;
    tree* statement = ss->statement;

    free(ss);
    ss = bottom;
    return statement;
}

ExpressionTree* mkExprTree(int op, tree* factor, ExpressionTree* left, ExpressionTree* right, Bool leftChild) {
    ExpressionTree* et = (ExpressionTree*)malloc(sizeof(ExpressionTree));
    et->op = op;
    et->factor = factor;
    et->label = -1;
    et->left = left;
    et->right = right;
    et->leftChild = leftChild;
    return et;
}

ExpressionTree* buildExprTree(tree* ast, Bool leftChild) {
    print("Building exprTree\n");
    switch(ast->type) {
        case 17: {
            if(ast->typeCase == 1) {
                print("CASE 17 1\n");
                ExpressionTree* l = buildExprTree(ast->children[0],true);
                ExpressionTree* r = buildExprTree(ast->children[1],false);
                return mkExprTree(ast->attribute->opval,NULL,l,r,leftChild);
            } else {
                print("CASE 17 0\n");
                return buildExprTree(ast->children[0],leftChild);
            }
        }
        case 18: {
            if(ast->typeCase == 1) {
                //ignore for now
                //unary minus...
                return NULL;
            } else if(ast->typeCase == 0) {
                print("CASE 18 0");
                return buildExprTree(ast->children[0],leftChild);
            } else {
                print("CASE 18 1");
                ExpressionTree* l = buildExprTree(ast->children[0],true);
                ExpressionTree* r = buildExprTree(ast->children[1],false);
                return mkExprTree(ast->attribute->opval,NULL,l,r,leftChild);
            }
        }
        case 19: {
            if(ast->typeCase == 1) {
                print("CASE 19 1\n");
                ExpressionTree* l = buildExprTree(ast->children[0],true);
                ExpressionTree* r = buildExprTree(ast->children[1],false);
                return mkExprTree(ast->attribute->opval,NULL,l,r,leftChild);
            } else {
                print("CASE 19 0\n");
                return buildExprTree(ast->children[0],leftChild);
            }
        }
        case 20: { //the big boi
            switch(ast->typeCase) {
                print("CASE 20\n");
                case 1:
                case 2:
                    //this needs work
                case 0:
                case 3:
                case 4:
                    return mkExprTree(-1,ast,NULL,NULL,leftChild);
                case 5:
                    return buildExprTree(ast->children[0],leftChild);
                case 6: //ignore for now
                    return NULL;
            }
        }
        default:
            print("Illegal case in build expression tree")
            return NULL;
    }
}

void printExprTreeHelper(ExpressionTree* et, int spaces) {
    for(int i = 0; i < spaces; ++i) {
        print(" ");
    }
    if(et->op == -1) {
        print("LEAF\n");
    } else {
        char* o = printOp(et->op);
        fprintf(stderr,"%s\n",o);
        printExprTreeHelper(et->left,spaces+4);
        printExprTreeHelper(et->right,spaces+4);
    }
}

void printExprTree(ExpressionTree* et) {
    print("--------------\n");
    printExprTreeHelper(et,0);
    print("--------------\n");
}

void labelExprTree(ExpressionTree* et) {
    if(et == NULL) {
        return;
    }
    labelExprTree(et->left);
    labelExprTree(et->right);
    if(et->op != -1) { //if et is an internal node
        if(et->left->label == et->right->label) {
            et->label = et->left->label + 1;
        } else if(et->left->label > et->right->label){
            et->label = et->left->label;
        } else {
            et->label = et->right->label;
        }
    } else { //et is a leaf
        et->label = et->leftChild;
    }
}

char* printOp(int op) {
    switch(op) {
        case 6:
            return "addl";
        case 7:
            return "subl";
        case 8:
            return "or";
        case 9:
            return "imull";
        case 10:
            return "idivl";
        case 11:
            return "and";
    }
    print("Bad operator printed");
    return "ERROR";
}

char* getNameExpr(TableStack* ts, ExpressionTree* expr) {
    //assume expr is a leaf
    char* out = (char*)malloc(sizeof(char)*40); //a single instruction can't be 40 characters, right?
    tree* name = expr->factor;
    switch(name->typeCase) {
        case 0:{
            Symbol* s = searchTableStack(ts,name->attribute->sval);
            sprintf(out,"-%d(%%ebp)",s->offset);
            break;
        }
        case 1:
        case 2:
            print("Not done yet");
            break;
        case 3:{
            sprintf(out,"$%d",name->attribute->ival);
            break;
        }    
        case 4:{
            //char* r = topRegisterStack();
            //fprintf(output,"movl $%f,%s",name->attribute->dval,r);
            print("Not done yet, need to figure out immediate mode floats");
            break;
        }    
    }
    return out;
}

void genExprHelper(TableStack* ts, ExpressionTree* expr) {
    if(expr->op == -1) { //if expr is a leaf
        char* valName = getNameExpr(ts,expr);
        char* r = topRegisterStack();
        fprintf(output,"    movl %s,%s\n",valName,r);
    } else { //expr is an internal node
        if(expr->right->label == 0) {
            char* valName = getNameExpr(ts,expr->right);
            genExprHelper(ts,expr->left);
            char* opname = printOp(expr->op);
            char* r = topRegisterStack();
            fprintf(output,"    %s %s,%s\n",opname,valName,r);
        } else if(expr->left->label < expr->right->label) {
            swapRegisterStack();
            genExprHelper(ts,expr->right);
            char* rr = popRegisterStack();
            genExprHelper(ts,expr->left);
            char* opname = printOp(expr->op);
            char* r = topRegisterStack();
            fprintf(output,"    %s %s,%s\n",opname,rr,r);
            pushRegisterStack(rr);
            swapRegisterStack();
        } else if(expr->right->label <= expr->left->label) {
            genExprHelper(ts,expr->left);
            char* rr = popRegisterStack();
            genExprHelper(ts,expr->right);
            char* opname = printOp(expr->op);
            char* r = topRegisterStack();
            fprintf(output,"    %s %s,%s\n",opname,rr,r);
            pushRegisterStack(rr);
        }
    }
}

void genExpr(TableStack* ts,tree* ast) {
    print("genExpr called\n");
    //the first step is to build an ExpressionTree
    ExpressionTree* expr = buildExprTree(ast,true);
    print("Expression tree built\n");
    printExprTree(expr);
    labelExprTree(expr); //label said tree
    print("Expression tree labeled\n");
    genExprHelper(ts,expr); //and then yeet it into gencode
}

void genFunction(TableStack* ts, tree* ast) {

}
void genAssignment(TableStack* ts, tree* ast) {

    assert(ast->typeCase == 0 && ast->type == 13);
    tree* variable = ast->children[0];
    Symbol* s = searchTableStack(ts,variable->attribute->sval);
    if(variable->typeCase == 0) {
       print("Generating expression code\n");
       genExpr(ts,ast->children[1]);
       char* r = topRegisterStack();
       fprintf(output,"    movl %s,-%d(%%ebp)\n",r,s->offset);
    } else { //array
        genExpr(ts,variable->children[0]);
        char* rr = popRegisterStack();
        genExpr(ts,ast->children[1]);
        char* r = topRegisterStack();
        fprintf(output,"    movl %s,-%d(%%ebp)\n",r,s->offset); //figure out how to add rr value to offset
        pushRegisterStack(rr);
        print("Unimplemented feature: assignment to array\n");
    }

}
void genProcedureCall(TableStack* ts, tree* ast) {

}
void genIfThen(TableStack* ts, tree* ast) {
    assert(ast->typeCase == 3 && ast->type == 13);

}
void genIfThenElse(TableStack* ts, tree* ast) {

}
void genWhile(TableStack* ts, tree* ast) {

}
