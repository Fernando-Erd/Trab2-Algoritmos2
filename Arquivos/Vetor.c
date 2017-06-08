#include "Estruturas.h"

//Lê os 4 números que o usuario entra
void LerDados (int *Vetor) {
	int i;
	printf ("Digite 4 números: ");
	for (i = 0; i < 4; i++) 
		scanf ("%d", &Vetor[i]);
}


//Função que gera valores aleatorios para o vetor
void GeraVetor (int *Vetor) {
        int i;
 
        srand (time(NULL));
        for (i=0; i < TAM; i++)
                Vetor[i] = (rand () % NUMMAX) + 1;
}

//Função que imprime o vetor 
void ImprimeVetor (int *Vetor) {
        int i;
  
	printf ("Pos: "); 
        for (i=0; i < TAM; i++)
                printf ("\t%d", i);
        printf ("\n");
	printf ("Num: ");
        for (i=0; i < TAM; i++)
                printf ("\t%d", Vetor[i]);
        printf ("\n");
}
