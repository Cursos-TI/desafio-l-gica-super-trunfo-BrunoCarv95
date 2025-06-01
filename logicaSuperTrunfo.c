#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

int main() {
    struct Carta carta1, carta2;

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
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos turísticos: %d\n", carta1.pontosTuristicos);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos turísticos: %d\n", carta2.pontosTuristicos);

    // Atributo a ser comparado
    // Exemplo: comparar por PIB (você pode trocar por outro manualmente)
    char atributo[] = "pib";  // Trocar para: "populacao", "area", "pib", "pontos", "densidade"

    printf("\n--- Resultado da Comparação (%s) ---\n", atributo);

    if (strcmp(atributo, "populacao") == 0) {
        if (carta1.populacao > carta2.populacao) {
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
    } else if (strcmp(atributo, "area") == 0) {
        if (carta1.area > carta2.area) {
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
    } else if (strcmp(atributo, "pib") == 0) {
        if (carta1.pib > carta2.pib) {
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
    } else if (strcmp(atributo, "pontos") == 0) {
        if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
            printf("Carta 1 venceu!\n");
        } else {
            printf("Carta 2 venceu!\n");
        }
    } else if (strcmp(atributo, "densidade") == 0) {
        float dens1 = carta1.populacao / carta1.area;
        float dens2 = carta2.populacao / carta2.area;
        if (dens1 < dens2) {
            printf("Carta 1 venceu! (menor densidade)\n");
        } else {
            printf("Carta 2 venceu! (menor densidade)\n");
        }
    } else {
        printf("Atributo desconhecido.\n");
    }

    return 0;
}
