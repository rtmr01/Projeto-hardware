#include <stdio.h>
#include <limits.h>
#include <string.h> 

void CompDeDois(int num) {
    if (num > 32767 || num < -32768) {
        printf("Por questão de segurança e integridade do MEU computador, este programa só vaiaaa até 16 bits.\n");
        return;
    }
    if (num < 0) {
        num = (1 << 16) + num;
    }

    printf("Seu número em Complemento de dois: ");
    for (int i = 15; i >= 0; i--) {
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

void hexa(int num) {
    if (num > 32767 || num < -32768) {
        printf("SE VC QUER UM NUMERO MAIOR QUE ISSO, COMPRE UM PC DA NASA, NÃO DA APPLE!\n");
        return;
    }
    if (num < 0) {
        num = (1 << 16) + num;
    }   
    printf("Representação hexadecimal em 16 bits: 0x%04X\n", num);
}

void octa(int num) {
    int octal[100];
    int i = 0;
    int decimal = num;

    if (decimal < 0) {
        decimal = (1 << 16) + decimal;
    }

    while (decimal != 0) {
        octal[i] = decimal % 8;
        decimal /= 8;
        i++;
    }

    printf("Seu número de base 10: %d\n", num);
    printf("Teu número em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void decimalParaBCD(int decimal) {
    int bcd[100];
    int i = 0;

    while (decimal != 0) {
        int digito = decimal % 10;
        bcd[i] = digito;
        decimal /= 10;
        i++;
    }

    printf("O número em BCD é: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%04d ", bcd[j]);
    }
    printf("\n");
}

void float_Representation(float num) {
    unsigned int bits;
    memcpy(&bits, &num, sizeof(bits));

    int sinal = (bits >> 31) & 1;
    int expoente = (bits >> 23) & 0xFF;
    int fracoes = bits & 0x7FFFFF;

    printf("Representação de %.2f como float:\n", num);
    printf("Sinal: %d\n", sinal);

    printf("Expoente: ");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }

    printf("\nFrações: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (fracoes >> i) & 1);
    }
    printf("\n");
}

void double_Rpr(double num2) {
    unsigned long long bits;
    memcpy(&bits, &num2, sizeof(bits));

    int sinal = (bits >> 63) & 1;
    int expoente = (bits >> 52) & 0x7FF;
    unsigned long long fracoes = bits & 0xFFFFFFFFFFFFF;

    printf("Representação de %.2lf como double:\n", num2);
    printf("Sinal: %d\n", sinal);

    printf("Expoente: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (expoente >> i) & 1);
    }

    printf("\nFrações: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (fracoes >> i) & 1);
    }
    printf("\n");
}

int main() {
    int escolha;
    int num;

    do {
        printf("Escolha uma conversão (1: Complemento de dois, 2: Octal, 3: Hexadecimal, 4: Float, 5: Double, 6: Sair): ");
        scanf("%d", &escolha);

        if (escolha == 6) {
            printf("Programa encerrado.\n");
        } else if (escolha == 1) {
            printf("Digite seu número: ");
            scanf("%d", &num);
            CompDeDois(num);
        } else if (escolha == 2) {
            printf("Digite seu número: ");
            scanf("%d", &num);
            octa(num);
        } else if (escolha == 3) {
            printf("Digite seu número: ");
            scanf("%d", &num);
            hexa(num);
        } else if (escolha == 4) {
            float num;
            printf("Digite seu número (float): ");
            scanf("%f", &num);
            float_Representation(num);
        } else if (escolha == 5) {
            double num2;
            printf("Digite seu número (double): ");
            scanf("%lf", &num2);
            double_Rpr(num2);
        } else {
            printf("Escolha inválida.\n");
        }
    } while (escolha != 6);

    return 0;
}
