#ifndef CADASTRODELOTES_H_INCLUDED
#define CADASTRODELOTES_H_INCLUDED

#define MAX_ANIMAIS 100  // Definindo o limite de animais por lote
#define MAX_TAREFA 256

/**
Principal header do código, objetivo de cadastro de lotes de gado dentro da propiedade,
dentro desse codigo é possível armazenar diferentes tipos de dados:

- Numero de identificação do lote
- Numero de animais contidos nesse lote
- Idade média em meses
- Peso atual(data de cadastro)
- Expectativa de ganho de peso ideal
- sexo
- Consumo diario
- Custo com alimentação (mensal)

Todos esses dados são cadastrados dentro de um txt que é utilizado posteriormente no código.

**/
// Definindo a estrutura Animal

typedef struct {
    // Struct fundamental de definição da estrutura de lotes
    int lote, numeroAnimais, idadeMeses;
    // Dados basicos de lote
    float pesoAtual, ganhoPesoIdeal;
    // Definição de dados para cadastro e previsões
    char sexo[30]; // Definição de sexo dos animais do lote
    float consumoAlimento; // Consumo de alimento
    float custoAlimentacao; // Custo de alimentação
}Animal;

// Função para cadastrar lote
void cadastrarLote(Animal animais[], int *quantidade) {
    if (*quantidade >= MAX_ANIMAIS) {
        printf("Limite de lotes cadastrados atingido!\n");
    }
    else{
        for(int i; i<(*quantidade); i++){
            printf("\nCadastro de lote:\n");
            printf("Digite o número do lote: ");
            scanf("%d", &animais[i].lote);
            printf("Digite o número de animais: ");
            scanf("%d", &animais[i].numeroAnimais);
            printf("Digite o peso atual (kg): ");
            scanf("%f", &animais[i].pesoAtual);
            printf("Digite o sexo dos animais: ");
            scanf("%s", animais[i].sexo);
            printf("Digite a idade média dos animais (meses): ");
            scanf("%d", &animais[i].idadeMeses);
            printf("Digite o ganho de peso ideal (kg): ");
            scanf("%f", &animais[i].ganhoPesoIdeal);
            printf("Digite o consumo de alimento por animal (kg): ");
            scanf("%f", &animais[i].consumoAlimento);
            printf("Digite o custo da alimentação por animal (R$): ");
            scanf("%f", &animais[i].custoAlimentacao);
            // Entrada de Dados do usuário para definição de lotes, dados salvos em um .txt
        }

        printf("Lote cadastrado com sucesso!\n");
    }
}

// Função para listar os lotes
void listarLotes(Animal animais[], int *quantidade) {
    printf("\n--- Lotes Cadastrados ---\n");
    for (int i=0; i<(*quantidade); i++) {
        printf("Lote %d: %d animais, Peso Médio: %.2f kg, Sexo: %s, Idade Média: %d meses\n",
               animais[i].lote,
               animais[i].numeroAnimais,
               animais[i].pesoAtual,
               animais[i].sexo,
               animais[i].idadeMeses);
               //Função para listagem dos dados ja cadastrados de um lote
    }
    printf("-----------------------------\n");
}

// Função para salvar dados em arquivo
void salvarDados(Animal animais[], int quantidade) {
    FILE *arquivo = fopen("dados_animais.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Lote: %d, Animais: %d, Peso: %.2f, Sexo: %s, Idade: %d meses, Ganho Ideal: %.2f kg, Consumo Alimento: %.2f kg, Custo Alimentacao: R$%.2f\n",
                animais[i].lote,
                animais[i].numeroAnimais,
                animais[i].pesoAtual,
                animais[i].sexo,
                animais[i].idadeMeses,
                animais[i].ganhoPesoIdeal,
                animais[i].consumoAlimento,
                animais[i].custoAlimentacao);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

#endif // CADASTRODELOTES_H_INCLUDED
