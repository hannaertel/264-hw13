FLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(FLAGS)
EXEC = hw13
OBJS =  hw13.o expressionTree.o tree.o scanner.o 
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

all: $(OBJS) expressionTree.h scanner.h tree.h
	$(GCC) $(OBJS) -o $(EXEC)

test1: all
	./$(EXEC) inputs/test1 output1


test2 : all
	./$(EXEC) inputs/test2 output2

test3: all
	./$(EXEC) inputs/test3 output3

test4: all
	./$(EXEC) inputs/test4 output4


memory:
	$(VALGRIND) --log-file=log1 ./$(EXEC) inputs/test1 log1
	$(VALGRIND) --log-file=log2 ./$(EXEC) inputs/test2 log2 
	$(VALGRIND) --log-file=log3 ./$(EXEC) inputs/test3 log3
	$(VALGRIND) --log-file=log4 ./$(EXEC) inputs/test4 log4
%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output???? log?
