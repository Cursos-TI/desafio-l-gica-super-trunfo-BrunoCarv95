#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

void exibirCarta(struct Carta c, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Cidade: %s\n", c.nomeCidade);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    // Cadastro da primeira carta
    printf("Cadastro da primeira carta:\n");
    printf("Estado (letra): ");
    scanf(" %c", &carta1.estado);
    printf("Código (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);
    printf("População: ");
    scanf("%lu", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Nº de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cadastro da segunda carta
    printf("\nCadastro da segunda carta:\n");
    printf("Estado (letra): ");
    scanf(" %c", &carta2.estado);
    printf("Código (ex: B02): ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);
    printf("População: ");
    scanf("%lu", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Nº de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Exibição das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu
    printf("\n--- Menu de Comparação ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    // Escolha de Comparação
    switch (opcao) {
        case 1:
            printf("\n--- Comparação por População ---\n");
            if (carta1.populacao > carta2.populacao) {
                printf("Carta 1 venceu!\n");
            } else if (carta2.populacao > carta1.populacao) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("\n--- Comparação por Área ---\n");
            if (carta1.area > carta2.area) {
                printf("Carta 1 venceu!\n");
            } else if (carta2.area > carta1.area) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("\n--- Comparação por PIB ---\n");
            if (carta1.pib > carta2.pib) {
                printf("Carta 1 venceu!\n");
            } else if (carta2.pib > carta1.pib) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 4:
            printf("\n--- Comparação por Pontos Turísticos ---\n");
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Carta 1 venceu!\n");
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Carta 2 venceu!\n");
            } else {
                printf("Empate!\n");
            }
            break;
        case 5:
            printf("\n--- Comparação por Densidade Populacional (menor vence) ---\n");
            {
                float dens1 = carta1.populacao / carta1.area;
                float dens2 = carta2.populacao / carta2.area;
                if (dens1 < dens2) {
                    printf("Carta 1 venceu! (menor densidade: %.2f)\n", dens1);
                } else if (dens2 < dens1) {
                    printf("Carta 2 venceu! (menor densidade: %.2f)\n", dens2);
                } else {
                    printf("Empate! (densidade: %.2f)\n", dens1);
                }
            }
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}