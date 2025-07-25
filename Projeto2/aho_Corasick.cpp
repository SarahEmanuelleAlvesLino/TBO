#include "aho_Corasick.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int AHOacessouuuuu = 0; // Variável global para contar a quantidade de acessos ao arquivo

struct TrieNo {
    unordered_map<char, TrieNo*> filho;
    vector<int> saida; // Índices dos padrões terminados neste nó
    TrieNo* failLink; // Link de falha para o nó pai
    TrieNo() : failLink(nullptr) {}
};

void construirTrie(const string& padroes, TrieNo*& raiz, int indice) {
    TrieNo* noAtual = raiz;
        for (char c : padroes) {
            char minusculo_c = tolower(c); 

            if(noAtual->filho.find(minusculo_c) == noAtual->filho.end()) {
                noAtual->filho[minusculo_c] = new TrieNo();
            }
            noAtual = noAtual->filho[minusculo_c];
        }
        noAtual->saida.push_back(indice); // Armazena o índice do padrão
        AHOacessouuuuu++; // Incrementa o contador de acessos
    
}

void FuncaoFalha(TrieNo* raiz) {
    queue<TrieNo*> fila;

    // Inicializa a fila com os filhos diretos da raiz
    for (auto& atual : raiz->filho) {
        atual.second->failLink = raiz; // O primeiro nível aponta para a raiz
        fila.push(atual.second);
        AHOacessouuuuu++; // Incrementa o contador de acessos
    }


    while (!fila.empty()) {
        TrieNo* noAtual = fila.front();
        fila.pop();

        for (auto& atual : noAtual->filho) {
            char ch = atual.first;
            TrieNo* filhoAtual = atual.second;

            fila.push(filhoAtual);

            TrieNo* noFalha = noAtual->failLink;
            while (noFalha->filho.find(ch) == noFalha->filho.end() &&  noFalha != nullptr ) {
                noFalha = noFalha->failLink; // Retrocede pelo nó através do link de falha
            }

            if(noFalha == nullptr) {
                filhoAtual->failLink = raiz; // Se não encontrar, aponta para a raiz
            } else {
                filhoAtual->failLink = noFalha->filho[ch]; // Caso contrário, aponta para o filho correspondente
            }
            filhoAtual->saida.insert(filhoAtual->saida.end(), filhoAtual->failLink->saida.begin(), filhoAtual->failLink->saida.end());

            fila.push(filhoAtual);
        }
        AHOacessouuuuu++; // Incrementa o contador de acessos
    }
}

void imprimi(const string& texto, int inicio, int fim, int linha) {
    cout << "[Linha " << linha << "]\tEncontrado o padrão: \"" << texto.substr(inicio, fim - inicio + 1) << "\"" << endl;
}

void ahoCorasickBusca(const string& texto, TrieNo* raiz, const vector<string>& padroes, int &linha) {
    TrieNo* noAtual = raiz;
    int novaLinhaBloco = 0; // Contador de novas linhas para formatação da saída
    for (int i = 0; i < texto.length(); i++) {
        char minusculo_ch = tolower(texto[i]);

        while (noAtual != nullptr && noAtual->filho.find(minusculo_ch) == noAtual->filho.end()) {
            noAtual = noAtual->failLink; // Retrocede pelo nó através do link de falha
        }

        if (noAtual == nullptr) {
            noAtual = raiz; // Se não encontrar, volta para a raiz
            continue;
        }

        noAtual = noAtual->filho[minusculo_ch];

        if(!noAtual->saida.empty()) {
            int linhaAteAqui = 0;
            for (int x = 0; x < i; ++x) {
                if(texto[x] == '\n') {
                    linhaAteAqui++;
                }
            }

            for (int idx : noAtual->saida) {
                imprimi(texto, i - padroes[idx].length() + 1, i, linhaAteAqui + 1);
                AHOacessouuuuu++; // Incrementa o contador de acessos ao arquivo
            }
        }

        if(texto[i] == '\n') {
            novaLinhaBloco++;

        }

        
    }
    linha += novaLinhaBloco; // Atualiza o número da linha para a próxima iteração
}

void liberaTrie(TrieNo* no) {
    if (no == nullptr) return;

    for (auto& par : no->filho) {
        liberaTrie(par.second);
    }
    delete no;
}

void executa_AhoCorasick(const string& texto, const vector<string>& padroes) {
}