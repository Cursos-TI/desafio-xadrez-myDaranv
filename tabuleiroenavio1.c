#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---------- 1º Navio - Horizontal ----------
    int linhaH = 1;
    int colunaH = 2;

    if (colunaH + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = 3;
        }
    }

    // ---------- 2º Navio - Vertical ----------
    int linhaV = 5;
    int colunaV = 6;

    if (linhaV + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // ---------- 3º Navio - Diagonal Principal (↘) ----------
    int linhaDiag1 = 0;
    int colunaDiag1 = 0;

    if (linhaDiag1 + TAM_NAVIO <= TAM && colunaDiag1 + TAM_NAVIO <= TAM) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaDiag1 + i][colunaDiag1 + i] == 0) {
                tabuleiro[linhaDiag1 + i][colunaDiag1 + i] = 3;
            }
        }
    }

    // ---------- 4º Navio - Diagonal Secundária (↙) ----------
    int linhaDiag2 = 2;
    int colunaDiag2 = 9;

    if (linhaDiag2 + TAM_NAVIO <= TAM && colunaDiag2 - TAM_NAVIO + 1 >= 0) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaDiag2 + i][colunaDiag2 - i] == 0) {
                tabuleiro[linhaDiag2 + i][colunaDiag2 - i] = 3;
            }
        }
    }

    // ---------- Exibe o Tabuleiro ----------
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
