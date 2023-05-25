#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct simbolo{
    char symbol;
    int frequencia;
}SIMBOLO;

/*ordenarvetor{

}

Agrupar{


}*/

int main(){
    int k;
    char ch, NomeArq[255];
    SIMBOLO *symbols = (SIMBOLO *)malloc(sizeof(SIMBOLO));
    printf("Digite o nome do arquivo: ");
    scanf("%s", &NomeArq[k]);
    FILE *Arquivo = fopen(NomeArq, "r");
    int i = 0;
    do{
        symbols[i].symbol = fgetc(Arquivo);
    }while(ch=fgetc(Arquivo)!=EOF);

    for(int j=0; j<=i; j++){
        printf("%c ", symbols[j].symbol);
    }
    fclose(Arquivo);
    return 0;
}