#include <stdio.h>
#include <string.h>

// Estrutura da carta
struct Carta {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *carta, int numero) {
    printf("\nCadastro da Carta %d:\n", numero);
    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Código da Carta: ");
    scanf(" %s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->cidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (R$): ");
    scanf("%f", &carta->pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir uma carta
void exibirCarta(struct Carta carta) {
    printf("\n--- %s ---\n", carta.cidade);
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f R$\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

// Função para comparar dois atributos e retornar vencedor
int compararAtributo(int tipo, struct Carta c1, struct Carta c2) {
    // tipo: 1-população, 2-área, 3-pib, 4-pontos turísticos, 5-densidade
    switch(tipo) {
        case 1: return (c1.populacao > c2.populacao) ? 1 : 2;
        case 2: return (c1.area > c2.area) ? 1 : 2;
        case 3: return (c1.pib > c2.pib) ? 1 : 2;
        case 4: return (c1.pontosTuristicos > c2.pontosTuristicos) ? 1 : 2;
        case 5: { // densidade populacional: menor vence
            float dens1 = c1.populacao / c1.area;
            float dens2 = c2.populacao / c2.area;
            return (dens1 < dens2) ? 1 : 2;
        }
        default: return 0; // inválido
    }
}

// Função para mostrar o menu de atributos
void menu() {
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
}

int main() {
    struct Carta carta1, carta2;
    int opcao1, opcao2, vencedor1, vencedor2;
    char escolha;

    // Cadastro das cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibição das cartas
    exibirCarta(carta1);
    exibirCarta(carta2);

    do {
        printf("\nDeseja comparar 1 ou 2 atributos? (1/2): ");
        scanf(" %c", &escolha);

        if (escolha == '1') {
            menu();
            printf("Digite a opção: ");
            scanf("%d", &opcao1);
            vencedor1 = compararAtributo(opcao1, carta1, carta2);

            printf("\nResultado da Comparação:\n");
            if (vencedor1 == 1)
                printf("Carta 1 (%s) venceu!\n", carta1.cidade);
            else if (vencedor1 == 2)
                printf("Carta 2 (%s) venceu!\n", carta2.cidade);
            else
                printf("Opção inválida!\n");

        } else if (escolha == '2') {
            menu();
            printf("Digite a primeira opção: ");
            scanf("%d", &opcao1);
            printf("Digite a segunda opção: ");
            scanf("%d", &opcao2);

            vencedor1 = compararAtributo(opcao1, carta1, carta2);
            vencedor2 = compararAtributo(opcao2, carta1, carta2);

            printf("\nResultado da Comparação:\n");
            if (vencedor1 == vencedor2)
                printf("Carta %d (%s) venceu nos dois atributos!\n", vencedor1, (vencedor1==1)? carta1.cidade : carta2.cidade);
            else
                printf("Empate! Cada carta venceu em um atributo.\n");

        } else {
            printf("Escolha inválida!\n");
        }

        printf("\nDeseja fazer outra comparação? (s/n): ");
        scanf(" %c", &escolha);

    } while (escolha == 's' || escolha == 'S');

    printf("\nObrigado por jogar o Super Trunfo - Países!\n");
    return 0;
}

