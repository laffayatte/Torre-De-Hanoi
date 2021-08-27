
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "TorreDeHanoi.h"

Pino **criarPinos(int n);
int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino);
void imprimir(Pino **pinos, int numPinos, int numDiscos);
int pinoNulo(Pino *pino);
int compdisco(Disco *d);
void linha(int m, int tam_disco, char meio);
int quant_disco(Pino *p);
void excluirPinos(Pino **pinos, int n);
int vitoria(Pino **pinos, int numPinos, int numDiscos);


Pino **criarPinos(int n){
    Pino **P = malloc(n * sizeof(Pino));
    return P;
}

void excluirPinos(Pino **pinos, int n){

    for (int i = 0; i < n; i++){ 
        excluirPino(pinos[i]);
    }
    free(pinos); 
}

int pinoNulo(Pino *pino){

    if (pino->topo == NULL){ 
        return 1;
    }else{
        return 0;
    }
}

int quant_disco(Pino *p){
    if (p == NULL){
        return 0;
    }else{
        return (p->numDiscos - '0');
    }
}

int tamdisco(Disco *d){
    if (d == NULL){
        return 6;
    }else{
        return (d->tamDisco - '0');
    }
}


int vitoria(Pino **pinos, int numPinos, int numDiscos){

    for (int i = 1; i < numPinos; i++){
        if ((pinos[i]->numDiscos - '0') == numDiscos){
            return 1;
        }
    } 
    return 0;
}

int moverDisco(Pino **pinos, int pinoOrigem, int pinoDestino){

    Disco *topo_origem = pinos[pinoOrigem - 1]->topo; 
    Disco *topo_destino = pinos[pinoDestino - 1]->topo;

    if (pinoNulo(pinos[pinoOrigem - 1]) == 1){
        printf("Movimento invalido. \n");
        return 0;
    }else if (tamdisco(topo_origem) > tamdisco(topo_destino)){
        printf("Movimento invalido. \n");
        return 0;
    }else{
        push(pinos[pinoDestino - 1], pop(pinos[pinoOrigem - 1]));
        return 1;
    }
}

void linha(int m, int tamanho, char meio){
    char *A = (char *)malloc(sizeof(char) * (m + 1));

    for (int i = 0; i < m + 1; i++){
        if (i < tamanho){
            A[i] = '_';
        }else{
            A[i] = ' ';
        }
    }

    for (int i = m; i >= 0; i--){

        printf("%c", A[i]);
    }
    printf("%c", meio);

    for (int i = 0; i < m + 1; i++){
        printf("%c", A[i]);
    }
    printf("\n");
}

void imprimir(Pino **pinos, int numPinos, int numDiscos){ 

    for (int i = 0; i < numPinos; i++)
    {
        printf("\n");
        Disco *d = pinos[i]->topo;
        for (int l = 0; l < (numDiscos - (quant_disco(pinos[i]))); l++)
            linha(numDiscos, 0, '|');
        for (int j = 0; j < (quant_disco(pinos[i])); j++)
        {
            linha(numDiscos, (d->tamDisco) - '0', '|');
            d = d->next;
        }
        linha(numDiscos, numDiscos + 1, '|');
        printf("\n");
        linha(numDiscos, 0, (i + 1) + '0');
        printf("\n");
    }
}

int main(){

    Pino **pinos;
    int m, n, origem, destino, jogadas = 0;
    int fim = 1;

    while (fim == 1)
    {
        printf("Insira a quantidade de Pinos:  [3..5] ");
        scanf(" %d", &n);
        if (n >= 3 && n <= 5)
            fim = 0;
        else
            printf("Entrada invalida\n");
    }
    fim = 1;
    while (fim == 1)
    {
        printf("Insira a quantidade de Discos: [3..5] ");
        scanf(" %d", &m);
        if (m >= 3 && m <= 5)
            fim = 0;
        else
            printf("Entrada invalida\n");
    }

    pinos = criarPinos(n);
    for (int i = 0; i < n; i++){
        pinos[i] = criarPino();
    }
    for (int j = 0; j < m; j++){
        Disco *d = criarDisco(m - j);
        push(pinos[0], d);
    }

    imprimir(pinos, n, m);

    while (vitoria(pinos, n, m) == 0){
        printf("Insira os pinos de origem e de destino: \n");
        scanf("%d %d", &origem, &destino);
        if ((origem >= 1 && origem <= n) && (destino >= 1 && destino <= n))
        {

            jogadas = jogadas + moverDisco(pinos, origem, destino);
            imprimir(pinos, n, m);
        }
        else
        {
            printf("Entrada invalida\n");
            imprimir(pinos, n, m);
        }
    }
    printf("PARABENS VOCE CONSEGUIU\n");
    printf("TOTAL DE JOGADAS: ");
    printf("%d\n", jogadas);

    excluirPinos(pinos, n); 
}