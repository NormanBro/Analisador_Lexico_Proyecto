#include <stdio.h>
#include <stdlib.h>
#include "FuncTokens.h"



void insertar(struct Token token)
{
	struct nodo *nuevo;
	nuevo = malloc(sizeof(struct nodo));

	nuevo->info = token;
	nuevo->izq	= NULL;
	nuevo->der	= NULL;

	if(raiz == NULL)
	{
		raiz = nuevo;
		actual = nuevo;
	}
	else
	{
		nuevo->izq	= actual;
		actual->der = nuevo;
		actual = nuevo;
	}
}


void imprimirLista(struct nodo *reco)
{
    struct nodo *aux;
    aux = reco;
    printf("|   Info    |   Tipo    |   NumColumna  |   NumFila |   Nombre  |\n");
    while(aux != NULL){

        printf("|   %s    |   %d    |   %d  |   %d  |   %s  |\n",aux->info.Lexema,aux->info.Tipo,aux->info.NCol,aux->info.NLinea,aux->info.Nombre);

        aux = aux->der;
    }

}
