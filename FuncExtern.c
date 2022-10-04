#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "FuncTokens.h"
void Insertar(char Cadena[80]){
    struct Token token;
    token.Tipo=PalRes;
    strcpy(token.Lexema,Cadena);
    insertar(token);
    printf("%s \n",token.Lexema);
}
