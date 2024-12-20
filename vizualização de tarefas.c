#ifndef LISTARTAREFAS_H_INCLUDED
#define LISTARTAREFAS_H_INCLUDED
void listarTarefas() {
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (!arquivo) {
        printf("Nenhuma tarefa encontrada!\n");
        return;
    }

    char tarefa[MAX_TAREFA];
    printf("Tarefas:\n");
    printf("-----------------------------\n");
    while (fgets(tarefa, MAX_TAREFA, arquivo)) {
        printf("- %s", tarefa);
    }
    printf("\n-----------------------------\n");

    fclose(arquivo);
}

#endif // LISTARTAREFAS_H_INCLUDED
