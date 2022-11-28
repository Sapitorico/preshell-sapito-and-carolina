CC= gcc	#compiler
RM=rm -f	#remove files
SRC= *.c	#files to be compiled
NAME= hsh	#executable name
CFLAGS= -Wall -Werror -Wextra -pedantic -std=gnu89 	#compiler flags
compil:	#compilation 
	$(CC) $(CFLAGS) $(SRC) -g -o $(NAME)
clean:	#delete the executable file
	$(RM) $(NAME)
run: $(NAME)	#run the executable
	./$(NAME)
val: $(NAME)
	valgrind --leak-check=full ./$(NAME)
re: clean all	#recompile
mem: compil val
all: compil run	#compile and run
