#ifndef FILTRO_H
#define FILTRO_H
#include "Filmes.h"
#include "Cinema.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>
#include <cmath>

#define HASH_CONST 100

using namespace std;

class Filtro {

private:
    static bool buscaString(vector<string> vetorFilmeCine, string achouuuu);

public:
    static void FiltroFilmes(vector<Filmes> (&filmes)[HASH_CONST], vector<Filmes> (&filmesFiltrados)[HASH_CONST], vector<string>& tipo, int anoInicio, int anoFim, int duracaoMin, int duracaoMax, vector<string> genero);
    static Filmes* LocalizaFilme(vector<Filmes> (&filmes)[HASH_CONST],int id);
    static void FiltraCinema(vector<Cinema>(& cinemas), vector<Cinema> &cinemasFiltrado, vector<string> tipo, vector<string> genero,vector<int> limiteDuracao, int distancia, float preco, vector<int>  limiteano,int pontoX,int pontoY);
    
};
#endif 

