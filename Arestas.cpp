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

#include "Arestas.h"

Arestas::Arestas(){

	tamanho = 0;
	descritor = NULL;
	custo = 0;
}
Arestas::~Arestas(){

}

void Arestas::print()
{
	struct Aresta *aux = descritor;
	while(aux != NULL)
	{
		cout<< "("<< aux->ID1 << "," << aux->ID2 << ")";
		aux = aux->prox;
		if (aux != NULL)
		{
			cout<< ",";
		}
	}
}

void Arestas::insereOrdenado(int ID1, int ID2, int peso)
{
	tamanho++;
	struct Aresta *a = (Aresta*) malloc(sizeof(struct Aresta));

	a->ID1 = ID1;
	a->ID2 = ID2;
	a->peso = peso;
	a->prox = NULL;
	a->ant = NULL;

	if (descritor == NULL)
	{
		descritor = a;
	}
	else
	{
		struct Aresta *aux;
		
		aux = descritor;

		bool set = false;

		while(!set)
		{

			if (a->peso > aux->peso || a->peso == INT_MIN)
			{
				if (aux->prox == NULL)
				{
					aux->prox = a;
					a->ant = aux;

					set = true;
				}
				else
				{
					aux = aux->prox;
				}
			}
			else
			{

				a->prox = aux;
				a->ant = aux->ant;

				if (aux->ant == NULL)
				{
					descritor = a;
				}
				else
				{
					aux->ant->prox = a;
				}
				aux->ant = a;
				set = true;
			}
		}
	}
}

void Arestas::insere(int ID1, int ID2, int peso)
{
	tamanho++;
	struct Aresta *a = (Aresta*) malloc(sizeof(struct Aresta));

	a->ID1 = ID1;
	a->ID2 = ID2;
	a->peso = peso;
	a->prox = NULL;
	a->ant = NULL;

	custo += peso;

	if (descritor == NULL)
	{
		descritor = a;
	}
	else
	{
		struct Aresta *aux = descritor;

		while(aux->prox != NULL)
		{
			aux = aux->prox;
		}
		aux->prox = a;
	}

}

struct Aresta* Arestas::retira()
{
	tamanho--;
	struct Aresta *aux;
	aux = descritor;

	if (descritor != NULL)
	{
		descritor = descritor->prox;
	}
	return aux;
}

int Arestas::getTamanho()
{
	return tamanho;
}

int Arestas::getCusto()
{
	return custo;
}