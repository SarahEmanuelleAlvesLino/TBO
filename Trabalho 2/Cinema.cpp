#include "Cinema.h"
#include "Filtro.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Cinema::setId(string idCinema) {
    this->idCinemas = idCinema;
}

string Cinema::getId() {
    return idCinemas;
}

void Cinema::setNome(string nome) {
    this->nome = nome;
}

string Cinema::getNome() {
    return nome;
}

void Cinema::setCordX(int cordX) {
    this->cordX = cordX;
}

int Cinema::getCordX() {
    return cordX;
}

void Cinema::setCordY(int cordY) {
    this->cordY = cordY;
}

int Cinema::getCordY() {
    return cordY;
}

void Cinema::setPreco(float preco) {
    this->preco = preco;
}

float Cinema::getPreco() {
    return preco;
}

void Cinema::setFilmesCinemas(Filmes* filme) {
    filmesCinemas.push_back(filme);              // Adiciona um filme à lista de filmes disponíveis no cinema
}

vector<Filmes*> Cinema::getFilmesCinemas() {
    return filmesCinemas; // Retorna a lista de filmes disponíveis no cinema
}

