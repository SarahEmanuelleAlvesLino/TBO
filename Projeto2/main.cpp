#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include "KMP.h"

using namespace std;
int acessouuuuu = 0; // Variável global para contar a quantidade de acessos ao arquivo

int main(){

    int op;

    do{
        cout << "______________________________________________________________________"<< endl;
        cout << "|                                                                    |" << endl;
        cout << "|                       Bem-vindo ao Projeto 2                       |" << endl;
        cout << "|                                                                    |" << endl;
        cout << "| 1 - KMP                                                            |" << endl;
        cout << "| 2 - Busca de várias palavras (Aho-Corasick)                        |" << endl;
        cout << "| 3 - Compressão e Descompressão de texto                            |" << endl;
        cout << "| 4 - Sair                                                           |" << endl;
        cout << "|____________________________________________________________________|" << endl;
        cout << "Digite a opção desejada: ";
        cin >> op;
        cin.ignore(); // Limpa o buffer de entrada
        system("clear");

        switch (op)
        {
            //KMP
            case 1:{

                cout << endl << "--------------------- KMP ---------------------" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "|                                                                    |" << endl;
                cout << "|>> Digite a quantidade de padroes que deseja pesquisar:             | " << endl;
                int n;
                cout << "|                                                                    |" << endl;
                cout << "|>> Quantidade de padroes: ";
                cin >> n;
                cin.ignore(); // Limpa o buffer de entrada
                cout << "|                                                                    |" << endl;
                cout << "|>> Digite o(s) padrao(s) que deseja pesquisar:                      | " << endl;
                cout << "|                                                                    |" << endl;
                vector<string> padroes(n);
                    for(int i = 0; i < n; i++){
                        cout << "|>> Padrão " << i+1 << ": ";
                        getline(cin, padroes[i]);
                    }
                cout << "|                                                                    |" << endl;
                cout << "|____________________________________________________________________|" << endl;

                    const int BufferTam = 16384;  // Tamanho do buffer é igual a 16KB o que nos garante que uma linha não seja quebrada no meio
                    char buffer[BufferTam];

                    //vector<const char*> padroes = {"mort"};

                for(size_t i = 0; i < padroes.size(); i++) {
                    cout << "Padrão " << i + 1 << ": " << padroes[i] << endl;

                    ifstream arquivo("texto.txt");
                    if(!arquivo.is_open()) {
                        cerr << "Erro ao abrir o arquivo." << endl;
                        return 1;
                    }
                    acessouuuuu++;

                    int linha = 1;
                    while (arquivo.getline(buffer, BufferTam)) {
                        // chamar a função KMP para cada linha do arquivo
                        // Exemplo: KMP(buffer, padroes[i]);
                        kmp(buffer, padroes[i].c_str(), linha);
                        //cout << "Linha " << linha << ": " << buffer << endl;  // Exibe a linha lida
                        linha++;
                        acessouuuuu++;
                    }

                    arquivo.close();
                    cout << "Total de acessos ao arquivo: " << acessouuuuu << endl;
                    acessouuuuu = 0; // Reseta o contador de acessos para o próximo padrão
                    cout << endl;
                    
                }
            }
                break;

            //Aho-Corasick
            case 2:{

            }
                break;

            //Compressão e Descompressão
            case 3:{

            }
                break;

            //Sair
            case 4:
                cout << "Saindo do sistema..." << endl;
                break;
            
            default:
                cout << "Opção inválida! Tente novamente." << endl;
                break;
        }

        }while (op != 4);
    


}