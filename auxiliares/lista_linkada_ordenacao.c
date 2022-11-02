/*
	Lista Linkada + Ordenação com Bubble Sort
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct No
{
	int valor;
	struct No *proximo;
} No;

void adicionar_valor(int valor, No **inicial);
void listar_valores(No *inicial);
int comparar_valores(int valorA, int valorB);
void bubble_sort(No **inicial);

int main()
{
	No *inicial = NULL;
	
	adicionar_valor(1, &inicial);
	adicionar_valor(4, &inicial);
	adicionar_valor(5, &inicial);
	adicionar_valor(3, &inicial);
	adicionar_valor(2, &inicial);
	
	listar_valores(inicial);
	
	bubble_sort(&inicial);
	
	listar_valores(inicial);
	
	return 0;
}

void adicionar_valor(int valor, No **inicial)
{
	No *novo_no = (No*)malloc(sizeof(No));
	
	novo_no->valor = valor;
	novo_no->proximo = NULL;
	
	if(*inicial == NULL)
	{
		*inicial = novo_no;
		return;
	}
	
	No *ultimo_no = *inicial;
	
	while(ultimo_no->proximo != NULL)
		ultimo_no = ultimo_no->proximo;
		
	ultimo_no->proximo = novo_no;
}

void listar_valores(No *inicial)
{
	printf("\n-- Listando --\n");
	
	No *aux = inicial;
	
	if(aux == NULL)
	{
		printf("Lista vazia");
		printf("\n\n");
		system("pause");
		return;
	}
	
	while(aux != NULL)
	{
		printf("%i ", aux->valor);
		
		aux = aux->proximo;
	}
	
	printf("\n\n");
	system("pause");
}

int comparar_valores(int valorA, int valorB)
{
	if(valorA > valorB) return 1;
	else if(valorA == valorB) return 0;
	else return -1;
}

void bubble_sort(No **inicial)
{
	// Caso lista contenha 0 ou 1 elemento
	if(*inicial == NULL || (*inicial)->proximo == NULL) return;
	
	No *auxiliar = *inicial, *copia;
	int auxiliar_valor;
	
	while(auxiliar != NULL)
	{
		copia = auxiliar->proximo;
		
		while(copia != NULL)
		{
			if(comparar_valores(auxiliar->valor, copia->valor) > 0)
			{
				auxiliar_valor = auxiliar->valor;
				auxiliar->valor = copia->valor;
				copia->valor = auxiliar_valor;
			}
			
			copia = copia->proximo;
		}
		
		auxiliar = auxiliar->proximo;
	}
}
