#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h" //https://github.com/rxi/log.c

void init(LinkedList *list) {
	log_info("Inicializando a lista");
	log_trace("init ->");
	list->first = NULL;
	list->size = 0;	
	log_debug("list->first: %p", list->first);
	log_debug("list->size: %d", list->size);
	log_trace("init <-");
}

int enqueue(LinkedList *list, void *data) {
	log_info("Adicionando no final da fila");
	log_trace("enqueue ->");
	Node *no = (Node*)malloc(sizeof(Node));
	if (no == NULL) {
		log_debug("no: %p", no);
		log_error("Memória insuficiente para a operação");
		return 0;
	} else {
		no->data = data;
		no->next = NULL;
	}
	if (isEmpty(list)) {
		list->first = no;
	} else {
		Node *aux = list->first;
		log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
		while (aux->next != NULL) {
			aux = aux->next;
			log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
		}
		aux->next = no;
		log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);		
	}
	list->size += 1;
	log_info("Dado inserido com sucesso!");
	log_debug("no(data,next): %p(%p,%p)", no, no->data, no->next);
	log_trace("enqueue <-");
	
	return 1;	
}

void* dequeue(LinkedList *list) {

  log_info("Removendo o primeiro elemento da fila");
  log_trace("dequeue ->");
  if ((isEmpty(list))) {
    log_warn("Não há elementos na fila para serem removidos");
    return NULL;
  } 
  Node *trash = list->first; 
  list->first = list->first->next;
  log_info("Removido com sucesso");
  void *data = trash->data;
  log_debug("data: %p", data);
  free(trash);
  list->size--;
  log_trace("dequeue <-");
  return data;
}

void* first(LinkedList *list) {
	log_info("Retornando o primeiro elemento da lista");
	log_trace("first ->");
	if (isEmpty(list)) {
		log_warn("Não há elementos na lista para retornar o primeiro dado");
		return NULL;
	}
	log_debug("Endereço do primeiro dado: %p", list->first->data);
	log_trace("first <-");
	return list->first->data;
	
}

void* last(LinkedList *list) {
	log_info("Retornando o último elemento da lista");
	log_trace("last ->");
	void *data = NULL;
	if (!isEmpty(list)) {
		Node *aux = list->first;
		log_debug("(*aux, list->first): (%p, %p)", aux, list->first);
		while (aux->next != NULL){
			aux = aux->next;
		}
	    data = aux->data;
	    log_debug("(data, aux->data): (%p, %p)", data, aux->data);
	}

	log_debug("Endereço do último dado: %p", data);
	log_trace("last <-");
	return data;
}

int push(LinkedList *list, void *data) {
	log_info("Inserindo no topo da pilha");
	log_trace("push ->");
	Node *newNode = (Node*) malloc(sizeof(Node));
	if (newNode==NULL) {
		
		return -1;}
	newNode->data = data;
	newNode->next = NULL;
	if (isEmpty(list)){
		list->first = newNode;
	}
	else{
		newNode->next = list->first;
		list->first = newNode;
	}
    list->size++;
	log_trace("push <-");
	return 1;
}

void* pop(LinkedList *list) {
	return NULL;
}

void* top(LinkedList *list) {
	return NULL;
}

bool isEmpty(LinkedList *list) {
	log_info("Verificando se a lista está vazia");
	log_trace("isEmpty ->");
	if (list == NULL) {
		log_error("Parâmetro inválido");
		log_debug("list: %p", list);
		return true;
	}
	log_debug("list->size: %d", list->size);
	log_trace("isEmpty <-");
	if (list->size == 0) {
		return true;
	} else {
		return false;
	}
}

int indexOf(LinkedList *list, void *data, compare equal) {
	return 0;
}

void* getPos(LinkedList *list, int pos) {
	return NULL;
}

Node* getNodeByPos(LinkedList *list, int pos) {
	return NULL;
}

int add(LinkedList *list, int pos, void *data) {
	return 0;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {
	return 0;
}

void* removePos(LinkedList *list, int pos) {
	return NULL;
}

bool removeData(LinkedList *list, void *data, compare equal) {
	return false;
}
