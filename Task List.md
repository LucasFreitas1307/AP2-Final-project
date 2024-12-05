# Task List
- Part of the code focused on task list, developed by Lucas Freitas.
```C 
#ifndef LISTARTAREFAS_H_INCLUDED
#define LISTARTAREFAS_H_INCLUDED
#define MAX_TAREFA 256

void listarTarefas()
{
    FILE *arquivo = fopen("tarefas.txt", "r");
    if (arquivo == NULL)
    {
        printf("Nenhuma tarefa encontrada!\n");
    }

    char tarefa[MAX_TAREFA];

    printf("Tarefas:\n");
    printf("-----------------------------\n\n");

    while (fgets(tarefa, MAX_TAREFA, arquivo))
    {
        printf("- %s", tarefa);
    }
    printf("\n-----------------------------\n");

    fclose(arquivo);
}


#endif // LISTARTAREFAS_H_INCLUDED
```
