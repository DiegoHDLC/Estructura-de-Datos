#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _nodo{
	char dato;
	struct _nodo *hizq, *hder;
}AB;

//archivo
char *leerTexto();
int contarDatos();
void imprimirArreglo(char*);
//arbol
AB *iniciaAB();
AB *insertaValorAB(AB *, char);
AB *creaNodoAB(char);
void imprimirArbol(AB *, int);

void imprimirArbol(AB *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		imprimirArbol(arbol->hder,cont+1);
		for(int i = 0; i < cont; i++){
			printf("   ");
		}
		printf("%c",arbol->dato);
		imprimirArbol(arbol->hizq,cont+1);
	}
}

AB *iniciaAB(){
	return NULL;
}

AB *creaNodoAB(char valor){
	int pausa;
	//scanf("%i",&pausa);
	AB *nuevoArbol = malloc(sizeof(char));
	
	nuevoArbol->dato = valor;
	nuevoArbol->hder = NULL;
	nuevoArbol->hizq = NULL;
	//printf("\nNodo creado\n");
	return nuevoArbol;
}
//1247NNN5N8NN36NNN
AB *insertaValorAB(AB *arbol, char valor){
	//printf("%c",valor);
	printf("\nentra valor : %c\n",valor);
	int pausa;
	if(arbol == NULL){
		AB *nuevoNodo = creaNodoAB(valor);
		arbol = nuevoNodo;
		printf("dato:%c\n",arbol->dato);
	}
	else{
		char valorRaiz = arbol->dato;
		printf("\nvalor raiz: %c\n",valorRaiz);
		scanf("%i",&pausa);
		//insertaValorAB(arbol->hizq,valor);
		if(valor < valorRaiz){
			if(valor == 'N'){
				arbol = NULL;
				//printf("\nentra en if izq\n");
			}else{
				insertaValorAB(arbol->hizq,valor);
			}
		}
		else{
			if(valor == 'N'){
				arbol = NULL;
				//printf("\nentra en if der\n");
			}else{
				insertaValorAB(arbol->hder,valor);
			}
		}
	}
	return arbol;
}

void imprimirArreglo(char *letras){
	int i = 0;
	while(letras[i] != '\0'){
		printf("%c",letras[i]);
		i++;
	}
}

int contarDatos(){
	int i = 0;
	FILE *fd1;
	fd1 = fopen("arbolBinario.txt","rt");
	while(fgetc(fd1)!=EOF){
		i++;
	}
	fclose(fd1);
	return i;
}

char *leerTexto(int *i){
	FILE *fd1;
	char c;
	int j;
	fd1 = fopen("arbolBinario.txt","rt");
	//modo rt: el archivo se abre para leer texto.
	if(fd1 == NULL){
		//Da un mensaje de error al no existir el archivo archivoAlumnos.txt en este caso.
		system("read -p 'Error al tratar de leer el archivo\nPresione una tecla para continuar...' var");
		system("clear");
	}
	*i = contarDatos();
	char *letras = malloc(sizeof(char)*(*i));
	for(j=0; (c = fgetc(fd1))!=EOF; j++){/*almacena caracteres del archivo, pero si llegase a encontrar 
				      que el caracter pertenece al final del archivo, sale del bucle y termina el programa.*/
		letras[j] = c;
		if(c =='\n'){//si encuentra un caracter de salto de linea, imprime un salto de linea.
			printf("\n");
		}
	}
	fclose(fd1);
	//system("clear");
	return letras;
}

