#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <string>
#include <iostream>
#include "Filmes.h"

using namespace std;

class Cinema {
    private:
        string idCinemas;
        string nome;
        int cordX;
        int cordY;
        float preco;
        vector<Filmes*> filmesCinemas; // Lista de filmes disponíveis no cinema

    public:
        void setId(string idCinemas);
        string getId();
        void setNome(string nome);
        string getNome();
        void setCordX(int cordX);
        int getCordX();
        void setCordY(int cordY);
        int getCordY();
        void setPreco(float preco);
        float getPreco();
        void setFilmesCinemas(Filmes* filme);
        vector<Filmes*> getFilmesCinemas();
        void limparFilmesCinemas(){
            filmesCinemas.clear(); // Limpa a lista de filmes disponíveis no cinema
        }
};

#endif 