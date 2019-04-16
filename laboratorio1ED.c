#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"liblab.h"

void main(){
	//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
	//unNumero: Número digitado por usuario para ser buscado.	 
	int tamano = 10,max = 40, unNumero;
	
	//Se llama al módulo creaListaNumerosVacia y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
	ListaNumeros *nuevaLista = creaListaNumerosVacia(tamano);
	//Se llama al módulo imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
	imprimirLista(nuevaLista);
	
	//Se llama al módulo creaListaNumerosLlena y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
	ListaNumeros *unaListaNumeros = creaListaNumerosLlena(tamano, max);
	//Se llama al procedimiento imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
	imprimirLista(unaListaNumeros);
	
	//El usuario digita un número para ser buscado dentro de la lista.
	printf("\nDigite un número para buscarlo: ");
	scanf("%i",&unNumero);
	
	//llama a la función buscaNumeroEnListaNumero, si encuentra un número: retorna 1 y si no lo encuentra retorna: -1.
	if(buscaNumeroEnListaNumeros(unaListaNumeros, unNumero)!=(-1)){
		printf("\nNúmero %i encontrado\n", unNumero);
	}else{
		printf("\nEl número %i no ha sido encontrado\n", unNumero);
	}
	
	//llama a la función eliminaListaNumeros, donde se libera la memoria creada para "unaListaNumeros" y "arreglo". 
	if(eliminaListaNumeros(unaListaNumeros))
	{
	printf("\nLista eliminada con éxito\n");
	}
	else{
	printf("\nNo hay lista para eliminar");
	}	
}


