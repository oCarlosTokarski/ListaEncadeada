#include <iostream>
using namespace std;

struct No{
	int dado;
	No* prox;
};

No* inicio = nullptr;

void inserirInicio(int val){
	struct No *novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = val;
	novo->prox = inicio;
	inicio = novo;
}

void inserirFinal(int val){
	struct No *novo = (struct No*) malloc(sizeof(struct No));
	novo->dado = val;
	novo->prox = nullptr;
	
	if(inicio == nullptr){
		inicio = novo;
		return;
	}
	
	No* aux = inicio;
	while(aux->prox != nullptr){
		aux = aux->prox;		
	}
	
	aux->prox = novo;
}

void inserirApos(int val, int apos){
	No* aux = inicio;
	
	while(aux != nullptr && aux->dado != apos){
		aux = aux->prox;
	}
	
	if(aux!=nullptr){
		No* novo = new No;
		novo->dado = val;
		novo->prox = aux->prox;
		aux->prox = novo;
	}else{
		cout << "Valor referencia nao encontrado" << endl;
	}
}

void remover(int val){
	No* atual = inicio;
	No* anterior = nullptr;
	
	while(atual != nullptr && atual->dado != val){
		anterior = atual;
		atual = atual->prox;
	}
	
	if(atual == nullptr){
		cout << "Valor nao encontrado" << endl;
		return;
	}
	
	if(anterior == nullptr){
		inicio = atual->prox;
	}else{
		anterior->prox = atual->prox;
	}
	
	free(atual);
}


void buscar(int val){
	No* aux = inicio;
	
	while(aux != nullptr){
		if(aux->dado == val){
			cout << "Valor encontrado!" << endl;
			return;
		}
		aux = aux->prox;
	}
	
	cout << "Valor nao encontrado" << endl;
}

void exibir(){
	No* aux = inicio;
	while(aux != nullptr){
		cout << aux->dado << " -> ";
		aux = aux->prox;
	}
	cout << "NULL" << endl;
}


int main(int argc, char** argv) {

	int opcao, valor, ref;
	
	do{
		cout << "Menu " << endl;
		cout << "1 -Inserir no inicio" << endl;
		cout << "2 -Inserir no final " << endl;
		cout << "3 -Inserir apos valor " << endl;
		cout << "4 -Remover valor " << endl;
		cout << "5 -Buscar valor " << endl;
		cout << "6 -Exibir lista " << endl;
		cout << "0 -Sair " << endl;
		cout << "Escolha uma opcao: ";
		
		cin >> opcao;
		
		switch(opcao){
			case 1:
				cout << "Valor: ";
				    cin >> valor;
				inserirInicio(valor);
				break;
			case 2:
				cout << "Valor: ";
				    cin >> valor;
				inserirFinal(valor);
				break;
			case 3:
				cout << "Inserir apos qual valor?: ";
				    cin >> ref;
				cout << "Valor: ";
				    cin >> valor;
				inserirApos(valor, ref);
				break;
			case 4:
				cout << "Qual valor remover? ";
				    cin >> valor;
				remover(valor);
				break;
			case 5:
                cout << "Qual valor deseja buscar? ";
                    cin >> valor;
                buscar(valor);
				break;
			case 6:
				exibir();
				break;
			case 0:
				break;
			default:
				cout << "Opcao invalida" << endl;
		}
	}while(opcao != 0);	

	return 0;
}
