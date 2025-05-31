#include "ListaEncadeadaDupla.h"
#include <iostream>
#include <random>
#include <assert.h>

using namespace std;

ListaEncadeadaDupla::~ListaEncadeadaDupla() {
    LimpaLista();
}

void ListaEncadeadaDupla::insere(int valor, int pos) {
    assert(pos <= tam);

    NoDuplo* novoNo = new NoDuplo();
    novoNo->valor = valor;

    if (pos == 0) {
        if(cabeca != NULL){
            novoNo->proximo = cabeca;
            novoNo->anterior = NULL;
            cabeca->anterior = novoNo;
        }
        cabeca = novoNo;
    } else {
        NoDuplo* atual = cabeca;
        for (int i = 0; i < pos - 1; i++){
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        if(atual->proximo != NULL) {
            atual->proximo->anterior = novoNo;
        }
        novoNo->anterior = atual;
        atual->proximo = novoNo;
    }
    tam++;
}

void ListaEncadeadaDupla::imprimeLista() {
    cout << " - Lista Encadeada Dupla: ";

    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    NoDuplo* atual = cabeca;
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->proximo;
    }
    cout << endl << endl;
}

void ListaEncadeadaDupla::imprimeInverso() {
    cout << " - Lista Encadeada Dupla em Ordem Inversa: ";
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }
    
    NoDuplo* atual = cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
    while (atual != NULL) {
        cout << atual->valor << " ";
        atual = atual->anterior;
    }
    cout << endl;
}

void ListaEncadeadaDupla::LimpaLista() {
    NoDuplo* atual = cabeca;
    while (atual != NULL) {
        NoDuplo* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    cabeca = NULL;
    tam = 0;
}

int ListaEncadeadaDupla::busca(int valor, int &acesso) {
    cout << " - Buscando o valor " << valor << " na lista: " << endl;
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return -1;
    }

    acesso = 0;
    unsigned posicao = 0;
    NoDuplo* atual = cabeca;
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

int ListaEncadeadaDupla::menorValor(int &retorna_Pos, int &acesso, int &precede) {
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
    NoDuplo* atual = cabeca;
    int menor = atual->valor;
    int posicao = 0;

    while(atual != NULL) {
        acesso++;

        if (atual->valor < menor) {
            menor = atual->valor;
            retorna_Pos = posicao;// posição +1
            precede = (atual->anterior != NULL) ? atual->anterior->valor : -1; // Atualiza precede com o valor do nó atual
        }
        atual = atual->proximo;  
        posicao++; 
        
        
    }
    return menor;
}

void ListaEncadeadaDupla::transposicao(int pos1, int pos2) {
    if(cabeca == NULL) {
        cout << "Lista vazia!" << endl << endl;
        return;
    }
    if (pos1 == pos2 ||pos1 < 0 || pos2 < 0 || pos1 >= tam || pos2 >= tam) {
        cout << "Posicoes invalidas para transposicao!" << endl;
        return;
    }
    cout << " - Transpondo as posições " << pos1 << " e " << pos2 << endl;

    NoDuplo* no1 = cabeca;
    NoDuplo* no2 = cabeca;
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

void ListaEncadeadaDupla::geraValoresAleatorios(int tamLista, int min, int max) {
    cout << " - Gerando valores aleatorios: " << endl;
    if(tamLista == 0) {
        cout << "Tamanho da lista não pode ser 0" << endl;
        return;
    }
    LimpaLista();
    
    srand(time(0));
    for (int i = 0; i < tamLista; i++) {
         int val = rand() % (max - min + 1) + min;
         insere(val, 0);
    }
}

