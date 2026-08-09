#include <stdio.h>
#include <string.h>
#include <ctype.h>

void menu() {
    printf("\n=====================================\n");
    printf("\tCalculadora Simples\n");
    printf("=====================================\n");
    printf("Selecione uma opção: \n");
    printf("\n");
    printf("1. Adição.\n");
    printf("2. Subtração.\n");
    printf("3. Multiplicação.\n");
    printf("4. Divisão.\n");
    printf("5. Sair.\n\n");

}
int verifica(char c[]) {
    // é um número?
    int i = 0;
    while (c[i] != '\0') {
        if (!(c[i] >= '0' && c[i] <= '9')) {
            return 2;
        }
        i ++;
    }
    // está no intervalo adequado?
    if (strlen(c) == 1 && (c[0] >= '1' && c[0] <= '5')) {
        return 0;
    }
    return 1;

}

int main() {
    char querer = 's';
    char opcao[200];

    while (1) {
        menu();
        printf("Opção: ");
        scanf("%s", opcao);

        if (verifica(opcao) == 0) {
            if (opcao[0] == '5') {
                printf("\nSaindo do programa... volte sempre!");
                querer = 'n';
                break;
            }

            float a, b;

            printf("Primeiro número: ");
            scanf("%f", &a);
            printf("Segundo número: ");
            scanf("%f", &b);

            switch(opcao[0]) {
                case '1':
                    printf("Resultado: %.2f + %.2f = %.2f\n", a, b, a + b);
                    break;
                
                case '2':
                    printf("Resultado: %.2f - %.2f = %.2f\n", a, b, a - b);
                    break;

                case '3':
                    printf("Resultado: %.2f * %.2f = %.2f\n", a, b, a * b);
                    break;

                case '4':
                    if (b != 0) {
                        printf("Resultado: %.2f / %.2f = %.2f\n", a, b, a / b);
                        break;
                    } else {
                        printf("Erro: divisão por zero não é permitida.\n");
                    }
            }

            printf("Você quer continuar? [s/n] ");
            scanf(" %c", &querer);

            while (tolower(querer) != 's' && tolower(querer) != 'n') {
                printf("\nErro, por favor, digite 's' para sim e 'n' para não.\n");
                printf("Você quer continuar? [s/n] ");
                scanf(" %c", &querer);
            }

            if (tolower(querer) == 'n') {
                printf("\nSaindo do programa... volte sempre!");
                break;
            }

        } else if (verifica(opcao) == 1) {
            printf("\nErro: número fora do intervalo permitido. Tente novamente.\n");
        } else if (verifica(opcao) == 2) {
            printf("\nErro: a entrada é não numérica. Tente novamente.\n");
        }


        
    }


    return 0;
}
