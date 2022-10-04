#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "FileArch.h"
#include "Funcposición.h"
#include "FuncTokens.h"
#include "AutoComilador.h"

int main()
{
    Arch=fopen("Codigo.txt","r");
    char Caract;

    NFila=1;
    NColumna=1;
    raiz=NULL;
    actual=NULL;
    struct Token token;

    if(Arch==NULL){
        printf("ERROR de encontrar Archivo");
        return 1;
    }

    while(feof(Arch)==0){
        Caract=fgetc(Arch);

        if(Caract=='ÿ'){
            Caract='\n';
        }

        if(Caract=='\n'){
            IncFila();
            VaciarColum();
        }
        if(isalpha(Caract)){
            token.NCol=NColumna;
            token.NLinea=NFila;
            AutoID(token);
        }else if(isdigit(Caract)){
            token.NCol=NColumna;
            token.NLinea=NFila;
            AutoNumer(token);
        }else if(isspace(Caract)){
            IncColum();
        }else if(Caract=='"'){
            token.NCol=NColumna;
            token.NLinea=NFila;
            AutoCadena(token);
        }
        else{
            token.NCol=NColumna;
            token.NLinea=NFila;
            AutoSymbol(token);
        }

    }

    imprimirLista(raiz);
    printf("Cantidad de Filas: %d \n",NFila);
    return 0;
}
