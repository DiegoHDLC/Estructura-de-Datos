//Se crea y se define la estructura _lista
typedef struct _lista{
	int cantidadActual; //cantidad de datos en el arreglo.
	int cantidadMaxima; //cantidad límite que puede tener este arreglo.
	int *arreglo; //el arreglo en forma de puntero.

}ListaNumeros;

//Prototipos de los modulos.
ListaNumeros *creaListaNumerosordenados(int tamano);
ListaNumeros *creaListaNumerosVacia(int tamano);
ListaNumeros *creaListaNumerosLlena(int tamano, int max);
int eliminaListaNumeros(ListaNumeros *);
void imprimirLista(ListaNumeros *);
int guardarEnArchivo(int, int, int, int, int);
//1.-
ListaNumeros *moduloInsertarFinal(ListaNumeros *, int);
ListaNumeros *insertaFinalLista(ListaNumeros *, int);
int buscaSecuencialNumeroEnListaNumeros(ListaNumeros *, int);
int crearNumeroAleatorio(int);

//2.-
ListaNumeros *insertaEnOrden(ListaNumeros *, int );
ListaNumeros *InsertarVariosEnOrden(ListaNumeros *,int,int);
ListaNumeros *ordenamientoLista(ListaNumeros *);
ListaNumeros *calcularEspacio(ListaNumeros *);
ListaNumeros *ordenarMenorMayor(ListaNumeros *);
ListaNumeros *InsertarVariosAlFinal(ListaNumeros *,int,int);

int buscaLugar(ListaNumeros *, int, int*);
int comparaEnteros(const void *, const void *);
int busquedaBinaria(ListaNumeros *,int);
int calculoTiempo(int _inicioSeg, int _finalSeg, int _restaSeg, int _restaNSeg);



//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
//unNumero: Número digitado por usuario para ser buscado.


ListaNumeros *InsertarVariosAlFinal(ListaNumeros *lista3,int unNumero,int max){
	int i=0;
	while(i < lista3->cantidadMaxima){
		unNumero = crearNumeroAleatorio(max);
		lista3 = insertaFinalLista(lista3, unNumero);
		lista3 = ordenamientoLista(lista3);
		i++;
	}
	return lista3;
}
//
ListaNumeros *InsertarVariosEnOrden(ListaNumeros *lista1,int unNumero,int max){
	int i;
	for(i = 0; i<lista1->cantidadMaxima && lista1->cantidadActual < lista1->cantidadMaxima; i++){
		unNumero = crearNumeroAleatorio(max);
		
		lista1=insertaEnOrden(lista1,unNumero);
	}
	return lista1;
}
int guardarEnArchivo(int pasadas, int tamano, int tiempoTotalIns, int tiempoTotalBus, int caso){
	FILE *fd;
	if(fd == NULL){
	//Da un mensaje de error al no existir el archivo archivoAlumnos.txt en este caso.
		system("read -p 'Error al tratar de agregar datos al archivo\nPresione una tecla para continuar...' var");
		return 0; //sale de la función;
	}
	if(caso == 1){
		fd = fopen("laboratorio2ED_1.csv","at");
	}
	else if(caso == 2){
		fd = fopen("laboratorio2ED_2.csv","at");
	}
	else if(caso == 3){
		fd = fopen("laboratorio2ED_3.csv","at");
	}
	fprintf(fd,"%i", pasadas);
	fprintf(fd," %i ,", tamano);
	fprintf(fd," %i ,", tiempoTotalIns);
	fprintf(fd," %i ,", tamano);
	fprintf(fd," %i\n ", tiempoTotalBus);
	fclose(fd);
	
	return 1;
}

ListaNumeros *moduloInsertarFinal(ListaNumeros *lista1,int max){
	int i, unNumero;
	for(i = 0; i < lista1->cantidadMaxima; i++){			
		unNumero = crearNumeroAleatorio(max);
		insertaFinalLista(lista1, unNumero);
	}
}

int crearNumeroAleatorio(int max){
	time_t t;
	int numero;
	numero = 1 + rand()%max;
	return numero;

}
//crea una lista llenandola con "ceros".
ListaNumeros *creaListaNumerosVacia(int tamano){
	int i=0;

	ListaNumeros *nuevaLista =malloc(sizeof(ListaNumeros));
	nuevaLista->cantidadActual = 0;
	nuevaLista->cantidadMaxima = tamano;
	
	nuevaLista->arreglo = malloc(sizeof(int)*tamano);
	return nuevaLista;
}

//Crea la lista llenandola con números entre 0 y "max", donde max es dictado por el usuario.
ListaNumeros *creaListaNumerosLlena(int tamano, int max){
	int i;
	ListaNumeros *nuevaLista = creaListaNumerosVacia(tamano);
	srand(time(NULL));
	for(i = 0; i < nuevaLista->cantidadMaxima; i++){
		nuevaLista->arreglo[i]= rand()%(max);/*almacena números entre 0 y "max" dentro del arreglo.*/
	}
	nuevaLista->cantidadActual = nuevaLista->cantidadMaxima;
	return nuevaLista;
}

ListaNumeros *creaListaNumerosordenados(int tamano){
	int i;
	ListaNumeros *nuevaLista = creaListaNumerosVacia(tamano);
	int j=5;
	for(i = 0; i < nuevaLista->cantidadMaxima; i++){
		nuevaLista->arreglo[i]= j;
		j++;
	}
	nuevaLista->cantidadActual = nuevaLista->cantidadMaxima;
	return nuevaLista;
}

