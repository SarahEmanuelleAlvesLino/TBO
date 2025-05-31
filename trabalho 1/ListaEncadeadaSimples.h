#ifndef LISTA_ENCADEADA_SIMPLES_H
#define LISTA_ENCADEADA_SIMPLES_H

#include <iostream>
#include <random>
#include <assert.h>

using namespace std;
// Class de um nó da lista encadeada
class No {
public:
    int valor;
    No* proximo;
};
// Classe da lista encadeada
class ListaEncadeadaSimples {
public:
    No* cabeca; // Ponteiro para o primeiro nó da lista
    int tam; 
    ListaEncadeadaSimples() {
        cabeca = NULL; 
        tam = 0; 
    }
    
    void insere(int valor, int pos);
    void imprimeInverso();
    void imprimeInversoRecursivo(No* no);
    void imprimeLista();
    int busca(int valor, int &acesso);  
    int menorValor(int &retorna_Pos, int &acesso, int &precede);
    void transposicao(int pos1, int pos2);
    void geraValoresAleatorios(int tamLista, int min, int max);
    ~ListaEncadeadaSimples();
    void LimpaLista();
    
};

#endif