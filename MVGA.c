#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Determinante 2x2;
int determinante2x2(int a, int b, int c, int d){
    int det = (a * d) - (b * c);
    return det;
}


int determinante3x3(int** m){
    int soma = 0;
    soma += m[0][0] * determinante2x2(m[1][1],m[1][2],m[2][1],m[2][2]);
    soma -= m[0][1] * determinante2x2(m[1][0],m[1][2],m[2][0],m[2][2]);
    soma += m[0][2] * determinante2x2(m[1][0],m[1][1],m[2][0],m[2][1]);
    return soma;
}

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

//M e N das duas matrizes devem ser iguais!
int** somaMatriz(int** v1, int** v2, int m, int n){
    int i, j;
    int** resp = (int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++) resp[i] = (int*)malloc(sizeof(int)*n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            resp[m][n] = v1[i][j] + v2[i][j];
        }
    }
    return resp;
}

//M e N das duas matrizes devem ser iguais!
int** subtraiMatriz(int** v1, int** v2, int m, int n){
    int i, j;
    int** resp = (int**)malloc(sizeof(int*)*m);
    for(i=0;i<m;i++) resp[i] = (int*)malloc(sizeof(int)*n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            resp[m][n] = v1[i][j] - v2[i][j];
        }
    }
    return resp;
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
    if(m == 2 && n == 2){
        int det = determinante2x2(matriz[0][0], matriz[0][1], matriz [1][0], matriz[1][1]);
        printf("\nDeterminante: %d", det);
    }
    if(m == 3 && n == 3){
        int det = determinante3x3(matriz);
        printf("\nDeterminante: %d", det);
    }
    

    for(i=0;i<m;i++){
        free(matriz[i]);
    }
    free(matriz);
    for(i=0;i<n;i++){
        free(matrizT[i]);
    }
    free(matrizT);
    
    return 0;
}