//Libera la memoria ocupada por el arreglo y por la lista.
int eliminaListaNumeros(ListaNumeros *unaListaNumeros){
	if(unaListaNumeros->arreglo && unaListaNumeros != NULL){ /*Verifica si la lista ha sido inicializada*/
		free(unaListaNumeros->arreglo);
		free(unaListaNumeros);
		return 1;
	}else{
		return 0;
	}
}

//Busca un número dictado por el usuario dentro del arreglo creado.
int buscaSecuencialNumeroEnListaNumeros(ListaNumeros *unaListaNumeros, int unNumero){
	int i;
	
	for(i=0; i < unaListaNumeros->cantidadMaxima; i++){
		if(unaListaNumeros->arreglo[i] == unNumero){
			return 1;
		}
	}
	return (-1);
}

//imprime los datos almacenados en la lista
void imprimirLista(ListaNumeros *nuevaLista){
	int i;
	for(i=0; i < nuevaLista->cantidadActual; i++){
		printf("Numero[%i]: %i \n",i+1,nuevaLista->arreglo[i]);
	}
	printf("\n");
}

//inserta un numero dictado por el usuario al final de la lista.
ListaNumeros *insertaFinalLista(ListaNumeros *nuevaLista, int unNumero){
	nuevaLista->arreglo[nuevaLista->cantidadActual] = unNumero;
	nuevaLista->cantidadActual++;
	return nuevaLista;
}

//Ordena una lista y luego inserta el numero entregado por el usuario;
ListaNumeros *insertaEnOrden(ListaNumeros *lista, int unNumero){

	//el valor de 'i' se iguala a la cantidad de datos que hay en el arreglo, esto se hace para empezara mover los datos desde el ultimo dato del arreglo.
	int posicion = 0, i = lista->cantidadActual;
	if(lista->cantidadActual==0){
		lista->arreglo[posicion] = unNumero;
		lista->cantidadActual++;
	}
	else{
		buscaLugar(lista,unNumero,&posicion);
		while(i > posicion){ /*corre los números de izquierda a derecha.*/
			lista->arreglo[i] = lista->arreglo[i-1];
			i--;
		}
		//agrega el número entregado por el usuario al arreglo.
		lista->arreglo[posicion] = unNumero;
		lista->cantidadActual++;
	}
	
	return lista;
}

//Busca el lugar donde insertar el número en el arreglo.
int buscaLugar(ListaNumeros *listaActual, int unNumero, int *j){
	while(*j < listaActual->cantidadMaxima){
		if(unNumero > listaActual->arreglo[*j]){
			return *j;
		}
		(*j)++;
	}
	
}

//Calcula cuantos números hay en el arreglo (el número '0' cuenta como si la casilla estuviera vacía).
ListaNumeros *calcularEspacio(ListaNumeros *listaActual){
	int i=0;
	listaActual->cantidadActual=0;
	while(i < listaActual->cantidadMaxima){
		if(listaActual->arreglo[i] != 0){
			listaActual->cantidadActual++;
		}
		i++;
	}
	return listaActual;
}

//Ordena la lista con el comando qSort
ListaNumeros *ordenamientoLista(ListaNumeros *lista){
	qsort(lista->arreglo,lista->cantidadActual,sizeof(int), &comparaEnteros);
	return lista;
}



//compara los enteros dentro de la lista.
int comparaEnteros(const void *p, const void *q){
	int x, y;
	x = *(int *) p;
	y = *(int *) q;
	if(x < y){
		return -1;
	}
	if(x == y ){
		return 0;
	}
	return 1;
}

//Busca el número entregado por el usuario mediante busqueda binaria
int busquedaBinaria(ListaNumeros *lista, int unNumero){
	int inf,sup,mitad;


	inf = 0;
	sup = lista->cantidadMaxima - 1;
	mitad = (sup + 1)/2;
	
	while(lista->arreglo[mitad] != unNumero && inf<sup){
		if(lista->arreglo[mitad] > unNumero){
			sup = mitad -1;
		}else{
			inf = mitad + 1;
		}
		mitad = (inf+sup)/2;
	

	}

	if(lista->arreglo[mitad] == unNumero){
		return 1;
	}
	return 0;
}

//ordena la lista de menor a mayor
ListaNumeros *ordenarMenorMayor(ListaNumeros *lista1){
	int i,j,tam;
	tam = lista1->cantidadMaxima;
	int arregloAux[tam];
		i = tam;
		j = 0;
		while(i > 0){
			arregloAux[j] = lista1->arreglo[i-1] ;
			i--;
			j++;
		}
		i=0;
		while(i < lista1->cantidadMaxima){
			lista1->arreglo[i] = arregloAux[i];
			i++;
		}
	return lista1;
}

//pasa los segundos a nanosegundos
int calculoTiempo(int _inicioSeg, int _finalSeg, int _restaSeg, int _restaNSeg){
	int _total;
	if(_restaSeg > 0){
		_total = (_restaSeg*(10^9) + _finalSeg) - _inicioSeg;
	}
	else{
		_total = _restaSeg*(10^9) + _restaNSeg;
	}
	return _total;
}

