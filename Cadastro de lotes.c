#ifndef DADOSCOMPRAS_H_INCLUDED
#define DADOSCOMPRAS_H_INCLUDED
#define MAX_DADOS 100

void exibirDados() {
    FILE *arquivo = fopen("dadosProp.txt", "r");
    if (!arquivo) {
        printf("Nenhuma informacao encontrada!\n");
        return;
    }

    char dados[MAX_DADOS];
    printf("Informacoes salvas:\n");
    printf("-----------------------------\n");
    while (fgets(dados, MAX_DADOS, arquivo)) {
        printf("- %s", dados);
    }
    printf("\n-----------------------------\n");

    fclose(arquivo);
}

void salvarDados(double valorRacao, int comprasRacao, int vendasLotes) {
    FILE *arquivo = fopen("dadosProp.txt", "a"); // Abre o arquivo em modo de anexo
    if (!arquivo) {
        printf("Erro ao abrir o arquivo para salvar os dados.\n");
        return;
    }

    fprintf(arquivo, "Valor da ração: %.2lf\n", valorRacao);
    fprintf(arquivo, "Número de compras de ração: %d\n", comprasRacao);
    fprintf(arquivo, "Número de vendas de lotes no mês: %d\n", vendasLotes);
    fprintf(arquivo, "-----------------------------\n");

    fclose(arquivo);
    printf("Dados salvos com sucesso!\n");
}

void entradaDados() {
    // Exemplo de uso
    double valorRacao;
    int comprasRacao, vendasLotes;

    printf("Digite o valor da ração: ");
    scanf("%lf", &valorRacao);
    printf("Digite o número de compras de ração: ");
    scanf("%d", &comprasRacao);
    printf("Digite o número de vendas de lotes no mês: ");
    scanf("%d", &vendasLotes);

    salvarDados(valorRacao, comprasRacao, vendasLotes);
    exibirDados();

    return 0;



}


#endif // DADOSCOMPRAS_H_INCLUDED
