%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"
#include "y.tab.h"
%}

whitespace [ \t]+
number  [0-9]+
ident   [A-Za-z][A-Za-z0-9]*

comment "(*"[^"*)"]*"*)"

%%

{whitespace}    ;
{comment}       ;

"program"   { fprintf(stderr,"[PROGRAM]");return PROGRAM; }
"var"       { fprintf(stderr,"[VAR]");return VAR; }
"procedure" { fprintf(stderr,"[PROCEDURE]");return PROCEDURE; }
"function"  { fprintf(stderr,"[FUNCTION]");return FUNCTION; }
"begin"     { fprintf(stderr,"[BEGIN]");return BBEGIN; }
"end"       { fprintf(stderr,"[END]");return END; }
".."        { fprintf(stderr,"[DOTS]");return DOTS; }
"array"     { fprintf(stderr,"[ARRAY]");return ARRAY; }
"of"        { fprintf(stderr,"[OF]");return OF; }
"integer"   { fprintf(stderr,"[INTEGER]");return INTEGER; }
"real"      { fprintf(stderr,"[REAL]");return REAL; }
"if"        { fprintf(stderr,"[IF]");return IF; }
"then"      { fprintf(stderr,"[THEN]");return THEN; }
"else"      { fprintf(stderr,"[ELSE]");return ELSE; }
"while"     { fprintf(stderr,"[WHILE]");return WHILE; }
"for"       { fprintf(stderr,"[FOR]");return FOR; }
"do"        { fprintf(stderr,"[DO]");return DO; }
":="        { fprintf(stderr,"[ASSIGNOP]");return ASSIGNOP; }
"<"         { fprintf(stderr,"[RELOP:%d]",LT); yylval.opval=0; return RELOP; }
"="         { fprintf(stderr,"[RELOP:%d]",EQ); yylval.opval=1; return RELOP; }
">"         { fprintf(stderr,"[RELOP:%d]",GT); yylval.opval=2; return RELOP; }
"<>"        { fprintf(stderr,"[RELOP:%d]",NE); yylval.opval=3; return RELOP; }
"<="        { fprintf(stderr,"[RELOP:%d]",LE); yylval.opval=4; return RELOP; }
">="        { fprintf(stderr,"[RELOP:%d]",GE); yylval.opval=5; return RELOP; }
"+"         { fprintf(stderr,"[ADDOP:%d]",PLUS); yylval.opval=6; return ADDOP; }
"-"         { fprintf(stderr,"[ADDOP:%d]",MINUS); yylval.opval=7; return ADDOP; }
"or"        { fprintf(stderr,"[ADDOP:%d]",OR); yylval.opval=8; return ADDOP; }
"*"         { fprintf(stderr,"[MULOP:%d]",STAR); yylval.opval=9; return MULOP; }
"/"         { fprintf(stderr,"[MULOP:%d]",SLASH); yylval.opval=10; return MULOP; }
"and"       { fprintf(stderr,"[MULOP:%d]",AND); yylval.opval=11; return MULOP; }
"not"       { fprintf(stderr,"[NOT]"); return NOT; }
{number}    { fprintf(stderr,"[NUM:%d]",atoi(yytext)); yylval.ival = atoi(yytext); return INUM; }
{number}"."{number}    { fprintf(stderr,"[NUM:%f]",atof(yytext)); yylval.dval = atof(yytext);  return RNUM; }
{ident}     { fprintf(stderr,"[ID:%s]",yytext); yylval.sval=strdup(yytext); return ID; }
";"         { fprintf(stderr,"[;]"); return yytext[0]; }
"\n"        { fprintf(stderr,"\n"); }
.           { fprintf(stderr,"{%c}",yytext[0]); return yytext[0]; /*complain*/ }

%%

int yyerror(char *msg) 
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}
