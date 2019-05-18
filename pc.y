%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "y.tab.h"

extern int yylex();
extern int yyerror(char*);


FILE* yyin;

%}

%union {
    int ival; //NUM
    double dval; //REAL
    int opval; //RELOP ADDOP MULOP
    char* sval; //ID
    tree* tval;
}


%token <ival> INUM
%token <dval> RNUM
%token PROGRAM /* keyword */
%token <sval> ID      /* keyword */
%token VAR
%token BBEGIN
%token END
%token PROCEDURE
%token FUNCTION
%token DOTS
%token ARRAY OF
%token INTEGER REAL
%token <opval> RELOP EQ NE LT LE GT GE
%token ASSIGNOP 
%token <opval> ADDOP PLUS MINUS OR 
%token <opval> MULOP STAR SLASH AND
%token NOT
%token IF THEN ELSE WHILE FOR DO

%left ADDOP
%left MULOP
%left RELOP

%type <tval> program
%type <tval> identifier_list
%type <tval> declarations
%type <tval> type
%type <tval> standard_type
%type <tval> subprogram_declarations
%type <tval> subprogram_declaration
%type <tval> subprogram_head
%type <tval> arguments
%type <tval> parameter_list
%type <tval> compound_statement
%type <tval> optional_statements
%type <tval> statement_list
%type <tval> statement
%type <tval> variable
%type <tval> procedure_statement
%type <tval> expression_list
%type <tval> expression
%type <tval> simple_expression
%type <tval> term
%type <tval> factor


%%


program /* 0 */
       : PROGRAM ID '(' identifier_list ')' ';'
         declarations subprogram_declarations
         compound_statement
         '.' {$$ = mktree(0,0,$4,$7,$8,$9); printTree($$); initCodeGen(); treeCheck($$);}
       ;

identifier_list /* 1 */
        : ID {$$ = mktree(1,0); $$->attribute->sval=$1;} 
        | identifier_list ',' ID {$$ = mktree(1,1,$1); $$->attribute->sval=$3;}
        ;

declarations /* 2 */
        : declarations VAR identifier_list ':' type ';' {$$ = mktree(2,0,$1,$3,$5);}
        | /*empty*/ {$$ = mktree(2,1);}
        ;

type /* 3 */
        : standard_type {$$ = mktree(3,0,$1);}
        | ARRAY '[' INUM DOTS INUM ']' OF standard_type {$$ = mktree(3,1,$8); $$->attribute->ab = mkArrayBounds($3,$5);} /* replace with type for multiarrays */
        ;

standard_type /* 4 */
        : INTEGER {$$ = mktree(4,0);}
        | REAL {$$ = mktree(4,1);}
        ;

subprogram_declarations /* 5 */
        : subprogram_declarations subprogram_declaration ';' {$$ = mktree(5,0,$1,$2);}
        | /* empty */ {$$ = mktree(5,1);}
        ;

subprogram_declaration /* 6 */
        : subprogram_head declarations subprogram_declarations compound_statement {$$ = mktree(6,0,$1,$2,$3,$4);}
        ;

subprogram_head /* 7 */
        : FUNCTION ID arguments ':' standard_type ';' {$$ = mktree(7,0,$3,$5); $$->attribute->sval=$2;}
        | PROCEDURE ID arguments ';' {$$ = mktree(7,1,$3); $$->attribute->sval=$2;}
        ;

arguments /* 8 */
        : '(' parameter_list ')' {$$ = mktree(8,0,$2);}
        | /* empty ; perhaps don't allow this */ {$$ = mktree(8,1);}
        ;

parameter_list /* 9 */
        : identifier_list ':' type {$$ = mktree(9,0,$1,$3);}
        | parameter_list ';' identifier_list ':' type {$$ = mktree(9,1,$1,$3,$5);}
        ;

compound_statement /* 10 */
        : BBEGIN optional_statements END {$$ = mktree(10,0,$2);}
        ;

optional_statements /* 11 */
        : statement_list {$$ = mktree(11,0,$1);}
        | /* empty */ {$$ = mktree(11,1);}
        ;

statement_list /* 12 */
        : statement {$$ = mktree(12,0,$1);}
        | statement_list ';' statement {$$ = mktree(12,1,$1,$3);}
        ;

statement /* 13 */
        : variable ASSIGNOP expression {$$ = mktree(13,0,$1,$3);}
        | procedure_statement {$$ = mktree(13,1,$1);}
        | compound_statement {$$ = mktree(13,2,$1);}
        | IF expression THEN statement {$$ = mktree(13,3,$2,$4);}
        | IF expression THEN statement ELSE statement {$$ = mktree(13,4,$2,$4,$6);}
        | WHILE expression DO statement {$$ = mktree(13,5,$2,$4);}
        /*| FOR '(' statement ';' expression ')' DO statement {$$ = mktree(13,6,$3,$5,$8);} */
        ;

variable /* 14 */
        : ID {$$ = mktree(14,0); $$->attribute->sval=$1;}
        | ID '[' expression ']' {$$ = mktree(14,1,$3); $$->attribute->sval=$1;}
        ;

procedure_statement /* 15 */
        : ID {$$ = mktree(15,0); $$->attribute->sval=$1;}
        | ID '(' expression_list ')' {$$ = mktree(15,1,$3); $$->attribute->sval=$1;}
        ;

expression_list /* 16 */
        : expression {$$ = mktree(16,0,$1);}
        | expression_list ',' expression {$$ = mktree(16,1,$1,$3);}
        ;

expression /* 17 */
        : simple_expression {$$ = mktree(17,0,$1);}
        | simple_expression RELOP simple_expression {$$ = mktree(17,1,$1,$3); $$->attribute->opval=$2;}
        ;

simple_expression /* 18 */
        : term {$$ = mktree(18,0,$1);}
        | ADDOP term {$$ = mktree(18,1,$2); $$->attribute->opval=$1;} /* unary minus */
        | simple_expression ADDOP term {$$ = mktree(18,2,$1,$3); $$->attribute->opval=$2;}
        ;

term /* 19 */
        : factor {$$ = mktree(19,0,$1);}
        | term MULOP factor {$$ = mktree(19,1,$1,$3); $$->attribute->opval=$2;}
        ;

factor /* 20 */
        : ID {$$ = mktree(20,0); $$->attribute->sval=$1;}
        | ID '(' expression_list ')' {$$ = mktree(20,1,$3); $$->attribute->sval=$1;}
        | ID '[' expression ']' {$$ = mktree(20,2,$3); $$->attribute->sval=$1;}
        | INUM {$$ = mktree(20,3); $$->attribute->ival=$1;}
        | RNUM {$$ = mktree(20,4); $$->attribute->dval=$1;}
        | '(' expression ')' {$$ = mktree(20,5,$2);}
        | NOT factor {$$ = mktree(20,6,$2);}
        ;


%%

int main(int argc, char** argv) {

    filename = argv[1];
    fprintf(stderr,"%s",filename);
    yyin = fopen(filename,"r");
    yyparse();


}
