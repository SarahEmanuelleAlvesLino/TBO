#ifndef LISTA_ENCADEADA_DUPLA_H
#define LISTA_ENCADEADA_DUPLA_H

#include <iostream>
#include <random>
#include <assert.h> 

using namespace std;

class NoDuplo {
public:
    int valor;
    NoDuplo* proximo;
    NoDuplo* anterior;
};

class ListaEncadeadaDupla {
public:
    NoDuplo* cabeca;
    int tam;

    ListaEncadeadaDupla() {
        cabeca = NULL;
        tam = 0;
    }

    void insere(int valor, int pos);
    void imprimeLista();
    void imprimeInverso();
    
    int busca(int valor, int &acesso);
    int menorValor(int &retorna_Pos, int &acesso, int &precede);
    void transposicao(int pos1, int pos2);
    void geraValoresAleatorios(int tamLista, int min, int max);
    ~ListaEncadeadaDupla();
    void LimpaLista();
    
};

#endif