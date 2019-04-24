//Lista
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct publicacion
{
    int llave; // consecutivo
    char contenido[20];
    struct publicacion *siguiente; //NEXT

}Pub;

void insertar(Pub **, char texto[]);
Pub * buscar(Pub **, int);
int borrar(Pub **, int);
int estaVacia(Pub **);
void imprimirLista(Pub **);


int main ()
{
	Pub *head = NULL;
  Pub *buscando = NULL;
	int loopMenu = 1;
	char frase[20];
	int key, EAB; //EAB= Elemento A Borrar
  time_t fecha;
  time(&(fecha));
  printf("\n\n Fecha: %s",ctime(&(fecha)));

    while (loopMenu == 1)
	{
        int opcion;
        printf("\n\nMENU:");
        printf("\nPara publicar algo, presione 1.");
        printf("\nPara buscar alguna publicacion, presione 2.");
        printf("\nPara borrar tu publicacion, presione 3.\n-->");
        scanf("%d",&opcion);

        while(opcion < 1 || opcion > 3)
		{
            printf("\nOpcion no valida. Intenta de nuevo:");
            scanf("%d",&opcion);
        }

        switch (opcion)
		{
          case 1:
          	printf("Comenzando a Insertar...\n" );
          	printf("\n\tQue estas pensando?...\n");
          	scanf("%s", frase);
    		insertar(&head, frase);
    		imprimirLista(&head);
    		getchar();

          break;

          case 2:
          	printf("Iniciando Busqueda...\n");
          	printf("Que numero de publicación buscas?...\n");
          	scanf("%d", &key);
		  	buscando = buscar(&head, key); // Buscando cuando hay elementos
    		if(buscando != NULL)
        	printf("\nEncontrado %d: %s\n", key, buscando->contenido);
   			getchar();

          break;

          case 3:
          	printf("Iniciando Borrado...\n");
          	printf("Que elemento deseas borrar?...\n");
          	scanf("%d", &EAB);
          	printf("\nBORRANDO %d...\n", borrar(&head, EAB) );
    		imprimirLista(&head);
    		getchar();
          break;
        }

         printf("\nPara continuar, presione 1.");
        printf("\nPara salir, presione 0.\n --> ");
        scanf("%d",&loopMenu);

        while(loopMenu < 0 || loopMenu > 1)
		{
            printf("Opcion no valida. Intenta de nuevo: ");
            scanf("%d",&loopMenu);
        }
        system("cls");
    }

    printf("\n\nPROGRAMA FINALIZADO\n\n");

    return 0;
}


int estaVacia(Pub **inicial)
{
    return *inicial == NULL; //Regresa 0 o 1
}


void insertar(Pub **inicial, char texto[])
{
    static int numPublicacion = 1;
    Pub *nuevo = NULL;
    // Se crea un nodo. Nuevo apuntará a él
    nuevo = (Pub *) malloc(sizeof(Pub));
    if ( nuevo != NULL )
	{
        nuevo->llave = numPublicacion++;
        strcpy(nuevo->contenido,texto);
        //Le asigna el valor al que está apuntando inicial
        nuevo->siguiente = *inicial;
        *inicial = nuevo;
    }
	else
	 {
        printf("\nNo se pudo insertar, memoria insuficiente\n");
     }
}

Pub * buscar(Pub **inicial, int buscoLlave)
{
    Pub *actual = *inicial;
    if(estaVacia(inicial))
	 { //Se utiliza la funcion
        printf("No se puede buscar cuando la lista esta vacia\n");
        return NULL;
    }
	else
	{
        printf("BUSCANDO llave %d...\n", buscoLlave);
        // Se recorrera hasta encontrar la coincidencia
        while(actual->llave != buscoLlave)
		{
            // Si el elemento en su posición siguiente es nulo se termina la funcion
            if(actual->siguiente == NULL)
			{
                printf("El elemento con llave %d no se encuentra en la lista\n", buscoLlave);
                return NULL;
            }
            // Se mueve a la referencia siguiente si no es nulo
            else
            {
            	actual = actual->siguiente;
            }
        }
        // Devuelve la direccion del nodo si encontro la llave en la lista
        return actual;
    }
}

int borrar(Pub **inicial, int llaveABuscar)
{
    Pub *anterior;
    Pub *actual;
    Pub *temporal;

    if( estaVacia(inicial) )
	{ //Se utiliza la funcion
        printf("No se puede eliminar cuando la lista esta vacia\n");
        return 0;
    }

    /* elimina el primer nodo si es la llave a buscar */
    if ( llaveABuscar == (*inicial)->llave )
	{
        temporal = *inicial; /* almacena el nodo a eliminar */
        *inicial = (*inicial)->siguiente; /* cambia la direccion de HEAD al siguiente */
        free( temporal ); /* libera el nodo a eliminar */
        return llaveABuscar;
    }
	else
	 {
        anterior = *inicial;
        actual = (*inicial)->siguiente;
        /* ciclo para localizar la ubicación correcta en la lista */
        while ( actual != NULL && actual->llave != llaveABuscar )
		{
            anterior = actual;
            actual = actual->siguiente;
        }
        /* elimina el nodo que apunta actual si no es nulo */
        if ( actual != NULL )
		{
            temporal = actual;
            anterior->siguiente = actual->siguiente;
            free( temporal ); /* libera el nodo a eliminar */
            return llaveABuscar;
        }
    }
    return 0;
}

void imprimirLista(Pub **inicial)
{
    Pub *mueve = *inicial;
    time_t timer;
    char buffer[20];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 20, "%d-%m-%Y %H:%M:%S", tm_info);
    // Se recorre la referencia hasta que el elemento ‘siguiente’ es nulo

    printf("_________________________________________________________________\n\t Fecha: %s\ns",buffer);
    while(mueve != NULL)
	{
    	printf("\n| %d : %s |	", mueve->llave, mueve->contenido);
        mueve = mueve->siguiente;
    }
    printf("\n_________________________________________________________________\n");
}
