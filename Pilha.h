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

#ifndef PILHA_H_
#define PILHA_H_

#include "lista.h"
#include "nodo.h"

template <class T>

class Pilha : public Lista<T>
{
public:
	Pilha() : Lista<T>()
	{
		/*Somente chama o construtor da classe mãe*/
	}

	Pilha(T dado) : Lista<T>(dado)
	{
		/*Somente chama o construtor da classe mãe*/
	}

	Pilha(const Pilha<T> &pilha)
	{
		Nodo<T>* aux = pilha.prim;
		while (aux != NULL)
		{
			this->insere(aux);
			aux = aux->getProx();
		}
	}
	~Pilha()
	{
		/*Somente chama o destrutor da classe mãe*/
	}

	void insere(T dado)
	{
		Nodo<T>* aux = new Nodo<T>(dado);
		if(this->prim == NULL)
		{
			this->prim = this->ult = aux;
		}
		else
		{
			this->ult->setProx(aux);
			aux->setAnt(this->ult);
			this->ult = aux;
		}
		this->tam++;
	}

	void insere (Nodo<T> *nodo)
	{
		if(this->prim == NULL)
		{
			this->prim = this->ult = nodo;
		}
		else
		{
			this->ult->setProx(nodo);
			nodo->setAnt(this->ult);
			this->ult = nodo;
		}
		this->tam++;
	}

	T retira()
	{
		// cout<< "SIM";
		Nodo<T> *aux = this->ult;
		this->tam--;
		
		if (this->ult == this->prim)
		{
			int dado = this->prim->getDado();
			this->prim = NULL;
			return dado;
		}
		
		this->ult->getAnt()->setProx(NULL);
		this->ult = this->ult->getAnt();

		return aux->getDado();
	}

	void imprime() const
	{
		Nodo<T>* aux = this->ult;
		int flag = 0;

		if (aux == NULL)
		{
			cout<< "Pilha Vazia"<< endl;
		}
		else
		{
			while(aux != NULL)
			{
				if (flag == 1)
				{
					cout<< ",";
				}
					flag = 1;
				aux->imprime();
				aux = aux->getAnt();


			}
		}
	}
};

#endif