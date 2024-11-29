#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    int op, cargo, cargoarq, op2;
    char senha[50], nome[50], senhaconf[50], nomearq[50], senhaarq[50];
    FILE *arqlogin;

    do
    {
        limparTela();
        printf("----REGISTRO----");
        printf("\n1- Cadastro;");
        printf("\n2- Login;");
        printf("\n0- Sair.");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d", &op);
        getchar();

        switch (op)
        {
        case 0:
            printf("Saindo...\n");
            return 0;

        case 1:
            limparTela();
            printf("----CADASTRO----\n");

            do
            {
                limparTela();
                printf("Escolha o cargo:\n");
                printf("1- Colaborador;\n");
                printf("2- Admin.\n");
                printf("\nDigite sua escolha: ");
                scanf("%d", &cargo);
                getchar();

                if (cargo != 1 && cargo != 2)
                {
                    limparTela();
                    printf("Opcao invalida.\n\n");
                    printf("Pressione Enter para tentar novamente...");
                    getchar();
                }
            }
            while (cargo != 1 && cargo != 2);

            do
            {
                limparTela();
                printf("----CADASTRO----\n");

                printf("Digite seu nome de usuario: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite sua senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0';

                printf("Confirme sua senha: ");
                fgets(senhaconf, sizeof(senhaconf), stdin);
                senhaconf[strcspn(senhaconf, "\n")] = '\0';

                if (strcmp(senha, senhaconf) != 0)
                {
                    limparTela();
                    printf("As senhas nao coincidem.\n\n");
                    printf("Pressione Enter para tentar novamente...");
                    getchar();
                }
            }
            while (strcmp(senha, senhaconf) != 0);

            arqlogin = fopen("dados.txt", "a");
            if (arqlogin == NULL)
            {
                printf("Erro ao abrir o arquivo.\n");
                return 1;
            }

            fprintf(arqlogin, "%s,%s,%d\n", nome, senha, cargo);
            fclose(arqlogin);

            printf("Cadastro realizado com sucesso!\n");
            break;

        case 2:
            arqlogin = fopen("dados.txt", "r");
            if (arqlogin == NULL)
            {
                limparTela();
                printf("Erro ao abrir o arquivo. Talvez voce precise se cadastrar primeiro.\n\n");
                printf("Pressione ENTER para tentar novamente...");
                getchar();
                break;
            }

            int login_success = 0;

            do
            {
                limparTela();
                printf("----LOGIN----\n");

                printf("Digite seu nome de usuario: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite sua senha: ");
                fgets(senha, sizeof(senha), stdin);
                senha[strcspn(senha, "\n")] = '\0';

                while (fscanf(arqlogin, "%49[^,],%49[^,],%d\n", nomearq, senhaarq, &cargoarq) != EOF)
                {
                    if (strcmp(nome, nomearq) == 0 && strcmp(senha, senhaarq) == 0)
                    {
                        login_success = 1;
                        break;
                    }
                }

                fclose(arqlogin);

                if (login_success)
                {
                    if (cargoarq == 1)
                    {
                        do
                        {
                            limparTela();
                            printf("Logado como: %s (Colaborador)\n\n", nomearq);
                            printf("---MENU---\n");
                            printf("1- Cadastro de lotes\n");
                            printf("2- Cadastro de tarefas\n");
                            printf("3- Vizualização de tarefas \n ");
                            printf("4- Cadastro de informacoes do proprietario");
                            printf("5- Vizualizar ICA \n");
                            printf("6- Vizualizar média de lucro \n");
                            printf("7- ")
                            printf("0- Deslogar/Sair\n\n");
                            printf("Selecione uma opcao: ");
                            scanf("%d", &op2);
                            getchar();

                            switch (op2)
                            {
                            case 1:
                                printf("Opcao 1 selecionada.\n");
                                getchar();
                                break;
                            case 2:
                                printf("Opcao 2 selecionada.\n");
                                getchar();
                                break;
                            case 0:
                                printf("Deslogando...\n");
                                break;
                            default:
                                limparTela();
                                printf("Opcao invalida.\n\n");
                                printf("Pressione ENTER para tentar novamente.");
                                getchar();
                            }
                        }
                        while (op2 != 0);
                    }
                    else
                    {
                        do
                        {
                            limparTela();
                            printf("Logado como: %s (Administrador)\n\n", nomearq);
                            printf("---MENU---\n");
                            printf("1- Criacao de tarefas \n");
                            printf("2- Listagem de tarefas \n");
                            printf("3- Cadastro de lotes");
                            printf("4- Listagem de lotes");
                            printf("5- Ver ICA(Indice de conversao alimentar)");
                            printf("6- Ver previsao de lucros");
                            printf("7- Situacao dos lotes(pronto para abate ou nao)");
                            printf("8- ")

                            printf("0- Deslogar/Sair\n\n");
                            printf("Selecione uma opcao: ");
                            scanf("%d", &op2);
                            getchar();

                            switch (op2)
                            {
                            case 1:
                                printf("Opcao 1 selecionada.\n");
                                criarTarefa();
                                getchar();
                                break;
                            case 2:
                                printf("Opcao 2 selecionada.\n");
                                listarTarefas();
                                getchar();
                                break;
                            case 3:
                                printf("Opcao 3 selecionada.");
                                cadastrarLote();
                                salvarDados();
                                getchar();
                                break;
                            case 4:
                                printf("Opcao 4 selecionada.");
                                listarLotes();
                                getchar();
                                break;
                            case 5:
                                printf("Opcao 5 selecionada");
                                printf("%lf", mediaGanho());
                                getchar();
                                break;
                            case 6:
                                printf("Opcao 6 selecionada.");




                            case 0:
                                printf("Deslogando...\n");
                                break;
                            default:
                                limparTela();
                                printf("Opcao invalida! Tente novamente.\n\n");
                                printf("Pressione ENTER para tentar novamente.");
                                getchar();
                            }
                        }
                        while (op2 != 0);
                    }
                }
                else
                {
                    limparTela();
                    printf("Usuario ou senha incorretos.\n\n");
                    printf("Pressione Enter para tentar novamente...");
                    getchar();
                }
            }
            while (!login_success) ;

            break;
        default:
            limparTela();
            printf("Opcao invalida.\n");
            printf("\nPressione Enter para tentar novamente...");
            getchar();
            break;
        }
    }
    while (op != 0);

    return 0;
}
