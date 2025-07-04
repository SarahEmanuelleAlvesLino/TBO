#ifndef FILMES_H
#define FILMES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Filmes {
private:
    int tconst; 
    int hash; // Valor de hash do tconst
    string titleType; 
    string primaryTitle; 
    string originalTitle; 
    int isAdult; 
    int startYear; 
    int endYear; 
    int runtimeMinutes; 
    vector<string> genres; 
    vector<string> idCinemas;

public:
    // Construtor padrão
    void setTconst(int tconst);
    int getTconst();

    void setHash(int hash);
    int getHash();

    void setTitleType(const string& titleType);
    string getTitleType();

    void setPrimaryTitle(const string& primaryTitle);
    string getPrimaryTitle();

    void setOriginalTitle(const string& originalTitle);
    string getOriginalTitle();

    void setIsAdult(int isAdult);
    int getIsAdult();

    void setStartYear(int startYear);
    int getStartYear();

    void setEndYear(int endYear);
    int getEndYear();

    void setRuntimeMinutes(int runtimeMinutes);
    int getRuntimeMinutes();
    
    void setGenres(const string& genre);
    vector<string> getGenres();
        

    
};
#endif