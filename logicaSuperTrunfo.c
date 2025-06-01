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

// Exibir uma carta
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

// Menu de atributos
void mostrarMenu() {
    printf("\n--- Menu de Comparação de Atributos ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
}

int compararAtributo(struct Carta c1, struct Carta c2, int atributo) {
    switch (atributo) {
        case 1:
            return (c1.populacao > c2.populacao) ? 1 : (c2.populacao > c1.populacao ? 2 : 0);
        case 2:
            return (c1.area > c2.area) ? 1 : (c2.area > c1.area ? 2 : 0);
        case 3:
            return (c1.pib > c2.pib) ? 1 : (c2.pib > c1.pib ? 2 : 0);
        case 4:
            return (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : (c2.pontosTuristicos > c1.pontosTuristicos ? 2 : 0);
        case 5: {
            float dens1 = (float)c1.populacao / c1.area;
            float dens2 = (float)c2.populacao / c2.area;
            return (dens1 < dens2) ? 1 : (dens2 < dens1 ? 2 : 0);
        }
        default:
            return -1;
    }
}

const char* nomeAtributo(int codigo) {
    switch (codigo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        default: return "Desconhecido";
    }
}

int main() {
    struct Carta carta1, carta2;
    int escolha1, escolha2;

    printf("=== Super Trunfo - Países (Nível Mestre) ===\n");

    // Cadastro carta 1
    printf("\nCadastro da primeira carta:\n");
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
    printf("Pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Cadastro carta 2
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
    printf("Pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Exibição
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Menu de seleção
    mostrarMenu();
    printf("\nEscolha o primeiro atributo para comparação: ");
    scanf("%d", &escolha1);
    printf("Escolha o segundo atributo para comparação: ");
    scanf("%d", &escolha2);

    int resultado1 = compararAtributo(carta1, carta2, escolha1);
    int resultado2 = compararAtributo(carta1, carta2, escolha2);

    printf("\n--- Resultado da Comparação ---\n");
    printf("Atributo 1 (%s): %s\n", nomeAtributo(escolha1),
           resultado1 == 1 ? "Carta 1 vence" :
           resultado1 == 2 ? "Carta 2 vence" : "Empate");

    printf("Atributo 2 (%s): %s\n", nomeAtributo(escolha2),
           resultado2 == 1 ? "Carta 1 vence" :
           resultado2 == 2 ? "Carta 2 vence" : "Empate");

    // Lógica final
    if ((resultado1 == 1 && resultado2 == 1) || 
        (resultado1 == 1 && resultado2 == 0) || 
        (resultado1 == 0 && resultado2 == 1)) {
        printf("\n🏆 Carta 1 é a vencedora geral!\n");
    } else if ((resultado1 == 2 && resultado2 == 2) || 
               (resultado1 == 2 && resultado2 == 0) || 
               (resultado1 == 0 && resultado2 == 2)) {
        printf("\n🏆 Carta 2 é a vencedora geral!\n");
    } else if (resultado1 == 0 && resultado2 == 0) {
        printf("\n🤝 Empate total! Ambas são incríveis cidades!\n");
    } else {
        printf("\n⚖️ Empate parcial! Ambas têm pontos fortes distintos!\n");
    }

    return 0;
}