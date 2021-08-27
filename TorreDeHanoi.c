#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "TorreDeHanoi.h"

Pino* criarPino(){
    Pino* p = (Pino*) malloc(sizeof(Pino)); 
    p -> numDiscos = 0+'0';
    p -> topo = NULL;
    return p; 
}

Disco* criarDisco(int n){
    Disco* d = (Disco*) malloc(sizeof(Disco));
    d->tamDisco = n+'0';
    d->next = NULL;
    return d;
}

Disco* pop(Pino* pino){
    Disco* d;
    if(pino -> topo == NULL){
        return NULL;
    }
    d = pino -> topo;
    pino -> topo = d -> next;
    pino -> numDiscos = ((pino->numDiscos-'0')-1)+'0';
    d -> next = NULL;
    return d;
}

void push(Pino* pino, Disco* disco){
    
    if(pino -> topo != NULL){
        disco -> next = pino -> topo;
        pino -> topo = disco;
        pino -> numDiscos = ((pino -> numDiscos -'0')+1)+'0';
    }
    if(pino -> topo == NULL){
        pino -> topo = disco;
        pino -> numDiscos = ((pino -> numDiscos -'0')+1)+'0';
    }

}

void excluirPino(Pino* pino){
    Disco* disco = pino -> topo;
    while(disco != NULL){
        Disco* A1;
        A1 = disco -> next;
        free(disco);
        disco = A1; 
    }
    free(pino);
}