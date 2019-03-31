//teste de funçao.... algoritmo de ordenação por vencedor by joão carlos
#include <stdio.h>
#include <stdlib.h>

void ordenar(int v[], int tam);

int main()
{

	int v[] = {6,1,5,2,6,9,3,6,7,56,9,4,10,15,13,2,17,29,5,80,1,3};
	
	int tam = sizeof(v)/sizeof(v[0]);
    
	int i;

	for(i=0; i<tam; i++)
	{
		printf("%d\n",v[i]);
	}

	printf("\n");

	ordenar(v, tam);

	for(i=0; i<tam; i++)
	{
		printf("%d\n",v[i]);
	}
}

void ordenar(int v[], int tam)
{
	int menor = 0, pm=0, troca=0, i,j;
    
    for(i=0; i<tam; i++)
    { 	
    	menor = v[i];
    	pm = i; 
    	
    	for(j=pm; j<tam; j++)
    	{ 
         	if(menor >= v[j])
         	{
         		menor = v[j];
         		pm = j;
         	} 
    	}

        troca = v[i]; 
        v[i] = menor; 
        v[pm] = troca;  
        printf("\raguarde...ordenando...");
    }

}
