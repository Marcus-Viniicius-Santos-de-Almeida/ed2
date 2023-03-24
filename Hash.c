#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Hash.h"
#include "DoublyLinkedList.h"

void initHash(HashStruct *hashStruct){
    log_info("Inicializando o Hash");
    log_trace("initHash ->");
    for (int i=0; i<MAX; i++){
        init(&(hashStruct->hashes));
    }
    hashStruct->size = 0;
    log_debug("size: %d", hashe->size);
    log_trace("initHash <-");
}
bool isHashEmpty(HashStruct *hashStruct){
    log_info("Verificando se a tabela de hash está vazia");
    return (hashStruct->size == 0);
}
int hash(char *key){
    log_info("Calculando o hash para a chave");
    log_trace("hash ->");

    log_trace("hash <-");    
    return 1;}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    
    return 1;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    
    return NULL;}

void* get(HashStruct *hashStruct, char *key, compare equal){
    
    return NULL;}

void* removeKey(HashStruct *hashStruct, char *key, compare equal){
    return NULL;
}

void showHashStruct(HashStruct *hashStruct){

}