#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int compara_caractere (const void *a, const void *b)
{
	return (*(char*)a - *(char*)b);
}

int compara_numeros (const void *a, const void *b)
{
	return (*(int*)b - *(int*)a);
}

Lista *cria_lista()
{
	Lista *lista;
	lista = (Lista*)malloc(sizeof(Lista));
	
	lista->tamanho = 0;
	lista->primeiro = (Elemento*)malloc(sizeof(Elemento));
	lista->primeiro->prox = NULL;
	lista->ultimo = lista->primeiro;
	
	return lista;
}

void insere_lista(Lista *lista, char *vetor, int tam)
{

	Elemento *aux, *aux2;

	aux2 = pesquisa_lista(lista, vetor);

	if(aux2 == NULL)
	{	
		aux = (Elemento*)malloc(sizeof(Elemento));
		aux->quantidade = 0;
		aux->palavra = (char*)malloc((tam+1)*sizeof(char));
		strcpy(aux->palavra, vetor);
		aux->quantidade += 1;
		aux->prox = NULL;
		
		// Ligo os componentes
		lista->tamanho += 1;
		lista->ultimo->prox = aux;
		lista->ultimo = lista->ultimo->prox;
	}

	else aux2->quantidade += 1;
}

Elemento *pesquisa_lista(Lista *lista, char *vetor)
{
	Elemento *aux;
	aux = lista->primeiro->prox;

	while(aux != NULL)
	{
		if(strcmp(vetor, aux->palavra) == 0)
				return aux;
		else
			aux = aux->prox;
	}

	return NULL;
}

void exibe_resultado(Lista *lista)
{
	Elemento *aux;
	aux = lista->primeiro->prox;
	int *vetor;
	vetor = (int*)malloc(lista->tamanho*sizeof(int));
	int i = 0;

	while(aux != NULL)
	{
		vetor[i] = aux->quantidade;
		aux = aux->prox;
		i++;
	}

	qsort(vetor, lista->tamanho, sizeof(int), compara_numeros);

	for (i = 0; i < lista->tamanho; i++)
	{
		printf("%d", vetor[i]);
		if(i+1 != lista->tamanho)
			printf(" ");
	}
	printf("\n");
	free(vetor);
}

void libera_lista(Lista *lista)
{
	Elemento *aux, *x;
	aux = lista->primeiro->prox;
	
	while(aux != NULL)
	{
		x = aux;
		aux = aux->prox;
		free(x->palavra);
		free(x);
	}
	
	free(lista->primeiro);
	free(lista);
}
