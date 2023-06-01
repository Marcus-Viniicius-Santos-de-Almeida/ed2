#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"



//void NewNode(SIMBOLO **edc, char *symbol, int frequency, )

/*ordenarvetor{

}

Agrupar{


}*/

typedef struct simbolo{
    char symbol;
    int frequencia;
    struct simbolo *left;
    struct simbolo *right;
}SIMBOLO;

int main(int argc, char* argv[]){
    int k, c;
    int t = 0;
    char ch, NomeArq[255], SC;
    SIMBOLO *symbols = (SIMBOLO *)malloc(sizeof(SIMBOLO)*99999999);
    //printf("Digite o nome do arquivo: ");
    //scanf("%s", &NomeArq[k]);
    FILE *Arquivo = fopen(argv[1], "r");
    int i = 0;
    while(!feof(Arquivo)){
        c = 0;
        SC = '\0';
        SC = fgetc(Arquivo);
        while(symbols[t]!=NULL){
            if(symbols[t].symbol==SC){
            c++;
            t++;
            }
        }
        if (c==0){
            symbols[i].symbol = SC;
        }
        printf("%c ", symbols[i].symbol);
        i++;
    }
        
    

    /*for(int j=0; j<=i; j++){
        printf("%c ", symbols[j].symbol);
    }
    fclose(Arquivo);*/
    return 0;
}