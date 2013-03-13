/* Nome: Thainan Bystronski Remboski
 * Matricula: 11100359
 * 
 * Nome: Willian Dalmorra de Souza
 * Matricula: 11100360
 * */
 
// Arquivo .h que realiza a definição da classe Lista

#ifndef LISTA_H_
#define LISTA_H_

#include "nodo.h" 			/* Inclui a definição da classe Nodo, pois esse tipo de
							 * dado é utilizado na definição da classe Lista */
							 
template <class T>			// Declara que a classe abaixo fará o uso de polimorfismo paramétrico (template)

class Lista {				// Definição e implementação da classe Lista

protected:					/* Palavra reservada que indica que o que for declarado
							 * a seguir é visível apenas dentro da classe (pode ser omitido) */
							 
	int tam;				/* Declaração dos atributos privados, respectivamente: tamanho da lista; */
	Nodo<T> *prim;			/* ponteiro para o primeiro elemento da lista; */
	Nodo<T> *ult;			/* ponteiro para o último elemento da lista */
	
public:						/* Palavra reservada que indica que o for declarado a seguir
							 * pode ser acessado de qualquer lugar em que o objeto seja visível */
								 
	Lista() {					// Implementação do construtor padrão da classe Lista
		prim = ult = NULL;
		tam = 0;
	}
	
	Lista(T dado) {					/* Implementação do construtor da classe Lista que recebe como parâmetro
									 * um tipo de dado definido em tempo de compilação */
		Nodo<T> *novo;	
		novo = new Nodo<T>(dado);
		prim = ult = novo;
		tam = 1;
	}
	
	Lista(const Lista<T> &l) {			// Implementação do construtor de cópia profunda da classe Lista
		this->prim = this->ult = NULL;
		this->tam = 0;
		Nodo<T> *aux;
		aux = l.ult;
		while(aux != NULL) {
			this->insere(aux->getDado());
			aux = aux->getAnt();
		}
	}
	
	~Lista() {						// Implementação do destrutor da classe Lista
		while(prim != NULL) {
			this->retira();
		}
	}
	
	void insere(T dado = 0) {		/* Implementação do método que insere um elemento no inicio da Lista
									 * recebendo como parâmetro um tipo de dado definido em tempo de compilação.
									 * Caso o parâmetro seja omitido, é atribuido a ele o valor 0 (zero) */
		Nodo<T> *novo;
		novo = new Nodo<T>(dado);
		novo->setProx(prim);
		novo->setAnt(NULL);
		if(prim != NULL) {
			prim->setAnt(novo);
		}
		prim = novo;
		if(ult == NULL) {
			ult = novo;
		}
		tam++;
	}
										 
	void insere(T dado, Nodo<T> *ant, Nodo<T> *prox) {	/* Implementação do método que insere um elemento
														* no meio da Lista recebendo como parâmetros um tipo de dado
														* definido em tempo de compilação e dois ponteiros para "Nodo"
														* (tipo de dado declarado em outro arquivo) */
		Nodo<T> *novo;
		novo = new Nodo<T>(dado);
		novo->setProx(prox);
		novo->setAnt(ant);
		if(ant != NULL) {
			ant->setProx(novo);
		}
		else {
			prim = novo;
		}
		if(prox != NULL) {
			prox->setAnt(novo);
		}
		else {
			ult = novo;
		}
		tam++;
	}

	void retira() {					// Implementação do método que remove um elemento do início da Lista
		Nodo<T> *aux;
		if(prim != NULL) {
			aux = prim;
			prim = prim->getProx();
			tam--;
			delete(aux);
		}
		if(tam == 0) {
			ult = NULL;
		}
	}
	
	void retira(T dado) {			/* Implementação do método que remove um elemento da Lista.
									 * Esse elemento é especificado pelo parâmetro */
		Nodo<T> *aux;
		Nodo<T> *linker;
		aux = busca(dado);
		if(aux != NULL) {
			linker = aux->getAnt();
			if(linker != NULL) {
				linker->setProx(aux->getProx());
			}
			else {
				prim = aux->getProx();
			}
			linker = aux->getProx();
			if(linker != NULL) {
				linker->setAnt(aux->getAnt());
			}
			else {
				ult = aux->getAnt();
			}
			delete aux;
			tam--;
		}
	}

	Nodo<T> *busca(T dado) const {			/* Implementação do método que procura um nodo na Lista, especificado
										 * pelo parâmetro, e retorna um ponteiro para esse Nodo */
		Nodo<T> *aux;
		T dta;
		aux = prim;
		while(aux != NULL) {
			dta = aux->getDado();
			if(dta == dado) {
				return aux;
			}
			aux = aux->getProx();
		}
		return aux;
	}
										 
	void imprime() const {				// Implementação do método que imprime na tela toda a lista
		Nodo<T> *aux;
		aux = prim;
		cout << "---------------------" << endl;
		if(aux == NULL) {
			cout << "Lista Vazia!" << endl;
		}
		while(aux != NULL) {
			cout << aux->getDado() << endl;
			aux = aux->getProx();
		}
		cout << "---------------------" << endl;
	}
	
	void imprime(Nodo<T> *n) const {				/* Implementação do método que imprime na tela um único Nodo,
											 * especificado pelo parâmetro */
		cout << "---------------------" << endl;
		if(n == NULL) {
			cout << "Elemento não encontrado!" << endl;
		}
		else {
			cout << n->getDado() << endl;
		}
		cout << "---------------------" << endl;
	}
										 
	int getTamanho() const{			// Implementação do método que retorna o tamanho da Lista
		return tam;
	}
	
	Nodo<T> *getPrimeiro() const{	// Implementação do método que retorna um ponteiro para o primeiro elemento da Lista
		return prim;
	}
	
	Nodo<T> *getUltimo() const{		// Implementação do método que retorna um ponteiro para o último elemento da Lista
		return ult;
	}
	
	/* OBS.: a palavra reservada "const" utilizada nos últimos seis métodos indica
	 * que eles não alteram o estado interno do objeto*/ 
	
};						// Fim da Implementação da classe Lista

#endif
