#ifndef FUNCOESAP2_H_INCLUDED
#define FUNCOESAP2_H_INCLUDED
//Média de ganho
//Média de gasto com alimentação
//Média de lucro
//ICA(Índice de conversão alimentar)
//Teste de peso ideal para venda

double mediaGanho(float ganhoTotal, int numeroDeVendas){
return ganhoTotal/numeroDeVendas;
}

double mediaGastoAlimentacao(int quantidadeDeComprasDeRacao, float gastoTotalRacao){
return gastoTotalRacao/quantidadeDeComprasDeRacao;
}

double mediaLucro(float ganhoTotal, float gastoTotal){
return ganhoTotal-gastoTotal;
}

double ICA(float consumoDeRacao, float ganhoPeso){
return consumoDeRacao/ganhoPeso;
}

bool testePesoIdeal(float peso, float gastoPorKgBoi, float precoVendaKgBoi){
if(peso*precoVendaKgBoi>=1.3*gastoPorKgBoi){
return True;//Se não rodar, mudar a função para int e retornar 0.
}
else{
return False;//Mesma coisa, mas retorna 1.
}
}


#endif // FUNCOESAP2_H_INCLUDED
