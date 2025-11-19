#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Determinante 2x2;
float determinante2x2(float a, float b, float c, float d){
    float det = (a * d) - (b * c);
    return det;
}


float determinante3x3(float** m){
    float soma = 0;
    soma += m[0][0] * determinante2x2(m[1][1],m[1][2],m[2][1],m[2][2]);
    soma -= m[0][1] * determinante2x2(m[1][0],m[1][2],m[2][0],m[2][2]);
    soma += m[0][2] * determinante2x2(m[1][0],m[1][1],m[2][0],m[2][1]);
    return soma;
}

//Primeira Versão com matriz mxn
float** transposta(float** v, float m, float n){
    int i, j=0;
    float** matrizT = (float**)malloc(sizeof(float*)*n);
    for(i=0;i<n;i++) matrizT[i] = (float*)malloc(sizeof(float)*m);
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matrizT[i][j] = v[j][i];
        }
    }
    return matrizT;
}

//M e N das duas matrizes devem ser iguais!
float** somaMatriz(float** v1, float** v2, int m, int n){
    int i, j;
    float** resp = (float**)malloc(sizeof(float*)*m);
    for(i=0;i<m;i++) resp[i] = (float*)malloc(sizeof(float)*n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            resp[i][j] = v1[i][j] + v2[i][j];
        }
    }
    return resp;
}

//M e N das duas matrizes devem ser iguais!
float** subtraiMatriz(float** v1, float** v2, int m, int n){
    int i, j;
    float** resp = (float**)malloc(sizeof(float*)*m);
    for(i=0;i<m;i++) resp[i] = (float*)malloc(sizeof(float)*n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            resp[i][j] = v1[i][j] - v2[i][j];
        }
    }
    return resp;
}

float** produto(float** v1, float** v2, int m1, int n1, int m2, int n2){
    int i, j, k, soma = 0;
    
    float** resp = (float**)malloc(sizeof(float*)*m1);
    for(i=0;i<m1;i++) resp[i] = (float*)malloc(sizeof(float)*n2);
    
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            soma = 0;
            for(k=0;k<n1;k++){
                soma += v1[i][k] * v2[k][j];
            }
            resp[i][j] = soma;
        }
    }
    return resp;
}

