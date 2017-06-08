//Arquivo com os  algoritmos de busca
#include "Estruturas.h"

//Algoritmo de Pesquisa Binaria
int PesquisaBinaria (int *Vetor, int Elem) {
	int meio, esquerda, direita;

	esquerda = 0;
	direita = TAM - 1;
	
	do {
		meio = (esquerda + direita)/2;
		if (Elem > Vetor[meio]) 
			esquerda = meio + 1;
		else
			direita = meio - 1;
	} while (Elem != Vetor[meio] && esquerda <= direita);
	if (Elem == Vetor [meio])
		return (meio);
	else
		return -1; //return -1 pq o se o elemento estiver na primeira posição irá retornar 0 (posição que ele se encontra no vetor)
}

//Algoritmo de Pesquisa Sequencial
int PesquisaSequencial(int *Vetor, int Elem) {
	int i;

	for (i = 0; i < TAM; i++) {
		if (Vetor[i] == Elem) 
			return i;
	}
	return -1; //-1 pq o elemento pode estar na posição zero 
}

//Chama as funções de Pesqusia para procurar o número no vetor
void VerificaNumero (int *Vetor, int *Escolhidos) {
	int i, acertos;
	
	acertos = 0;
	//os dois primeiros numeros serão buscados pela PesquisaSequencial
	for (i = 0; i < 2; i++) 
		if (PesquisaSequencial (Vetor, Escolhidos[i]) != -1) {
			printf ("Acertou o Numero %d, Parabéns\n", Escolhidos[i]);
			acertos++;
		}
	//os dois ultimos numeros serão buscados pela PesquisaBinaria
	for (i = i; i < 4; i++)
		if (PesquisaBinaria (Vetor, Escolhidos[i]) != -1) {
			printf ("Acertou o Numero %d, Parabéns\n", Escolhidos[i]);
			acertos++;
		}
	printf ("O Total de Acertos foi de: %d\n", acertos);
}
