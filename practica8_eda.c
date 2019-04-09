#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i;

struct nodo{

  int valor; //HAY QUE CAMBIAR ESTO, DEBERIA SER CONTENIDO(CARACTERES), NO UN ENTERO
  struct nodo *NEXT;
  struct nodo *PREV;

};

int Insertar(struct nodo **HEAD, int dato);
void ImprimirLista(struct nodo *HEAD);

int main (void){
  int loopMenu = 1,op,valores,n,m;
  system("clear");
  system("cls");
  printf("---- PROYECTO DE LISTA DOBLE  -----");
  struct nodo *HEAD = NULL;
  printf("\nPOR EL MOMENTO SOLO ES POSIBLE INSERTAR ELEMENTOS:\n");
  printf("\nINGRESE EL VALOR DE SU PRIMER ELEMENTO --> ");
  scanf("%d",&n);
  Insertar(&HEAD,n);
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
        printf("\nINGRESA EL VALOR DEL ELEMENTO:  ");
        scanf("%d",&valores);
        m = Insertar(&HEAD,valores);
        while(m == 0){
          Insertar(&HEAD,valores);
        }
        ImprimirLista(HEAD);
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
    printf("\n\t%d\n",auxiliar->valor);
    auxiliar = auxiliar->NEXT;
  }

}
