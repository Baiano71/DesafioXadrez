#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5  // Tamanho fixo 5x5

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Colocar navios (valor 3) como exemplo
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[3][3] = 3;
}

void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2 - i) && j <= (TAM_HABILIDADE / 2 + i))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origem_linha, int origem_coluna) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTab = origem_linha - TAM_HABILIDADE / 2 + i;
            int colTab = origem_coluna - TAM_HABILIDADE / 2 + j;

            if (linhaTab >= 0 && linhaTab < TAM_TABULEIRO && colTab >= 0 && colTab < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] != 3)
                    tabuleiro[linhaTab][colTab] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    printf("=== Tabuleiro original ===\n");
    imprimirTabuleiro(tabuleiro);

    // Exemplo: aplicar cone
    gerarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);

    printf("\n=== Tabuleiro com Cone ===\n");
    imprimirTabuleiro(tabuleiro);

    // Resetar tabuleiro para nova visualização
    inicializarTabuleiro(tabuleiro);
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[3][3] = 3;

    // Exemplo: aplicar cruz
    gerarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);

    printf("\n=== Tabuleiro com Cruz ===\n");
    imprimirTabuleiro(tabuleiro);

    // Resetar tabuleiro novamente
    inicializarTabuleiro(tabuleiro);
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[3][3] = 3;

    // Exemplo: aplicar octaedro
    gerarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);

    printf("\n=== Tabuleiro com Octaedro ===\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
