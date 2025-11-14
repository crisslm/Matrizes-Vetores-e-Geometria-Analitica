#include <stdio.h>
#include <stdlib.h>

//Primeira Versão com matriz mxn
int** transposta(int** v, int m, int n){
    int i, j=0;
    int** matrizT = (int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++) matrizT[i] = (int*)malloc(sizeof(int)*m);
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matrizT[i][j] = v[j][i];
        }
    }
    return matrizT;
}

int main() {
    int m,n,i,j;
    printf("Insira o tamanho da matriz MxN: ");
    scanf("%d%d",&m,&n);
    
    int** matriz = (int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++) matriz[i] = (int*)malloc(sizeof(int)*n);
    
    printf("Insira os elementos da matriz:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&matriz[i][j]);
        }
    }

    int** matrizT = transposta(matriz, m, n);
    printf("\nMatriz transposta: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d ",matrizT[i][j]);
        }
        printf("\n");
    }

    
    
    return 0;
}