#include "Filtro.h"
#include "Filmes.h"
#include "Cinema.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool Filtro::buscaString(vector<string> vetorFilmeCine, string achouuuu) {
    for (string nome : vetorFilmeCine) {
            if (nome.compare(achouuuu) == 0) {
                return true;
            }
        }
        return false;
}

void Filtro::FiltroFilmes(vector<Filmes> (&filmes)[HASH_CONST], vector<Filmes> (&filmesFiltrados)[HASH_CONST], vector<string>& tipo, int anoInicio, int anoFim, int duracaoMin, int duracaoMax, vector<string> genero) {
    bool foiInserido, passouuuu;
    
    for(vector<Filmes> hash: filmes){
        for(Filmes filme: hash){
            passouuuu = true;
            foiInserido = true;

            //Vé se o filtro foi selecionado e se é diferente
            if(!tipo.empty()) {
                bool tipoCompativel = false;
                // Procura se o tipo do filme existe na lista de tipos do filtro
                for (const string& tipoDoFiltro : tipo) {
                    if (filme.getTitleType().compare(tipoDoFiltro) == 0) {
                        tipoCompativel = true; 
                        break; 
                    }
    }

                // Se, após a busca, o tipo do filme não for compatível com nenhum do filtro...
                if (!tipoCompativel) {
                    passouuuu = false; 
                    continue;
                }
            }
            if(duracaoMin != -2 && duracaoMax != -2) {   // verifica se foltro foi selecionado se ele esestiver -2, significa que não foi selecionado
                if(filme.getRuntimeMinutes() < duracaoMin || filme.getRuntimeMinutes() > duracaoMax) {
                    passouuuu = false;
                    continue;
                }
            }

             if (passouuuu && (anoInicio != -2)) {
                int anoDoFilme = filme.getStartYear();
                if (anoDoFilme == -1 || anoDoFilme < anoInicio || anoDoFilme > anoFim) {
                    passouuuu = false; 
                }
            }

            if (!genero.empty()) {
                for(string generoBusca: filme.getGenres()) {
                    for(string generos : genero) {
                        if(generoBusca.compare(generos) == 0 && foiInserido ) {
                            int hashFiltrados = filme.getTconst() % HASH_CONST;
                                filmesFiltrados[hashFiltrados].push_back(filme);
                                foiInserido = false; 
                                break; 
                            
                        }
                    }
                }
                passouuuu = false; // Se algum gênero foi encontrado, não precisa continuar verificando outros gêneros
            }
            
            if(passouuuu){
                int hashFiltrados = filme.getTconst() % HASH_CONST; // Calcula o hash do filme filtrado
                filmesFiltrados[hashFiltrados].push_back(filme); // Adiciona o filme ao vetor de filmes filtrados
            }
        }
    }
}


//Filtro utilizando HASH E BUSCA BINÁRIA
Filmes* Filtro::LocalizaFilme(vector<Filmes> (&filmes)[HASH_CONST], int id) {
    int hash = id % HASH_CONST;
    if(filmes[hash].size() != 0) {
        int inicio = 0, fim = filmes[hash].size() - 1;
        Filmes* aux = new Filmes;

        while(inicio <= fim){
            int meio = inicio + (fim-inicio) / 2;
            if(filmes[hash][meio].getTconst() == id) {
                *aux = filmes[hash][meio]; 
                return aux; 
            } 
            if(filmes[hash][meio].getTconst() < id) {
                inicio = meio + 1; 
            } else {
                fim = meio - 1; 
            }
        }
        delete aux;
        return nullptr; 
    }
    return nullptr;
}


void Filtro::FiltraCinema(vector<Cinema>(& cinemas), vector<Cinema> (&cinemasFiltrado), vector<string> tipo, vector<string> genero, vector<int> limiteDuracao, int distancia, float preco, vector<int> limiteano, int pontoX, int pontoY) {
    bool passouuuu;
    for(Cinema cinema : cinemas) {
        passouuuu = true;
        
        if(!(tipo.empty() && genero.empty() && (limiteDuracao[0] == -2 && limiteDuracao[1] == -2) && (limiteano[0] == -2 && limiteano[1] == -2))) {

                for (Filmes* filme : cinema.getFilmesCinemas()) {

                        if (filme != nullptr) {
                            //FILTRO DE TIPO
                            if(!tipo.empty() && !buscaString(tipo, filme->getTitleType())) {
                                passouuuu = false; // Se o tipo do filme não está na lista de tipos, não é válido
                                continue; // Sai do loop de tipos se já encontrou um tipo incompatível
                            }
                            else if(buscaString(tipo, filme->getTitleType())) {
                                // Se não houver filtro de tipo, não precisa verificar
                                passouuuu = true; // O filme é válido se não houver filtro de tipo
                            }

                            //FILTRO DE GENERO
                            if(!genero.empty()){
                                for(string generoBusca : genero){
                                    if(!buscaString(filme->getGenres(), generoBusca)) {
                                        passouuuu = false; 
                                        continue; 
                                    }
                                    else {
                                        passouuuu = true; 
                                    }
                                }
                            }

                            //FILTRO DE DURACAO
                            if(limiteDuracao[0] != -2 && limiteDuracao[1] != -2) {
                                if(filme->getRuntimeMinutes() < limiteDuracao[0] || filme->getRuntimeMinutes() > limiteDuracao[1]) {
                                    passouuuu = false; // Se a duração do filme não está dentro dos limites, não é válido
                                    continue; 
                                }
                            }

                            // FILTRO DE ANO
                                if (limiteano[0] != -2 && limiteano[1] != -2) {
                                    bool temAnoValido = false;

                                    for (Filmes* filme : cinema.getFilmesCinemas()) {
                                        if (filme == nullptr) continue;

                                        int start = filme->getStartYear();
                                        int end = filme->getEndYear();

                                        // Considera filmes com StartYear dentro do intervalo
                                        if (start >= limiteano[0] && start <= limiteano[1]) {
                                            temAnoValido = true;
                                            break;
                                        }

                                        // Considera filmes com EndYear válido dentro do intervalo
                                        if (end != -1 && end >= limiteano[0] && end <= limiteano[1]) {
                                            temAnoValido = true;
                                            break;
                                        }
                                    }

                                    if (!temAnoValido) {
                                        passouuuu = false;
                                    }
                                }
                        }else{
                            passouuuu = false; 
                        }
                    }
                }

        //FILTRO DE DISTANCIA
        if(distancia != -2) {
            float distanciaCalculada = sqrt(pow((cinema.getCordX() - pontoX), 2) + pow((cinema.getCordY() - pontoY), 2));
            if(distanciaCalculada > distancia) {
                passouuuu = false; // Se a distância do cinema for maior que a distância limite, não é válido
                continue; 
            }
        }

        //FILTRO DE PRECO
        if(preco != -2) {
            if(cinema.getPreco() > preco) {
                passouuuu = false; // Se o preço do cinema for maior que o preço limite, não é válido
                continue; 
            }
        }

        // Se passou por todos os filtros, adiciona o cinema ao vetor de cinemas filtrados
        if(passouuuu) {
            cinemasFiltrado.push_back(cinema); // Adiciona o cinema ao vetor de cinemas filtrados
        }

    }
}
    



