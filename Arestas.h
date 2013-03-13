#ifndef ARESTAS_H_
#define ARESTAS_H_

#include <cstdlib>
#include <iostream>

using namespace std;

struct Aresta
{
	int ID1,ID2,peso;
	struct Aresta *prox,*ant;

};

class Arestas
{
	struct Aresta *descritor;
	int tamanho;
	int custo;

public:

	Arestas();

	~Arestas();

	void insereOrdenado(int ID1, int ID2, int peso);

	void insere(int ID1, int ID2, int peso);

	Aresta* retira();

	int getTamanho();

	int getCusto();

	void print();
};

#endif


