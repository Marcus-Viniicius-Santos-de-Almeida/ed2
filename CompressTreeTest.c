#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "log.h"
#include <stdbool.h>



//void NewNode(SIMBOLO **edc, char *symbol, int frequency, )

/*ordenarvetor{

}

Agrupar{


}*/

bool compara(SIMBOLO *symbols1, SIMBOLO *symbols2, int c) {
    int f;
    for(int i=0; i<=c, i++)[
        f = 0;
        for(int j=0; j<=c; j++)[
            if(symbols1[i].symbol==symbols2[j].symbols)[
                f++;
            ]
        ]
    ]
 
    
    
    char *d1 = data1;
    char *d2 = data2;
    return (*d1==*d2)?true:false;
}

typedef struct simbolo{
    char symbol;
    int frequencia;
    struct simbolo *left;
    struct simbolo *right;
}SIMBOLO;

int main(int argc, char* argv[]){
    int k;
    int c;
    char ch, NomeArq[255], SC;
    //printf("Digite o nome do arquivo: ");
    //scanf("%s", &NomeArq[k]);
    FILE *Arquivo = fopen(argv[1], "r");
    int i = 1;
    c=0;

       while(!feof(Arquivo)){
        ch = fgetc(Arquivo);
        c++;
        printf("%d ", c);
    }
    SIMBOLO *symbolsF = (SIMBOLO *)malloc(sizeof(SIMBOLO)*c);
    fseek(Arquivo, 0, SEEK_SET);

    while(!feof(Arquivo)){
        ch = fgetc(Arquivo);
         printf("%c ", ch);

        //symbols[i].symbol = fgetc(Arquivo);
        //printf("%c ", symbols[i].symbol);
        i++;
    } 
    

    /*int s = i;
    //symbolsV[x].symbol=symbolsF[int ('')+1];
    SIMBOLO *symbolsV = (SIMBOLO *)malloc(sizeof(SIMBOLO)*i);
    for(int g=0; g<=i; g++){
        c=0;
        for(int h=0; h<=s; h++){
            if(compara(symbolsF[g].symbol, symbolsV[h].symbol)){
                c++;
            }
        }
    }*/

    /*for(int d=0; d<=i; d++){
        if(symbolsF[d].symbol==symbolsV[d].symbol){
            if
        }
    }*/
    

    /*for(int j=0; j<=i; j++){
        printf("%c ", symbols[j].symbol);
    }
    fclose(Arquivo);*/
    return 0;
}