#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i;

struct nodo{

  int valor; //HAY QUE CAMBIAR ESTO, DEBERIA SER CONTENIDO(CARACTERES), NO UN ENTERO
  struct nodo *NEXT;
  struct nodo *PREV;

};

struct nodo *InsertarNodo(int x);
int Insertar(struct nodo **HEAD, int dato);
void ImprimirLista(struct nodo *HEAD);



int main (void){
  int loopMenu = 1,op,valores,verificador;
  system("clear");
  system("cls");
  printf("---- PROYECTO DE LISTA DOBLE  -----");
  struct nodo *HEAD = NULL;
  verificador = Insertar(&HEAD,55);
  printf("%d",verificador);
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
        printf("\nINGRESA EL VALOR:  ");
        scanf("%d",&valores);
        InsertarNodo(valores);
      break;
      case 2:
        printf("\n");
      break;
      case 3:

      break;
    }
  }
  return 0;
}



struct nodo *InsertarNodo(int x){
  struct nodo *nuevo = NULL;
  nuevo = (struct nodo*)malloc(sizeof(struct nodo));
  if (nuevo != NULL){
    nuevo->valor = x;
  }
  return nuevo;
}

int Insertar(struct nodo **HEAD,int dato){

  struct nodo *nuevo = NULL;
  nuevo = InsertarNodo(dato);
  if (nuevo != NULL){
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
  struct nodo *auxiliar = HEAD;

  while (auxiliar != NULL) {
    printf("\n%d\n", auxiliar->valor);
    auxiliar = auxiliar->NEXT;
  }
}
