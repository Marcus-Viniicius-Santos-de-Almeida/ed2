#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Blockchain.h"
#include "log.h"

static void hash_to_string(char string[65], const uint8_t hash[32]){
    size_t i;
    for (i=0; i<32; i++){
        string += sprintf(string, "%02x", hash[i]);
    }
}

char* calculateHash(int index, char* previousHash, unsigned long timestamp, float data){
    char input[1024];
    sprintf(input, "%i%s%lu%.8f", index, previousHash, timestamp, data);
    uint8_t hash[32];
    char *hash_string = (char*)malloc(sizeof(char)*65);
    calc_sha_256(hash, input, strlen(input));
    hash_to_string(hash_string, hash);
    return hash_string;
}

Block* generateNextBlock(Blockchain *blockchain, float data){
    Block *previousBlock = getLatestBlock(blockchain);
    Block *newBlock = (Block*)malloc(sizeof(Block));
    newBlock->data = data;
    newBlock->previousHash = previousBlock->hash;
    newBlock->index = previousBlock->index+1;
    newBlock->timestamp = time(NULL);
    newBlock->hash = calculateBlockHash(newBlock);
    return newBlock;
}

void initBlockchain(Blockchain *blockchain){
    Block *genesisBlock = (Block*)malloc(sizeof(Block));
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->previousBlock = NULL;
    genesisBlock->timestamp = time(NULL);
    genesisBlock->data = 1000000;
    genesisBlock->hash = calculateHash(genesisBlock->index, genesisBlock->previousHash, genesisBlock->timestamp, genesisBlock->data)
}

