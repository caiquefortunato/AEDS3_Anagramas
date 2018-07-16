#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main()
{
	Lista *lista;
	//lista = cria_lista();

	char *vetor;
	vetor = (char*)malloc(51*sizeof(char));
	int i;
	int entrada, tam;
	char caractere;

	scanf("%d", &entrada);
	for (i = 0; i < entrada; i++)
	{
		lista = cria_lista();
		while(1)
		{
			scanf("%s", vetor);
			tam = strlen(vetor);
			qsort(vetor, tam, sizeof(char), compara_caractere);
			insere_lista(lista, vetor, tam);

			scanf("%c", &caractere);
			if (caractere == ' ')
			{
				tam = 0;
			}
			if (caractere == '\n')
			{
				break;
			}
		}

		exibe_resultado(lista);
		
		libera_lista(lista);
	}


	free(vetor);

	return 0;
}
