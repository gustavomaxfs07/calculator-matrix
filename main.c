#include <stdio.h>

void criar_matriz(int linhas, int colunas, int matriz[linhas][colunas], char nome) {
    printf("Digite os elementos da matriz %c %dx%d:\n", nome, linhas, colunas);
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void formato_matriz(int *linhas, int *colunas, char nome) {
    do {
        printf("Digite o numero de linhas da matriz %c: ", nome);
        scanf("%d", linhas);
        if (*linhas <= 0) {
            printf("Valor invalido\n");
        }
    } while (*linhas <= 0);

    do {
        printf("Digite o numero de colunas da matriz %c: ", nome);
        scanf("%d", colunas);
        if (*colunas <= 0) {
            printf("Valor invalido\n");
        }
    } while (*colunas <= 0);
}

void exibir_matriz(int linhas, int colunas, int matriz[linhas][colunas], char nome) {
    printf("Matriz %c:\n", nome);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicacao_matrizes(int linhasA, int colunasA, int linhasB, int colunasB, int A[linhasA][colunasA], int B[linhasB][colunasB], int resultado[linhasA][colunasB]) {
    for (int i = 0; i < linhasA; i++) {
        for (int j = 0; j < colunasB; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < colunasA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void calculo_multiplicacao_matriz(){
    int linhasA, colunasA, linhasB, colunasB;

    do{

        formato_matriz(&linhasA, &colunasA, 'A');
        formato_matriz(&linhasB, &colunasB, 'B');

        if (colunasA != linhasB) {
            printf("Colunas da matriz A diferente do numero de linhas da matriz B!\n\n");
        }

    } while (colunasA != linhasB);

    int matrizA[linhasA][colunasA];
    int matrizB[linhasB][colunasB];

    int resultado[linhasA][colunasB];

    criar_matriz(linhasA, colunasA, matrizA, 'A');
    criar_matriz(linhasB, colunasB, matrizB, 'B');

    multiplicacao_matrizes(linhasA, colunasA, linhasB, colunasB, matrizA, matrizB, resultado);
    
    printf("\nResultado da multiplcacao das matrizes (A * B):\n");
    exibir_matriz(linhasA, colunasB, resultado, 'R');
}

void subtracao_matrizes(int linhas, int colunas, int A[linhas][colunas], int B[linhas][colunas], int resultado[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }
}

void calculo_subtracao_matriz(){
    int linhas, colunas;

    formato_matriz(&linhas, &colunas, 'R');

    int matrizA[linhas][colunas];
    int matrizB[linhas][colunas];
    int resultado[linhas][colunas];

    criar_matriz(linhas, colunas, matrizA, 'A');
    criar_matriz(linhas, colunas, matrizB, 'B');

    subtracao_matrizes(linhas, colunas, matrizA, matrizB, resultado);

    printf("\nResultado da subtracao das matrizes (A - B):\n");
    exibir_matriz(linhas, colunas, resultado, 'R');
}

void somar_matrizes(int linhas, int colunas, int A[linhas][colunas], int B[linhas][colunas], int resultado[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

void calculo_soma_matriz(){
    int linhas, colunas;

    formato_matriz(&linhas, &colunas, 'R');

    int matrizA[linhas][colunas];
    int matrizB[linhas][colunas];
    int resultado[linhas][colunas];

    criar_matriz(linhas, colunas, matrizA, 'A');
    criar_matriz(linhas, colunas, matrizB, 'B');

    somar_matrizes(linhas, colunas, matrizA, matrizB, resultado);

    printf("\nResultado da soma das matrizes (A + B):\n");
    exibir_matriz(linhas, colunas, resultado, 'R');
}

void tipo_calculo_matrizes(){
    int opcao;

    do {
        printf("\n\n======= MENU =======\n");
        printf("1 - Soma de matrizes\n");
        printf("2 - Subitracao de matrizes\n");
        printf("3 - Multiplicacao de matrizes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                calculo_soma_matriz();
                break;

            case 2:
                calculo_subtracao_matriz();
                break;

            case 3:
                calculo_multiplicacao_matriz();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);
}

int determinante(int n, int matriz[n][n]) {
    int resultado = 0;

    // Caso base: matriz 1x1
    if (n == 1) {
        return matriz[0][0];
    }

    // Caso base: matriz 2x2
    if (n == 2) {
        return (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
    }

    int submatriz[n-1][n-1];

    // Expansão pela primeira linha
    for (int x = 0; x < n; x++) {
        int subi = 0; // índice da linha da submatriz
        for (int i = 1; i < n; i++) {
            int subj = 0; // índice da coluna da submatriz
            for (int j = 0; j < n; j++) {
                if (j == x) {
                    continue;
                }
                submatriz[subi][subj] = matriz[i][j];
                subj++;
            }
            subi++;
        }
        
        // Calcula o cofator
        int cofator = (x % 2 == 0 ? 1 : -1) * matriz[0][x];
        resultado += cofator * determinante(n - 1, submatriz);
    }

    return resultado;
}

void determinante_matriz(){
    int lineAndColun;
    char nome = 'x';

    do {
        printf("Digite o numero de linhas e colunas: ");
        scanf("%d", &lineAndColun);

        if (lineAndColun <= 0){
            printf("Valor invalido\n");
        }
    } while (lineAndColun <= 0);

    int matriz[lineAndColun][lineAndColun];
    criar_matriz(lineAndColun, lineAndColun, matriz, nome);

    int resultado = determinante(lineAndColun, matriz);

    printf("Determinante da matriz: %d\n", resultado);

    // exibir_matriz(lineAndColun, lineAndColun, matriz, nome);
}

int main() {
    int opcao;

    do {
        printf("\n======= MENU =======\n");
        printf("1 - Calcular matrizes\n");
        printf("2 - Calcular determinante\n");
        printf("0 - Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                tipo_calculo_matrizes();
                break;

            case 2:
                determinante_matriz();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}
