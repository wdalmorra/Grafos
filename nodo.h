/* Nome: Thainan Bystronski Remboski
 * Matricula: 11100359
 * 
 * Nome: Willian Dalmorra de Souza
 * Matricula: 11100360
 * */
 
// Arquivo .h que realiza a definição da classe Nodo

#ifndef NODO_H_
#define NODO_H_
							
#include <iostream>		// Inclui a biblioteca "iostream", para realizar entrada e saida
#include <cstdlib>		// Inclui a biblioteca "stdlib.h"

using namespace std;	// Importa as funções do pacote std

template <class T>		// Declara que a classe abaixo fará o uso de polimorfismo paramétrico (template)

class Nodo {			// Definição e implementação da classe Nodo

private:				/* Palavra reservada que indica que o que for declarado
						 * a seguir é visível apenas dentro da classe (pode ser omitido) */
						 
	T dado;				/* Declaração dos atributos privados, respectivamente: dado, de um tipo definido
						 * em tempo de compilação (template); */
	Nodo<T> *ant;		/* ponteiro para o Nodo anterior; */
	Nodo<T> *prox;		/* ponteiro para o próximo Nodo. */	
		
public:					/* Palavra reservada que indica que o for declarado a seguir
						 * pode ser acessado de qualquer lugar em que o objeto seja visível */

	Nodo() {				// Implementação do construtor padrão da classe Nodo
		setDado(0);
		setAnt(NULL);
		setProx(NULL);
	}

	
	Nodo(T dado) {			/* Implementação do construtor da classe Nodo que recebe como parâmetro
							 * um tipo de dado definido em tempo de compilação */
		setDado(dado);
		setAnt(NULL);
		setProx(NULL);
	}

	Nodo(const Nodo<T> &n) {	// Implementação do construtor de cópia profunda da classe Nodo
		this->setDado(n.dado);
		this->setAnt(n.ant);
		this->setProx(n.prox);
	}

	~Nodo() {}				// Implementação do destrutor da classe Nodo

	void imprime() {			// Implementação do método que imprime na tela, o valor de um Nodo
		cout << this->getDado();
	}

	void setDado(T dado) {			/* Implementação do método que seta o valor do dado com o valor
									* passado por parâmetro */
		this->dado = dado;
	}

	void setAnt(Nodo<T> *ant) {		/* Implementação do método que seta o valor do ponteiro anterior
									* com o valor passado por parâmetro */
		this->ant = ant;
	}

	void setProx(Nodo<T> *prox) {	/* Implementação do método que seta o valor do ponteiro próximo
									* com o valor passado por parâmetro */
		this->prox = prox;
	}
	
	T getDado() const {			// Implementação do método que retorna o valor do dado
		return dado;
	}
	
	Nodo<T> *getAnt() const {		// Implementação do método que retorna um ponteiro para o Nodo anterior
		return ant;
	}
	
	Nodo<T> *getProx() const {		// Implementação do método que retorna um ponteiro para o próximo Nodo
		return prox;
	}
	
	/* OBS.: a palavra reservada const utilizada nos últimos três métodos indica
	 * que eles não alteram o estado interno do objeto*/
	
};		// Fim da Implementação da classe Lista

#endif
