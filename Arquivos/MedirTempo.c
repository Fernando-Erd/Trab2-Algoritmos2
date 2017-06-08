#include "Funções.h"
#include "Estruturas.h"

//Calcula o Tempo da Execução do SelectSort
void TempoSelectSort (int *Vetor) {
 	struct timeval inicio, final;
	int tmili, i;
	
	gettimeofday(&inicio, NULL);
	for (i = 0; i < 10000; i ++) {
       		GeraVetor(Vetor);	
		SelectSort (Vetor);
	}
    	gettimeofday(&final, NULL);
    	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	printf ("O SelectSort Demorou %d Centesimos\n", tmili);
}

//Calcula o Tempo da Execução do BubbleSort
void TempoBubbleSort (int *Vetor) {
 	struct timeval inicio, final;
	int tmili, i;

	gettimeofday(&inicio, NULL);
	for (i = 0; i < 10000; i ++) {
       		GeraVetor(Vetor);
		BubbleSort (Vetor);
	}
    	gettimeofday(&final, NULL);
    	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	printf ("O BubbleSort Demorou %d Centesimos\n", tmili);
}

//Calcula o Tempo da Execução do QuickSort Recursivo
void TempoQuickSortRecursivo (int *Vetor) {
 	struct timeval inicio, final;
	int tmili, i;

	gettimeofday(&inicio, NULL);
	for (i = 0; i < 10000; i ++) {
       		GeraVetor(Vetor);
		QuickSortRecursivo (Vetor, 0, TAM);
	}
    	gettimeofday(&final, NULL);
    	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	printf ("O QuickSort Recursivo Demorou %d Centesimos\n", tmili);
}

//Calcula o Tempo da Execução do QuickSort Iterativo
void TempoQuickSortIterativo (int *Vetor) {
 	struct timeval inicio, final;
	int tmili, i;

	gettimeofday(&inicio, NULL);
	for (i = 0; i < 10000; i ++) {
       		GeraVetor(Vetor);
		QuickSortIterativo (Vetor, 0, TAM);
	}
    	gettimeofday(&final, NULL);
    	tmili = (int) (1000 * (final.tv_sec - inicio.tv_sec) + (final.tv_usec - inicio.tv_usec) / 1000);
	printf ("O QuickSort Iterativo Demorou %d Centesimos\n", tmili);
}

