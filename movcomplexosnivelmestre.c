#include <stdio.h>

// ---------------------- TORRE (Recursiva) -------------------------
void moverTorre(int casasRestantes) {
    if (casasRestantes == 0) return;

    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

// ---------------------- RAINHA (Recursiva) -------------------------
void moverRainha(int casasRestantes) {
    if (casasRestantes == 0) return;

    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// ---------------------- BISPO (Recursiva + Loops Aninhados) -------------------------
void moverBispo(int i, int limite) {
    if (i > limite) return;

    // Loop interno representa o deslocamento horizontal para cada passo vertical
    for (int j = 1; j <= 1; j++) {
        printf("Cima Direita\n");
    }

    moverBispo(i + 1, limite);
}

// ---------------------- CAVALO (Loops Aninhados Complexos) -------------------------
void moverCavalo() {
    // Duas casas para cima, uma para a direita
    int casasVerticais = 2;
    int casasHorizontais = 1;

    printf("\nMovimento do CAVALO:\n");

    for (int i = 1; i <= casasVerticais; i++) {
        if (i == 2) {  // Depois da segunda casa para cima
            for (int j = 1; j <= casasHorizontais; j++) {
                printf("Direita\n");
                break;  // Pode sair após imprimir a direita
            }
        } else {
            if (i == 1) {
                printf("Cima\n");
                continue;
            }
            printf("Cima\n");
        }
    }
}

int main() {
    // ---------------------- TORRE -------------------------
    printf("Movimento da TORRE:\n");
    moverTorre(5);

    // ---------------------- BISPO -------------------------
    printf("\nMovimento do BISPO:\n");
    moverBispo(1, 5);

    // ---------------------- RAINHA ------------------------
    printf("\nMovimento da RAINHA:\n");
    moverRainha(8);

    // ---------------------- CAVALO ------------------------
    moverCavalo();

    return 0;
}
