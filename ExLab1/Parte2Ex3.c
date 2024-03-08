#include <stdio.h>

void ordenarDecrescente(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int valores[10];
    int i;

    printf("Digite 10 valores:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    ordenarDecrescente(valores, 10);

    printf("Valores em ordem decrescente:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    return 0;
}