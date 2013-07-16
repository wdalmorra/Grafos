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

#include "Grafo.h"
#include <cstdio>

int main(int argc, char const *argv[])
{
	
	string reader,read;
	
	int leitor;

	cin>> reader >> leitor;

	if (reader.compare("*Vertices") == 0)
	{
		Grafo *g = new Grafo(leitor);

		cin>> read;

		while (read.compare("*Arcs") != 0 && read.compare("*Edges") != 0)
		{
			leitor = atoi(read.c_str());

			cin>> reader;

			g->inserirVertice(leitor,reader);

			cin>> read;
		}

		int flag;
		if (read.compare("*Arcs") == 0)
		{
			flag = 0;
			g->setTipo(true);
		}
		else
		{
			if (read.compare("*Edges") == 0)
			{
				flag = 1;
				g->setTipo(false);
			}
			else
			{
				cout<< "Entrada Invalida "<<endl;
				return 1;
			}
		}

		cin>> read;
		while(read.compare("*Queries") != 0)
		{
			int Id1, Id2, peso;

			Id1 = atoi(read.c_str());

			cin>> read;

			Id2 = atoi(read.c_str());

			cin>> read;

			peso = atoi(read.c_str());


			if (flag == 0)
			{
				g->inserirAresta(Id1,Id2,peso);
			}
			else
			{
				g->inserirAresta(Id1,Id2,peso);
				g->inserirAresta(Id2,Id1,peso);
			}
			cin>> read;
		}

		cin>> reader;
		while (reader.compare("@") != 0)
		{
			if (reader.compare("get") == 0)
			{
				cin>> reader;
				int id = atoi(reader.c_str());
				g->getId(id);
			} else {
				if (reader.compare("delete") == 0)
				{
					cin>> reader;
					int id = atoi(reader.c_str());
					g->removerVertice(id);
				} else {
					if (reader.compare("vizinhos") == 0)
					{
						cin>> reader;
						int id = atoi(reader.c_str());
						g->vizinhos(id);	
					} else {
						if (reader.compare("conexao") == 0)
						{
							cin>> reader;
							int id1 = atoi(reader.c_str());
							
							cin>> reader;
							int id2 = atoi(reader.c_str());
							
							g->conexao(id1,id2);
						} else {
							if (reader.compare("ordemtopologica") == 0)
							{
								g->ordemTopologica();
							} else {
								if (reader.compare("arvoreminima") == 0)
								{
									g->arvoreMinima();
								} else {
									if (reader.compare("menorcaminho") == 0)
									{
										cin>> reader;
										int id1 = atoi(reader.c_str());
										cin>> reader;
										int id2 = atoi(reader.c_str());
										g->menorCaminho(id1,id2);
									} else {
										cout<< "Instrução inválida"<<endl;
									}
								}
							}
						}
					}
				}
			}
			cin >> reader;
		}

	}
	else
	{
		cout<< "Entrada invalida" <<endl;
	}
	return 0;
}