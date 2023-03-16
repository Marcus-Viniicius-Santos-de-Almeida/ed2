#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "GeneralizedLinkedList.h"
#include <stdbool.h>

int addAtom(Node **list, int atom){
   Node *no = (Node*)malloc(sizeof(Node));
   if(no==NULL) return -1;
   no->type = 0;
   no->atomList.atom = atom;
   no->tail = NULL;
   list->tail = *no;
   return 1;
}

/*void showGeneralizedList(Node *list){
    Node *aux = (Node*)malloc(sizeof(Node));
    if (aux==NULL) return -1;
    aux = list;
    while (aux != NULL){
      if(aux->atomList.atom != NULL){
         printf("Atom: %d", aux->atomList.atom);
      }
      else if (aux->atomList->list){
         printf("", aux->atomList-);
      }
    }
    return NULL;
}*/

int addList(Node **list, Node **subList){
    Node *no = (Node*)malloc(sizeof(Node));
   if(no==NULL) return -1;
   no->type = 1;
   no->atomList->list = subList->list;
   no->tail = NULL;
   list->tail = *no;
   return 1;
}