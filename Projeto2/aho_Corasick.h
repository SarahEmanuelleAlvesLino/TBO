#ifndef ARO_CORASICK_H
#define ARO_CORASICK_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct TrieNo {
    unordered_map<char, TrieNo*> filho;
    vector<int> saida; // Índices dos padrões terminados neste nó
    TrieNo* failLink; // Link de falha para o nó pai
    TrieNo() : failLink(nullptr) {}
};

void executa_AhoCorasick(const string& texto, const vector<string>& padroes);
void construirTrie(const string& padroes, TrieNo*& raiz, int indice);
void FuncaoFalha(TrieNo* raiz);
void liberaTrie(TrieNo* no);




#endif