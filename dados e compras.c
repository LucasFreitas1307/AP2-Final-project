#ifndef CADASTRORACAO_H_INCLUDED
#define CADASTRORACAO_H_INCLUDED

// Estrutura para armazenar os dados de ração e vendas
typedef struct
{
    int numeroComprasRacao, numeroVendasLote;
    float precoRacao, precoPelaVenda;

} CadastroRacao;


void salvarDadosRacao(CadastroRacao dados1)
{

    FILE *arquivo = fopen("racao_vendas.txt", "a"); // Abre o arquivo no modo append
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para salvar dados");
        getchar();
        return;
    }


// Salva os dados da estrutura no arquivo
    fprintf(arquivo, "%d %.2f %d %.2f\n", dados1.numeroComprasRacao, dados1.precoRacao, dados1.numeroVendasLote, dados1.precoPelaVenda);

    fclose(arquivo);
    printf("Dados salvos com sucesso.\n");
}

void lerarquivo()
{

    FILE *arquivo = fopen("racao_vendas.txt", "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para salvar dados");
        getchar();
        return;
    }

    int ncra, nvla;
    float pra, pva;

    while (fscanf(arquivo, "%d %f %d %f\n", &ncra, &pra, &nvla, &pva) != EOF)
    {
        printf("Quantidade de ração comprada: %d\nPreço das rações: %.2f\nQuantidade de vendas do lote: %d\nPreço de venda do lote: %.2f", ncra, pra, nvla, pva);
    }

}



// Função para capturar os dados do usuário
void registrarDadosUsuario1()
{
    CadastroRacao dados;

    // Capturando o número de compras de ração
    printf("Digite o número de compras de ração realizadas: ");
    scanf("%d", &dados.numeroComprasRacao);

    // Capturando o preço da ração
    printf("Digite o preço da ração (por kg ou por unidade): ");
    scanf("%f", &dados.precoRacao);

    // Capturando o número de vendas de lote
    printf("Digite o número de vendas de lote realizadas: ");
    scanf("%d", &dados.numeroVendasLote);

    printf("Digite o valor arrecadado com a venda: ");
    scanf("%f", &dados.precoPelaVenda);

    // Salvar os dados no arquivo
    salvarDadosRacao(dados);
}

#endif // CADASTRORACAO_H_INCLUDED
