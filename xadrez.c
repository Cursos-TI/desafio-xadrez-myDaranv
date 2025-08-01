#include <stdio.h>

int main() {
    // ---------------------- TORRE -------------------------
    // A torre anda em linha reta (horizontal ou vertical).
    // Aqui simularemos 5 casas para a direita com 'for'.

    printf("Movimento da TORRE:\n");

    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    // ---------------------- BISPO -------------------------
    // O bispo se move na diagonal.
    // Aqui simularemos 5 casas na diagonal cima-direita com 'while'.

    printf("\nMovimento do BISPO:\n");

    int j = 1;
    while (j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    // ---------------------- RAINHA ------------------------
    // A rainha se move em todas as direções.
    // Aqui simularemos 8 casas para a esquerda com 'do-while'.

    printf("\nMovimento da RAINHA:\n");

    int k = 1;
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= 8);

    return 0;
}
