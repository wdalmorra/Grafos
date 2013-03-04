#include "Grafo.h"

Grafo::Grafo(int vertices){

	// Cria o ponteiro da matriz com n vertices
	matrizAdj = malloc((vertices*vertices)*sizeof(int));

}