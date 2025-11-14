#include <stdio.h>
#include <stdlib.h>

//Primeira Versão com matriz mxn
void transposta(int** v, int n){
    int i, j=0;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            int aux = v[i][j];
            v[i][j] = v[j][i];
            v[j][i] = aux;
        }
    }
}

int main() {
    int n,i,j;
    printf("Insira o tamanho da matriz N: ");
    scanf("%d",&n);
    
    int** matriz = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++) matriz[i] = (int*)malloc(sizeof(int)*n);
    
    pritf("Insira os elementos da matriz: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matriz[i][j]);
        }
    }

    transposta(matriz, n);
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    
    
    return 0;
}