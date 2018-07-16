typedef struct Elemento
{
	char *palavra;
	int quantidade;
	struct Elemento *prox;
} Elemento;

typedef struct Lista
{
	Elemento *primeiro;
	Elemento *ultimo;
	int tamanho;
}Lista;

// Funcao que ordena os caracteres
int compara_caractere (const void *a, const void *b);
// Funcao que ordena os numeros
int compara_numeros (const void *a, const void *b);
// Funcao que cria lista vazia
Lista *cria_lista();
// Funcao que insere um vetor ordenado na lista
void insere_lista(Lista *lista, char *vetor, int tam);
// Funcao que pesquisa se existe elemento na lista
Elemento *pesquisa_lista(Lista *lista, char* vetor);
// Funcao que exibe meu resultado
void exibe_resultado(Lista *lista);
// FUncao que libera a lista
void libera_lista(Lista *lista);
