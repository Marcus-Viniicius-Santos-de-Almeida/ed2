#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct simbolo{
    char symbol;
    int frequencia;
}SIMBOLO;

//void NewNode(SIMBOLO **edc, char *symbol, int frequency, )

/*ordenarvetor{

}

Agrupar{


}*/

int main(int argc, char* argv[]){
    int k;
    char ch, NomeArq[255];
    SIMBOLO *symbols = (SIMBOLO *)malloc(sizeof(SIMBOLO)*200);
    //printf("Digite o nome do arquivo: ");
    //scanf("%s", &NomeArq[k]);
    FILE *Arquivo = fopen(argv[1], "r");
    int i = 0;
    while(!feof(Arquivo)){
         symbols[i].symbol = fgetc(Arquivo);
         printf("%c ", symbols[i].symbol);
         i++;
    }
        
    

    /*for(int j=0; j<=i; j++){
        printf("%c ", symbols[j].symbol);
    }
    fclose(Arquivo);*/
    return 0;
}