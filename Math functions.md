# Math functions
- Part of the code focused on mathematical functions, developed by Luis Felipe Scheneider.

 ```C 
#ifndef FUNCOESAP2_H_INCLUDED
#define FUNCOESAP2_H_INCLUDED
/**

Header destinada as funções matemáticas utilizadas no código,
separação realizada pra facilitar a implementação e coordenação do funcionamento do código.
 Dentro dessa header existem funções para:
 - Média de gasto com alimentação
 - Média de ganho(lucro) por lote
 - Média de lucro total
 - Índice de conversão alimentar
**/

double mediaGanho(float ganhoTotal, int numeroDeVendas) {
    return ganhoTotal / numeroDeVendas;
}
//printf("%.2lf", mediaGanho(asd, ki));


double mediaGastoAlimentacao(int numeroAnimais, float precoRacao, int numeroComprasRacao) {

    return precoRacao * numeroComprasRacao / numeroAnimais;
}

double mediaLucro(float ganhoTotal, float gastoTotal) {
    return ganhoTotal - gastoTotal;
}

double ICA(float consumoDeRacao, float ganhoPeso) {
    return consumoDeRacao / ganhoPeso;

    // precoRacao * numerocompraracao == gastototalracao
}


/**
 * Testa se o peso do animal é ideal para venda.
 * @param peso - Peso atual do animal.
 * @param gastoPorKgBoi - Custo para criar o boi por kg.
 * @param precoVendaKgBoi - Preço de venda por kg.
 * @return 0 se o peso é ideal, 1 caso contrário.
 */
int testePesoIdeal(float peso, float gastoPorKgBoi, float precoVendaKgBoi) {
    if (peso * precoVendaKgBoi >= 1.3 * gastoPorKgBoi*peso) {
        return 0; // Peso ideal para venda
    } else {
        return 1; // Não está no peso ideal
    }
}



#endif // FUNCOESAP2_H_INCLUDED


```
