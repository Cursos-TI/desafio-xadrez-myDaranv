#include <stdio.h>

int main() {
    // ---------------------- TORRE -------------------------
    // Move 5 casas para a direita (for)
    printf("Movimento da TORRE:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }

    // ---------------------- BISPO -------------------------
    // Move 5 casas na diagonal cima-direita (while)
    printf("\nMovimento do BISPO:\n");
    int j = 1;
    while (j <= 5) {
        printf("Cima Direita\n");
        j++;
    }

    // ---------------------- RAINHA ------------------------
    // Move 8 casas para a esquerda (do-while)
    printf("\nMovimento da RAINHA:\n");
    int k = 1;
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= 8);

    // ---------------------- CAVALO ------------------------
    // Move 2 casas para baixo e 1 para a esquerda (L)
    // Usa loops aninhados: for externo + while interno
    printf("\nMovimento do CAVALO:\n");

    int casasBaixo = 2;
    int casasEsquerda = 1;

    // Primeiro loop: 2 movimentos para baixo (for obrigatório)
    for (int i = 1; i <= casasBaixo; i++) {
        printf("Baixo\n");

        // Loop interno: movimento para esquerda após as 2 casas para baixo
        if (i == casasBaixo) {
            int contador = 1;
            while (contador <= casasEsquerda) {
                printf("Esquerda\n");
                contador++;
            }
        }
    }

    return 0;
}
