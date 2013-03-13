#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include "Pilha.h"
#include "Fila.h"
#include "Heap.h"
#include "Arestas.h"
#include "ConjuntoDisjunto.h"

#define NULO -1

using namespace std;
class Grafo
{
	int *matrizAdj;
	string *tabelaRef;
	int numeroVert,numeroVertAtual;

public:

	Grafo(int vertices);
	~Grafo();
	void getId(int ID);
	
	void inserirVertice(int ID, string nome);
	void inserirAresta(int ID1, int ID2, int peso);
	
	void removerVertice(int ID);
	void removerAresta(int ID1, int ID2);
	
	void vizinhos(int ID);

	void conexao(int ID1, int ID2);
	
	void ordemTopologica();

	void arvoreMinima();

	void imprimeTable();

	void menorCaminho(int ID1, int ID2);
};

#endif