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