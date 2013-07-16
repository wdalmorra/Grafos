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

#ifndef ARESTAS_H_
#define ARESTAS_H_

#include <cstdlib>
#include <iostream>
#include <climits>

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


