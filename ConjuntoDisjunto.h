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


#ifndef CONJUNTODISJUNTO_H_
#define CONJUNTODISJUNTO_H_


class ConjuntoDisjunto
{
	int *c;
	int *tamanho;

public:
	ConjuntoDisjunto(int tamanho);
	~ConjuntoDisjunto();

	void merge(int ID1, int ID2);

	int find(int ID);

};


#endif