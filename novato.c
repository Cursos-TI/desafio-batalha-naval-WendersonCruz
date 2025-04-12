#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se o navio cabe dentro dos limites e não sobrepõe outro navio
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            if (coluna + i >= TAMANHO_TABULEIRO || tabuleiro[linha][coluna + i] != 0)
                return 0; // Fora do limite ou sobreposição
        } else if (orientacao == 'V') {
            if (linha + i >= TAMANHO_TABULEIRO || tabuleiro[linha + i][coluna] != 0)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio na matriz do tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = 3;
        } else if (orientacao == 'V') {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para imprimir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Números das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i); // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Coordenadas dos navios (definidas no código)
    int linhaNavioH = 2, colunaNavioH = 4; // Navio horizontal
    int linhaNavioV = 5, colunaNavioV = 7; // Navio vertical

    inicializarTabuleiro(tabuleiro);

    // Verifica e posiciona navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H')) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, 'H');
    } else {
        printf("Erro ao posicionar o navio horizontal!\n");
    }

    // Verifica e posiciona navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V')) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, 'V');
    } else {
        printf("Erro ao posicionar o navio vertical!\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
