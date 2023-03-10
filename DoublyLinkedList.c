#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "log.h"

void init(DoublyLinkedList *list) {
    log_info("Iniciando a lista");
    log_trace("init ->");
    Node *trashNode = (Node*)malloc(sizeof(Node));
    trashNode->data=NULL;
    log_debug("Data: %p", trashNode->data);
    trashNode->previous=trashNode;
    log_debug("Previous: %p\n", trashNode->previous);
    trashNode->next=trashNode;
    log_debug("Next: %p", trashNode->next);
    list->first=trashNode;
    log_debug("First: %p",  list->first);
    list->size=0;
    log_debug("Size: %d",  list->size);
    log_trace("init <-");
}

int enqueue(DoublyLinkedList *list, void *data) {
    log_info("Inserindo no final da lista");
    log_trace("enqueue ->"); 
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    log_debug("Data: %p", newNode->data);
    newNode->next = list->first;
    log_debug("Next: %p", newNode->next);
    newNode->previous = list->first->previous;
    log_debug("Previous: %p", newNode->previous);
    list->first->previous->next = newNode;
    log_debug("first->previous->next: %p", list->first->previous->next);
    list->first->previous = newNode;
    log_debug("first->previous: %p", list->first->previous);
    list->size++;
    log_debug("Size: %d", list->size);
    log_trace("enqueue <-");
    return 1;
}

void* dequeue(DoublyLinkedList *list) {
    log_info("Removendo do início da fila");
    log_trace("dequeue ->");
    if (isEmpty(list)){
        log_warn("Não há elementos na fila para serem removidos");
        return NULL;}
    Node *trash = list->first;
    Node *first = list->first->next;
    first->next->previous = trash;
    trash->next = first->next;
    log_info("Removido com sucesso");
    void *data = first->data;
    log_debug("Data: %p", data);
    free(first);
    list->size--;
    log_debug("size: %d", list->size);
    log_trace("dequeue <-");
    return data;
}

void* first(DoublyLinkedList *list) {
    log_info("Consultando o primeiro da fila");
    log_trace("first ->");
    log_debug("Data: %p", list->first->next->data);
    log_trace("first <-");
    return list->first->next->data;
}

void* last(DoublyLinkedList *list) {
    log_info("Consultando o último da fila");
    log_trace("last ->");
    log_debug("Data: %p", list->first->previous->data);
    log_trace("last <-");
    return list->first->previous->data;
}

int push(DoublyLinkedList *list, void *data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = list->first->next;
    newNode->previous = list->first;
    list->first->next->previous = newNode;
    list->first->next = newNode;
    list->size++;
    return 1;
}

void* pop(DoublyLinkedList *list) {
    return dequeue(list);
}

void* top(DoublyLinkedList *list) {
    return first(list);
}

bool isEmpty(DoublyLinkedList *list) {
    log_info("Verificando se a lista está vazia");
    log_trace("isEmpty ->");
    if (list->size==0) log_info("Lista vazia");
    else log_info("A lista não está vazia");
    log_trace("isEmpty <-");
    return (list->size==0);
}

int indexOf(DoublyLinkedList *list,void *data,compare equal) {
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first->next;
    while(aux!=list->first && !equal(aux->data,data)) {
        aux=aux->next;
        count++;
    }
    return (aux==list->first)?-1:count;
}

Node* getNodeByPos(DoublyLinkedList *list,int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *aux = list->first->next;
    for (int count=0;(aux!=list->first && count<pos);count++,aux=aux->next);
    return aux;
}

void* getPos(DoublyLinkedList *list,int pos) {
    Node *res = getNodeByPos(list,pos);
    return (res==NULL)?NULL:res->data;
}

int add(DoublyLinkedList *list, int pos, void *data) {
    Node *aux = getNodeByPos(list, pos);
    if (aux==NULL) return -2;
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode==NULL) return -1;
    newNode->data = data;
    newNode->next = aux;
    newNode->previous = aux->previous;
    aux->previous->next = newNode;
    aux->previous = newNode;
    list->size++;
    return 1;
}

//REVISAR
int addAll(DoublyLinkedList *listDest, int pos, DoublyLinkedList *listSource) {
Node *aux = getNodeByPos(listDest, pos);
    if (aux==NULL) return -2;
    if (isEmpty(listSource)) return -1;
    listSource->first->previous->next = aux;
    listSource->first->next->previous = aux->previous;
    aux->previous->next = listSource->first->next;
    aux->previous = listSource->first->previous;
    listDest->size+=listSource->size;
    return listSource->size;
}

//REVISAR
void* removePos(DoublyLinkedList *list, int pos) {
    if (isEmpty(list) || pos>=list->size) return NULL;
    Node *nodeRemove = getNodeByPos(list, pos);
    nodeRemove->previous->next = nodeRemove->next;
    nodeRemove->next->previous = nodeRemove->previous;
    void* dataRemove = nodeRemove->data;
    free(nodeRemove);
    list->size--;
    return dataRemove;
}

bool removeData(DoublyLinkedList *list, void *data, compare equal) {
    if (isEmpty(list)) return -1;
    Node *nodeRemove = list->first->next;
    while(nodeRemove!=list->first && !equal(nodeRemove->data,data))
        nodeRemove=nodeRemove->next;
    if (nodeRemove!=list->first) {
        nodeRemove->previous->next = nodeRemove->next;
        nodeRemove->next->previous = nodeRemove->previous;
        free(nodeRemove->data);
        free(nodeRemove);
        list->size--;
        return true;
    } else {
        return false;
    }
}

void show(DoublyLinkedList *list, printNode print) {
    Node *aux = list->first->next;
    while (aux!=list->first) {
        print(aux->data);
        aux=aux->next;
    }
    printf("\n");
}

void showMem(DoublyLinkedList *list) {
    printf("Trash Node: %p\n\n",list->first);
    Node *aux = list->first->next;
    printf("Node Addr : Previous - Data - Next\n\n");
        while (aux!=list->first) {
            printf("%p: %p - %p - %p\n",aux, aux->previous, aux->data, aux->next);
            aux=aux->next;
}
}