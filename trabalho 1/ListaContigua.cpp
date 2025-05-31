#include "ListaContigua.h"
#include <iostream>
#include <random>
#include <assert.h>

#define MAX_TAM 100
#define NDEBAG

using namespace std;

void ListaContigua::insere(int valor, int pos) {
    if(tam == MAX_TAM) {
        cout << " Lista cheia!" << endl;
        return;
    }
    assert(pos <= tam);    

    if (pos < 0 || pos > tam) {
        cout << "Posicao invalida!" << endl;
        return;
    }

    if (pos < tam) {
        for(int i = tam - 1; i >= pos; i--) {
            lista[i + 1] = lista[i];
            if (i == 0) break; // Evita overflow

        }
    }

    lista[pos] = valor;
    tam++;
}

void ListaContigua::imprimeAleatorio(vector<int> &lista) {
    cout << " - Lista em ordem aleatoria: ";
    for (unsigned i = 0; i < lista.size(); i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}  


void ListaContigua::imprimeLista() {
    cout << " -  Lista: ";

    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    for (int i = 0; i < tam; i++) {
        cout << lista[i] << " ";
    }
    cout << endl << endl;
}

void ListaContigua::imprimeInversa() {
    cout << " - Lista em Ordem Inversa: ";
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    for (int i = tam - 1; i >= 0; i--) {
        cout << lista[i] << " ";
    }
    cout << endl;
}

int ListaContigua::busca(int valor, int &acesso) {
    cout << " - Buscando o valor " << valor << " na lista: " << endl;
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return -1;
    }

    acesso = 0;

    for (int i = 0; i < tam; i++) {
        acesso++;
        if (lista[i] == valor) {
            return i;
        }
    }
    return -1;
}

int ListaContigua::menorValor(int &retorna_Pos, int &acesso) {
    if(tam == 0) {
        cout << "Lista vazia!" << endl;
        return -1;
    }

    acesso = 0;
    int menor = lista[0];
    retorna_Pos = 0;

    for (int i = 1; i < tam; i++) {
        acesso++;
        if (lista[i] < menor) {
            menor = lista[i];
            retorna_Pos = i;
        }
    }
    return menor;
}

void ListaContigua::transposicao(int pos1, int pos2){
    if (pos1 == pos2 ||pos1 < 0 || pos2 < 0 || pos1 >= tam || pos2 >= tam) {
        cout << "Posicoes invalidas para transposicao!" << endl;
        return;
    }

    cout << " - Transpondo as posições " << pos1 << " e " << pos2 << endl;

    int temp = lista[pos1];
    lista[pos1] = lista[pos2];
    lista[pos2] = temp;
}

void ListaContigua::geraValoresAleatorios(int tamLista, int min, int max) {
    if(tamLista > MAX_TAM || tamLista < 0) {
        cout << "Tamanho da lista excede o maximo permitido!" << endl;
        return;
    }
    lista.clear();
    lista.resize(tamLista);

    srand(time(0));
    for (int i = 0; i < tamLista; i++) {
         lista[i] = rand() % (max - min + 1) + min;
         lista.push_back(lista[i]);
    }
}
