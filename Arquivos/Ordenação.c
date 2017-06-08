//Arquivo com os Algoritmos de Ordenação

#include "Estruturas.h"
//Função para trocar valores
void Troca (int *Vetor, int i, int j) {
	int aux;

	aux = Vetor[i];
	Vetor [i] = Vetor[j];
	Vetor [j] = aux;
}

//Algoritmo de Ordenação do SelectSort
void SelectSort (int *Vetor) {
	int i, j, menor;

	for (i = 0; i < TAM - 1; i++) {
		menor = i;
		for (j = i + 1; j < TAM; j++)
			if (Vetor[menor] > Vetor[j])
				menor = j;
		Troca (Vetor, i, menor);
	}
}

//Algoritmo de Ordenação do BubbleSort
void BubbleSort (int *Vetor) {
	bool trocou;
	int i;

	trocou = true;
	while (trocou) {
		trocou = false;
		for (i=0; i < TAM; i++) {
			if (Vetor[i] > Vetor[i+1]) {
				Troca(Vetor,i,i+1);
				trocou = true;
			}
		}
	}
}

//Acha a posicao da Mediana
int Mediana(int *Vetor, int esq, int dir) {
	int aux;
	aux = (dir+esq)/2; // elem. do meio do vetor
	
	//mediana dos 3 numeros

	if ( (Vetor[esq] >= Vetor[aux]) && (Vetor[esq] <= Vetor[dir]) )
	   return esq;
	
	else if ( (Vetor[esq] >= Vetor[dir]) && (Vetor[esq] <= Vetor[aux]) )
		return esq;
	
	else if ( (Vetor[dir] >= Vetor[aux]) && (Vetor[dir] <= Vetor[esq]) )
		return dir;

	else if ( (Vetor[dir] >= Vetor[esq]) && (Vetor[dir] <= Vetor[aux]) )
		return dir;
	
	else if ( (Vetor[aux] >= Vetor[esq]) && (Vetor[aux] <= Vetor[dir]) )
		return aux;
	
	else if ( (Vetor[aux] >= Vetor[dir]) && (Vetor[aux] <= Vetor[esq]) )
		return aux;

}

//Particiona o QuickSort
int Particao (int *Vetor, int esq, int dir) {
	int i,j,pivo,aux;
	aux = Mediana(Vetor,esq,dir);
	pivo = Vetor[aux];
	i = esq;
	j = dir;
	while (i < j) {
		
		while ( (Vetor[i] <= pivo) && (i < dir) )
			i++;

		while (Vetor[j] > pivo) 
			j--;

		if (i < j) 
			Troca(Vetor,j,i);
	}
	
	Vetor[esq] = Vetor[j];
	Vetor[j] = pivo;
  	return j;
}

//Algoritmo de Ordenação do QuickSort com Recursão
void QuickSortRecursivo (int Vetor[], int Esquerda, int Direita) {
	int pospivo;
	   if (Esquerda < Direita) {
		pospivo = Particao(Vetor, Esquerda, Direita);
		QuickSortRecursivo(Vetor,Esquerda,pospivo-1);
		QuickSortRecursivo(Vetor,pospivo+1,Direita);
	}
}

//Algoritmo de Ordenação do QuickSort Iterativo
void QuickSortIterativo (int Vetor[], int Esquerda, int Direita) {
	int Posicao;
	int Pilha[TAM];
	int top;

	top = -1;
	//Empilha os Indices
	Pilha[++top] = Esquerda;
	Pilha[++top] = Direita;
	while (top >= 0) {
		//Desempilha os Indices
		Direita = Pilha[top--];
		Esquerda = Pilha[top--];

		Posicao = Particao(Vetor, Esquerda, Direita);

		if (Posicao-1 > Esquerda) {
			//Empilha os Indices
			Pilha[++top] = Esquerda;
			Pilha[++top] = Posicao - 1;
        	}
       		 if (Posicao+1 < Direita) {
			//Empilha os Indices
        		Pilha[++top] = Posicao + 1;
        	    	Pilha[++top] = Direita;
        	}
    }
}
