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

   if(*list == NULL){
      *list = no;
   }
   else {
      Node *aux = NULL;
      for (aux = *list; aux->tail!=NULL; aux=aux->tail);
      aux->tail = no;
   }

   return 1;
}

void showGeneralizedList(Node *list){
    Node *aux = (Node*)malloc(sizeof(Node));
    aux = list;
    printf("(");
    while (aux != NULL){
      if(aux->type == 0){
         printf("%d,", aux->atomList.atom);
      }
      else if(aux->type == 1){
         showGeneralizedList(aux->atomList.list);
      }
      aux=aux->tail;
    }
    printf(")");
}

int addList(Node **list, Node **subList){
    Node *no = (Node*)malloc(sizeof(Node));
   if(no==NULL) return -1;
   no->type = 1;
   no->atomList.list = *subList;
   no->tail = NULL;

    if(*list == NULL){
      *list = no;
   }
   else {
      Node *aux = NULL;
      for (aux = *list; aux->tail!=NULL; aux=aux->tail);
      aux->tail = no;
   }

   return 1;
}