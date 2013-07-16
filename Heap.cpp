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

#include "Heap.h"

Heap::Heap(int tamanho,int ID1, int ID2)
{
	vetor = new Nod[tamanho];

	for (int i = 0; i < tamanho; ++i) {
		vetor[i].setId(i);
		vetor[i].setValor(MAX);
	}

	ult_pos = tamanho-1;

	vetor[0].setValor(0);
	vetor[0].setId(ID1);
	vetor[ID1].setId(0);

}

Heap::~Heap()
{

}

bool Heap::isEmpty()
{
	if (ult_pos < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Heap::getDistance(int ID)
{
	int i;
	for (i = 0; i <= ult_pos; ++i) {
		if (vetor[i].getId() == ID)
		{
			return  vetor[i].getValor();
		}
	}
}
void Heap::setHeap(int valor,int ID)
{
	int i;

	for (i = 0; i <= ult_pos; ++i) {
		if (vetor[i].getId() == ID)
		{
			vetor[i].setValor(valor);
			break;
		}
	}

	bool trocou = true;

		while ((vetor[i].getValor()) < (vetor[(i-1)/2]).getValor())
		{
			Nod root;

			root.setId(vetor[i].getId());
			root.setValor(vetor[i].getValor());

			vetor[i].setId(vetor[(i-1)/2].getId());
			vetor[i].setValor(vetor[(i-1)/2].getValor());

			vetor[(i-1)/2].setId(root.getId());
			vetor[(i-1)/2].setValor(root.getValor());
			i = (i -1)/2;
		}

}

void Heap::imprime()
{
	for (int i = 0; i <= ult_pos; ++i) {

		cout << vetor[i].getValor() << "  " << vetor[i].getId() << endl;
	}
}

Nod Heap::retira()
{
	Nod root,rootRet;

	rootRet.setId(vetor[0].getId());
	rootRet.setValor(vetor[0].getValor());

	vetor[0].setId(vetor[ult_pos].getId());
	vetor[0].setValor(vetor[ult_pos].getValor());

	ult_pos--;

	int i = 0;

	while (vetor[i].getValor() > vetor[i*2+1].getValor() || vetor[i].getValor() > vetor[i*2+2].getValor())
	{
			if ((i *2 + 1 >= ult_pos) && (i *2 + 2 >= ult_pos))
			{
				break;	
			}
			if (vetor[i*2+1].getValor() < vetor[i*2+2].getValor())
			{
				root.setId(vetor[i].getId());
				root.setValor(vetor[i].getValor());

				vetor[i].setId(vetor[i*2+1].getId());
				vetor[i].setValor(vetor[i*2+1].getValor());

				vetor[i*2+1].setId(root.getId());
				vetor[i*2+1].setValor(root.getValor());

				i  = i*2+1;
			}
			else
			{
				root.setId(vetor[i].getId());
				root.setValor(vetor[i].getValor());

				vetor[i].setId(vetor[i*2+2].getId());
				vetor[i].setValor(vetor[i*2+2].getValor());

				vetor[i*2+2].setId(root.getId());
				vetor[i*2+2].setValor(root.getValor());

				i  = i*2+2;
			}
	}
	return rootRet;
}

Nod::Nod()
{

}

Nod::~Nod()
{

}

void Nod::setValor(int v)
{
	valor = v;
}

void Nod::setId(int i)
{
	ID = i;
}

int Nod::getValor()
{
	return valor;
}

int Nod::getId()
{
	return ID;
}