#include "Grafo.h"
#include "Heap.h"

int main(int argc, char const *argv[])
{
	Grafo *graf = new Grafo(6);
	// Heap *heap = new Heap(10,5,7);


	// heap->setHeap(3,0);
	// heap->setHeap(2,1);
	// heap->setHeap(18,2);
	// heap->setHeap(9,3);
	// heap->setHeap(1,4);
	// heap->setHeap(14,5);
	// heap->setHeap(11,6);
	// heap->setHeap(12,7);
	// heap->setHeap(10,8);
	// heap->setHeap(32,9);

	// heap->imprime();

	graf->inserirVertice(0,"Ola");
	graf->inserirVertice(1,"Oi");
	graf->inserirVertice(2,"Hello");
	graf->inserirVertice(3,"Mundo");
	graf->inserirVertice(4,"Dia");
	graf->inserirVertice(5,"Bom");


	graf->inserirAresta(0,3,10);
	graf->inserirAresta(0,5,15);
	graf->inserirAresta(0,2,2);
	graf->inserirAresta(1,3,2);
	graf->inserirAresta(2,3,4);
	graf->inserirAresta(3,4,1);
	graf->inserirAresta(5,1,3);
	graf->inserirAresta(4,0,3);

	graf->ordemTopologica();

	graf->menorCaminho(0,2);
	// graf->inserirAresta(3,0,20);

	// // graf->removerVertice(2);

	// graf->getId(2);
	// graf->getId(3);

	// // graf->removerVertice(2);

	// // graf->imprimeTable();

	// // graf->removerAresta(3,0);


	// graf->conexao(0,2);

	// graf->ordemTopologica();

	// // graf->imprimeTable();

	// graf->vizinhos(3);



	return 0;
}