#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{

  int valor; //HAY QUE CAMBIAR ESTO, DEBERIA SER CONTENIDO(CARACTERES), NO ENTERO
  struct nodo *NEXT;
  struct nodo *PREV;
  char *contenido;
};

//DECLARACION DE FUNCIONES
int Insertar(struct nodo **HEAD, int dato);
void ImprimirLista(struct nodo *HEAD);
void Borrar(struct nodo **HEAD);
void Buscar(struct nodo **HEAD);

//FUNCION PRINCIPAL
int main (void){
  int loopMenu = 1,op,valores,n,m;
  system("clear");
  system("cls");
  printf("---- PROYECTO DE LISTA DOBLE  -----");
  //DECLARAMOS EL PRIMER ELEMENTO (HEAD)
  struct nodo *HEAD = NULL;
  printf("\nPOR EL MOMENTO SOLO ES POSIBLE INSERTAR ELEMENTOS:\n");
  printf("\nINGRESE EL VALOR DE SU PRIMER ELEMENTO --> ");
  scanf("%d",&n);
  //SE GENERA Y SE APUNTAN A NULO, PORQUE ESTÁ SOLITO :(
  HEAD = (struct nodo*)malloc(sizeof(struct nodo));
  HEAD->NEXT = NULL;
  HEAD->PREV = NULL;
  HEAD->valor = n;
  ImprimirLista(HEAD);
  while(loopMenu == 1){
    printf("\n\nELIGE UNA OPERACION:\n");
    printf("\t1.-INSERTAR ELEMENTO.");
    printf("\n\t2.-BUSCAR ELEMENTO.");
    printf("\n\t3.-BORRAR ELEMENTO.");
    printf("\n--> ");
    scanf("%d",&op);
    while(op < 1 || op > 3){
          printf("OPCION NO VALIDA. INTENTA DE NUEVO --> ");
          scanf("%d",&op);
    }
    switch (op){
      case 1:
        system("clear");
        system("cls");
        printf("\nINGRESA EL VALOR DEL ELEMENTO:  ");
        scanf("%d",&valores);
        //LA VARIABLE m SIRVE PARA VERIFICAR QUE SÍ SE HAYA CREADO EL NODO
        //EN CASO CONTRARIO, LO REPITE HASTA QUE LA FUNCION NOS REGRESE 1
        //ENTONCES ESTARÁ VERIFICADO QUE SE CREÓ CORRECTAMENTE
        m = Insertar(&HEAD,valores);
        while(m == 0){
          Insertar(&HEAD,valores);
        }
        //EL HEAD AHORA ES EL NUEVO ELEMENTO, POR TANTO SE RECORRE
        HEAD = HEAD->PREV;
        ImprimirLista(HEAD);
      break;
      case 2:
        Buscar(&HEAD);
      break;
      case 3:
        Borrar(&HEAD);
      break;
    }
  }
  return 0;
}

//SI SOLO QUEREMOS OBTENER DATOS, ES APUNTADOR SIMPLE
//SI QUEREMOS MODIFICAR LA VARIABLE, ES APUNTADOR DOBLE
int Insertar(struct nodo **HEAD,int dato){

  struct nodo *nuevo = NULL;
  nuevo = (struct nodo*)malloc(sizeof(struct nodo));
  if (nuevo != NULL){
    nuevo->valor = dato;
    nuevo->NEXT = *HEAD;
    nuevo->PREV = NULL;
    if( *HEAD != NULL){
      (*HEAD)->PREV = nuevo;
    }
    return 1;
  }
  return 0;
}

void ImprimirLista(struct nodo *HEAD){
  printf("\nIMPRIMIENDO...");
  struct nodo *auxiliar = HEAD;

  while (auxiliar != NULL) {
    printf("\n\t|| %d ||",auxiliar->valor);
    auxiliar = auxiliar->NEXT;
  }

}

void Buscar(struct nodo **HEAD){


}

void Borrar(struct nodo **HEAD){


}
