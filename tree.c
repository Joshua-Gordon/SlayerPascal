#include "tree.h"
#include "y.tab.h"

void printTreeHelper(tree* t, int spaces);

void printTree(tree* t) {
    printTreeHelper(t,0);
}

void printTreeHelper(tree* t, int spaces) {
    if(t == NULL) {
        return;
    }
    print("\n");
    for(int i = 0; i < spaces; ++i) {
        print(" ");
    }
    switch(t->type) { 
        case 0:
            print("[PROGRAM]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 1:
            fprintf(stderr,"[ID LIST:%s]",t->attribute->sval);
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 2:
            print("[DECLARATIONS]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 3:
            print("[TYPE]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 4:
            print("[STANDARD_TYPE]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 5:
            print("[SUBPROGRAM DECLARATIONS]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 6:
            print("[SUBPROGRAM DECLARATION]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 7:
            fprintf(stderr,"[SUBPROGRAM HEAD:%s]",t->attribute->sval);
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 8:
            print("[ARGS]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 9:
            print("[PARAM LIST]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 10:
            print("[COMPOUND STATEMENT]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 11:
            print("[OPTIONAL STATEMENTS]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 12:
            print("[STATEMENT LIST]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 13:
            print("[STATEMENT]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 14:
            fprintf(stderr,"[VARIABLE:%s]",t->attribute->sval);
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 15:
            fprintf(stderr,"[PROCEDURE STATEMENT:%s]",t->attribute->sval);
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 16:
            print("[EXPRESSION LIST]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 17:
            if(t->attribute->opval){
                fprintf(stderr,"[EXPRESSION:%d]",t->attribute->opval);
            } else {
                print("[EXPRESSION]");
            }
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 18:
            if(t->attribute->opval){
                fprintf(stderr,"[SIMPLE EXPRESSION:%d]",t->attribute->opval);
            } else {
                print("[SIMPLE EXPRESSION]");
            }
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 19:
            if(t->attribute->opval) {
                fprintf(stderr,"[TERM:%d]",t->attribute->opval);
            } else {
                print("[TERM]");
            }
            fprintf(stderr,": %d",t->numChildren);
            break;
        case 20:
            if(t->typeCase == 3 ) {
                fprintf(stderr,"[FACTOR:%d]",t->attribute->ival);
            } else if(t->typeCase == 4) {
                fprintf(stderr,"[FACTOR:%f]",t->attribute->dval);
            } else if(t->typeCase < 3) {
                fprintf(stderr,"[FACTOR:%s]",t->attribute->sval);
            } else {
                print("[FACTOR]");
            }
            //print("[FACTOR]");
            fprintf(stderr,": %d",t->numChildren);
            break;
        default:
            print("{NANDATE !}\n");
            fprintf(stderr,"Type is %d",t->type);
            break;
    }
    for(int i = 0; i < t->numChildren; ++i) {
        printTreeHelper(t->children[i],spaces+4);
    }
}

#define setUpTree(x) ({ \
                    node->numChildren = x;\
                    node->children = (tree**)malloc(sizeof(tree*)*x); \
                        for(int i = 0; i < x; ++i) { \
                            node->children[i] = va_arg(children,tree*); \
                        } \
                    }) 
#define noArg() { node->numChildren = 0; }

tree* mktree(int type, int typeCase, ...) {
    tree* node = (tree*)malloc(sizeof(tree));
    assert(node != NULL);
    node->type = type;
    node->typeCase = typeCase;
    node->attribute = (attr*)malloc(sizeof(attr));
    va_list children;
    va_start(children,typeCase); //typeCase is the last named parameter of the function
    switch(type) { //253 lines before macro expansion. Ow my bones.
        case 0: //program
            setUpTree(4);
            break;
        case 1: //identifier list
            switch(typeCase) {
                case 0:
                    noArg();
                    break;
                case 1:
                    setUpTree(1);
                    break;
                default:
                    print("Nonexistant typecase in [ID LIST]\n");
            }
            break;
        case 2: //declarations
            switch(typeCase) {
                case 0:
                    setUpTree(3);
                    break;
                case 1:
                    noArg();
                    break;
                default:
                    print("Nonexistant typecase in [DECLARATIONS]\n");
            }
            break;
        case 3: //type
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    setUpTree(1); //Yeah, this is useless, but what if I want to make it different later?
                    break;
                default:
                    print("Nonexistant typecase in [TYPE]\n");
            }
            break;
        case 4: //standard type
            noArg();
            break;
        case 5: //subprogram declarations
            switch(typeCase) {
                case 0:
                    setUpTree(2);
                    break;
                case 1:
                    noArg();
                    break;
                default:
                    print("Nonexistant typecase in [SUBPROGRAM DECLARATIONS]\n");
            }
            break;
        case 6: //subprogram declaration
            setUpTree(4);
            break;
        case 7: //subprogram head
            switch(typeCase) {
                case 0:
                    setUpTree(2);
                    break;
                case 1:
                    setUpTree(1);
                    break;
                default:
                    print("Nonexistant typecase in [SUBPROGRAM HEAD]");
            }
            break;
        case 8: //arguments
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    noArg();
                default:
                    print("Nonexistant typecase in [ARGUMENTS]\n");
            }
            break;
        case 9: //parameter list
            switch(typeCase) {
                case 0:
                    setUpTree(2);
                    break;
                case 1:
                    setUpTree(3);
                    break;
                default:
                    print("Nonexistent typecase in [PARAMETER LIST]\n");
            }
            break;
        case 10: //compound statement
            setUpTree(1);
            break;
        case 11: //optional statements
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    noArg();
                    break;
                default:
                    print("Nonexistant typecase in [OPTIONAL STATEMENTS]\n");
            }
            break;
        case 12: //statement list
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    setUpTree(2);
                    break;
                default:
                    print("Nonexistant typecase in [STATEMENT LIST]\n");
            }
            break;
        case 13: //statement
            switch(typeCase) {
                case 0:
                    setUpTree(2);
                    break;
                case 1:
                    setUpTree(1);
                    break;
                case 2:
                    setUpTree(1);
                    break;
                case 3:
                    setUpTree(2);
                    break;
                case 4:
                    setUpTree(3);
                    break;
                case 5:
                    setUpTree(2);
                    break;
                case 6:
                    setUpTree(3);
                    break;
                default:
                    print("Nonexistent typecase in [STATEMENT]\n");
            }
            break;
        case 14: //variable
            switch(typeCase) {
                case 0:
                    noArg();
                    break;
                case 1:
                    setUpTree(1);
                    break;
                default:
                    fprintf(stderr,"Typecase: %d\n",typeCase);
                    print("Nonexistent typecase in [VARIABLE]\n");
            }
            break;
        case 15: //procedure statement
            switch(typeCase) {
                case 0:
                    noArg();
                    break;
                case 1:
                    setUpTree(1);
                    break;
                default:
                    print("Nonexistent typecase in [PROCUEDURE STATEMENT]\n");
            }
            break;
        case 16: //expression list
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    setUpTree(2);
                    break;
                default:
                    print("Nonexistent typecase in [EXPRESSION LIST]\n");
            }
            break;
        case 17: //expression
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    setUpTree(2);
                    break;
                default:
                    print("Nonexistent typecase in [EXPRESSION]\n");
            }
            break;
        case 18: //simple expression
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    setUpTree(2);
                    break;
                case 2:
                    setUpTree(2);
                    break;
                default:
                    print("Nonexistent typecase in [SIMPLE EXPRESSION]\n");
            }
            break;
        case 19: //term
            switch(typeCase) {
                case 0:
                    setUpTree(1);
                    break;
                case 1:
                    setUpTree(2);
                    break;
                default:
                    print("Nonexistent typecase in [TERM]\n");
            }
            break;
        case 20: //factor
            switch(typeCase) {
                case 0:
                    noArg();
                    break;
                case 1:
                    setUpTree(1);
                    break;
                case 2:
                    setUpTree(1);
                    break;
                case 3:
                    noArg();
                    break;
                case 4:
                    noArg();
                    break;
                case 5:
                    setUpTree(1);
                    break;
                case 6:
                    setUpTree(1);
                    break;
                default:
                    print("Nonexistent typecase in [FACTOR]\n");
            }
            break;
        case 21: //sign
            noArg();
            break;
        default:
            print("Nonexistent type in mktree");
    }
    return node;
}

arrayBounds* mkArrayBounds(int start, int stop) {
    arrayBounds* ab = (arrayBounds*)malloc(sizeof(arrayBounds));
    ab->start = start;
    ab->stop = stop;
    return ab;
}

//Takes a node of `type` or `standard_type` and returns the SymbolType of it
SymbolType getTypeLiteral(tree* t) {
    if(t->type == 3) {
        SymbolType type = getTypeLiteral(t->children[0]);
        if(t->typeCase == 1) {
            switch(type) {
                case S_INT:
                    return S_INTARR;
                case S_REAL:
                    return S_REALARR;
                default:
                    print("Issue in getTypeLiteral");
                    return S_INVALID;
            }
        } else {
            return type;
        }
    } else if(t->type == 4) {
        if(t->typeCase == 1) {
            return S_REAL;
        }
        return S_INT;
    } else {
        return S_INVALID; //"I have decided that I want to die" -MS
    }
}

//Performs semantic analysis, and calls the code generator to advance the compiler
Bool treeCheck(tree* ast) {
    SymbolTable* globalScopeTable = mkSymbolTable(NULL);
    TableStack* globalScope = mkTableStack(NULL,globalScopeTable);
    print("\nBEGINNING TREE CHECK!\n");
    if(ast->type != 0) {
        print("Program does not start with program declaration.\n");
        return false;
    }
    //Time for an IN ORDER TREE TRAVERSAL
    Bool passes = recursiveTreeCheck(globalScope,ast);
    if(passes) {
        print("Code gen time!\n");
    } else {
        print("Semantic errors!");
    }
    return passes;
}

ArgList* buildArgListFromExprList(TableStack* symbols, tree* exprlist) {
    if(exprlist->typeCase == 0) {
        SymbolType t = evalType(symbols,exprlist->children[0]);
        return mkArgList(NULL,t,"");
    } else {
        SymbolType t = evalType(symbols,exprlist->children[1]);
        return mkArgList(buildArgListFromExprList(symbols,exprlist->children[0]),t,"");
    }
}

Bool matchArgsExprList(TableStack* symbols,ArgList* args,tree* exprlist,char* fname) {
    ArgList* supplied = reverseArgList(buildArgListFromExprList(symbols,exprlist));

    int i = 0;
    for(ArgList* itr = args; itr != NULL; itr=itr->next) {
        i++;
    }
    fprintf(stderr,"Arguments of %s:\n",fname);
    printArgs(i,args);
    fprintf(stderr,"Arguments given to %s:\n",fname);
    printArgs(i,supplied);
    Bool valid = true;
    while(args != NULL) {
        if(supplied) {
            if(supplied->type != args->type) {
                fprintf(stderr,"Argument [%s] of %s has type ",args->name,fname);
                printSymbolType(args->type);
                print(" but supplied value has type ");
                printSymbolType(supplied->type);
                print("!\n");
                valid = false;
            }
        } else {
            fprintf(stderr,"Not enough arguments given to %s\n",fname);
            return false;
        }
        args = args->next;
        supplied = supplied->next;
    }
    if(supplied != NULL) {
        fprintf(stderr,"Too many arguments given to %s!\n",fname);
        return false;
    }
    return valid;
}

Bool recursiveTreeCheck(TableStack* symbols,tree* ast) {
    switch(ast->type) {
        case 2: {//declarations 
            Symbol* var = NULL;
            tree* idList = NULL;
            tree* itr = ast;
            while(itr->typeCase == 0) {
                //print("Accessing id list\n");
                idList = itr->children[1];
                while(1) {
                    //fprintf(stderr,"Inserting symbol [%s] into table\n",idList->attribute->sval);
                    SymbolType type = evalType(symbols,itr->children[2]);

                    if(type == S_INTARR || type == S_REALARR) {
                        //print("Creating array symbol\n");
                        arrayBounds* ab = ast->children[2]->attribute->ab;
                        var = mkSymbol(idList->attribute->sval,type,ab->start,ab->stop);
                    } else {
                        var = mkSymbol(idList->attribute->sval,type);
                    }
                    //print("Symbol created\n"); 
                    symbolTableInsert(symbols->st,var);
                    //print("Insertion successful\n");
                    if(idList->typeCase == 1)
                        idList = idList->children[0];
                    else
                        break;
                }
                //print("Moving to next type\n");
                itr = itr->children[0];
                //print("Moved\n");
            }
            return true;
        }
        case 5: { //subprogram_declarations
            print("Checking subprogram declarations\n");
            tree* itr = ast;
            Bool valid = true;
            Bool stillvalid;
            while(itr->typeCase == 0) {
                stillvalid = recursiveTreeCheck(symbols,itr->children[1]);
                valid = valid && stillvalid;
                itr = itr->children[0];
            }
            return valid;
        }
        case 6: { //subprogram_declaration
            print("Checking subprogram declaration\n");
            //The plan is to make a scope containing
            //all the declarations here, and recurse with it
            tree* head = ast->children[0];
            //Symbol* funProc;
            SymbolType returnType;
            switch(head->typeCase) {
                case 0: //this is a function declaration
                    //need to get return type
                    if(head->children[1]->typeCase == 0) {
                        returnType = S_INTFUN;
                    } else {
                        returnType = S_REALFUN;
                    }
                    break;
                case 1: //this is a procedure declaration
                    returnType = S_PROCEDURE;
                    break;
            }
            fprintf(stderr,"    Grabbing arguments for %s\n",head->attribute->sval);
            //Now to get arguments
            ArgList* arguments = NULL;
            int numArgs = 0;
            if(head->children[0]->typeCase == 0) { //This function/procedure has arguments
                tree* paramList = head->children[0]->children[0];
                //Build ArgList from paramlist
                fprintf(stderr,"Building ArgList for %s\n",head->attribute->sval); 
                while(paramList->typeCase == 1) {
                    //grab identifier list
                    SymbolType argumentType = getTypeLiteral(paramList->children[2]);
                    tree* id = paramList->children[1];
                    print("Grabbing arguments of type ");
                    printSymbolType(argumentType);
                    print("\n");
                    while(id->typeCase != 0) {
                        ArgList* node = mkArgList(arguments,argumentType,id->attribute->sval);
                        fprintf(stderr,"Adding argument [%s]\n",id->attribute->sval);
                        arguments = node;
                        numArgs++;
                        id = id->children[0];
                    }
                    //need to grab last argument
                    ArgList* node = mkArgList(arguments,argumentType,id->attribute->sval);
                    fprintf(stderr,"Adding argument [%s]\n",id->attribute->sval);
                    arguments = node;
                    numArgs++;
                    paramList = paramList->children[0];
                }
                //paramList is now the last type of parameter
                assert(paramList->typeCase == 0);
                SymbolType argumentType = getTypeLiteral(paramList->children[1]);
                tree* id = paramList->children[0];
                while(id->typeCase != 0) {
                    ArgList* node = mkArgList(arguments,argumentType,id->attribute->sval);
                    fprintf(stderr,"Adding argument [%s]\n",id->attribute->sval);
                    arguments = node;
                    numArgs++;
                    id = id->children[0];
                }
                ArgList* node = mkArgList(arguments,argumentType,id->attribute->sval);
                fprintf(stderr,"Adding argument [%s]\n",id->attribute->sval);
                arguments = node;
                numArgs++;
                //ArgList is now built
               printArgs(numArgs,arguments); 

            } else {
                fprintf(stderr,"%s has no arguments\n",head->attribute->sval);
            } //else no arguments
            //Now to insert into symbol table and then make a new scope
            //top of subprogram declaration is still `ast`
            Symbol* subprogram = mkSymbol(head->attribute->sval,returnType,numArgs,arguments);
            
            symbolTableInsert(symbols->st,subprogram);

            //new scope time
            SymbolTable* newscope = mkSymbolTable(subprogram);
            if(head->typeCase == 0) {
                newscope->isFunctionScope = 1;
            }
            TableStack* newstack = mkTableStack(symbols,newscope);
            ArgList* argItr = arguments;
            while(argItr != NULL) {
                Symbol* arg = mkSymbol(argItr->name,argItr->type);
                symbolTableInsert(newstack->st,arg);
                argItr = argItr->next;
            }

            //Need to process declarations
            Bool passed = recursiveTreeCheck(newstack,ast->children[1]); 
            Bool stillpassed = recursiveTreeCheck(newstack,ast->children[2]); 
            passed = passed && stillpassed;
            //Now to release it on the compound statement
            stillpassed = recursiveTreeCheck(newstack,ast->children[3]);
            return passed && stillpassed; 
        }
        case 0:{ //program
                Bool passed = recursiveTreeCheck(symbols,ast->children[1]);
                Bool stillpassed = recursiveTreeCheck(symbols,ast->children[2]);
                passed = passed && stillpassed;
                stillpassed = recursiveTreeCheck(symbols,ast->children[3]);
                return passed && stillpassed;
               }
        break;
        case 1: //identifier_list
        case 3: //type
        case 4: //standard_type
        case 7: //subprogram_head
        case 8: //arguments
        case 9: //parameter_list
            fprintf(stderr,"recursiveTreeCheck should not end up here [%d]\n",ast->type);
            return false;
        case 10: { //compound_statement
           print("Checking compound statement\n");
           Bool valid = true;
           Bool stillvalid;
           tree* optStatements = ast->children[0];
           if(optStatements->typeCase == 1) {
               return true;
           }
           tree* itr = optStatements->children[0];
           while(itr->typeCase == 1) {
               stillvalid = recursiveTreeCheck(symbols,itr->children[1]);
               valid= valid && stillvalid;
               itr=itr->children[0];
           }
           stillvalid = recursiveTreeCheck(symbols,itr->children[0]);
          
           print("About to generate code for compound statement\n");
           generateCode(symbols,ast);
           print("Generated code for compound statement\n");

           return valid && stillvalid;
        }
        case 13: //statement
            print("Checking statement\n");
            switch(ast->typeCase) {
                case 0: {
                    tree* var = ast->children[0];
                    char* varname = var->attribute->sval;
                    Symbol* varSymbol= searchTableStackFunction(symbols,varname);
                    if(varSymbol == NULL) {
                        fprintf(stderr,"Undeclared variable: %s\n",varname);
                        return false;
                    }
                    if(recursiveTreeCheck(symbols,ast->children[1])) {
                        if(varSymbol->type != evalType(symbols,ast->children[1])){
                            //could be return statement
                            if(varSymbol->type == S_INTFUN){
                                if(evalType(symbols,ast->children[1]) == S_INT){
                                    return true;
                                } else {
                                    fprintf(stderr,"Int function [%s] returns not int value!\n",varname);
                                    return false;
                                }
                            } else if(varSymbol->type == S_REALFUN) {
                                if(evalType(symbols,ast->children[1]) == S_REAL) {
                                    return true;
                                } else {
                                    fprintf(stderr,"Real function [%s] returns not real value!\n",varname);
                                    return false;
                                }
                            }
                            fprintf(stderr,"Variable [%s] assigned value of wrong type!\n",varname); 
                            return false;
                        }
                        return true;
                    } else {
                        print("\nDEBUG\n");
                        return false;
                    }
                    break;
                    
                }
                case 1: { //procedure statement
                    Bool valid = true;
                    tree* procst = ast->children[0];
                    char* procname = procst->attribute->sval;
                    if(strcmp(procname,"writeln") == 0 || strcmp(procname,"read") == 0) {
                        //built in, check that there is one arg of type int or real
                        if(procst->typeCase == 0) {
                            fprintf(stderr,"%s requires one argument!\n",procname);
                            return false;
                        }
                        tree* exprlist = procst->children[0];
                        if(exprlist->typeCase != 0) {
                            fprintf(stderr,"%s requires one argument!\n",procname);
                            return false;
                        }
                        tree* expr = exprlist->children[0];
                        if(recursiveTreeCheck(symbols,expr)) {
                            SymbolType t = evalType(symbols,expr);
                            if(t != S_INT && t != S_REAL) {
                                fprintf(stderr,"%s requires int or real argument!\n",procname);
                                return false;
                            }
                        }
                        return true;
                    } else { //non-builtin procedure call
                        Symbol* s = searchTableStack(symbols,procname);
                        if(!s) {
                            valid = false;
                            fprintf(stderr,"Procedure [%s] not declared!\n",procname);
                        }
                        //Gotta match up types to arguments
                        if(procst->typeCase == 0) {
                            return valid;
                        }
                        tree* exprlist = procst->children[0];
                        ArgList* args = s->attr->args;
                        valid = matchArgsExprList(symbols,args,exprlist,procname);
                    }
                    return valid;
                }
                case 2: { //compound_statement
                    return recursiveTreeCheck(symbols,ast->children[0]);
                }
                case 3: { //if then
                    Bool valid = true;
                    tree* condition = ast->children[0];
                    if(isBooleanValued(symbols,condition)) {
                        valid = recursiveTreeCheck(symbols,condition);
                    } else {
                        print("If statement requires boolean valued condition!\n");
                        valid = false;
                    }
                    return recursiveTreeCheck(symbols,ast->children[1]) && valid;
                }
                case 4: { //if then else
                    Bool valid = true;
                    tree* condition = ast->children[0];
                    if(isBooleanValued(symbols,condition)) {
                        valid = recursiveTreeCheck(symbols,condition);
                    } else {
                        print("If statement requires boolean valued condition!\n");
                        valid = false;
                    }
                    tree* then = ast->children[1];
                    tree* els  = ast->children[2];
                    valid = recursiveTreeCheck(symbols,then) && valid;
                    return recursiveTreeCheck(symbols,els) && valid;
                }
                case 5: { //while do
                    Bool valid = true;
                    tree* condition = ast->children[0];
                    if(isBooleanValued(symbols,condition)) {
                        valid = recursiveTreeCheck(symbols,condition);
                    } else {
                        print("While statement requires boolean valued condition!\n");
                        valid = false;
                    }
                    return recursiveTreeCheck(symbols,ast->children[1]) && valid;
                }
                default:
                    return false;
            }
        case 16: { //expression_list
            Bool valid = true;
            tree* itr = ast;
            while(itr->typeCase == 1) {
                valid = recursiveTreeCheck(symbols,itr->children[1]) && valid;
                itr = itr->children[0];
            }
            valid = recursiveTreeCheck(symbols,itr->children[0]) && valid;
            return valid;
        }
        case 17: { //expression
            switch(ast->typeCase) {
                case 0: //just a simple expression
                    return recursiveTreeCheck(symbols,ast->children[0]);
                case 1:{ //a relop is involved
                    tree* left = ast->children[0];
                    tree* right = ast->children[1];
                    Bool valid = true;
                    valid = recursiveTreeCheck(symbols,left) && valid;
                    valid = recursiveTreeCheck(symbols,right) && valid;
                    valid = ((evalType(symbols,left) == S_INT && evalType(symbols,right) == S_INT) || (evalType(symbols,left) == S_REAL && evalType(symbols,right) == S_REAL)) && valid;


                    return valid;
                }         
            }
        }
        case 18: { //simple expression
            switch(ast->typeCase) {
                case 0: //term
                    return recursiveTreeCheck(symbols,ast->children[0]);
                case 1: { //unary minus
                    Bool valid = true;
                    valid = evalType(symbols,ast->children[0]) == S_INT || evalType(symbols,ast->children[0]) == S_REAL;
                    return recursiveTreeCheck(symbols,ast->children[0]) && valid;
                }
                case 2: { //addition
                    Bool valid = true;
                    tree* left = ast->children[0];
                    tree* right = ast->children[1];
                    valid = recursiveTreeCheck(symbols,left) && valid;
                    valid = recursiveTreeCheck(symbols,right) && valid;
                    if(ast->attribute->opval == 8) { //or
                        valid = isBooleanValued(symbols,left) && isBooleanValued(symbols,right) && valid;
                    } else {
                        valid = ((evalType(symbols,left) == S_INT && evalType(symbols,right) == S_INT) || (evalType(symbols,left) == S_REAL && evalType(symbols,right) == S_REAL)) && valid;
                    }
                    if(!valid) {
                        print("Invalid addition!\n");
                    }
                    return valid;
                }
            }
        }
        case 19: { //term
            switch(ast->typeCase) {
                case 0: //factor
                    return recursiveTreeCheck(symbols,ast->children[0]);
                case 1: {
                    Bool valid = true;
                    tree* left = ast->children[0];
                    tree* right = ast->children[1];
                    valid = recursiveTreeCheck(symbols,left) && valid;
                    valid = recursiveTreeCheck(symbols,right) && valid;
                    if(ast->attribute->opval == 11) { //and
                        valid = isBooleanValued(symbols,left) && isBooleanValued(symbols,right) && valid;
                    } else {
                        valid = ((evalType(symbols,left) == S_INT && evalType(symbols,right) == S_INT) || (evalType(symbols,left) == S_REAL && evalType(symbols,right) == S_REAL)) && valid;
                    }
                    if(!valid) {
                        print("Invalid multiplication!\n");
                    }
                    return valid;
                }

            }

        }
        case 20: { //factor
            switch(ast->typeCase) {
                case 0: { //id
                    char* name = ast->attribute->sval;
                    Symbol* s = searchTableStack(symbols,name);
                    if(s) {
                        return true;
                    }
                    fprintf(stderr,"Symbol [%s] not declared!\n",name);
                    return false;
                }
                case 1: { //function call
                    char* funcName = ast->attribute->sval;
                    Bool valid = true;
                    Symbol* s = searchTableStack(symbols,funcName);
                    if(s == NULL) {
                        fprintf(stderr,"Function [%s] is not declared!\n",funcName);
                        valid = false;
                    }
                    if(s->type != S_INTFUN && s->type != S_REALFUN) {
                        fprintf(stderr,"Symbol [%s] is not a function but is called as one!\n",funcName);
                        valid = false;
                    }
                    //check arguments
                    ArgList* args = s->attr->args; //list is stored in order

                    tree* exprlist = ast->children[0];
                    valid = matchArgsExprList(symbols,args,exprlist,funcName) && valid;
                    return valid;

                }
                case 2: { //array access
                   Bool valid = true;
                   char* name = ast->attribute->sval; 
                   Symbol* s = searchTableStack(symbols,name);
                   if(s->type != S_INTARR && s->type != S_REALARR) {
                       fprintf(stderr,"Symbol [%s] is not an array but was accessed as one!\n",name);
                       valid = false;
                   }
                   valid = valid && recursiveTreeCheck(symbols,ast->children[0]);
                   SymbolType idx = evalType(symbols,ast->children[0]);
                   if(idx != S_INT) {
                       fprintf(stderr,"Cannot access array [%s] with non-integer index\n",name);
                       valid = false;
                   }
                   return valid;
                }
                case 3: { //integer
                   return true;
                }
                case 4: { //real
                   return true;
                }
                case 5: { //parens
                   return recursiveTreeCheck(symbols,ast->children[0]);
                }
                case 6: {
                   Bool valid = true;
                   valid = recursiveTreeCheck(symbols,ast->children[0]) && valid;
                   if(!isBooleanValued(symbols,ast->children[0])) {
                       print("Cannot apply NOT to non-boolean expression!\n");
                       valid = false;
                   }
                   return valid;
                }
            }
        }    
        default:
            print("Unimplemented check!\n");
            TableStack* s = symbols;
            while(s->next) {
                print("\nScope:\n");
                printSymbolTable(s->st);
                s = s->next;
            }
            print("\nGlobal scope:\n");
            printSymbolTable(s->st);
    }
    return true;
}

//Takes a tree and returns it's type. If it has no type, then the function returns S_INVALID
SymbolType evalType(TableStack* ts, tree* ast) {
    switch(ast->type) {
        case 3: //type
            switch(ast->typeCase) {
                case 0:
                    return evalType(ts,ast->children[0]);
                case 1:
                    switch(evalType(ts,ast->children[0])) {
                        case S_INT:
                            return S_INTARR;
                        case S_REAL:
                            return S_REALARR;
                        default:
                            return S_INVALID;
                    }
                default:
                    return S_INVALID;
            }
        case 4: { //standard_type
            switch(ast->typeCase) {
                case 0:
                    return S_INT;
                case 1:
                    return S_REAL;
                default:
                    return S_INVALID;
            }
        }
        case 14: { //variable
            switch(ast->typeCase) {
                case 0:
                    return searchTableStack(ts,ast->attribute->sval)->type;
                case 1: {
                    SymbolType t =searchTableStack(ts,ast->attribute->sval)->type;
                    switch(t) {
                        case S_INTARR:
                            return S_INT;
                        case S_REALARR:
                            return S_REAL;
                        default:
                            return S_INVALID;
                    }
                }
            }
        }
        case 17: //expression
            if(ast->typeCase != 0) {
                return S_INVALID;
            }
            return evalType(ts, ast->children[0]);
        case 18: //simple expression
            switch(ast->typeCase) {
                case 0:
                    return evalType(ts,ast->children[0]);
                case 1:
                    return evalType(ts,ast->children[0]);
                case 2: {
                    SymbolType leftExprType = evalType(ts,ast->children[0]);
                    SymbolType termType = evalType(ts,ast->children[1]);
                    if(termType == leftExprType) {
                        return termType;
                    } else {
                        return S_INVALID;
                    }
                }
                default:
                        print("What? Nonexistant typecase for simple_expression in evalType");
                        return S_INVALID;
            }
        case 19: //term
            switch(ast->typeCase) {
                case 0:
                    return evalType(ts,ast->children[0]);
                case 1: {
                    SymbolType leftExprType = evalType(ts,ast->children[0]);
                    SymbolType factorType = evalType(ts,ast->children[1]);
                    if(factorType == leftExprType) {
                        return factorType;
                    } else {
                        return S_INVALID;
                    }
                }
                default:
                        print("What? Nonexistant typecase for term in evalType");
                        return S_INVALID;
            }
        case 20: //factor
            switch(ast->typeCase) {
                case 0: {
                    Symbol* var = searchTableStack(ts,ast->attribute->sval);
                    return var->type;
                }
                case 1: {
                    Symbol* var = searchTableStack(ts,ast->attribute->sval);
                    switch(var->type) {
                        case S_INTFUN:
                            return S_INT;
                        case S_REALFUN:
                            return S_REAL;
                        default:
                            fprintf(stderr,"Non-function name [%s] called as function",ast->attribute->sval);
                            return S_INVALID;
                    }
                }
                case 2: {
                    Symbol* var = searchTableStack(ts,ast->attribute->sval);
                    switch(var->type) {
                        case S_INTARR:
                            return S_INT;
                        case S_REALARR:
                            return S_REAL;
                        default:
                            fprintf(stderr,"Non-array name [%s] accessed as array",ast->attribute->sval);
                    }            
                } 
                case 3:
                    return S_INT;
                case 4:
                    return S_REAL;
                case 5:
                    return evalType(ts,ast->children[0]);
                case 6:
                    return S_INVALID;
            }
        default:
            return S_INVALID;
    }
    //Code should never get here
    print("untyped code given to typechecker");
    return S_INVALID;
}

//used for checking if statements
//Assumes expr has already been semantically checked
Bool isBooleanValued(TableStack* symbols,tree* expr) {
    switch(expr->type) {
        case 17:
               return expr->typeCase == 1; 
        case 18:
               return expr->typeCase == 2 && expr->attribute->opval == 8;
        case 19:
               return expr->typeCase == 1 && expr->attribute->opval == 11; 
        case 20:
               return expr->typeCase == 6 && isBooleanValued(symbols,expr->children[0]);
        default:
            return false;

    }
}
