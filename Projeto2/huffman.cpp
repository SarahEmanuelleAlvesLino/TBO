#include "huffman.h" 
#include <iostream>
#include <fstream>


using namespace std;


void construirTabela(HuffmanNode* raiz, string codigo, unordered_map<char, string>& tabela) {
    
    if (!raiz) return;

    // Se for um nó folha, armazena o código correspondente ao caractere
    if (!raiz->esquerda && !raiz->direita) {
        tabela[raiz->caractere] = codigo;
    }

    // Recursivamente constrói a tabela para os nós filhos
    construirTabela(raiz->esquerda, codigo + "0", tabela);
    construirTabela(raiz->direita, codigo + "1", tabela);
}


void armazenarArvore(ofstream& arquivo, HuffmanNode* raiz) {
    if (!raiz) return;

    // Se for um nó folha, escreve '1' seguido do caractere
    if (!raiz->esquerda && !raiz->direita) {
        arquivo.put('1');
        arquivo.put(raiz->caractere);
    } else {
        arquivo.put('0'); // Nó interno, marcação como "0"
        armazenarArvore(arquivo, raiz->esquerda);
        armazenarArvore(arquivo, raiz->direita);
    }
}


HuffmanNode* reconstruirArvore(ifstream& arquivo) {
    char flag;
    arquivo.get(flag); // Lê a flag que indica se é um nó folha ou nó interno

    // Se for um nó folha, cria um nó com o caractere lido
    if (flag == '1') {
        char caractere;
        arquivo.get(caractere);
        return new HuffmanNode(caractere, 0);
    }

    // Se for um nó interno, recria os nós filhos recursivamente 
    HuffmanNode* esquerda = reconstruirArvore(arquivo);
    HuffmanNode* direita = reconstruirArvore(arquivo);
    HuffmanNode* novoNo = new HuffmanNode('\0', 0);
    novoNo->esquerda = esquerda;
    novoNo->direita = direita;
    return novoNo;
}


void liberarArvore(HuffmanNode* raiz) {
    if (!raiz) return;

    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    delete raiz;
}


void calcularCompressao(const string& arquivoOriginal, const string& arquivoComprimido) {
    ifstream original(arquivoOriginal, ios::binary | ios::ate);
    ifstream comprimido(arquivoComprimido, ios::binary | ios::ate);

    if (!original || !comprimido) {
        cerr << "Erro ao abrir os arquivos para cálculo da compressão!" << endl;
        return;
    }

    streamsize tamanhoOriginal = original.tellg();
    streamsize tamanhoComprimido = comprimido.tellg();

    original.close();
    comprimido.close();

    if (tamanhoOriginal == 0) {
        cerr << "Arquivo original vazio, não é possível calcular a compressão!" << endl;
        return;
    }

    double taxaCompressao = (1.0 - (double)tamanhoComprimido / tamanhoOriginal) * 100;

    cout << "Tamanho do arquivo original: " << tamanhoOriginal << " bytes" << endl;
    cout << "Tamanho do arquivo comprimido: " << tamanhoComprimido << " bytes" << endl;
    cout << "Taxa de compressão: " << taxaCompressao << " %" << endl;
}


void compactarArquivo(const string& input, const string& output) {
    ifstream arquivoEntrada(input, ios::binary);
    ofstream arquivoSaida(output, ios::binary);
    
    if (!arquivoEntrada || !arquivoSaida) {
        cerr << "Erro ao abrir os arquivos!" << endl;
        return;
        }
    
        // Vetor de frequências baseado no código ASCII 
        int frequencias[256] = {0};
    
        // Conta a frequência dos caracteres
        char c;
        while (arquivoEntrada.get(c)) {
            frequencias[(unsigned char)c]++;
        }
        
        arquivoEntrada.clear();  // Limpa flags de erro 
        arquivoEntrada.seekg(0); // Retorna ao início do arquivo para a leitura novamente
    
        // Cria fila de prioridade e constrói árvore de Huffman
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> fila;
        for (int i = 0; i < 256; i++) {
            if (frequencias[i] > 0) {
                fila.push(new HuffmanNode(static_cast<char>(i), frequencias[i]));
            }
        }
    
        while (fila.size() > 1) {
            HuffmanNode* esquerda = fila.top(); fila.pop();
            HuffmanNode* direita = fila.top(); fila.pop();
            HuffmanNode* novoNo = new HuffmanNode('\0', esquerda->frequencia + direita->frequencia);
            novoNo->esquerda = esquerda;
            novoNo->direita = direita;
            fila.push(novoNo);
        }
        HuffmanNode* raiz = fila.top();
    
        unordered_map<char, string> tabelaHuffman;
        construirTabela(raiz, "", tabelaHuffman);

    
        // Escreve no arquivo a quantidade de bits não preenchidos
        string codigoBinario;
        while (arquivoEntrada.get(c)) {
            codigoBinario += tabelaHuffman[(unsigned char)c];
        }
    
        unsigned char bitsNaoPreenchidos = (8 - (codigoBinario.size() % 8)) % 8;
        arquivoSaida.put(bitsNaoPreenchidos);
    
        armazenarArvore(arquivoSaida, raiz);
    
        // Converte código binário para bytes e escreve no arquivo
        for (size_t i = 0; i < codigoBinario.size(); i += 8) {
            bitset<8> byte(codigoBinario.substr(i, 8));
            arquivoSaida.put(static_cast<unsigned char>(byte.to_ulong()));
        }
    
        liberarArvore(raiz);
    }
    

void descompactarArquivo(const string& input, const string& output) {
    ifstream arquivoEntrada(input, ios::binary);
    ofstream arquivoSaida(output, ios::binary);

    if (!arquivoEntrada || !arquivoSaida) {
        cerr << "Erro ao abrir os arquivos!" << endl;
        return;
    }

    // Lê o número de bits não preenchidos no último byte do arquivo compactado
    char bitsNaoPreenchidos;
    arquivoEntrada.get(bitsNaoPreenchidos);

    HuffmanNode* raiz = reconstruirArvore(arquivoEntrada);

    // Lê os bytes compactados e converte para string binária
    HuffmanNode* atual = raiz;
    char c;
    string codigoBinario;
    while (arquivoEntrada.get(c)) {
        bitset<8> bits(c);
        codigoBinario += bits.to_string();
    }

    // Remove os bits extras adicionados no final
    codigoBinario = codigoBinario.substr(0, codigoBinario.size() - bitsNaoPreenchidos);

    // Decodifica a sequência de bits e escreve os caracteres descompactados no arquivo de saída
    for (char bit : codigoBinario) {
        atual = (bit == '0') ? atual->esquerda : atual->direita;
        if (!atual->esquerda && !atual->direita) {
            arquivoSaida.put(atual->caractere);
            atual = raiz;
        }
    }

    liberarArvore(raiz);
}
