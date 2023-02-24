#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

int main() {
	FILE *file = fopen("program.log","w");
	
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);
	
	LinkedList lista;
	init(&lista);

	int *numero = malloc(sizeof(int));
	*numero = 10;
	enqueue(&lista, numero);
	numero = malloc(sizeof(int));
	*numero = 20;
	enqueue(&lista, numero);
	first(&lista);
    //printf("%d\n", *((int*)dequeue(&lista)));
    //printf("%d\n", *((int*)dequeue(&lista)));
    //dequeue(&lista);

				

	return EXIT_SUCCESS;
}
