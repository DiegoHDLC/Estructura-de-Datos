//Se crea y se define la estructura _lista
typedef struct _lista{
	int cantidadActual; //cantidad de datos en el arreglo.
	int cantidadMaxima; //cantidad límite que puede tener este arreglo.
	int *arreglo; //el arreglo en forma de puntero.
}ListaNumeros;

//Prototipos de los modulos.
ListaNumeros *creaListaNumerosVacia(int tamano);
ListaNumeros *creaListaNumerosLlena(int tamano, int max);
int eliminaListaNumeros(ListaNumeros *);
int buscaNumeroEnListaNumeros(ListaNumeros *, int);
void imprimirLista(ListaNumeros *);

//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
//unNumero: Número digitado por usuario para ser buscado.

//crea una lista llenandola con "ceros".
ListaNumeros *creaListaNumerosVacia(int tamano){
	int i=0;
	ListaNumeros *nuevaLista = malloc(sizeof(ListaNumeros));
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
		//almacena números entre 0 y "max" dentro del arreglo.
		nuevaLista->arreglo[i]= rand()%(max);
	}
	nuevaLista->cantidadActual = nuevaLista->cantidadMaxima;
	return nuevaLista;
}

//Libera la memoria ocupada por el arreglo y por la lista.
int eliminaListaNumeros(ListaNumeros *unaListaNumeros){
	//Verifica si la lista ha sido inicializada
	if(unaListaNumeros->arreglo && unaListaNumeros != NULL){
		free(unaListaNumeros->arreglo);
		free(unaListaNumeros);
		return 1;
	}else{
		return 0;
	}
}

//Busca un número dictado por el usuario dentro del arreglo creado.
int buscaNumeroEnListaNumeros(ListaNumeros *unaListaNumeros, int unNumero){
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
	int i=0;
	for(i=0; i < nuevaLista->cantidadMaxima; i++){
		printf("%i ",nuevaLista->arreglo[i]);
	}
	printf("\n");
}

int busquedaSecuencial(ListaNumeros 


