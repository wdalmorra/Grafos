#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
class Grafo
{
	int *matrizAdj;
	string tabelaRef[100];
	int numeroVert;

public:

	Grafo(int vertices);
	~Grafo();

	void inserirVertice(int ID, string nome);
	void inserirAresta(int ID1, int ID2, int peso);
	void removerVertice(int ID);
	void imprimeTable();
};

#endif