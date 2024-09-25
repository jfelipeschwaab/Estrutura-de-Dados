#include <stdio.h>
#include <string.h> 

void criarArray(); 

int main() {
    printf("Arrays sao formas maravilhosas de aplicar algo, Arrays sao um conjunto de elementos de um mesmo tipo, onde sua busca ocorre por meio da indexacao, onde o primeiro elemento sempre estara no index 0, Arrays podem ser unidimensionais (Vetores) e Bi-dimensionais (Matrizes)\n");

    criarArray();

    return 0;
}

void criarArray() {
    int op = 0;

    int arrayDeInteiros[5];
    char arrayDeString[50];
    float arrayDeFloat[5];

    printf("Digite qual tipo de array voce deseja criar: \n1. Do tipo inteiro\n2. Do tipo String\n3. Do tipo float\n4. Sair do programa\n");
    
    while (op != 4) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    arrayDeInteiros[i] = i;
                }

                printf("Esse eh meu array de inteiros:\n");
                for (int j = 0; j < 5; j++) {
                    printf("|%d|", arrayDeInteiros[j]);
                }
                printf("\n");
                break;
            
            case 2: 
                strcpy(arrayDeString, "Joao Felipe");

                printf("\nIsso eh uma string na posicao 0:\n%s\n", arrayDeString);
                break;

            case 3: 
                for (int i = 0; i < 5; i++) {
                    arrayDeFloat[i] = i + 0.5;
                }

                printf("Esse eh meu array de floats:\n");
                for (int j = 0; j < 5; j++) {
                    printf("|%.2f|", arrayDeFloat[j]);
                }
                printf("\n");
                break;

            case 4: 
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

        if (op != 4) {
            printf("\nDigite qual tipo de array voce deseja criar: \n1. Do tipo inteiro\n2. Do tipo String\n3. Do tipo float\n4. Sair do programa\n");
        }
    }
}
