#include <stdio.h>
#include <stdbool.h>

#define TAM 10
#define NAVIO 3
#define AGUA 0
#define PARTE_NAVIO 3

// Função para verificar se é possível posicionar o navio
bool pode_posicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;

        // Verifica se está dentro dos limites
        if (x < 0 || x >= TAM || y < 0 || y >= TAM)
            return false;

        // Verifica se já existe navio na posição
        if (tabuleiro[x][y] != AGUA)
            return false;
    }
    return true;
}

// Posiciona um navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM][TAM], int linha, int coluna, int dx, int dy) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + i * dx;
        int y = coluna + i * dy;
        tabuleiro[x][y] = PARTE_NAVIO;
    }
}

// Imprime o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Coordenadas e direções dos navios
    // dx, dy definem a direção: (1,0)=vertical | (0,1)=horizontal | (1,1)=diagonal ↘️ | (1,-1)=diagonal ↙️

    // Navio 1 - Horizontal (linha 1, coluna 1)
    if (pode_posicionar(tabuleiro, 1, 1, 0, 1))
        posicionar_navio(tabuleiro, 1, 1, 0, 1);

    // Navio 2 - Vertical (linha 3, coluna 5)
    if (pode_posicionar(tabuleiro, 3, 5, 1, 0))
        posicionar_navio(tabuleiro, 3, 5, 1, 0);

    // Navio 3 - Diagonal ↘️ (linha 0, coluna 0)
    if (pode_posicionar(tabuleiro, 0, 0, 1, 1))
        posicionar_navio(tabuleiro, 0, 0, 1, 1);

    // Navio 4 - Diagonal ↙️ (linha 0, coluna 9)
    if (pode_posicionar(tabuleiro, 0, 9, 1, -1))
        posicionar_navio(tabuleiro, 0, 9, 1, -1);

    // Exibe o tabuleiro final
    exibir_tabuleiro(tabuleiro);

    return 0;
}

