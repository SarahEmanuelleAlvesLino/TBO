#include "aho_Corasick.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int AHOacessouuuuu = 0; // Variável global para contar a quantidade de acessos ao arquivo


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
            while (noFalha != nullptr && noFalha->filho.find(ch) == noFalha->filho.end() ) {
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

void imprimi(const string& padrao, const string& palavra, int linha) {
    //cout << "\tLinha:  " << linha << "\tPadrão encontrado: \"" << texto.substr(inicio, fim - inicio + 1) << "\"" << endl;
    cout << "\tLinha: " << linha << "\tPadrão: " << padrao << "\t encontrado na palavra: " << palavra << endl;
}

void ahoCorasickBusca(const string& texto, TrieNo* raiz, const vector<string>& padroes, int &linha) {
    TrieNo* noAtual = raiz;
    int novaLinhaBloco = 0; // Contador de novas linhas para formatação da saída
    
    cout << endl;
    for (size_t i = 0; i < texto.length(); i++) {
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
            for (size_t x = 0; x < i; ++x) {
                if(texto[x] == '\n') {
                    linhaAteAqui++;
                }
            }

             
            for (int idx : noAtual->saida) {
                // Acha a posição inicial e final do PADRÃO no texto do bloco
                size_t fim_padrao = i;
                size_t inicio_padrao = fim_padrao - padroes[idx].length() + 1;

                // Expande para a esquerda para achar o INÍCIO da palavra
                size_t inicio_palavra = inicio_padrao;
                while (inicio_palavra > 0 && texto[inicio_palavra - 1] != ' ' && texto[inicio_palavra - 1] != '\n') {
                    inicio_palavra--;
                }

                //Expande para a direita para achar o FIM da palavra
                size_t fim_palavra = fim_padrao;
                while (fim_palavra < texto.length() - 1 && texto[fim_palavra + 1] != ' ' && texto[fim_palavra + 1] != '\n') {
                    fim_palavra++;
                }

                // Extrai a palavra completa do texto
                string palavra_encontrada = texto.substr(inicio_palavra, fim_palavra - inicio_palavra + 1);

                //  Calcula a linha correta da ocorrência
                int linhaAteAqui = 0;
                for (size_t x = 0; x < i; ++x) {
                    if(texto[x] == '\n') {
                        linhaAteAqui++;
                    }
                }
                
                //Chama a nova função de impressão

                imprimi(padroes[idx], palavra_encontrada, linha + linhaAteAqui);
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
    if(texto.empty() || padroes.empty()) {
        cout << "Texto ou padrões vazios. Nenhuma busca realizada." << endl;
        return;
    }

    TrieNo* raiz = new TrieNo();
    //int i = 0;

    for(size_t i =0; i < padroes.size(); i++) {
        construirTrie(padroes[i], raiz, i);
    }

    FuncaoFalha(raiz);

    ifstream arquivo(texto);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << texto << endl;
        liberaTrie(raiz);
        return; 
    }
    AHOacessouuuuu++;

    size_t MAXtamanhoTexto = 0;

    //descobrir o padrão mais longo
    for(const auto& padrao : padroes) {
            MAXtamanhoTexto = max(MAXtamanhoTexto, padrao.length());
    }

    size_t tamSobreposicao = (MAXtamanhoTexto > 0) ? MAXtamanhoTexto - 1 : 0;

    const size_t bufferTam = 16384;
    vector<char> buffer(bufferTam);
    int linha = 1;
    string str_sobreposicao = "";

    while(arquivo.read(buffer.data(), bufferTam) || arquivo.gcount() > 0) {
        AHOacessouuuuu++; // Incrementa o contador de acessos ao arquivo
        streamsize bytesLidos = arquivo.gcount();

        string textoAtual_Buscar = str_sobreposicao + string(buffer.data(), bytesLidos);

        ahoCorasickBusca(textoAtual_Buscar, raiz, padroes, linha);

        // Atualiza a sobreposição para a próxima iteração
        if(textoAtual_Buscar.length() > tamSobreposicao) {
            str_sobreposicao = textoAtual_Buscar.substr(textoAtual_Buscar.length() - tamSobreposicao);
        } else {
            str_sobreposicao = textoAtual_Buscar; // Se o texto for menor que a sobreposição, mantém o texto atual
        }

    }

    arquivo.close();
    liberaTrie(raiz);
    AHOacessouuuuu = 0;
}