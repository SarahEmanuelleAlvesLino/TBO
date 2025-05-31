#include "ListaEncadeadaSimples.h"
#include <iostream>
#include <random>
#include <assert.h>
//#include <ctime>
//#include <cstdlib>

using namespace std;

void ListaEncadeadaSimples::insere(int valor, int pos) {
    assert(pos <= tam);

    No* novoNo = new No();
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (pos == 0) {
        novoNo->proximo = cabeca;
        cabeca = novoNo;
    } else {
        No* atual = cabeca;
        for (int i = 0; i < pos - 1; i++){
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
    tam++;
}

void ListaEncadeadaSimples::imprimeInverso() {
    cout << " - Lista em ordem inversa: ";
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }
    imprimeInversoRecursivo(cabeca);
    cout << endl;
}

void ListaEncadeadaSimples::imprimeInversoRecursivo(No* no) {
    if (no == NULL) {
        return;
    }
    imprimeInversoRecursivo(no->proximo);
    cout << no->valor << " ";
}

void ListaEncadeadaSimples::imprimeLista() {
    cout << " - Lista Encadeada Simples: ";

    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    No* atual = cabeca;
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl << endl;
}

int ListaEncadeadaSimples::busca(int valor, int &acesso) {
    cout << " - Buscando o valor " << valor << " na lista: " << endl;
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return -1;
    }

    acesso = 0;

    No* atual = cabeca;
    unsigned posicao = 0;
    while (atual != NULL) {
        acesso++;
        if (atual->valor == valor) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}

int ListaEncadeadaSimples::menorValor(int &retorna_Pos, int &acesso, int &precede) {
    cout << " - Buscando o menor valor da lista: " << endl;
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return -1;
    }
    if (cabeca == NULL) {
        cout << "Lista vazia!" << endl;
        return -1;
    }

    acesso = 0;
    No* atual = cabeca;
    int menor = atual->valor;
    int posicao = 0;
    retorna_Pos = 0;
    precede = -1; // Inicializa precede como -1

    while(atual->proximo != NULL) {
        acesso++;
        if (atual->proximo->valor < menor) {
            menor = atual->proximo->valor;
            retorna_Pos = posicao + 1;
            precede = atual->valor; // Atualiza precede com o valor do nó atual
        }   
        atual = atual->proximo;
        posicao++;
    }

    if(atual->valor == menor) {
        retorna_Pos = 0;
        precede = -1; // Atualiza precede como -1 se o menor valor for o primeiro nó
    }
    return menor;
}

void ListaEncadeadaSimples::transposicao(int pos1, int pos2) {
    if(cabeca == NULL) {
        cout << "Lista vazia!" << endl << endl;
        return;
    }
    if (pos1 == pos2 ||pos1 < 0 || pos2 < 0 || pos1 >= tam || pos2 >= tam) {
        cout << "Posicoes invalidas para transposicao!" << endl;
        return;
    }
    cout << " - Transpondo as posições " << pos1 << " e " << pos2 << endl;

    No* no1 = cabeca;
    No* no2 = cabeca;
    int valor1, valor2 ;

    for (int i = 0; i < pos1; i++) {
        no1 = no1->proximo;   
    }
    valor1 = no1->valor;

    for (int i = 0; i < pos2; i++) {
        no2 = no2->proximo;
    }
    valor2 = no2->valor;
    no1->valor = valor2;
    no2->valor = valor1;
    
}

void ListaEncadeadaSimples::geraValoresAleatorios(int tamLista, int min, int max) {
    cout << " - Gerando valores aleatorios: " << endl;
    LimpaLista();

    srand(time(0));
    for (int i = 0; i < tamLista; i++) {
         int val = rand() % (max - min + 1) + min;
         insere(val, 0);
    }
}

void ListaEncadeadaSimples::LimpaLista() {
    No* atual = cabeca;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    cabeca = NULL;
    tam = 0;
}

ListaEncadeadaSimples::~ListaEncadeadaSimples() {
    LimpaLista();
}