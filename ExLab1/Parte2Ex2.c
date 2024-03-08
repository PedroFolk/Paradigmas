#include <stdio.h>

void multiplicarMatrizes(int A[3][3], int B[3][3], int C[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void subtrairMatrizes(int A[3][3], int B[3][3], int C[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void somarMatrizes(int A[3][3], int B[3][3], int C[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void imprimirMatriz(int mat[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void calcularTransposta(int mat[3][3], int transposta[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            transposta[j][i] = mat[i][j];
        }
    }
}

int main() {
    int A[3][3], B[3][3], C[3][3], opcao;
    
    printf("Digite os valores da matriz A (ordem 3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Digite os valores da matriz B (ordem 3x3):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    do {
        printf("\nEscolha a opção:\n");
        printf("(1) C=A*B\n");
        printf("(2) C=A-B\n");
        printf("(3) C = A+B\n");
        printf("(4) A Transposta da matriz C, sendo que C=A*B\n");
        printf("(5) Sair do Programa\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                multiplicarMatrizes(A, B, C);
                printf("O resultado de A*B é:\n");
                imprimirMatriz(C);
                break;
            case 2:
                subtrairMatrizes(A, B, C);
                printf("O resultado de A-B é:\n");
                imprimirMatriz(C);
                break;
            case 3:
                somarMatrizes(A, B, C);
                printf("O resultado de A+B é:\n");
                imprimirMatriz(C);
                break;
            case 4:
                multiplicarMatrizes(A, B, C);
                printf("A transposta da matriz resultante de A*B é:\n");
                int transpostaC[3][3];
                calcularTransposta(C, transpostaC);
                imprimirMatriz(transpostaC);
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 5);
    
    return 0;
}
