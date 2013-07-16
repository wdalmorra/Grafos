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

#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <cstdlib>
#include <limits.h>

using namespace std;

#define MAX INT_MAX

class Nod
{
	int valor;
	int ID;

public:

	Nod();
	~Nod();
	int getValor();
	int getId();
	void setValor(int v);
	void setId(int i);
};

class Heap
{
	Nod *vetor;
	int ult_pos;

	int *map;

public:

	Heap(int tamanho,int ID1,int ID2);
	~Heap();

	void insere(int valor,int ID);
	Nod retira();
	void imprime();
	void setHeap(int valor, int ID);
	bool isEmpty();
	int getDistance(int ID);

};

#endif