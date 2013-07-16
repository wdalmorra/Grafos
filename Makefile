##
##	Universidade Federal de Pelotas
##	Centro de Desenvolvimento Tecnologico - CDTec
##	Bacharelado em Ciência da Computação
##
##	Estruturas de Dados 2 - 2012/2
##
##	Professor Ricardo Matsumura Araújo
##
##	Algoritmo de Implementação de Grafos
##
##	Aluno:
##		William Dalmorra de Souza		11100360

Grafo:  Grafo_main.o Grafo.o Heap.o ConjuntoDisjunto.o Arestas.o
	g++ -o Grafo Grafo_main.o Grafo.o Heap.o ConjuntoDisjunto.o Arestas.o

Grafo_main.o: Grafo_main.cpp
	g++ -c Grafo_main.cpp

Arestas.o: Arestas.cpp Arestas.h
	g++ -c Arestas.cpp
	
Grafo.o: Grafo.cpp Grafo.h Arestas.h ConjuntoDisjunto.h Heap.h
	g++ -c Grafo.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c  Heap.cpp

ConjuntoDisjunto.o: ConjuntoDisjunto.cpp ConjuntoDisjunto.h
	g++ -c ConjuntoDisjunto.cpp


clean:
	rm *.o Grafo