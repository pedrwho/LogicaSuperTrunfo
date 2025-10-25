#include <stdio.h>
#include <string.h>

struct Carta {
    char nome[30];
    float populacao;
    float area;
    float pib;
    float densidade;
};

float pegarValor(struct Carta c, int opcao) {
    switch (opcao) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 214.0, 8516.0, 22000.0, 25.1};
    struct Carta carta2 = {"Canadá", 38.0, 9976.0, 18000.0, 3.8};

    int escolha1, escolha2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma1, soma2;

    printf("=== SUPER TRUNFO - DESAFIO MESTRE ===\n\n");

    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demografica\n");
    printf("Opcao: ");
    if (scanf("%d", &escolha1) != 1) {
        printf("Entrada invalida! Encerrando programa.\n");
        return 0;
    }

    if (escolha1 < 1 || escolha1 > 4) {
        printf("Opcao invalida! Encerrando programa.\n");
        return 0;
    }

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    switch (escolha1) {
        case 1:
            printf("2 - Area\n3 - PIB\n4 - Densidade Demografica\n");
            break;
        case 2:
            printf("1 - Populacao\n3 - PIB\n4 - Densidade Demografica\n");
            break;
        case 3:
            printf("1 - Populacao\n2 - Area\n4 - Densidade Demografica\n");
            break;
        case 4:
            printf("1 - Populacao\n2 - Area\n3 - PIB\n");
            break;
    }
    printf("Opcao: ");
    if (scanf("%d", &escolha2) != 1) {
        printf("Entrada invalida! Encerrando programa.\n");
        return 0;
    }

    if (escolha2 == escolha1 || escolha2 < 1 || escolha2 > 4) {
        printf("Opcao invalida ou repetida! Encerrando programa.\n");
        return 0;
    }

    valor1_carta1 = pegarValor(carta1, escolha1);
    valor1_carta2 = pegarValor(carta2, escolha1);
    valor2_carta1 = pegarValor(carta1, escolha2);
    valor2_carta2 = pegarValor(carta2, escolha2);

    printf("\n=== RESULTADO DAS COMPARACOES ===\n\n");

    printf("Primeiro atributo: ");
    switch (escolha1) {
        case 1: printf("Populacao\n"); break;
        case 2: printf("Area\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Demografica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, valor1_carta1, carta2.nome, valor1_carta2);

    printf("\nSegundo atributo: ");
    switch (escolha2) {
        case 1: printf("Populacao\n"); break;
        case 2: printf("Area\n"); break;
        case 3: printf("PIB\n"); break;
        case 4: printf("Densidade Demografica\n"); break;
    }
    printf("%s: %.2f | %s: %.2f\n", carta1.nome, valor2_carta1, carta2.nome, valor2_carta2);

    float pontos1 = 0, pontos2 = 0;
    pontos1 += (escolha1 == 4) ? (valor1_carta1 < valor1_carta2) : (valor1_carta1 > valor1_carta2);
    pontos2 += (escolha1 == 4) ? (valor1_carta2 < valor1_carta1) : (valor1_carta2 > valor1_carta1);
    pontos1 += (escolha2 == 4) ? (valor2_carta1 < valor2_carta2) : (valor2_carta1 > valor2_carta2);
    pontos2 += (escolha2 == 4) ? (valor2_carta2 < valor2_carta1) : (valor2_carta2 > valor2_carta1);

    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n%s: %.2f\n", carta1.nome, soma1, carta2.nome, soma2);

    if (soma1 > soma2)
        printf("\n🏆 %s venceu a rodada!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("\n🏆 %s venceu a rodada!\n", carta2.nome);
    else
        printf("\n🤝 Empate!\n");

    return 0;
}
