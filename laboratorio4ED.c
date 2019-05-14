#include "lab4ED.h"

void main(){
	char *letras,valor;
	AB *arbol = iniciaAB();
	int max,i, contador = 0, pausa;
	
	letras = leerTexto(&max);
	
	imprimirArreglo(letras);
	arbol = iniciaAB();
	printf("\n");
	i=0;
	while(i < max){
		valor = letras[i];
		//printf("\nentra valor : %c\n",valor);
		arbol = insertaValorAB(arbol,valor);
		//printf("nuevo arbol: %c",arbol->dato);
		//scanf("%i",&pausa);
		i++;
		//printf("\nentra al while\n");
	}
	imprimirArbol(arbol,contador);

}
