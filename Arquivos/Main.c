#include "Estruturas.h"
#include "Funções.h"


int main () {
        int Vetor[TAM], Escolhidos[4];
	int comando, Ordena;	
	for (;;) {	
		printf ("1 - Jogar\n2 - Comparar Algortimos\n");
		scanf ("%d", &comando);
		switch (comando) {
			case 1:
			printf ("Digite 4 Valores de 1 a 50\n");
			LerDados (Escolhidos);
			GeraVetor (Vetor);
			//Sorteia o Algoritmo para Ordenar o Vetor
			srand (time (NULL));
			Ordena = rand() % 4;
			
			switch (Ordena) {
			
				case 0:
				printf ("O Vetor Foi Ordenado Pelo SelectSort\n");
				SelectSort (Vetor);
				break;
				
				case 1:
				printf ("O Vetor Foi Ordenado Pelo BubbleSort\n");
				BubbleSort (Vetor);
				break;
			
				case 2:
				printf ("O Vetor Foi Ordenado Pelo QuickSort Recursivo\n");
				QuickSortRecursivo (Vetor, 0, TAM);
				break;
				
				case 3:
				printf ("O Vetor Foi Ordenado Pelo QuickSort Iterativo\n");
				QuickSortIterativo (Vetor, 0, TAM);
				break;
			}
			//Chama a Pesquisa 
			VerificaNumero (Vetor, Escolhidos);
			ImprimeVetor (Vetor);
			break;
		
			//Tempo de Execução dos programas
			case 2:
			TempoSelectSort (Vetor);
			TempoBubbleSort (Vetor);
			TempoQuickSortRecursivo (Vetor);
			TempoQuickSortIterativo (Vetor);
		}
	}
}