int main() {
    int opcoes = 0; 
    int m, n, i, j;
    while(opcoes != -1){
        printf("\nO que deseja fazer?");
        printf("\n1)Determinante (2x2 ou 3x3)");
        printf("\n2)Transposta de uma Matriz");
        printf("\n3)Operações básicas de matriz.");
        printf("\n4)Produto de Matrizes.");
        printf("\n-1)Sair.");
        printf("\nInsira aqui(1,2,3 ou -1): ");
        scanf("%d",&opcoes);
        switch(opcoes){
            case 1:
                printf("Insira o tamanho da matriz MxN: ");
                scanf("%d%d",&m,&n);
                if(m > 3 || n > 3){
                    printf("\nErro no tamanho: M >3 ou N > 3!\n\n");
                    break;
                }
                if(m != n){
                    printf("Erro: Diferenca de tamanho de m e n!\n");
                    break;
                }                
                float** matriz = (float**)malloc(sizeof(float*)*m);
                for(i=0;i<m;i++) matriz[i] = (float*)malloc(sizeof(float)*n);
                
                printf("Insira os elementos da matriz:\n");
                for(i=0;i<m;i++){
                    for(j=0;j<n;j++){
                        scanf("%f",&matriz[i][j]);
                    }
                }
                if(m == 2){
                    float det = determinante2x2(matriz[0][0],matriz[0][1],matriz[1][0],matriz[1][1]);
                    printf("Determinante = %.1f",det);
                }
                if(m == 3){
                    float det = determinante3x3(matriz);
                    printf("Determinante = %.1f",det);
                }
                for(i=0;i<m;i++){
                    free(matriz[i]);
                }
                free(matriz);
            break;

            case 2:
                printf("Insira o tamanho da matriz MxN: ");
                scanf("%d%d",&m,&n);

                float** matriz2 = (float**)malloc(sizeof(float*)*m);
                for(i=0;i<m;i++) matriz2[i] = (float*)malloc(sizeof(float)*n);
                
                printf("Insira os elementos da matriz:\n");
                for(i=0;i<m;i++){
                    for(j=0;j<n;j++){
                        scanf("%f",&matriz2[i][j]);
                    }
                }

                float** matrizT = transposta(matriz2, m, n);

                printf("\nMatriz transposta: \n");
                for(i=0;i<n;i++){
                    for(j=0;j<m;j++){
                        printf("%.0f ",matrizT[i][j]);
                    }
                    printf("\n");
                }
            break;

            case 3:
                printf("Insira o tamanho das matrizes MxN: ");
                scanf("%d%d",&m,&n);

                float** matriz3 = (float**)malloc(sizeof(float*)*m);
                for(i=0;i<m;i++) matriz3[i] = (float*)malloc(sizeof(float)*n);

                float** matriz4 = (float**)malloc(sizeof(float*)*m);
                for(i=0;i<m;i++) matriz4[i] = (float*)malloc(sizeof(float)*n);
                
                printf("Insira os elementos da matriz 1:\n");
                for(i=0;i<m;i++){
                    for(j=0;j<n;j++){
                        scanf("%f",&matriz3[i][j]);
                    }
                }
                
                printf("\nInsira os elementos da matriz 2:\n");
                for(i=0;i<m;i++){
                    for(j=0;j<n;j++){
                        scanf("%f",&matriz4[i][j]);
                    }
                }
                float** resp1 = somaMatriz(matriz3, matriz4, m, n);
                float** resp2 = subtraiMatriz(matriz3, matriz4, m, n);
                
                printf("Soma das Matrizes: \n");

                for(i=0;i<m;i++){
                    for(j=0;j<n;j++){
                        printf("%.1f ",resp1[i][j]);
                    }
                    printf("\n");
                }

                printf("Subtracao das matrizes: \n");

                for(i=0;i<m;i++){
                    for(j=0;j<n;j++){
                        printf("%.1f ",resp2[i][j]);
                    }
                    printf("\n");
                }
            break;
            
            case 4:
            int m1, n1, m2, n2;
            printf("Insira o tamanho da matriz 1 MxN: ");
            scanf("%d%d",&m1,&n1);
            
            float** matriz5 = (float**)malloc(sizeof(float*)*m1);
            for(i=0;i<m1;i++) matriz5[i] = (float*)malloc(sizeof(float)*n1);
            
            printf("\nInsira o tamanho da matriz 2 MxN: ");
            scanf("%d%d",&m2,&n2);
            
            float** matriz6 = (float**)malloc(sizeof(float*)*m2);
            for(i=0;i<m2;i++) matriz6[i] = (float*)malloc(sizeof(float)*n2);
            
             printf("Insira os elementos da matriz 1:\n");
                for(i=0;i<m1;i++){
                    for(j=0;j<n1;j++){
                        scanf("%f",&matriz5[i][j]);
                    }
                }
                
             printf("Insira os elementos da matriz 2:\n");
                for(i=0;i<m2;i++){
                    for(j=0;j<n2;j++){
                        scanf("%f",&matriz6[i][j]);
                    }
                }
                
            float** produtom = produto(matriz5, matriz6, m1, n1, m2, n2);

            printf("Produto das matrizes: \n");

                for(i=0;i<m1;i++){
                    for(j=0;j<n2;j++){
                        printf("%.1f ",produtom[i][j]);
                    }
                    printf("\n");
                }            
            
            break;
            
            case -1:
                return 0;
            break;
            default:
                printf("\nOpcao invalida.");
            break;
        }
        
    }
    return 0;
}