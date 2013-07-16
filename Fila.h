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


#ifndef FILA_H_
#define FILA_H_

#include "lista.h"
#include "nodo.h"

template<class T>

class Fila : public Lista<T>
{

public:
	Fila():Lista<T>()
	{
		/*Somente chama o construtor da classe mãe*/
	}
	Fila(T dado): Lista<T>(dado)
	{
		/*Somente chama o construtor da classe mãe*/
	}
	Fila(const Fila<T> &fila)
	{
		Nodo<T> * nodo;
		nodo = fila.prim;
		while (nodo != NULL)
		{
			this->insere(nodo);
			nodo = nodo->getProx();
		}
	}
	~Fila()
	{
		/*Somente chama o destrutor da classe mãe*/
	}

	void insere( T dado )
	{
		// cout<< dado<< "aushaushua"<<endl;
		Nodo<T> *aux = new Nodo<T>(dado);
		if (this->prim == NULL)
		{
			this->prim = this->ult = aux;
		}
		else
		{	this->ult->setProx(aux);
			aux->setAnt(this->ult);
			this->ult = aux;
		}
		this->tam++;
	}
	
	bool pertence(T dado)	
	{
		Nodo<T> *aux = this->prim;
		while (aux != NULL)
		{
			if (aux->getDado() == dado)
			{
				return true;
			}
			else
			{
				aux = aux->getProx();
			}
		}
		return false;
	}
	void insere( Nodo<T> *dado )
	{
		if (this->prim == NULL)
		{
			this->prim = this->ult = dado;
		}
		else
		{	this->ult->setProx(dado);
			dado->setAnt(this->ult);
			this->ult = dado;
		}
		this->tam++;
	}
	
	T retira()
	{

		Nodo<T> *Aux = this->prim;
		this->tam--;
		if (this->ult == this->prim)
		{
			int dado = this->prim->getDado();
			this->prim = NULL;
			return dado;
		}
		this->prim->getProx()->setAnt(NULL);
		this->prim = this->prim->getProx();

		return Aux->getDado();
	}

	void imprime() const
	{
		Nodo<T> *aux = 	this->prim;
		if (aux == NULL)
		{
			cout<< "Fila Vazia" << endl;
		}
		else
		{
			while(aux != NULL)
			{
				aux->imprime();
				aux = aux->getProx();
				if (aux != NULL)
				{
					cout<< ",";
				}
			}
		}
	}
};

#endif
