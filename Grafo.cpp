#include "Grafo.h"

Grafo::Grafo(int vertices){

	int i,j;

	tabelaRef = new string[vertices];

	// Cria o ponteiro da matriz com n vertices
	matrizAdj = (int*) malloc((vertices*vertices)*sizeof(int));

	// Inicia a matriz com valor "nulo"
	for (i = 0; i < vertices; ++i) {
		for (j = 0; j < vertices; ++j) {
			matrizAdj[i*vertices + j] = -1;
		}
	}

	numeroVert = vertices;
	numeroVertAtual = vertices;

} // Fim construtor

Grafo::~Grafo()
{
	delete tabelaRef;
	free(matrizAdj);
}

void Grafo::getId(int ID)
{
	cout<< "{\"vertice\":{\"ID\":"<<ID<<", \"dado\":\""<< tabelaRef[ID]<<"\", \"resposta\":\"";
	if (tabelaRef[ID] == "")
	{
		cout<< "Falha";
	}
	else
	{
		cout<< "Sucesso";
	}
	cout<< "\"}}"<<endl;
}
void Grafo::inserirVertice(int ID, string nome)
{
	tabelaRef[ID] = nome;
}// Fim inserirVertice

void Grafo::inserirAresta(int ID1, int ID2, int peso)
{
	matrizAdj[ID1*numeroVert+ID2] = peso;
	// arestas->insereOrdenado(ID1,ID2,peso);
}

void Grafo::removerVertice(int ID)
{
	int j;
	cout<< "{\"delete\":{\"ID\":"<< ID << "\"resposta\":\"";

	if (tabelaRef[ID].compare("") > 0)
	{
		tabelaRef[ID] = "";

		for (j = 0; j < numeroVert; ++j) {
			// Apaga todas as arestas para o qual ele aponta
			matrizAdj[ID*numeroVert+j] = -1;

			// Apaga todas as arestas para o qual apontam para ele
			matrizAdj[j*numeroVert+ID] = -1;
		}
		cout<< "Sucesso\"}}"<<endl;
	}
	else
	{
		cout<< "Falha\"}}"<<endl;
	}
	numeroVertAtual--;
}

void Grafo::removerAresta(int ID1, int ID2)
{
	matrizAdj[ID1*numeroVert+ID2] = -1;
}

void Grafo::imprimeTable()
{
	int i,j;
	for (i = 0; i < numeroVert; ++i) {
		cout<< tabelaRef[i]<< endl;
	}

	for (i = 0; i < numeroVert; ++i) {
		for (j = 0; j < numeroVert; ++j) {
			cout<<matrizAdj[ i*numeroVert + j]<< "\t";
		}
		cout<< endl;
	}
}

void Grafo::vizinhos(int ID)
{
	int i,flag = 0;
	cout<< "{\"vizinhos\":{\"ID\":"<< ID << " \"resposta\":";
	if (tabelaRef[ID] == "")
	{
		cout<<"\"Falha\", \"vizinhos\":[]}}"<<endl;
	}
	else
	{
		cout<< "\"Sucesso\",\"vizinhos\":[";
		
		for (i = 0; i < numeroVert; ++i) {
			if (matrizAdj[ID*numeroVert+i] != -1)
			{
				if (flag != 0)
				{
					cout<<",";
				}
				flag = 1;
				cout << i;
			}
		}
		
		cout<<"]}}" << endl;
	}

}

void Grafo::conexao(int ID1, int ID2)
{
	int v;
	int i;
	int *visitas = (int*) malloc(numeroVert*sizeof(int));

	cout<< "{\"conexao\":{\"ID1\":" << ID1 <<", \"ID2\":"<< ID2<< ", \"resposta\":";  
	
	if (tabelaRef[ID1] == "" || tabelaRef[ID2] == "")
	{
		cout<< "\"falha\",\"conexao\":\"\"}}"<<endl;
	}
	else
	{

		cout<< "\"sucesso\",\"conexao\":\"";
		for (i = 0; i < numeroVert; ++i) {
			visitas[i] = 0;
		}

		Pilha<int> pilha;

		pilha.insere(ID1);

		while(pilha.getTamanho() != 0)
		{
			v = pilha.retira();
			visitas[v] = 1;

			if (v == ID2)
			{
				cout<< "sim\"}}"<<endl;
				return;
			}
			for (i = 0; i < numeroVert; ++i) {
				if (matrizAdj[v*numeroVert + i]	!= -1)
				{
					// Se esse nodo nao foi visitado insere ele na pilha
					if (visitas[i] == 0)
					{
						pilha.insere(i);
					}
					// Senão nao faz nada, apenas passa reto
				}
			}
		}
		cout<< "não\"}}"<<endl;
		return;
	}
}

