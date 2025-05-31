#include <iostream>
#include <random>
#include <assert.h>
#include "ListaContigua.h"
#include "ListaEncadeadaSimples.h"
#include "ListaEncadeadaDupla.h"

#define MAX_TAM 100
#define MIN_VAL 1
#define MAX_VAL 1000
#define NDEBUG 

using namespace std;

int main(){
    ListaContigua listaC;
    ListaEncadeadaSimples listaES;
    ListaEncadeadaDupla listaED;

    cout << "________________________ TRABALHO DE TBO ________________________" << endl;
    cout << "Nomes: Sarah Emanuelle & Tainara Ribeiro" << endl << endl;

    cout << "__________________________________________________________________" << endl;
    cout << " - MENU:" << endl << endl << " \t1 - Lista Contigua" << endl << "\t2 - Lista Encadeada Simples" << endl << "\t3 - Lista Encadeada Dupla" << endl << endl << "Selecione uma opção: " << endl;
    
    int opcao;
    cin >> opcao;
    cout << endl;

    if (opcao < 1|| opcao > 3) {
        cout << "Opção inválida!" << endl;
        return 0;
    }

    int menor, acesso, pos, encontrado, precede;

    switch (opcao){
        case 1:
            cout << "______________________ LISTA CONTIGUA ____________________________" << endl << "__________________________________________________________________" << endl;
            //OPERAÇÃO 1
            listaC.insere(8,0);
            listaC.insere(1,1);
            listaC.insere(3,2); 
            listaC.insere(4,3);
            listaC.insere(3,4);
            listaC.insere(6,5);
            listaC.insere(10,6);
            listaC.insere(8,7);
            listaC.insere(9,8);
            listaC.insere(1,9);
            //OPERAÇÃO 7
            listaC.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 3            
            cout << "_______________ INSERE EM UMA POSIÇÃO ESPECIFICA: ________________" << endl << "__________________________________________________________________" << endl;
            cout << " - Insere o valor 11 na posição 10: " << endl;
            listaC.insere(11,10);
            listaC.imprimeLista();

            cout << " - Insere o valor 2 na posição 4: " << endl;
            listaC.insere(2,4);
            listaC.imprimeLista();

            cout << " - Insere o valor 7 na posição 0: " << endl;
            listaC.insere(7,0);
            listaC.imprimeLista();
            cout << "__________________________________________________________________" << endl;
            
            //OPERAÇÃO 5
            cout << "_____________________________ BUSCA: _____________________________" << endl << "__________________________________________________________________" << endl;
            encontrado = listaC.busca(10, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;

            encontrado = listaC.busca(8, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;

            encontrado = listaC.busca(12, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 4
            cout << "________________________ TRANSPOSIÇÃO: ___________________________" << endl << "__________________________________________________________________" << endl;
            listaC.transposicao(3, 4);
            listaC.imprimeLista();
            listaC.transposicao(0, 6);
            listaC.imprimeLista();
            listaC.transposicao(6, 12);
            listaC.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 6
            cout << "_____________________ BUSCA PELO MENOR VALOR: ____________________" << endl << "__________________________________________________________________" << endl;
            menor = listaC.menorValor(pos, acesso);
            cout << "\t - Menor valor: " << menor << endl;
            cout << "\t - Posição do menor valor: " << pos << endl;
            cout << "\t - Acesso: " << acesso << endl;
            cout << "__________________________________________________________________" << endl;
            
            //OPERAÇÃO 8
            cout << "________________________ LISTA INVERSA: __________________________" << endl << "__________________________________________________________________" << endl;
            listaC.imprimeInversa();
            cout << endl;
            cout << "__________________________________________________________________" << endl;   

            //OPERAÇÃO 2
            cout << "______________________ GERA LISTA ALEATORIA: _____________________" << endl << "__________________________________________________________________" << endl;
            listaC.geraValoresAleatorios(10, MIN_VAL, MAX_VAL);
            listaC.imprimeLista();
            cout << " - Buscando menor valor:" << endl;
            menor = listaC.menorValor(pos, acesso);
            cout << "\t - Menor valor: " << menor << endl;
            cout << "\t - Posição do menor valor: " << pos << endl;
            cout << "\t - Acesso: " << acesso << endl;
            listaC.imprimeInversa();
            cout << endl;
            cout << "__________________________________________________________________" << endl;

            break;

            case 2:
            cout << "_____________________ LISTA ENCADEADA SIMPLES ____________________" << endl << "__________________________________________________________________" << endl;
            listaES.insere(8,0);
            listaES.insere(1,1);
            listaES.insere(3,2); 
            listaES.insere(4,3);
            listaES.insere(3,4);
            listaES.insere(6,5);
            listaES.insere(10,6);
            listaES.insere(8,7);
            listaES.insere(9,8);
            listaES.insere(1,9);
            //OPERAÇÃO 7
            listaES.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 3            
            cout << "_______________ INSERE EM UMA POSIÇÃO ESPECIFICA: ________________" << endl << "__________________________________________________________________" << endl;
            cout << " - Insere o valor 11 na posição 10: " << endl;
            listaES.insere(11,10);
            listaES.imprimeLista();

            cout << " - Insere o valor 2 na posição 4: " << endl;
            listaES.insere(2,4);
            listaES.imprimeLista();

            cout << " - Insere o valor 7 na posição 0: " << endl;
            listaES.insere(7,0);
            listaES.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 5
            cout << "_____________________________ BUSCA: _____________________________" << endl << "__________________________________________________________________" << endl;
            encontrado = listaES.busca(10, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;

            encontrado = listaES.busca(8, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;

            encontrado = listaES.busca(12, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 4
            cout << "________________________ TRANSPOSIÇÃO: ___________________________" << endl << "__________________________________________________________________" << endl;
            listaES.transposicao(3, 4);
            listaES.imprimeLista();
            listaES.transposicao(0, 6);
            listaES.imprimeLista();
            listaES.transposicao(6, 12);
            listaES.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 6
            cout << "_____________________ BUSCA PELO MENOR VALOR: ____________________" << endl << "__________________________________________________________________" << endl;
            menor = listaES.menorValor(pos, acesso, precede);
            cout << "\t - Menor valor: " << menor << endl;
            cout << "\t - Posição do menor valor: " << pos << endl;
            cout << "\t - Acesso: " << acesso << endl;
            cout << "\t - Valor do Predecessor: " << precede << endl;
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 8
            cout << "________________________ LISTA INVERSA: __________________________" << endl << "__________________________________________________________________" << endl;
            listaES.imprimeInverso();
            cout << endl;
            cout << "__________________________________________________________________" << endl;   

            //OPERAÇÃO 2
            cout << "______________________ GERA LISTA ALEATORIA: _____________________" << endl << "__________________________________________________________________" << endl;
            listaES.geraValoresAleatorios(10, MIN_VAL, MAX_VAL);
            listaES.imprimeLista();
            menor = listaES.menorValor(pos, acesso, precede);
            cout << "\t - Menor valor: " << menor << endl;
            cout << "\t - Posição do menor valor: " << pos << endl;
            cout << "\t - Acesso: " << acesso << endl;
            listaES.imprimeInverso();
            cout << endl;
            cout << "__________________________________________________________________" << endl;
 

            break;

            case 3:
            cout << "______________________ LISTA ENCADEADA DUPLA _____________________" << endl << "__________________________________________________________________" << endl;
            listaED.insere(8,0);
            listaED.insere(1,1);
            listaED.insere(3,2); 
            listaED.insere(4,3);
            listaED.insere(3,4);
            listaED.insere(6,5);
            listaED.insere(10,6);
            listaED.insere(8,7);
            listaED.insere(9,8);
            listaED.insere(1,9);
            //OPERAÇÃO 7
            listaED.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 3            
            cout << "_______________ INSERE EM UMA POSIÇÃO ESPECIFICA: ________________" << endl << "__________________________________________________________________" << endl;
            cout << " - Insere o valor 11 na posição 10: " << endl;
            listaED.insere(11,10);
            listaED.imprimeLista();

            cout << " - Insere o valor 2 na posição 4: " << endl;
            listaED.insere(2,4);
            listaED.imprimeLista();

            cout << " - Insere o valor 7 na posição 0: " << endl;
            listaED.insere(7,0);
            listaED.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 5
            cout << "_____________________________ BUSCA: _____________________________" << endl << "__________________________________________________________________" << endl;
            encontrado = listaED.busca(10, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;

            encontrado = listaED.busca(8, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;

            encontrado = listaED.busca(12, acesso);
            encontrado != -1 ? cout << " - Valor encontrado na posição: " << encontrado << endl : cout << " - Valor não encontrado!" << endl;
            cout << " - Acesso: " << acesso << endl << endl;
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 4
            cout << "________________________ TRANSPOSIÇÃO: ___________________________" << endl << "__________________________________________________________________" << endl;
            listaED.transposicao(3, 4);
            listaED.imprimeLista();
            listaED.transposicao(0, 6);
            listaED.imprimeLista();
            listaED.transposicao(6, 12);
            listaED.imprimeLista();
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 6
            cout << "_____________________ BUSCA PELO MENOR VALOR: ____________________" << endl << "__________________________________________________________________" << endl;
            menor = listaED.menorValor(pos, acesso, precede);
            cout << "\t - Menor valor: " << menor << endl;
            cout << "\t - Posição do menor valor: " << pos << endl;
            cout << "\t - Acesso: " << acesso << endl;
            cout << "\t - Valor do Predecessor: " << precede << endl;
            cout << "__________________________________________________________________" << endl;

            //OPERAÇÃO 8
            cout << "________________________ LISTA INVERSA: __________________________" << endl << "__________________________________________________________________" << endl;
            listaED.imprimeInverso();
            cout << endl;
            cout << "__________________________________________________________________" << endl;   

            //OPERAÇÃO 2
            cout << "______________________ GERA LISTA ALEATORIA: _____________________" << endl << "__________________________________________________________________" << endl;
            listaED.geraValoresAleatorios(10, MIN_VAL, MAX_VAL);
            listaED.imprimeLista();
            menor = listaED.menorValor(pos, acesso, precede);
            cout << "\t - Menor valor: " << menor << endl;
            cout << "\t - Posição do menor valor: " << pos << endl;
            cout << "\t - Acesso: " << acesso << endl;
            listaED.imprimeInverso();
            cout << endl;
            cout << "__________________________________________________________________" << endl;

            break;

            default:
            cout << "Opção inválida!" << endl;
            break;
    }

    //LIMPA LISTA
    listaES.LimpaLista();
    listaED.LimpaLista();
    
    return 0;
}
