#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>      
#include <fstream>       
#include <vector>        
#include <queue>
#include <unordered_map>          
#include <bitset>        

using namespace std;

struct HuffmanNode {
    char caractere;     
    int frequencia;     
    HuffmanNode *esquerda, *direita; 

    // Construtor do nó, inicializa com os valores passados e define os filhos como nulos
    HuffmanNode(char c, int f) : caractere(c), frequencia(f), esquerda(nullptr), direita(nullptr) {}
};

// Compara a fila de prioridade usada na construção da árvore de Huffman
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequencia > b->frequencia; // A fila de prioridade organiza os nós em ordem crescente de frequência
    }
};

    void compactarArquivo(const string& input, const string& output);    
    void descompactarArquivo(const string& input, const string& output); 

    void construirTabela(HuffmanNode* raiz, string codigo, unordered_map<char, string>& tabela);
    void armazenarArvore(ofstream& arquivo, HuffmanNode* raiz); 
    HuffmanNode* reconstruirArvore(ifstream& arquivo); 
    void liberarArvore(HuffmanNode* raiz); 
    void calcularCompressao(const string& arquivoOriginal, const string& arquivoComprimido); 

#endif 
