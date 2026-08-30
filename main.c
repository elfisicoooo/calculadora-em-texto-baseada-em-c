#include <stdio.h>
#include <string.h>
#include <ctype.h>

void menu() {
    printf("\n=====================================\n");
    printf("\tCalculadora Simples\n");
    printf("=====================================\n");
    printf("Selecione uma opcao: \n");
    printf("\n");
    printf("1. Adicao.\n");
    printf("2. Subtracao.\n");
    printf("3. Multiplicacao.\n");
    printf("4. Divisao.\n");
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
        printf("Opcao: ");
        scanf("%s", opcao);

        if (verifica(opcao) == 0) {
            if (opcao[0] == '5') {
                printf("\nSaindo do programa... volte sempre!");
                querer = 'n';
                break;
            }

            float a, b;

            printf("Primeiro numero: ");
            scanf("%f", &a);
            printf("Segundo numero: ");
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
                        printf("Erro: divisao por zero não eh permitida.\n");
                    }
            }

            printf("Voce quer continuar? [s/n] ");
            scanf(" %c", &querer);

            while (tolower(querer) != 's' && tolower(querer) != 'n') {
                printf("\nErro, por favor, digite 's' para sim e 'n' para nao.\n");
                printf("Voce quer continuar? [s/n] ");
                scanf(" %c", &querer);
            }

            if (tolower(querer) == 'n') {
                printf("\nSaindo do programa... volte sempre!");
                break;
            }

        } else if (verifica(opcao) == 1) {
            printf("\nErro: numero fora do intervalo permitido. Tente novamente.\n");
        } else if (verifica(opcao) == 2) {
            printf("\nErro: a entrada eh nao numerica. Tente novamente.\n");
        }
    }
    return 0;
}
