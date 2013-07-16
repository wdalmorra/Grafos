/*
	Universidade Federal de Pelotas
	Centro de Desenvolvimento Tecnologico - CDTec
	Bacharelado em Ciência da Computação

	Estruturas de Dados 2 - 2012/2

	Professor Ricardo Matsumura Araújo

	Algoritmo de Implementação de Grafos

	Aluno:
		William Dalmorra de Souza		11100360
*/

#ifndef GRAFO_H_
#define GRAFO_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include "Pilha.h"
#include "Fila.h"
#include "Heap.h"
#include "Arestas.h"
#include "ConjuntoDisjunto.h"

using namespace std;
class Grafo
{
	int *matrizAdj;
	string *tabelaRef;
	int numeroVert,numeroVertAtual;
	bool arestasNegativas;
	bool direcionado;

public:

	Grafo(int vertices);
	~Grafo();
	void setTipo(bool tipo);

	void getId(int ID);
	
	void inserirVertice(int ID, string nome);
	void inserirAresta(int ID1, int ID2, int peso);
	
	void removerVertice(int ID);
	void removerAresta(int ID1, int ID2);
	
	void vizinhos(int ID);

	void conexao(int ID1, int ID2);

	void buscaProfundidade(int ID1, int ID2);
	
	void ordemTopologica();

	void arvoreMinima();

	void imprimeTable();

	void menorCaminho(int ID1, int ID2);
};

#endif