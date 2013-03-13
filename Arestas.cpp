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
		cout<< "("<< aux->ID1 << "," << aux->ID2 << ") " << aux->peso << endl;
		aux = aux->prox;
	}
}

void Arestas::insereOrdenado(int ID1, int ID2, int peso)
{
	tamanho++;
	struct Aresta *a = (Aresta*) malloc(sizeof(struct Aresta));

	// cout<< "DENTRO DO INSERE DO ARESTAS: "<<endl<< ID1 <<"  "<< ID2<< "  "<< peso<<endl;
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

			// cout<< a->peso<< "   "<< aux->peso<<endl;
			if (a->peso > aux->peso)
			{
				// cout<< "SIM"<<endl;
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

	descritor = descritor->prox;

	return aux;
}

// void Arestas::retira(int ID1, int ID2, int peso)
// {
// 	struct Aresta *aux = descritor;
// 	struct Aresta *aux2;
// 	bool achou = false;
	
// 	while(!achou)
// 	{
// 		if (aux->ID1 == ID1 && aux->ID2 == ID2 && aux->peso == peso)
// 		{
// 			while(aux->prox !== NULL)
// 			{

// 			}
// 		}
// 	}

// }

int Arestas::getTamanho()
{
	return tamanho;
}

int Arestas::getCusto()
{
	return custo;
}