void Grafo::ordemTopologica()
{
	int i,j, aponta;
	int nodo;
	int *matrizAux = (int*) malloc(numeroVert*numeroVert*sizeof(int));
	
	Fila<int> ordem;
	Fila<int> s;
	
	//Copia a matriz de adjacencia e ja crio a fila de nodo q nao tem ninguem apontando pra ele
	for (i = 0; i < numeroVert; ++i) {
		aponta = 0;
		for (j = 0; j < numeroVert; ++j) {
			matrizAux[j*numeroVert+i] = matrizAdj[j*numeroVert+i];
			if (matrizAux[j*numeroVert+i] != -1)
			{
				aponta = 1;
			}
		}
		if (aponta == 0 && tabelaRef[i] != "")
		{
			s.insere(i);
		}
	}

	while(s.getTamanho() != 0)
	{
		nodo = s.retira();
		ordem.insere(nodo);

		for (i = 0; i < numeroVert; ++i) {
			if (matrizAux[nodo*numeroVert+i] != -1)
			{
				matrizAux[nodo*numeroVert+i] = -1;

				// Verifico se o nodo "i" tem mais arestas, se tiver entao nao faço nada caso contrario insiro ele na fila s
				aponta = 0;

				for (j = 0; j < numeroVert; ++j) {
					if (matrizAux[j*numeroVert+i] != -1 && !s.pertence(j))
					{
						aponta = 1;
					}
				}

				if (aponta == 0  && tabelaRef[i] != "" && !s.pertence(i))
				{
					// Entao nao tem mais nenhuma aresta q aponta para ele logo insere ele na fila
					s.insere(i);
				}
			}
		}
	}

	// Verifica se sobrou alguma aresta no grafo
	aponta = 0;
	for ( i = 0; i < numeroVert; ++i) {
		for ( j = 0; j < numeroVert; ++j) {
			if (matrizAux[i*numeroVert+j] != -1)
			{
				aponta = 1;
			}
		}
	}
	if (aponta == 0)
	{
		cout<<"{\"ordemtop\":[";
		
		ordem.imprime();

		cout<<"]}" <<endl;
	}
	else
	{
		cout<< "Grafo possui ciclos"<< endl;
	}
}

void Grafo::menorCaminho(int ID1, int ID2)
{
	Heap *h = new Heap(numeroVert, ID1,ID2);
	int *distancia = new int[numeroVert];

	for (int i = 0; i < numeroVert; ++i) {
		distancia[i] = INT_MAX;
	}

	distancia[ID1] = 0;

	int *caminho = new int[numeroVert];

	caminho[ID1] = ID1;

	while(!h->isEmpty())
	{
		Nod u;
		u = h->retira();

		for (int i = 0; i < numeroVert; ++i) {
			if (matrizAdj[u.getId()*numeroVert+i] != -1)
			{
				int altura = u.getValor() + matrizAdj[u.getId()*numeroVert+i];

				if (altura < h->getDistance(i))
				{
					h->setHeap(altura,i);
					distancia[i] = altura;

					caminho[i] = u.getId();


				}
			}
		}
	}
	int i = ID2;

	Pilha<int> cam;

	while(caminho[i] != i){
		cam.insere(i);
		i = caminho[i];
	}
	cam.insere(i);

	cout<< "{\"menorcaminho\":{\"ID1\":" << ID1 << ",\"ID2\":" << ID2 << ", \"caminho\":[";

	if (cam.getTamanho() != 0)
	{
		cam.imprime();
	}

	cout<< "],\"custo\":"<< distancia[ID2]<< "}}" <<endl;
	
	delete h;
	delete distancia;
	delete caminho;

}

void Grafo::arvoreMinima()
{
	Arestas *arestas = new Arestas();

	for (int i = 0; i < numeroVert; ++i) {
		for (int j = 0; j < numeroVert; ++j) {
			if (matrizAdj[i*numeroVert+j] != NULO)
			{
				arestas->insereOrdenado(i,j,matrizAdj[i*numeroVert+j]);
			}
		}
	}

	// this->imprimeTable();

	// cout<< "------------------------"<<endl;

	// arestas->print();

	// cout<< "---------------------------"<<endl;

	Arestas *t = new Arestas();
	struct Aresta *e;
	ConjuntoDisjunto *c = new ConjuntoDisjunto(numeroVert);

	while(t->getTamanho() < (numeroVertAtual-1))
	{

		int conj_id1,conj_id2;

		e = arestas->retira();

		conj_id1 = c->find(e->ID1);
		conj_id2 = c->find(e->ID2);

		if (conj_id1 != conj_id2)
		{
			c->merge(conj_id1,conj_id2);
			// cout<< "INSERIU NO T"<<endl;
			// cout<< " ID1: "<< e->ID1 << " "<< e->ID2<< " peso: " << e->peso<<endl;
			t->insere(e->ID1,e->ID2,e->peso);
		}
	}
	t->print();
	delete arestas;
	delete e;
	delete c;
	delete t;
}
