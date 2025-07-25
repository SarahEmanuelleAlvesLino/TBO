#include <iostream>      
#include "huffman.h" 

int main(int argc, char* argv[]) {
    // Verifica se o número correto de argumentos foi passado
    if (argc != 4) {
        cerr << "Uso: ./huffman C/D arquivo_entrada arquivo_saida" << endl;
        return 1; 
    }

    char operacao = argv[1][0];  // Obtém o primeiro caractere do argumento que define a operação
    string arquivoEntrada = argv[2];  
    string arquivoSaida = argv[3];    


    if (operacao == 'C'){     //Compactação ('C')
        compactarArquivo(arquivoEntrada, arquivoSaida); 
        calcularCompressao(arquivoEntrada, arquivoSaida); 
    }else if (operacao == 'D')    //Descompactação ('D') 
        descompactarArquivo(arquivoEntrada, arquivoSaida); 
        
    return 0; 
}