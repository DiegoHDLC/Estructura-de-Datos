#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"liblab2.h"

void main(){
	//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
	//unNumero: Número digitado por usuario para ser buscado.	 
	int tamano = 5,max = 40, unNumero,i=0,p,opcion,dato;
	char salir;
	//struct timespec start, finish; 
   
	system("clear");
	printf("1.-Caso base\n2.-Segundo Laboratorio\n3.-Salir\nOpcion: ");
	scanf("%i",&opcion);
	//CASO BASE
	//Se llama al módulo creaListaNumerosLlena y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
	ListaNumeros *unaListaNumeros = creaListaNumerosLlena(tamano, max);
	ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
	ListaNumeros *lista3 = creaListaNumerosVacia(tamano);
	//Se llama al procedimiento imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
	switch(opcion){
		case 1:
			imprimirLista(unaListaNumeros);
			//El usuario digita un número para ser buscado dentro de la lista.
			printf("\nDigite un número para buscarlo: ");
			scanf("%i",&unNumero);
	
			//llama a la función buscaNumeroEnListaNumero, si encuentra un número: retorna 1 y si no lo encuentra retorna: -1.
			if(buscaSecuencialNumeroEnListaNumeros(unaListaNumeros, unNumero)!=(-1)){
				printf("\nNúmero %i encontrado\n", unNumero);
			}else{
				printf("\nEl número %i no ha sido encontrado\n", unNumero);
			}
		
			//llama a la función eliminaListaNumeros, donde se libera la memoria creada para "unaListaNumeros" y "arreglo". 
			if(eliminaListaNumeros(unaListaNumeros)){
				printf("\nLista eliminada con éxito\n");
			}
			else{
				printf("\nNo hay lista para eliminar");
			}
			;break;
		case 2:
//SEGUNDO LABORATORIO
//1.- Insertar al final y buscar secuencialmente.

			//Se llama al módulo creaListaNumerosVacia y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
		
			//Se llama al módulo imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
			system("clear");
			printf("1.-Insertar al final y buscar secuencialmente\n2.-Insertar en orden y usar busqueda binaria\n3.-Insertar siempre al final, ordenar despúes de cada inserción y usar busqueda binaria\nOpcion: ");
			scanf("%i",&opcion);
			switch(opcion){
				case 1:
					//clock_gettime(CLOCK_REALTIME, &start); 
					imprimirLista(lista1);

					//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).
					system("clear");
					imprimirLista(lista1);
					while(i<lista1->cantidadMaxima){
						printf("Digite un número:"); 
						scanf("%i",&unNumero);
						system("clear");
						insertaFinalLista(lista1, unNumero);
						imprimirLista(lista1);
						i++;
					}
	
					//Busca secuencialmente un numero en el arreglo.
					printf("\nQué Número desea buscar en la lista?\nNúmero: ");
					scanf("%i",&unNumero);
					if(buscaSecuencialNumeroEnListaNumeros(lista1, unNumero)!=(-1)){
						printf("\nNúmero %i encontrado\n", unNumero);
					}else{
						printf("\nEl número %i no ha sido encontrado\n", unNumero);
					}
					//llama a la función eliminaListaNumeros, donde se libera la memoria creada para "unaListaNumeros" y "arreglo". 
					if(eliminaListaNumeros(lista1)){
						printf("\nLista eliminada con éxito\n");
					}
					else{
						printf("\nNo hay lista para eliminar");
					}
					
					;break;
					//clock_gettime(CLOCK_REALTIME, &finish); 
				case 2:
//2.- Inserta en orden y usa búsqueda binaria.
	
					//Inserta en un numero en una lista ordenanda.
					ordenamientoLista(lista1);
					imprimirLista(lista1);
					calcularEspacio(lista1);
					while(i<lista1->cantidadMaxima){
						printf("\nDigite un número:"); 
						scanf("%i",&unNumero);
						system("clear");
						insertaEnOrden(lista1,unNumero);
						imprimirLista(lista1);
						i++;
					}
					//Busca un numero por busqueda binaria
					if(lista1->cantidadActual == lista1->cantidadMaxima){
						//primero ordenando de menor a mayor para utilizar busqueda binaria.
						ordenarMenorMayor(lista1);
						imprimirLista(lista1);
						printf("\nQué Número desea buscar en la lista?\nNúmero: ");
						scanf("%i",&dato);
						if(busquedaBinaria(lista1,dato)){
							printf("\nNúmero %i encontrado\n", dato);
						}else{
							printf("\nEl número %i no ha sido encontrado\n",dato);
						}
					}
					else{
						printf("\nPrimero llene el arreglo de numeros");
					}
					;break;
				case 3:
//3.- Insertar siempre al final, ordenar con quicksort después de cada inserción, y usar busqueda binaria
					i=0;
					while(i<lista3->cantidadMaxima){
						printf("Digite un número:"); 
						scanf("%i",&unNumero);
						system("clear");
						insertaFinalLista(lista3, unNumero);
						ordenamientoLista(lista3);
						imprimirLista(lista3);
						i++;
					}
					printf("\nQué Número desea buscar en la lista?\nNúmero: ");
					scanf("%i",&dato);
					if(busquedaBinaria(lista3,dato)!=(-1)){
						printf("\nNúmero %i encontrado\n", dato);
					}else{
						printf("\nEl número %i no ha sido encontrado\n",dato);
						}
					;break;
	
			}
			;break;
		case 3 :break;
	}
}


