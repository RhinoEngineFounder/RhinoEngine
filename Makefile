CC=g++
CLIBS=-Wall -lSDL2
FILES=Engine/*/*.cpp Player.cpp

Main:
	$(CC) $(CLIBS) $(FILES) $(MAINFILE) -o $(NAME)

Run:
	$(CC) $(CLIBS) $(FILES) $(MAINFILE) -o $(NAME)
	./$(NAME)
	clear
