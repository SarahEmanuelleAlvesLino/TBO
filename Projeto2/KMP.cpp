#include "KMP.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

//int acessouuuuu = 0; // Variável global para contar a quantidade de acessos ao arquivo

vector<int> criarTabelaLPS(int tamanhoPadrao, const char* padroes) {
    //int tamanhoPadrao = strlen(padroes);
    vector<int> tabelaLPS(tamanhoPadrao, 0);
    int comprimento = 0; // Comprimento do prefixo mais longo
    int i = 1;

    while (i < tamanhoPadrao) {
        if (padroes[i] == padroes[comprimento]) {
            comprimento++;
            tabelaLPS[i] = comprimento;
            i++;
        } else {
            if (comprimento != 0) {
                comprimento = tabelaLPS[comprimento - 1];
            } else {
                tabelaLPS[i] = 0;
                i++;
            }
        }
    }
    return tabelaLPS;
}

//FUNÇÃO KMP
void kmp(const char* textoAchado, const char* padroes, int linha) {
    int tamanhoTexto = strlen(textoAchado);
    int tamanhoPadrao = strlen(padroes);

    vector<int> tabelaLPS = criarTabelaLPS(tamanhoPadrao, padroes);
    int i = 0; // Índice para o texto
    int j = 0; // Índice para o padrão
    int posicao = -1; // Posição do padrão encontrado

    for(i = 0; i < tamanhoTexto;) {
        if (padroes[j] == textoAchado[i]) {
            if(posicao == -1) {
                posicao = i; // Armazena a posição do primeiro caractere do padrão encontrado
            }
            i++;
            j++;
        }

        if (j == tamanhoPadrao) {
            int posicaoFinal = i - 1; // Posição final do padrão encontrado
            // Ajusta a posição para o início da palavra
            while(posicao >= 0 && textoAchado[posicao] != ' ' && textoAchado[posicao] != '\n') {
                posicao--; // Ajusta a posição para o início da palavra
            }

            //Ajusta a posição para o final da palavra
            while (posicaoFinal < tamanhoTexto && textoAchado[posicaoFinal] != ' ' && textoAchado[posicaoFinal] != '\n') {
                posicaoFinal++; // Ajusta a posição para o final da palavra
            }
            
            imprimi(textoAchado, posicao + 1, posicaoFinal - 1, linha); // Imprime a palavra encontrada

            j = tabelaLPS[j - 1];
            acessouuuuu++; // Incrementa o contador de acessos ao arquivo
            posicao = -1; // Reseta a posição para o próximo padrão
        } else if (i < tamanhoTexto && padroes[j] != textoAchado[i]) {
            if (j != 0) {
                j = tabelaLPS[j - 1];
            } else {
                i++;
            }
            posicao = -1; // Reseta a posição se o padrão não for encontrado
        }
    }
    
}

void imprimi(const char* texto, int inicio, int fim, int linha) {
    cout << "Linha " << linha << ": ";
    for (int i = inicio; i <= fim; i++) {
        cout << texto[i];
    }
    cout << endl;
}

