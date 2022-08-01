CC=g++
CLIBS=-Wall -lSDL2
FILES=Engine/Super.cpp Engine/FVector/FVector.cpp Engine/Object/Object.cpp Engine/Game/GameLayer.cpp Engine/Renderer/Renderer.cpp MyCube.cpp

Main: Engine/*.cpp
	$(CC) $(CLIBS) $(FILES) $(MAINFILE) -o $(NAME)

Run: Engine/*.cpp
	$(CC) $(CLIBS) $(FILES) $(MAINFILE) -o $(NAME)
	./$(NAME)
	clear