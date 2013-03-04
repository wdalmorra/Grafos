#include "Grafo.h"

Grafo::Grafo(int vertices){

	int i,j;

	// Cria a tabela de referencias
	// tabelaRef = (string*) malloc(vertices*sizeof(string));

	// Cria o ponteiro da matriz com n vertices
	matrizAdj = (int*) malloc((vertices*vertices)*sizeof(int));

	// Inicia a matriz com valor "nulo"
	for (i = 0; i < vertices; ++i) {
		for (j = 0; j < vertices; ++j) {
			matrizAdj[i*vertices + j] = -1;
		}
	}

	numeroVert = vertices;

} // Fim construtor

void Grafo::inserirVertice(int ID, string nome)
{
	tabelaRef[ID] = nome;
}// Fim inserirVertice

void Grafo::inserirAresta(int ID1, int ID2, int peso)
{
	matrizAdj[ID1*numeroVert+ID2] = peso;
}

void Grafo::removerVertice(int ID)
{
	int j;
	if (tabelaRef[ID].compare("") == 0)
	{
		for (j = 0; j < numeroVert; ++j) {

			// Apaga todas as arestas para o qual ele aponta
			matrizAdj[ID*numeroVert+j] = -1;

			// Apaga todas as arestas para o qual apontam para ele
			matrizAdj[j*numeroVert+ID] = -1;
		}
	}
}

void Grafo::imprimeTable()
{
	for (int i = 0; i < numeroVert; ++i) {
		cout<< tabelaRef[i]<< endl;
	}
}
