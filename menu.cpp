#include <stdio.h>
#include <stdlib.h>
#include <new>
#include <string>
#include <iostream>

using namespace std;

struct pessoa{
	string nome;
	int rg;
};

void limpaTela() {
	system("CLS");
}

void imprimeSequencial(pessoa *ponteiroSequencial, int tam) {
	
	int i;
	
	for(i = 0; i < tam; i++) {
		cout << i << " - " << ponteiroSequencial[i].nome << ", " << ponteiroSequencial[i].rg << "\n";
	}
	
	cout << "\n\n";
}

void adcComecoSequencial(pessoa *&ponteiroSequencial, // *& = contexto global
 string nome, int rg, int *tamanhoDaLista) {
	
	if(*tamanhoDaLista == 0) {
		ponteiroSequencial[0].nome = nome;
    	ponteiroSequencial[0].rg = rg;
	} else {
		// Caso o vetor já tenha membros
		pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista + 1];
        novaListaSequencial[0].nome = nome;
        novaListaSequencial[0].rg = rg;
    
        // Passa os elementos do vetor antigo para o novo
        int i;
    
	    for(i = 0; i < *tamanhoDaLista; i++) {
	    	novaListaSequencial[i + 1].nome = ponteiroSequencial[i].nome;
	    	novaListaSequencial[i + 1].rg = ponteiroSequencial[i].rg;
		}
	
		// Atualiza o ponteiro para lista nova
		ponteiroSequencial = novaListaSequencial;
		// Atualiza tamanho da lista
		
		}
		
		*tamanhoDaLista += 1;
}

void adcFinalSequencial(pessoa *&ponteiroSequencial,
 string nome, int rg, int *tamanhoDaLista) {
	
	if(*tamanhoDaLista == 0) {
		ponteiroSequencial[0].nome = nome;
    	ponteiroSequencial[0].rg = rg;
	} else {
		int tam = *tamanhoDaLista + 1;
		// Caso o vetor já tenha membros
		pessoa *novaListaSequencial = new pessoa[tam];
        novaListaSequencial[tam - 1].nome = nome;
        novaListaSequencial[tam - 1].rg = rg;
    
        // Passa os elementos do vetor antigo para o novo
        int i;
    
	    for(i = 0; i < (tam - 1); i++) {
	    	novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
	    	novaListaSequencial[i].rg = ponteiroSequencial[i].rg;
		}
	
		// Atualiza o ponteiro para lista nova
		ponteiroSequencial = novaListaSequencial;
		// Atualiza tamanho da lista
		
		}
		
		*tamanhoDaLista += 1;
}

void adcPosicaoSequencial(pessoa *&ponteiroSequencial,
 string nome, int rg, int n, int *tamanhoDaLista) {
	
	int tam = *tamanhoDaLista + 1;
	pessoa *novaListaSequencial = new pessoa[tam];
    
    int i;
    
    for(i = 0; i < n; i++) {	
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;	
	}
	
	novaListaSequencial[n].nome = nome;
    novaListaSequencial[n].rg = rg;
    
    for(i = (n + 1); i < tam; i++) {	
        novaListaSequencial[i].nome = ponteiroSequencial[i - 1].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i - 1].rg;	
	}
		
	ponteiroSequencial = novaListaSequencial;
	    
	*tamanhoDaLista += 1; 
}

void removePrimeiro(pessoa *&ponteiroSequencial, int *tamanhoDaLista) {

	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista];
	
	int i;
    
    for(i = 0; i < (*tamanhoDaLista - 1); i++) {	
        novaListaSequencial[i].nome = ponteiroSequencial[i + 1].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i + 1].rg;	
	}
	
	ponteiroSequencial = novaListaSequencial;
	    
	*tamanhoDaLista -= 1; 
}

void removeFinal(pessoa *&ponteiroSequencial, int *tamanhoDaLista) {

	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista];
	
	int i;
    
    for(i = 0; i < (*tamanhoDaLista - 1); i++) {	
        novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
        novaListaSequencial[i].rg = ponteiroSequencial[i].rg;	
	}
	
	ponteiroSequencial = novaListaSequencial;
	    
	*tamanhoDaLista -= 1; 
}

void removeSequencial(pessoa *&ponteiroSequencial, int n, int *tamanhoDaLista) {
	
	pessoa *novaListaSequencial = new pessoa[*tamanhoDaLista];
    
    int i;
    
    for(i = 0; i < (*tamanhoDaLista - 1); i++) {	
 	  
 	    if(i < n) {
    	  novaListaSequencial[i].nome = ponteiroSequencial[i].nome;
          novaListaSequencial[i].rg = ponteiroSequencial[i].rg;	
        } else {
       	  novaListaSequencial[i].nome = ponteiroSequencial[i + 1].nome;
          novaListaSequencial[i].rg = ponteiroSequencial[i + 1].rg;	
		}	
	}
			
	ponteiroSequencial = novaListaSequencial;
	    
	*tamanhoDaLista -= 1; 
}

