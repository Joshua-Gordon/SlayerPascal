CC = clang
flags = -g -Weverything
YACC = bison
LEX = flex
EXEC = slayer

$(EXEC): y.tab.o lex.yy.o tree.o symboltable.o codegen.o
	$(CC) $(FLAGS) -o $(EXEC) y.tab.o lex.yy.o tree.o symboltable.o codegen.o -lfl -ly

codegen.o: codegen.c
	$(CC) $(FLAGS) -c codegen.c

symboltable.o: symboltable.c
	$(CC) $(FLAGS) -c symboltable.c

tree.o: tree.c
	$(CC) $(FLAGS) -c tree.c

y.tab.o: y.tab.c
	$(CC) $(FLAGS) -c y.tab.c

lex.yy.o: lex.yy.c
	$(CC) $(FLAGS) -c lex.yy.c

y.tab.c: pc.y
	$(YACC) -y -dv pc.y

lex.yy.c: pc.l
	$(LEX) -l pc.l

clean:
	rm -f y.tab.* lex.yy.* y.output
