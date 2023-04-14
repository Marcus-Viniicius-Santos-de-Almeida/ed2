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
    int sum = 0;
    for (int i = 0; key[i]!=0; i++){
        sum+=key[i]*(i+1);
    }
    log_trace("hash <-");    
    return sum%MAX;
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal){
    log_info("Iserindo um par (chave, valor");
    log_trace("put ->");
    if (!containskay(hashStruct, key, equal)) {
        int res = enqueue(&hashStruct->hashes[hash(key)], data);
        hashStruct->size+=res;
        log_debug("res: %d", res);
        return res;
    }
    log_trace("hash <-");
    return 0;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal){
    log_info("Verificando se a chave já existe na tabela de hash");
    log_trace("containskey ->");
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    log_trace("containskay <-");
    return (pos!=-1)?true:false;
}

void* get(HashStruct *hashStruct, char *key, compare equal){
     log_info("valor buscando pela chave");
    return NULL;}

void* removeKey(HashStruct *hashStruct, char *key, compare equal){
    return NULL;
}

void showHashStruct(HashStruct *hashStruct){

}