#include<stdio.h>
#include<stdlib.h>
#include<time.h>	
#include <unistd.h>
#include"liblab2.h"

void main(){
	//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
	//unNumero: Número digitado por usuario para ser buscado.	 
	int tamano = 5,max = 100, unNumero,i=0,p,opcion,dato,pasadas=0;
	unsigned long tInsFinalSec, tInsFinalNSec, tiempoTotalIns;
	unsigned long tBSecuencialSec, tBSecuencialNSec, tiempoTotalBus;
	unsigned long tInsOrdSec, tInsOrdNSec, tiempoTotalInsOrd;
	unsigned long tBBinariaSec, tBBinariaNSec, tiempoTotalBusBin;
	//printf("%ld\n",sizeof(long));
	char salir;
	struct timespec startIns, finishIns, startBusSec, finishBusSec, startInsOrd, finishInsOrd, startBusBin, finishBusBin; 
   
	system("clear");
	printf("1.-Caso base\n2.-Segundo Laboratorio\n3.-Salir\nOpcion: ");
	scanf("%i",&opcion);
	//CASO BASE
	//Se llama al módulo creaListaNumerosLlena y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
	ListaNumeros *unaListaNumeros = creaListaNumerosVacia(tamano);
	//ListaNumeros *lista1 = creaListaNumerosVacia(tamano);//creaListaNumerosVacia(tamano);
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
//1.- Insertar al final y buscar secuencialmente.

			//Se llama al módulo creaListaNumerosVacia y se almacena la lista creada en la variable de tipo estructura "nuevaLista".
		
			//Se llama al módulo imprimirLista, donde se le entrega la lista creada anteriormente, para imprimir la lista en consola.
			
			printf("1.-Insertar al final y buscar secuencialmente\n2.-Insertar en orden y usar busqueda binaria\n3.-Insertar siempre al final, ordenar despúes de cada inserción y usar busqueda binaria\nOpcion: ");
			scanf("%i",&opcion);
			switch(opcion){
				case 1:
				system("clear");
				while(tamano <= 1000){
					tamano = tamano + 1;
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
					//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).			
					printf("\ncantidad maxima nueva 2222: %i\n",lista1->cantidadMaxima);
					printf("\n.....\n");
					clock_gettime(CLOCK_REALTIME, &startIns); 	/*inicia cronometro Insercion.*/
					
					for(i = 0; i < lista1->cantidadMaxima; i++){
						//system("clear");
						unNumero = crearNumeroAleatorio(max);
						insertaFinalLista(lista1, unNumero);
					}
					
					imprimirLista(lista1);
					clock_gettime(CLOCK_REALTIME, &finishIns);	/*finaliza cronometro Insercion.*/
					
					tInsFinalSec = finishIns.tv_sec - startIns.tv_sec;
					tInsFinalNSec = finishIns.tv_nsec - startIns.tv_nsec;
				
					tiempoTotalIns = calculoTiempo(startIns.tv_sec,finishIns.tv_sec,tInsFinalSec,tInsFinalNSec);
					
					clock_gettime(CLOCK_REALTIME, &startBusSec);	/*inicia cronometro busqueda secuencial.*/
				 	unNumero = crearNumeroAleatorio(max);	/*Crea un numero para ser buscado.*/
				 	//Busca secuencialmente un numero en el arreglo.
					if(buscaSecuencialNumeroEnListaNumeros(lista1, unNumero)!=(-1)){
						printf("\nNúmero %i encontrado\n", unNumero);
					}else{
						printf("\nEl número %i no ha sido encontrado\n", unNumero);
					}
					
					clock_gettime(CLOCK_REALTIME, &finishBusSec);	/*finaliza cronometro busqueda secuencial*/
					//almacena segundos y nanosegundos entregados por cronometro.
					tBSecuencialSec = finishBusSec.tv_sec - startBusSec.tv_sec;
					tBSecuencialNSec = finishBusSec.tv_nsec - startBusSec.tv_nsec;
					//cambia los segundos a nanosegundos.
					tiempoTotalBus = calculoTiempo(startBusSec.tv_sec, finishBusSec.tv_sec, tBSecuencialSec, tBSecuencialNSec);
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %ld [nseg]\ntiempo busqueda: %ld [nseg]\n\n", pasadas,tamano, tiempoTotalIns, tiempoTotalBus);
						
					//llama a la función eliminaListaNumeros, donde se libera la memoria creada para "unaListaNumeros" y "arreglo".
					/*if(eliminaListaNumeros(lista1)){
						printf("\nLista eliminada con éxito\n");
					}
					else{
						printf("\nNo hay lista para eliminar");
					}*/
					pasadas++;
				}
					
				;break;
				
				case 2:
					
				while(tamano <= 1000){
					ListaNumeros *lista1 = creaListaNumerosVacia(tamano);
					tamano++;
//2.- Inserta en orden y usa búsqueda binaria.
			
					//Inserta en un numero en una lista ordenanda.
					ordenamientoLista(lista1);
					
					imprimirLista(lista1);
					calcularEspacio(lista1); 	/*calcula cuantos elementos hay en la lista y devuelve la cantidad*/
					
					
					clock_gettime(CLOCK_REALTIME, &startInsOrd); 	/*inicia cronometro Insercion Ordenada.*/
					for(i = 0; i<lista1->cantidadMaxima && lista1->cantidadActual < lista1->cantidadMaxima; i++){
						unNumero = crearNumeroAleatorio(max);
						insertaEnOrden(lista1,unNumero);
					}
					imprimirLista(lista1);
					clock_gettime(CLOCK_REALTIME, &finishInsOrd);	/*finaliza cronometro Insercion Ordenada.*/
					
					tInsOrdSec = finishInsOrd.tv_sec - startInsOrd.tv_sec;
					tInsOrdNSec = finishInsOrd.tv_nsec - startInsOrd.tv_nsec;
					tiempoTotalInsOrd = calculoTiempo(startInsOrd.tv_sec, finishInsOrd.tv_sec, tInsOrdSec, tInsOrdNSec);
					
					if(lista1->cantidadActual == lista1->cantidadMaxima){ /*Busca un numero por busqueda binaria*/
						
						ordenarMenorMayor(lista1);	/*ordena de menor a mayor para utilizar busqueda binaria.*/
						unNumero = crearNumeroAleatorio(max);
						clock_gettime(CLOCK_REALTIME, &startBusBin);	/*inicia cronometro busqueda binaria.*/
						if(busquedaBinaria(lista1,unNumero)){
							printf("\nNúmero %i encontrado\n", unNumero);
						}else{
							printf("\nEl número %i no ha sido encontrado\n",unNumero);
						}
						clock_gettime(CLOCK_REALTIME, &finishBusBin);	/*finaliza cronometro busqueda binaria*/
						
						tBBinariaSec = finishBusBin.tv_sec - startBusBin.tv_sec;
						tBBinariaNSec = finishBusBin.tv_nsec - startBusBin.tv_nsec;
						tiempoTotalBusBin = calculoTiempo(startBusBin.tv_sec, finishBusBin.tv_sec, tBBinariaSec, tBBinariaNSec);	
					}
					else{
						printf("\nPrimero llene el arreglo de numeros");
					}
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %ld [nseg]\ntiempo busqueda: %ld [nseg]\n\n",pasadas,tamano, tiempoTotalInsOrd, tiempoTotalBusBin);
					pasadas++;
				}
				;break;
				
				case 3:
				
				//while(tamano <= 100){
//3.- Insertar siempre al final, ordenar con quicksort después de cada inserción, y usar busqueda binaria.

				//Inserta numeros al final en un arreglo hasta completarlo (el número '0' da a entender que la casilla está vacía).		
					clock_gettime(CLOCK_REALTIME, &startIns); 
					/*inicia cronometro Insercion.*/
					while(i < lista3->cantidadMaxima){
						unNumero = crearNumeroAleatorio(max);
						insertaFinalLista(lista3, unNumero);
						ordenamientoLista(lista3);
						i++;
					}
					imprimirLista(lista3);
					
					clock_gettime(CLOCK_REALTIME, &finishIns);	/*finaliza cronometro Insercion.*/
					tInsFinalSec = finishIns.tv_sec - startIns.tv_sec;
					tInsFinalNSec = finishIns.tv_nsec - startIns.tv_nsec;
				
					tiempoTotalIns = calculoTiempo(startIns.tv_sec,finishIns.tv_sec,tInsFinalSec,tInsFinalNSec);
					
					if(lista3->cantidadActual == lista3->cantidadMaxima){ /*Busca un numero por busqueda binaria*/
						
						ordenarMenorMayor(lista3);	/*ordena de menor a mayor para utilizar busqueda binaria.*/
						unNumero = crearNumeroAleatorio(max);
						clock_gettime(CLOCK_REALTIME, &startBusBin);	/*inicia cronometro busqueda binaria.*/
						if(busquedaBinaria(lista3,unNumero)){
							printf("\nNúmero %i encontrado\n", unNumero);
						}else{
							printf("\nEl número %i no ha sido encontrado\n",unNumero);
						}
						clock_gettime(CLOCK_REALTIME, &finishBusBin);	/*finaliza cronometro busqueda binaria*/
						
						tBBinariaSec = finishBusBin.tv_sec - startBusBin.tv_sec;
						tBBinariaNSec = finishBusBin.tv_nsec - startBusBin.tv_nsec;
						tiempoTotalBusBin = calculoTiempo(startBusBin.tv_sec, finishBusBin.tv_sec, tBBinariaSec, tBBinariaNSec);	
					}
					else{
						printf("\nPrimero llene el arreglo de numeros");
					}
					printf("\npasadas: %i\ntamano: %i\ntiempo insercion: %ld [nseg]\ntiempo busqueda: %ld [nseg]\n\n",pasadas,tamano, tiempoTotalIns, tiempoTotalBusBin);
				//	tamano = tamano + 1;
				//	pasadas++;
				//}	
					;break;
					case 4 : 
						i=0;
						while(i < 100){
							unNumero = crearNumeroAleatorio(max);
							printf("\nnumero : %i\n",unNumero);
							//insertaFinalLista(lista1, unNumero);
							i++;
						}
			;break;
	
			}
			;break;
			
		case 3 :break;
	}
}


