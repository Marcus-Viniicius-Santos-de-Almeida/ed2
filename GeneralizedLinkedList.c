#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "GeneralizedLinkedList.h"

int addAtom(Node **list, int atom){
   Node *no = (Node*)malloc(sizeof(Node));
   if(no==NULL) return -1;
   no->type = 0;
   no->atomlist.atom = atom;
   no->tail = NULL;
   list->tail = &no;
   return 1;
}

void showGeneralizedList(Node *list){
    
}