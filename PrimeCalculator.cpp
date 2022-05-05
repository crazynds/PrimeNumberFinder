//============================================================================
// Name        : PrimeCalculator.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "AsmFunctions.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>



using namespace std;

/**
 * Descrição do funcionamento da busca por primos:
 *  - Inicialmente bucar os primeiros 10.000 primeiros numeros primos para ter como base inicial
 *  Thread principal:
 *      Achar possiveis primos e criar um arquivo contendo 10.000 possiveis numeros primos
 *  Thread secundaria:
 *      Pegar os arquivos contendo 10.000 possiveis primos e verificar cada um deles se é primo de fato
 *      Se não for descara o numero e vai para o próximo
 *      Se for salva num arquivo de numeros primos desordenados
 *  Thread terciaria:
 *      Quando alguma thread precisa de mais numeros primos para computar essa thread entra em ação
 *      Ela pausa as threads anteriores e ordena o arquivo de primos verificados desordenados
 *          e salva ao final do arquivo de numeros primos ordenados
 **/

#define PRIMEIROS_PRIMOS 10000
#define PRIME_TYPE unsigned long long

PRIME_TYPE primeirosPrimos[PRIMEIROS_PRIMOS];



void procuraPrimosIniciais(){
    int primos= 0;
    long numeroBase = 5;
    bool ePrimo;

    primeirosPrimos[primos++]=2;
    primeirosPrimos[primos++]=3;

    while(primos<PRIMEIROS_PRIMOS){
        ePrimo=true;
        for(int x=1;x<primos;x++){
            if(numeroBase%primeirosPrimos[x]==0){
                ePrimo = false;
                break;
            }
        }
        if(ePrimo){
            primeirosPrimos[primos++]=numeroBase;
        }
        numeroBase+=2;
    }
    ofstream output( "primes/primes-1", ios::binary );
    output.write((char*)primeirosPrimos,primos*sizeof(PRIME_TYPE));

    output.close();
}

PRIME_TYPE possiveisPrimos[10000000];
void procuraPossiveiPrimos(){
    const int MASK_FORCE = 8;
    PRIME_TYPE totToSearch =1, sizeMask = 0;

    for(int x=0;x<MASK_FORCE;x++){
        totToSearch*=primeirosPrimos[x];
    }
    sizeMask = totToSearch;
    for(int x=MASK_FORCE-1;x>=0;x--){
        sizeMask-= sizeMask/primeirosPrimos[x];
    }
    PRIME_TYPE *mask = (PRIME_TYPE *) malloc(sizeof(PRIME_TYPE)*sizeMask);
    PRIME_TYPE index= 0,primos=0;
    bool find;
    for(int x=0;x<totToSearch;x++){
        find =true;
        for(int y=0;y<MASK_FORCE;y++){
            if(x%primeirosPrimos[y]==0){
                find = false;
                break;
            }
        }
        if(find){
            mask[index++] = x; 
            //printf("%d | ",mask[index-1]);
        }
    }
    printf("\n");

    PRIME_TYPE start = totToSearch;
    while(primos<1024){
        for(int x=0;x<index;x++){
            PRIME_TYPE aux = start+mask[x];
            possiveisPrimos[primos++] = aux;
        }
        start+=totToSearch;
    }
    free(mask);

    printf("Tamanho mask: %d | Total slot: %d\n",sizeMask,totToSearch);
    printf("Encontrado %d na mascara\n",index);
    printf("Proporcao: %.2lf%%\n",(double)sizeMask/(double)totToSearch*100);
}

void confirmaPossiveisPrimos(){

}

void ordenaESalvaPrimosDesordenados(){

}




void iniciaDoZero(){
    procuraPrimosIniciais();
    procuraPossiveiPrimos();
}


void reiniciaBusca(){

}


int main() {
    iniciaDoZero();
    //for(int x=0;x<100;x++){
    //    printf("Primo %d = %u\n",x,primeirosPrimos[x]);
    //}
	return 0;
}
