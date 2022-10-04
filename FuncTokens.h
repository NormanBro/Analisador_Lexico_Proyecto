#ifndef FUNCTOKENS_H_INCLUDED
#define FUNCTOKENS_H_INCLUDED

enum TipoToken
{
		PalRes,
		Id,
		Num,
		Sim,
		Cad,
};

struct Token
{
	enum TipoToken Tipo;
	char Lexema[80];
	int NCol;
	int NLinea;
	char Nombre[80];
};

struct nodo
{
    struct Token info;
    struct nodo *izq;
    struct nodo *der;
};

struct nodo *raiz;
struct nodo *actual;


void insertar(struct Token token);
void imprimirLista(struct nodo *reco);

#endif // FUNCTOKENS_H_INCLUDED
