//Se crea y se define la estructura _lista
typedef struct _lista{
	int cantidadActual; //cantidad de datos en el arreglo.
	int cantidadMaxima; //cantidad límite que puede tener este arreglo.
	int *arreglo; //el arreglo en forma de puntero.
	int cont;
}ListaNumeros;

//Prototipos de los modulos.
ListaNumeros *creaListaNumerosVacia(int tamano);
ListaNumeros *creaListaNumerosLlena(int tamano, int max);
int eliminaListaNumeros(ListaNumeros *);
void imprimirLista(ListaNumeros *);
int continuar(char*);
//1.-
ListaNumeros *insertaFinalLista(ListaNumeros *, int);
int buscaSecuencialNumeroEnListaNumeros(ListaNumeros *, int);
//2.-
ListaNumeros *ordenamientoLista(ListaNumeros *);
ListaNumeros *calcularEspacio(ListaNumeros *);
ListaNumeros *ordenarMenorMayor(ListaNumeros *);
int buscaLugar(ListaNumeros *, int, int*);
int comparaEnteros(const void *, const void *);
int busquedaBinaria(ListaNumeros *,int);


//tamano: tamaño del arreglo; - max: el número más grande que puede tener el arreglo.
//unNumero: Número digitado por usuario para ser buscado.

//crea una lista llenandola con "ceros".
ListaNumeros *creaListaNumerosVacia(int tamano){
	int i=0;
	ListaNumeros *nuevaLista = malloc(sizeof(ListaNumeros));
	nuevaLista->cantidadActual = 0;
	nuevaLista->cantidadMaxima = tamano;
	nuevaLista->cont = 0;
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
	int i=0;
	for(i=0; i < nuevaLista->cantidadMaxima; i++){
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
ListaNumeros *insertaEnOrden(ListaNumeros *listaActual, int unNumero){

	//el valor de 'i' se iguala a la cantidad de datos que hay en el arreglo, esto se hace para empezara mover los datos desde el ultimo dato del arreglo.
	int posicion = 0, i = listaActual->cantidadActual;
	
	if(listaActual->cantidadActual < listaActual->cantidadMaxima){
		buscaLugar(listaActual,unNumero,&posicion);
		//corre los números de izquierda a derecha.
		while(i > posicion){
			listaActual->arreglo[i] = listaActual->arreglo[i-1];
			i--;
		}
		//agrega el número entregado por el usuario al arreglo.
		listaActual->arreglo[posicion] = unNumero;
		listaActual->cantidadActual++;
	}
	return listaActual;
}

//Busca el lugar donde insertar el número en el arreglo.
int buscaLugar(ListaNumeros *listaActual, int unNumero, int *i){
	while(*i < listaActual->cantidadMaxima){
		if(unNumero > listaActual->arreglo[*i]){
			return *i;
		}
		(*i)++;
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
ListaNumeros *ordenamientoLista(ListaNumeros *lista1){
	qsort(lista1->arreglo,lista1->cantidadMaxima,sizeof(int), &comparaEnteros);
	return lista1;
}



//compara los enteros dentro de la lista.
int comparaEnteros(const void *p, const void *q){
	int x, y;
	x = *(int *) p;
	y = *(int *) q;
	if(x > y){
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
	sup = lista->cantidadMaxima;
	
	while((inf+1)!=sup){
		mitad = (inf + sup)/2;
		if(lista->arreglo[mitad] == unNumero){
			return 1;
		}
		if(lista->arreglo[mitad] > unNumero){
			sup = mitad;
			mitad = (inf + sup)/2;
		}
		if(lista->arreglo[mitad] < unNumero){
			inf = mitad;
			mitad = (inf + sup)/2;
		}
	}
	return (-1);
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

/*int continuar(char *opcion){
	if(*opcion == ('s'||'S')){
		return 1;
	}else if(*opcion == ('n'||'N')){
		return 0;
	}
}*/
