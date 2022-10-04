#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "AutoComilador.h"
#include "FuncTokens.h"
#include "FileArch.h"
#include "Funcposición.h"


void AutoID(struct Token token){
    char Caracter;
    char Cadena[80];

    int estado=1;
    int inc=0;
    int finalizar=0;
    fseek(Arch,-1,SEEK_CUR);

    while(finalizar==0 || feof(Arch)==0){
        Caracter=fgetc(Arch);
        IncColum();

        switch(estado){
            case 1:
                if(isalpha(Caracter)){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=2;
                }else{
                    finalizar=1;
                }
                break;
            case 2:
                if(isalnum(Caracter)){

                    Cadena[inc]=Caracter;
                    inc++;
                }else{
                    finalizar=1;
                }
                break;
        }//Switch

        if(finalizar==1){
            break;
        }
    }//While
    if(estado==2){
        fseek(Arch,-1,SEEK_CUR);
        DecColum();
        token.Tipo=PalRes;
        strcpy(token.Nombre,"Indentificador");
        strcpy(token.Lexema,Cadena);
        insertar(token);
    }


}
void AutoNumer(struct Token token){
    char Caracter;
    char Cadena[80];

    int estado=1;
    int inc=0;
    int finalizar=0;
    fseek(Arch,-1,SEEK_CUR);

    while(finalizar==0 || feof(Arch)==0){
        Caracter=fgetc(Arch);
        IncColum();
        switch(estado){
            case 1:
                if(isdigit(Caracter)){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=2;
                }else{
                    finalizar=1;
                }
                break;
            case 2:
                if(isdigit(Caracter)){
                    Cadena[inc]=Caracter;
                    inc++;

                }else{
                    finalizar=1;
                }
                break;
        }//Switch
        if(finalizar==1){
            break;
        }
    }//While
    if(estado==2){
        fseek(Arch,-1,SEEK_CUR);
        DecColum();
        token.Tipo=Num;
        strcpy(token.Nombre,"Numero");
        strcpy(token.Lexema,Cadena);
        insertar(token);
    }

}
void AutoSymbol(struct Token token){
    char Caracter;
    char Cadena[80];

    int estado=1;
    int inc=0;
    int finalizar=0;
    fseek(Arch,-1,SEEK_CUR);

    while(finalizar==0 || feof(Arch)==0){
        Caracter=fgetc(Arch);
        IncColum();
        switch(estado){
            case 1:
                if(Caracter=='+' || Caracter=='-' || Caracter=='*' || Caracter=='/' || Caracter=='=' || Caracter==';' || Caracter=='[' || Caracter=='{' ||Caracter=='}' || Caracter==']'){
                    Cadena[inc]=Caracter;
                    inc++;
                    finalizar=1;
                    estado=2;
                }else if(Caracter=='!' || Caracter=='<' || Caracter=='>' || Caracter=='='){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=3;
                }else if(Caracter=='&'){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=5;
                }
                else if(Caracter=='|'){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=6;
                }
                else{
                    finalizar=1;
                }
                break;
            case 3:
                if(Caracter=='='){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=4;
                    finalizar=1;
                }else{
                    finalizar=1;
                }
                break;
            case 5:
                if(Caracter=='&'){
                    Cadena[inc]=Caracter;
                    inc++;
                    finalizar=1;
                    estado=4;
                }else{
                    finalizar=1;
                }
                break;
            case 6:
                if(Caracter=='|'){
                    Cadena[inc]=Caracter;
                    inc++;
                    finalizar=1;
                    estado=4;
                }else{
                    finalizar=1;
                }
                break;
        }//switch

        if(finalizar==1){
            break;
        }

    }//while
    if(estado==2 || estado==3 || estado==4){
        //fseek(Arch,-1,SEEK_CUR);
        DecColum();
        token.Tipo=Sim;
        strcpy(token.Nombre,"Simbolo");
        strcpy(token.Lexema,Cadena);
        insertar(token);
    }

}
void AutoCadena(struct Token token){
    char Caracter;
    char Cadena[80];

    int estado=1;
    int inc=0;
    int finalizar=0;
    fseek(Arch,-1,SEEK_CUR);
    while (feof(Arch==0) || finalizar==0){
        Caracter=fgetc(Arch);
        IncColum();
        switch(estado){
            case 1:
                if(Caracter=='"'){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=2;
                }else{
                    finalizar=1;
                }
                break;
            case 2:
                if(Caracter=='"'){
                    Cadena[inc]=Caracter;
                    inc++;
                    estado=3;
                    finalizar=1;
                }else{
                    Cadena[inc]=Caracter;
                    inc++;
                }
                break;
        }//switch
        if(finalizar==1){
            break;
        }
    }//While
        if(estado==3){
            DecColum();
            token.Tipo=Cad;
            strcpy(token.Nombre,"Cadena");
            strcpy(token.Lexema,Cadena);
            insertar(token);
        }
}
