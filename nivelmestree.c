#include <stdio.h>

#define TAM 10
#define TAM_HAB 5
#define NAVIO 3
#define HABILIDADE 5
#define AGUA 0

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar um navio horizontal de tamanho 3
void posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i < TAM) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

// Função para construir a matriz de habilidade em forma de cone
void construirCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Cone cresce para baixo com base no centro
            if (j >= 2 - i && j <= 2 + i && i <= 2) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para construir a matriz de habilidade em forma de cruz
void construirCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para construir a matriz de habilidade em forma de octaedro (losango)
void construirOctaedro(int octa[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octa[i][j] = 1;
            } else {
                octa[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origemLinha, int origemColuna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = origemLinha + i - 2;
                int colunaTabuleiro = origemColuna + j - 2;

                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM &&
                    colunaTabuleiro >= 0 && colunaTabuleiro < TAM &&
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] == AGUA) {
                    
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAM][TAM];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posiciona navios de exemplo
    posicionarNavioHorizontal(tabuleiro, 1, 2);
    posicionarNavioHorizontal(tabuleiro, 5, 5);

    // Constrói habilidades
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);       // Aplica cone com origem em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);       // Aplica cruz com origem em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);   // Aplica octaedro com origem em (7,7)

    // Exibe o resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}
