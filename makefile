hepsi:derle

derle:
	g++ -I./include -c ./src/node.cpp -o ./lib/node.o
	g++ -I./include -c ./src/bst.cpp -o ./lib/bst.o
	g++ -I./include ./src/Kaynak.cpp -o ./bin/Kaynak ./lib/bst.o ./lib/node.o
	
calistir:
	Kaynak