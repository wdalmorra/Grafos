#include "ConjuntoDisjunto.h"

ConjuntoDisjunto::ConjuntoDisjunto(int tamanho)
{
	c = new int[tamanho];
	this->tamanho = new int[tamanho];

	for (int i = 0; i < tamanho; ++i) {
		c[i] = i;
		this->tamanho[i] = 1;
	}

}

ConjuntoDisjunto::~ConjuntoDisjunto()
{

}

void ConjuntoDisjunto::merge(int conj1, int conj2)
{
	if (tamanho[conj1] > tamanho[conj2])
	{
		c[conj1] = c[conj2];

	} else {
		if (tamanho[conj1] < tamanho[conj2])
		{
			c[conj2] = c[conj1];
		}
		else
		{
			c[conj1] = c[conj2];
			tamanho[conj1]++;
		}
	}

}

int ConjuntoDisjunto::find(int ID)
{
	if (c[ID] == ID)
	{
		return ID;
	}
	else
	{
		c[ID] = this->find(c[ID]);
		return c[ID];
	}
}
