#include "Heap.h"

Heap::Heap(int tamanho,int ID1, int ID2)
{
	vetor = new Nod[tamanho];

	// map = new int[tamanho];

	// for (int i = 0; i < tamanho; ++i) {
	// 	map[i] = i;
	// }

	for (int i = 0; i < tamanho; ++i) {
		vetor[i].setId(i);
		vetor[i].setValor(MAX);
	}

	ult_pos = tamanho-1;

	vetor[0].setValor(0);
	vetor[0].setId(ID1);
	vetor[ID1].setId(0);


	// for (int i = 0; i <= ult_pos; ++i) {
	// 	cout<< "vetor "<< vetor[i].getValor()<< "  id  " << vetor[i].getId()<<endl;
	// }

	// map[ID1] = 0;
	// map[0] = ID1;

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

	// for (i = 0; i <= ult_pos; ++i) {
	// 	cout<< "MAP "<<i << map[i]<< endl;
	// }

	// cout<< ID <<"     " << map[ID]<<endl;

	// vetor[map[ID]].setValor(valor);

	bool trocou = true;

	// i = map[ID];

		while ((vetor[i].getValor()) < (vetor[(i-1)/2]).getValor())
		{
			Nod root;

			// cout<< "map i2  "<< map[vetor[i].getId()]<<endl;
			// cout<< "map cont2  "<< map[vetor[(i-1)/2].getId()]<<endl;

			root.setId(vetor[i].getId());
			root.setValor(vetor[i].getValor());

			vetor[i].setId(vetor[(i-1)/2].getId());
			vetor[i].setValor(vetor[(i-1)/2].getValor());

			vetor[(i-1)/2].setId(root.getId());
			vetor[(i-1)/2].setValor(root.getValor());

			// map[i] = (i-1)/2;
			// cout<< "map i"<< map[vetor[i].getId()]<<endl;
			// map[(i-1)/2] = i;
			// cout<< "map cont"<< map[vetor[(i-1)/2].getId()]<<endl;

			i = (i -1)/2;
		}


	// for (int i = 0; i <= ult_pos; ++i) {
	// 	cout<< "vetor "<< vetor[i].getValor()<< "  id  " << vetor[i].getId()<<endl;
	// }
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

	// vetor[ult_pos].setId(rootRet.getId());
	// vetor[ult_pos].setValor(rootRet.getValor());

	ult_pos--;

	// cout<< "INICIO"<<endl;
	// this->imprime();

	int i = 0;

	while (vetor[i].getValor() > vetor[i*2+1].getValor() || vetor[i].getValor() > vetor[i*2+2].getValor())
	{
			if ((i *2 + 1 >= ult_pos) && (i *2 + 2 >= ult_pos))
			{
				// cout<< i << "  POSICAO  " << ult_pos<<endl;
				break;
			}
			if (vetor[i*2+1].getValor() < vetor[i*2+2].getValor())
			{
			// 	cout<< "ANTES:"<<endl;
			// 	cout<< vetor[i].getValor() << " I " << vetor[i].getId()<<endl;
			// 	cout<< vetor[i*2+1].getValor() << " I *2 + 1   " << vetor[i*2+1].getId()<<endl;
				root.setId(vetor[i].getId());
				root.setValor(vetor[i].getValor());

				vetor[i].setId(vetor[i*2+1].getId());
				vetor[i].setValor(vetor[i*2+1].getValor());

				vetor[i*2+1].setId(root.getId());
				vetor[i*2+1].setValor(root.getValor());
				
				// cout<< "DEPOIS: "<<endl;
				// cout<< vetor[i].getValor() << " I " << i <<  "   "<<vetor[i].getId()<<endl;
				// cout<< vetor[i*2+1].getValor() << " I *2 + 1  " << vetor[i*2+1].getId()<<endl;

				i  = i*2+1;
			}
			else
			{
				// cout<< "Antes"<<endl;
				// cout<< vetor[i].getValor() << " I " << vetor[i].getId()<<endl;
				// cout<< vetor[i*2+2].getValor() << " I *2 + 1" << vetor[i*2+2].getId()<<endl;

				root.setId(vetor[i].getId());
				root.setValor(vetor[i].getValor());

				vetor[i].setId(vetor[i*2+2].getId());
				vetor[i].setValor(vetor[i*2+2].getValor());

				vetor[i*2+2].setId(root.getId());
				vetor[i*2+2].setValor(root.getValor());
				
				// cout<< "Depois:"<<endl;
				// cout<< vetor[i].getValor() << " I " << i << "    "<< vetor[i].getId()<<endl;
				// cout<< vetor[i*2+2].getValor() << " I *2 + 1   " << vetor[i*2+2].getId()<<endl;

				i  = i*2+2;
			}
			// cout<< "-----------------"<<endl;
			// this->imprime();

	}
	// cout<< vetor[4].getValor() <<endl;


	// cout<< "FIM\n\n"<<endl;
	// this->imprime();


	return rootRet;
}

Nod::Nod()
{
	// valor = v ;
	// ID = i;
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