bool procuraRg(pessoa *&ponteiroSequencial, int rg, int *tamanhoDaLista) {
	
    int i;
    
    for(i = 0; i < *tamanhoDaLista; i++) {	
 	  
 	    if(ponteiroSequencial[i].rg == rg) {
    	  cout << "Encontrado: " << ponteiroSequencial[i].rg << ", pertencente a : "
	      << ponteiroSequencial[i].nome << "\n";
          return true;
        } 
	}
			
	cout << "RG de numero: " << rg << "não encontrado.\n";
	return false;
}

int main () {
	
	int funcaoDesejada = 1;
	
	// Ponteiro para a lista sequencial
	pessoa *ponteiroSequencial;
	
	int tamanhoDaLista = 0;
	
	pessoa *exemploListaSequencial = new pessoa[2];
	
	exemploListaSequencial[0].nome = "John";
	exemploListaSequencial[0].rg = 123;
	exemploListaSequencial[1].nome = "Nick";
	exemploListaSequencial[1].rg = 321; 
	
	// Faz o ponteiro principal apontar para o novo vetor
	ponteiroSequencial = exemploListaSequencial; 
		
	while(funcaoDesejada < 10 && funcaoDesejada > 0) {
		
		cout << "Operacoes: \n\n";
		cout << "1 - Insercao de um node no inicio da lista \n";
		cout << "2 - Insercao de um node no final da lista \n";
		cout << "3 - Insercao de um node na posicao N \n";
		cout << "4 - Retirar um node do Inicio da lista \n";
		cout << "5 - Retirar um node do fim da lista \n";
		cout << "6 - Retirar um node da posicao N \n";
		cout << "7 - Procurar um node com campo RG \n";
		cout << "8 - Imprimir a lista \n";
		cout << "9 - Sair so sistema \n";
		cout << "\n Escolha um numero e pressione ENTER \n";
		
		cin >> funcaoDesejada;
		
		limpaTela();
		
		// Variáveis usadas para as operações
		string nome;
		int rg, n;
		
		switch(funcaoDesejada) {
			case 1:
				
				cout << "1 - Insercao de um node no inicio da lista \n";
				cout << "Digite um nome: ";
				cin >> nome;
				cout << "Digite um RG: "; 
				cin >> rg;
				
				adcComecoSequencial(ponteiroSequencial, nome, rg, &tamanhoDaLista);
				limpaTela();
				
				cout << "Inserido com sucesso !\n";
				
				break;
			case 2:
				
				cout << "2 - Insercao de um node no final da lista \n";
				cout << "Digite um nome: ";
				cin >> nome;
				cout << "Digite um RG: "; 
				cin >> rg;
				
				adcFinalSequencial(ponteiroSequencial, nome, rg, &tamanhoDaLista);
				limpaTela();
				
				cout << "Inserido com sucesso !\n";
				
				break;
			case 3:
				
				cout << "3 - Insercao de um node na posicao N \n";
				cout << "Digite um nome: ";
				cin >> nome;
				cout << "Digite um RG: "; 
				cin >> rg;
				cout << "Digite uma posicao para armazenamento: "; 
				cin >> n;
				
				if(n == 0) {
					adcComecoSequencial(ponteiroSequencial, nome, rg, &tamanhoDaLista);
				} else if(n == tamanhoDaLista) {
					adcFinalSequencial(ponteiroSequencial, nome, rg, &tamanhoDaLista);
				} else {
					adcPosicaoSequencial(ponteiroSequencial, nome, rg, n, &tamanhoDaLista);
				}
				
				limpaTela();
				
				cout << "Inserido com sucesso !\n";
				
				break;
			case 4:
				
				cout << "4 - Retirar um node do Inicio da lista \n";
				
				removePrimeiro(ponteiroSequencial, &tamanhoDaLista);
				
				limpaTela();
				
				cout << "Remocao realizada !\n\n";
				
				break;
			case 5:
				
				cout << "5 - Retirar um node do Final da lista \n";
				
				removeFinal(ponteiroSequencial, &tamanhoDaLista);
				
				limpaTela();
				
				cout << "Remocao realizada !\n\n";
				
				break;
			case 6:
				
				cout << "6 - Retirar um node na posicao N \n";
				cout << "Digite a posicao a ser removida \n";
				cin >> n;
				
				if(n == tamanhoDaLista) {
					removeFinal(ponteiroSequencial, &tamanhoDaLista);
				} else if(n == 0) {
					removePrimeiro(ponteiroSequencial, &tamanhoDaLista);
				} else {
				  removeSequencial(ponteiroSequencial, n, &tamanhoDaLista);	
				}
				
				limpaTela();
			
				cout << "Remocao realizada !\n\n";
							
				break;
			case 7:
				
				cout << "7 - Procurar um node com campo RG \n";
				cout << "Digite um RG que vc procura \n";
				cin >> rg;
				
				procuraRg(ponteiroSequencial, rg, &tamanhoDaLista);
				
				break;
			case 8:
				
				limpaTela();
				
				imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
				
				break;
			case 9:
				funcaoDesejada = 0;
				
				cout << "\n Saiu do sistema \n";
				break;
		}
	}
	
	return 0;
}
