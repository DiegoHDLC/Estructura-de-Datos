#include<stdio.h>
#include<stdlib.h>
#include<time.h>	
#include <unistd.h>
#include"liblab2.h"

void main(){
	//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
	//unNumero: Número digitado por usuario para ser buscado.	 
	int tamano = 1000,max = 100000, unNumero,i=0,p,opcion,dato,pasadas=0,pausa;
	unsigned long tInsFinalSec, tInsFinalNSec, tiempoTotalIns;
	unsigned long tBSecuencialSec, tBSecuencialNSec, tiempoTotalBus;
	unsigned long tInsOrdSec, tInsOrdNSec, tiempoTotalInsOrd;
	unsigned long tBBinariaSec, tBBinariaNSec, tiempoTotalBusBin;
	srand(time(NULL));
	char salir;
	struct timespec start, finish;
   
	system("clear");
	printf("1.-Caso base\n2.-Segundo Laboratorio\n3.-Salir\nOpcion: ");
	scanf("%i",&opcion);
	//CASO BASE
	//Se llama al módulo creaListaNumerosLlena y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
	ListaNumeros *unaListaNumeros = creaListaNumerosVacia(tamano);
	ListaNumeros *lista1 = creaListaNumerosVacia(tamano);//creaListaNumerosVacia(tamano);
	ListaNumeros *lista3 = creaListaNumerosVacia(tamano);//creaListaNumerosVacia(tamano);
	//Se llama al procedimiento imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
	switch(opcion){
		case 1:
			imprimirLista(unaListaNumeros);
			//El usuario digita un número para ser buscado dentro de la lista.
			printf("Digite un número para buscarlo: ");
			scanf("%i",&unNumero);
			//clock_gettime(CLOCK_REALTIME, &start);
	
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
			
			printf("1.-Insertar al final y buscar secuencialmente\n2.-Insertar en orden y usar busqueda binaria\n3.-Insertar siempre al final, ordenar despúes de cada inserción y usar busqueda binaria\nOpcion: ");
			scanf("%i",&opcion);
			switch(opcion){
				case 1:
//1.- Insertar al final y buscar secuencialmente.
//Se llama al módulo creaListaNumerosVacia y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
				system("clear");
				while(pasadas <= 1000){
					tamano = tamano + 1000; //el tamaño maximo posible fue de 6.400.000 o se congela el proceso
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
					//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).			
					clock_gettime(CLOCK_REALTIME, &start); 	/*inicia cronometro Insercion.*/
					moduloInsertarFinal(lista1,max);
					clock_gettime(CLOCK_REALTIME, &finish);	/*finaliza cronometro Insercion.*/
					
					tInsFinalSec = finish.tv_sec - start.tv_sec;
					tInsFinalNSec = finish.tv_nsec - start.tv_nsec;
					//cambia los segundos a nanosegundos.
					tiempoTotalIns = calculoTiempo(start.tv_sec,finish.tv_sec,tInsFinalSec,tInsFinalNSec);
					
					unNumero = crearNumeroAleatorio(max);	/*Crea un numero para ser buscado.*/
					clock_gettime(CLOCK_REALTIME, &start);	/*inicia cronometro busqueda secuencial.*/
				 	//Busca secuencialmente un numero en el arreglo.
					if(buscaSecuencialNumeroEnListaNumeros(lista1, unNumero)!=(-1)){
						printf("\nNúmero %i encontrado\n", unNumero);
					}else{
						printf("\nEl número %i no ha sido encontrado\n", unNumero);
					}
					
					clock_gettime(CLOCK_REALTIME, &finish);	/*finaliza cronometro busqueda secuencial*/
					//almacena segundos y nanosegundos entregados por cronometro.
					tBSecuencialSec = finish.tv_sec - start.tv_sec;
					tBSecuencialNSec = finish.tv_nsec - start.tv_nsec;
					//cambia los segundos a nanosegundos.
					tiempoTotalBus = calculoTiempo(start.tv_sec, finish.tv_sec, tBSecuencialSec, tBSecuencialNSec);
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %ld [nseg]\ntiempo busqueda: %ld [nseg]\n\n", pasadas,tamano, tiempoTotalIns, tiempoTotalBus);
					pasadas++;
				}	
				;break;
				
				case 2:
//2.- Inserta en orden y usa búsqueda binaria.
				while(pasadas <= 1000){
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
					tamano = tamano + 1000; /*el tamaño maximo posible fue de 6.400.000 o se congela el proceso*/
					ordenamientoLista(lista1);	/*Ordena la lista de Mayor a menor.*/
					calcularEspacio(lista1); 	/*calcula cuantos elementos hay en la lista y devuelve la cantidad*/
					
					clock_gettime(CLOCK_REALTIME, &start); 	/*inicia cronometro Insercion Ordenada.*/
					for(i = 0; i<lista1->cantidadMaxima && lista1->cantidadActual < lista1->cantidadMaxima; i++){
						unNumero = crearNumeroAleatorio(max);
						insertaEnOrden(lista1,unNumero);
					}
					clock_gettime(CLOCK_REALTIME, &finish);	/*finaliza cronometro Insercion Ordenada.*/
					//imprimirLista(lista1);
					
					
					tInsOrdSec = finish.tv_sec - start.tv_sec;
					tInsOrdNSec = finish.tv_nsec - start.tv_nsec;
					//cambia los segundos a nanosegundos.
					tiempoTotalInsOrd = calculoTiempo(start.tv_sec, finish.tv_sec, tInsOrdSec, tInsOrdNSec);
					ordenarMenorMayor(lista1);	/*ordena de menor a mayor para utilizar busqueda binaria.*/
					unNumero = crearNumeroAleatorio(max);
					
					clock_gettime(CLOCK_REALTIME, &start);	/*inicia cronometro busqueda binaria.*/
					if(busquedaBinaria(lista1,unNumero)){
						printf("\nNúmero %i encontrado\n", unNumero);
					}else{
						printf("\nEl número %i no ha sido encontrado\n",unNumero);
					}
					clock_gettime(CLOCK_REALTIME, &finish);	/*finaliza cronometro busqueda binaria*/
					
					tBBinariaSec = finish.tv_sec - start.tv_sec;
					tBBinariaNSec = finish.tv_nsec - start.tv_nsec;
					//cambia los segundos a nanosegundos.
					tiempoTotalBusBin = calculoTiempo(start.tv_sec, finish.tv_sec, tBBinariaSec, tBBinariaNSec);	
					
					
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %ld [nseg]\ntiempo busqueda: %ld [nseg]\n\n",pasadas,tamano, tiempoTotalInsOrd, tiempoTotalBusBin);
					pasadas++;
				}
				;break;
				
				case 3:
//3.- Insertar siempre al final, ordenar con quicksort después de cada inserción, y usar busqueda binaria.
//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).
				while(pasadas <= 1000){	
					ListaNumeros *lista3 = creaListaNumerosVacia(tamano);//creaListaNumerosVacia(tamano);
					tamano = tamano + 1000;
					clock_gettime(CLOCK_REALTIME, &start); 	/*inicia cronometro Insercion.*/
					i=0;
					while(i < lista3->cantidadMaxima){
						//system("clear");
						unNumero = crearNumeroAleatorio(max);
						//printf("\n.........\n");
						insertaFinalLista(lista3, unNumero);
						ordenamientoLista(lista3);
						i++;
						//printf("\ni: %i\n",i);
					}
				
					//imprimirLista(lista3);
					//scanf("%i",&pausa);
					
					clock_gettime(CLOCK_REALTIME, &finish);	/*finaliza cronometro Insercion.*/
					tInsFinalSec = finish.tv_sec - start.tv_sec;
					tInsFinalNSec = finish.tv_nsec - start.tv_nsec;
				
					tiempoTotalIns = calculoTiempo(start.tv_sec,finish.tv_sec,tInsFinalSec,tInsFinalNSec);
					
					if(lista3->cantidadActual == lista3->cantidadMaxima){ /*Busca un numero por busqueda binaria*/
						
						ordenarMenorMayor(lista3);	/*ordena de menor a mayor para utilizar busqueda binaria.*/
						unNumero = crearNumeroAleatorio(max);
						clock_gettime(CLOCK_REALTIME, &start);	/*inicia cronometro busqueda binaria.*/
						if(busquedaBinaria(lista3,unNumero)){
							printf("\nNúmero %i encontrado\n", unNumero);
						}else{
							printf("\nEl número %i no ha sido encontrado\n",unNumero);
						}
						clock_gettime(CLOCK_REALTIME, &finish);	/*finaliza cronometro busqueda binaria*/
						
						tBBinariaSec = finish.tv_sec - start.tv_sec;
						tBBinariaNSec = finish.tv_nsec - start.tv_nsec;
						tiempoTotalBusBin = calculoTiempo(start.tv_sec, finish.tv_sec, tBBinariaSec, tBBinariaNSec);	
					}
					else{
						printf("\nPrimero llene el arreglo de numeros");
					}
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %ld [nseg]\ntiempo busqueda: %ld [nseg]\n\n",pasadas,tamano, tiempoTotalIns, tiempoTotalBusBin);
					//scanf("%i",&pausa);
					pasadas = pasadas + 1;
				}
					;break;
	
			}
			;break;
			
		case 3 :break;
	}
}


