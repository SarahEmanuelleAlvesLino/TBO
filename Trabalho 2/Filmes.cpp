#include "Filmes.h"
#include "Filtro.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Filmes::setTconst(int tconst) {
    this -> tconst = tconst;
}

int Filmes::getTconst() {
    return tconst;
}

void Filmes::setHash(int hash) {
    this->hash = hash % HASH_CONST;
}

int Filmes::getHash() {
    return hash;
}

void Filmes::setTitleType(const string& titleType) {
    this->titleType = titleType;
}

string Filmes::getTitleType() {
    return titleType;
}

void Filmes::setPrimaryTitle(const string& primaryTitle) {
    this->primaryTitle = primaryTitle;
}

string Filmes::getPrimaryTitle() {
    return primaryTitle;
} 

void Filmes::setOriginalTitle(const string& originalTitle) {
    this->originalTitle = originalTitle;
}

string Filmes::getOriginalTitle() {
    return originalTitle;
}

void Filmes::setIsAdult(int isAdult) {
    this->isAdult = isAdult;
}

int Filmes::getIsAdult() {
    return isAdult;
}

void Filmes::setStartYear(int startYear) {
    this->startYear = startYear;
}

int Filmes::getStartYear() {
    return startYear;
}

void Filmes::setEndYear(int endYear) {
    this->endYear = endYear;
}

int Filmes::getEndYear() {
    return endYear;
}

void Filmes::setRuntimeMinutes(int runtimeMinutes) {
    this->runtimeMinutes = runtimeMinutes;
}

int Filmes::getRuntimeMinutes() {
    return runtimeMinutes;
}

void Filmes::setGenres(const string& genre) {
    genres.push_back(genre);
}

vector<string> Filmes::getGenres() {
    return genres;
}



