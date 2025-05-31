#ifndef LISTA_CONTIGUA_H
#define LISTA_CONTIGUA_H

#include <iostream>
#include <random>
#include <assert.h>

#define MAX_TAM 100
#define NDEBAG

using namespace std;

class ListaContigua {
public:
    vector<int> lista;
    int tam;
    ListaContigua(){
        tam = 0;
        lista.resize(MAX_TAM); // reserva um espaço de tamanho MAX_TAM pra lista de dados
    }

    void insere(int valor, int pos);
    void imprimeAleatorio(vector<int> &lista);
    void imprimeLista();
    void imprimeInversa();
    int busca(int valor, int &acesso);
    int menorValor(int &retorna_Pos, int &acesso);
    void transposicao(int pos1, int pos2);
    void geraValoresAleatorios(int tamLista, int min, int max);
};

#endif