all:
	g++ *.cpp -std=c++11 -o outfile -lsfml-graphics -lsfml-window -lsfml-system
	./outfile