#include "Filtro.h"
#include <iostream>
#include <sstream>
#include <chrono>
#include <vector>
#include <fstream>

using namespace std;

string Remove_Espaco(string restoPalavra, int qnt){
    restoPalavra.erase(0, qnt);
    return restoPalavra;
}

void salvaFiltroFilmes(vector<Filmes> (&filmesFiltrados)[HASH_CONST]){
    ofstream arqFiltro("filtroFilmes.txt");
    if(!arqFiltro.is_open()){
        cerr << "Erro ao abrir o arquivo filtroFilmes.txt" << endl;
        return;
    }

        for(vector<Filmes> hash: filmesFiltrados){
            for(Filmes filme : hash){
                arqFiltro <<"ID: "<< filme.getTconst() << endl
                      << "Tipo: " << filme.getTitleType() << endl
                      << "Titulo Principal: " << filme.getPrimaryTitle() << endl
                      << "Titulo Original: " << filme.getOriginalTitle() << endl
                      << "Adulto: " << filme.getIsAdult() << endl
                      << "Ano de Inicio: " << filme.getStartYear() << endl
                      << "Ano de Fim: " << filme.getEndYear() << endl
                      << "Duracao: " << filme.getRuntimeMinutes() << endl
                      << "Generos: ";
                      for(string genero : filme.getGenres()){
                          arqFiltro << genero;
                          if(&genero != &filme.getGenres().back()) // Não adiciona vírgula no último gênero
                              arqFiltro << ",";
                      }
                arqFiltro << endl << "Lançamento: " << filme.getStartYear() << endl
                        << "Fim: " << filme.getEndYear() << endl 
                        << "Duração: " << filme.getRuntimeMinutes() << endl;

                arqFiltro << endl;
            }
        arqFiltro << endl;
    }
    arqFiltro.close();
    cout << "______________________________________________________________________" << endl;
    cout << "|                                                                    |" << endl;
    cout << "| >> Filtro salvo em 'filtroFilmes.txt'                              |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << endl;
}

void imprimirFiltroFilmes(vector<Filmes> (&filmesFiltrados)[HASH_CONST]){
    cout << "______________________________________________________________________" << endl;
    cout << "|                                                                    |" << endl;
    cout << "| >> FILMES FILTRADOS:                                               |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << endl;

    for(vector<Filmes> hash: filmesFiltrados){
        for(Filmes filme : hash){
            cout << "______________________________________________________________________"<< endl;
            cout << "ID: " << filme.getTconst() << endl
                 << "\t Tipo: " << filme.getTitleType() << endl
                 << "\t Titulo Principal: " << filme.getPrimaryTitle() << endl
                 << "\t Titulo Original: " << filme.getOriginalTitle() << endl
                 << "\t Adulto: " << filme.getIsAdult() << endl
                 << "\t Ano de Inicio: " << filme.getStartYear() << endl
                 << "\t Ano de Fim: " << filme.getEndYear() << endl
                 << "\t Duracao: " << filme.getRuntimeMinutes() << endl
                 << "\t Generos: ";
            for(string genero : filme.getGenres()){
                cout << genero;
                if(&genero != &filme.getGenres().back()) // Não adiciona vírgula no último gênero
                    cout << ",";
            }
            cout << endl << "\t Lançamento: " << filme.getStartYear() << endl
                 << "\t Fim: " << filme.getEndYear() << endl
                 << "\t Duração: " << filme.getRuntimeMinutes() << endl 
                 << endl;
        }
        cout << "______________________________________________________________________"<< endl;
    }
        cout << endl;
}

void salvaFiltroCinemas(vector<Cinema> &cinemasFiltrados){
    ofstream arqFiltro("filtroCinemas.txt");
    if(!arqFiltro.is_open()){
        cerr << "Erro ao abrir o arquivo filtroCinemas.txt" << endl;
        return;
    }

    for(Cinema cinema : cinemasFiltrados){
        arqFiltro << "ID: " << cinema.getId() << endl
                  << "Nome: " << cinema.getNome() << endl
                  << "Coordenada X: " << cinema.getCordX() << endl
                  << "Coordenada Y: " << cinema.getCordY() << endl
                  << "Preço: " << cinema.getPreco() << endl
                  << "Filmes Disponíveis: ";
        for(Filmes* cinema: cinema.getFilmesCinemas()){
            if(cinema != nullptr) {
                arqFiltro << "tt" << cinema->getTconst() << ", ";
            }
           
        }
        cout << endl;
        arqFiltro << endl;
        arqFiltro << endl;
    }
    arqFiltro.close();
    cout << "______________________________________________________________________" << endl;
    cout << "|                                                                    |" << endl;
    cout << "| >> Filtro salvo em 'filtroCinemas.txt'                             |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << endl;
}

void imprimirFiltroCinemas(vector<Cinema> &cinemasFiltrados){
    cout << "______________________________________________________________________" << endl;
    cout << "|                                                                    |" << endl;
    cout << "| >> CINEMAS FILTRADOS:                                              |" << endl;
    cout << "|____________________________________________________________________|" << endl;
    cout << endl;

    for(Cinema cinema : cinemasFiltrados){
        cout << "______________________________________________________________________"<< endl;
        cout << "ID: " << cinema.getId() << endl
             << "\t Nome: " << cinema.getNome() << endl
             << "\t Coordenada X: " << cinema.getCordX() << endl
             << "\t Coordenada Y: " << cinema.getCordY() << endl
             << "\t Preço: " << cinema.getPreco() << endl
             << "\t Filmes Disponíveis: ";
        for(Filmes* filme : cinema.getFilmesCinemas()){
            if(filme != nullptr) {
                cout <<"tt" << filme->getTconst() << ", ";
            }
        }
        cout << endl;
    }
    cout << "______________________________________________________________________"<< endl;
}

int main(){
    auto cronometro = chrono::high_resolution_clock::now();
    int op;

    //Variaveis para filmes
    vector<Filmes> filmes[HASH_CONST];
    stringstream separalinha;
    string linha;
    string coluna;
    ifstream ArqFilmes ;

    //Variaveis para cinemas
    ifstream ArqCinemas;
    vector<Cinema> cinemas;
    string separaLinhaCinema;
    string separaColunaCinema;
    int idCinema = 0;

    

    // ---------------Filmes-------------------
    ArqFilmes.open("filmesCrop.txt");
    if(!ArqFilmes.is_open()){
        cerr << "Erro ao abrir o arquivo filmesCrop.txt" << endl;
        return 1;
    }

    getline(ArqFilmes, linha); // Pular o cabeçalho
    linha.clear();

    auto inicioLeituraFilmes = chrono::high_resolution_clock::now();

    while(getline(ArqFilmes, linha)){
        Filmes filme;
        separalinha.str(linha);

        try{
            getline(separalinha, coluna, '\t');   
            int id = stoi(Remove_Espaco(coluna, 2));
            filme.setTconst(id);                             //remove o tt
            filme.setHash(id);                               //armazena na hash, sem o tt e como inteiro  
        }catch(const std::invalid_argument& e){
            separalinha.clear();
        }

        getline(separalinha, coluna, '\t');                
        filme.setTitleType(coluna);

        getline(separalinha, coluna, '\t');
        filme.setPrimaryTitle(coluna);

        getline(separalinha, coluna, '\t');
        filme.setOriginalTitle(coluna);

        getline(separalinha, coluna, '\t');
        if(isdigit(coluna[0])){
            filme.setIsAdult(stoi(coluna));
        } else {
            filme.setIsAdult(-1); // Se não for um número, assume -1
        }

        getline(separalinha, coluna, '\t');
        if(isdigit(coluna[0])){
            filme.setStartYear(stoi(coluna));
        } else {
            filme.setStartYear(-1);  
        }

        getline(separalinha, coluna, '\t');
        if(isdigit(coluna[0])){
            filme.setEndYear(stoi(coluna));
        } else {
            filme.setEndYear(-1);                           
        }

        getline(separalinha, coluna, '\t');
        if(isdigit(coluna[0])){
            filme.setRuntimeMinutes(stoi(coluna));
        } else {
            filme.setRuntimeMinutes(-1);                 
        }

        getline(separalinha, coluna);
        stringstream separaAux;
        string genero;
        separaAux.str(coluna);

        if(coluna.find(',') == string::npos){
            // Se não houver vírgula, significa que é um único gênero
            filme.setGenres(coluna);
        } else {
            // Se houver vírgula, separa os gêneros
            while(getline(separaAux, genero, ',')){
                if(!genero.empty()){
                    filme.setGenres(genero);
                }
            }
        }

        separalinha.clear(); // Limpa o estado do stringstream para a próxima linha
        filmes[filme.getHash()].push_back(filme); // Adiciona o filme ao vetor correspondente na hash
    }

    auto TerminaLeituraFilme= chrono::high_resolution_clock::now();
    auto tempoLeitura = TerminaLeituraFilme - inicioLeituraFilmes;
    cout << "- Tempo de leitura de Filme: " << chrono::duration_cast<chrono::seconds>(tempoLeitura).count() << " segundos" << endl;
    cout << "- Tempo de leiturade Filme: " << chrono::duration_cast<chrono::milliseconds>(tempoLeitura).count() << " millisegundos" << endl;
    ArqFilmes.close();

// ---------------Cinemas-------------------

    ArqCinemas.open("cinemas.txt");

    if(!ArqCinemas.is_open()){
        cerr << "Erro ao abrir o arquivo cinemas.txt" << endl;
    }

    getline(ArqCinemas, separaLinhaCinema); // Pular o cabeçalho    
    separaLinhaCinema.clear();

    auto inicioLeituraCinemas = chrono::high_resolution_clock::now();
    while(getline(ArqCinemas, separaLinhaCinema)){
        Cinema cinema;
        stringstream separaColuna(separaLinhaCinema);

        while(getline(separaColuna, separaColunaCinema, ',')){
            switch (idCinema){
            case 0:
                cinema.setId(separaColunaCinema);
                break;
            case 1:
                cinema.setNome(Remove_Espaco(separaColunaCinema,1));
                break;
            case 2:
                    cinema.setCordX(stoi(Remove_Espaco(separaColunaCinema,1)));
                break;
            case 3:
                    cinema.setCordY(stoi(Remove_Espaco(separaColunaCinema,1)));
                break;
            case 4:
                    cinema.setPreco(stof(Remove_Espaco(separaColunaCinema,1)));
                break;            
            default:
                cinema.setFilmesCinemas(Filtro::LocalizaFilme(filmes, stoi(Remove_Espaco(separaColunaCinema, 3)))); // Adiciona o filme ao cinema
                break;
            }
            idCinema++;
        }
        idCinema = 0; // Reseta o contador para a próxima linha
        cinemas.push_back(cinema); // Adiciona o cinema ao vetor de cinemas
    }

    //LÊ ARQUIVO DE FILME PARA PROCURAR POR TITULO E GENERO

    auto TerminaLeituraCinemas = chrono::high_resolution_clock::now();
    auto tempoLeituraCinemas = TerminaLeituraCinemas - inicioLeituraCinemas;
    cout << "- Tempo de leitura Cinema: " << chrono::duration_cast<chrono::seconds>(tempoLeituraCinemas).count() << " segundos" << endl;
    cout << "- Tempo de leitura Cinema: " << chrono::duration_cast<chrono::milliseconds>(tempoLeituraCinemas).count() << " milisegundos" << endl;

    ArqCinemas.close(); // Fecha o arquivo de cinemas

    

    // -----------------Menu-------------------
    do{
        cout << "______________________________________________________________________"<< endl;
        cout << "|                                                                    |" << endl;
        cout << "|        Bem-vindo ao sistema de filtragem de filmes e Cinemas!      |" << endl;
        cout << "|                                                                    |" << endl;
        cout << "| 1 - Filtrar Filmes                                                 |" << endl;
        cout << "| 2 - Filtrar Cinemas                                                |" << endl;
        cout << "| 3 - Sair do Sistema                                                |" << endl;
        cout << "|____________________________________________________________________|" << endl;
        cout << "Digite a opção desejada: ";
        cin >> op;
        cin.ignore(); // Limpa o buffer de entrada
        system("clear");

        switch (op){
            //BUSCA DE FILMES
            case 1:{
                vector<Filmes> FiltroFilmes[HASH_CONST];
                vector<string> generoBusca;
                vector<string> tipoBusca;
                string tipo, generoAux;
                generoBusca.clear();
                tipo.clear();
                int duracaoMinima = -2, duracaoMaxima = -2, anoInicio = -2, anoFim = -2;
                int resposta, qntGenero, qntAux;

                //PESQUISAR FILTRO
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum tipo?                                    |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Quantos tipos deseja incluir no filtro?                          |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite a quantidade desejada:                                     |" << endl;   
                    cin >> qntAux;
                    cout << "______________________________________________________________________"<< endl;

                    for (int i = 0; i < qntAux; i++){
                        int escolhaTipo;
                        string tipoSelecionado;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "|                         Escolha o tipo                             |" << endl;
                        cout << "|  1 - MOVIE (FILME)                                                 |" << endl;
                        cout << "|  2 - SHORT (CURTA-METRAGEM)                                        |" << endl;
                        cout << "|  3 - TV SERIES (SERIES DE TV)                                      |" << endl;
                        cout << "|  4 - TV EPISODE (TELEFILME)                                        |" << endl;
                        cout << "|  5 - VIDEO                                                         |" << endl;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "Digite o tipo " << i + 1 << " que deseja: ";
                        cin >> escolhaTipo;

                        switch (escolhaTipo){
                            case 1:
                                tipoSelecionado = "movie";
                                break;
                            
                            case 2:
                                tipoSelecionado = "short";
                                break;

                            case 3:
                                tipoSelecionado = "tv series";
                                break;

                            case 4:
                                tipoSelecionado = "tvEpisode";
                                break;

                            case 5:
                                tipoSelecionado = "video";
                                break;

                            default:
                                cout << "OPCAO INVALIDA"<< endl;
                                i--; 
                                continue; // Volta para o início do loop se a opção for inválida
                        }
                        
                        tipoBusca.push_back(tipoSelecionado);
                        
                    }
                    system("clear");
                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                system("clear");

                //BUSCA POR ANO
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Deseja filtrar por ano?                                          |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  1 - SIM                                                           |" << endl;
                    cout << "|  2 - NAO                                                           |" << endl;
                    cout << "______________________________________________________________________"<< endl;
                    cout << "Digite a opção desejada: ";
                    cin >> resposta;

                    if(resposta == 1){
                        int modo;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "|>> Escolha o modo de filtro de ano.                                 |" << endl;
                        cout << "|                                                                    |" << endl;
                        cout << "|  1 - ANO ESPECIFICO                                                |" << endl;
                        cout << "|  2 - INTERVALO DE ANOS                                             |" << endl;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "Digite a opção desejada: ";
                        cin >> modo;

                        switch (modo){
                            case 1:{
                                cout << "______________________________________________________________________"<< endl;
                                cout << "|>> Digite o ano especifico:                                         |" << endl;
                                cout << "|                                                                    |" << endl;
                                cout << "|  Digite o ano especifico:                                          |" << endl;
                                cin >> anoInicio;
                                cout << "______________________________________________________________________"<< endl;
                                anoFim = anoInicio; 
                                system("clear");
                                break;
                            }
                            case 2:{
                                cout << "______________________________________________________________________"<< endl;
                                cout << "|>> Digite o ano inicial:                                            |" << endl;
                                cout << "|                                                                    |" << endl;
                                cout << "|  Digite o ano inicial:                                             |" << endl;   
                                cin >> anoInicio;
                                cout << "______________________________________________________________________"<< endl;
                                do{
                                    cout << "______________________________________________________________________"<< endl;
                                    cout << "|>> Digite o ano final:                                              |" << endl;
                                    cout << "|                                                                    |" << endl;
                                    cout << "|  Digite o ano final:                                               |" << endl;   
                                    cin >> anoFim;
                                    cout << "______________________________________________________________________"<< endl;

                                    if(anoInicio > anoFim){
                                        cout << "Ano inicial maior que o final, tente novamente!" << endl;
                                    }
                                } while(anoInicio > anoFim);
                                    system("clear");
                            }    
                            default:{
                                cout << "OPCAO INVALIDA"<< endl;
                                break;
                            }
                        }system("clear");
                    }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                    system("clear");
                
                //BUSCA POR DURACAO ESPECIFICA
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum filme com alguma duracao especifica?     |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){
                        cout << "______________________________________________________________________"<< endl;
                        cout << "|>> Digite a duracao minima do filme:                                |" << endl;
                        cout << "|                                                                    |" << endl;
                        cout << "|  Digite a duracao minima:                                          |" << endl;   
                        cin >> duracaoMinima;
                        cout << "______________________________________________________________________"<< endl;

                        do{
                            cout << "______________________________________________________________________"<< endl;
                            cout << "|>> Digite a duracao maxima do filme:                                |" << endl;
                            cout << "|                                                                    |" << endl;
                            cout << "|  Digite a duracao maxima:                                          |" << endl;   
                            cin >> duracaoMaxima;
                            cout << "______________________________________________________________________"<< endl;
                            
                            if(duracaoMinima > duracaoMaxima){
                                cout << "Duracao minima maior que a maxima, tente novamente!" << endl;
                            }
                    } while(duracaoMinima > duracaoMaxima);
                    system("clear");

                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                system("clear");

                //BUSCAR GENERO
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum genero?                                  |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta != 2){
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Quantos generos deseja incluir no filtro?                        |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite a quantidade desejada:                                     |" << endl;   
                    cin >> qntGenero;
                    cout << "______________________________________________________________________"<< endl;

                    for(int i = 0; i < qntGenero; i++){
                        int escolhaGenero;
                        string generoSelecionado;

                        cout << "______________________________________________________________________"<< endl;
                        cout << "|                         Escolha o Genero                           |" << endl;
                        cout << "|  1 - ACTION                                                        |" << endl;
                        cout << "|  2 - ANIMATION                                                     |" << endl;
                        cout << "|  3 - COMEDY                                                        |" << endl;
                        cout << "|  4 - DRAMA                                                         |" << endl;
                        cout << "|  5 - HISTORY                                                       |" << endl;
                        cout << "|  6 - MUSIC                                                         |" << endl;
                        cout << "|  7 - SHORT                                                         |" << endl;
                        cout << "|  8 - TALK-SHOW                                                     |" << endl;
                        cout << "|  9 - BIOGRAPHY                                                     |" << endl;
                        cout << "|  10 - DOCUMENTARY                                                  |" << endl;
                        cout << "|  11 - NEWS                                                         |" << endl;
                        cout << "|  12 - SCI-FI                                                       |" << endl;
                        cout << "|  13 - REALITY-TV                                                   |" << endl;
                        cout << "|  14 - FAMILY                                                       |" << endl;
                        cout << "|  15 - ADULT                                                        |" << endl;
                        cout << "|  16 - GAME-SHOW                                                    |" << endl;
                        cout << "|  17 - HORROR                                                       |" << endl;
                        cout << "|  18 - THRILLER                                                     |" << endl;
                        cout << "|  19 - WAR                                                          |" << endl;
                        cout << "|  20 - CRIME                                                        |" << endl;
                        cout << "|  21 - MYSTERY                                                      |" << endl;
                        cout << "|  22 - SPORT                                                        |" << endl;
                        cout << "|  23 - FANTASY                                                      |" << endl;
                        cout << "|  24 - ROMANCE                                                      |" << endl;
                        cout << "|  25 - ADVENTURE                                                    |" << endl;
                        cout << "|  26 - MUSICAL                                                      |" << endl;
                        cout << "|  27 - WESTERN                                                      |" << endl;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "Digite o genero " << i + 1 << " que deseja: ";
                        cin >> escolhaGenero;

                        switch (escolhaGenero){
                            case 1:
                                generoSelecionado = "Action";
                                break;
                            
                            case 2:
                                generoSelecionado = "Animation";
                                break;

                            case 3:
                                generoSelecionado = "Comedy";
                                break;

                            case 4:
                                generoSelecionado = "Drama";
                                break;

                            case 5:
                                generoSelecionado = "History";
                                break;

                            case 6:
                                generoSelecionado = "Music";
                                break;

                            case 7:
                                generoSelecionado = "Short";
                                break;

                            case 8:
                                generoSelecionado = "Talk-Show";
                                break;

                            case 9:
                                generoSelecionado = "Biography";
                                break;

                            case 10:
                                generoSelecionado = "Documentary";
                                break;

                            case 11:
                                generoSelecionado = "News";
                                break;

                            case 12:
                                generoSelecionado = "Sci-Fi";
                                break;

                            case 13:
                                generoSelecionado = "Reality-TV";
                                break;
                        
                            case 14:
                                generoSelecionado = "Family";
                                break;

                            case 15:
                                generoSelecionado = "Adult";
                                break;

                            case 16:
                                generoSelecionado = "Game-Show";
                                break;

                            case 17:
                                generoSelecionado = "Horror";
                                break;

                            case 18:
                                generoSelecionado = "Thriller";
                                break;
                            
                            case 19:
                                generoSelecionado = "War";
                                break;

                            case 20:
                                generoSelecionado = "Crime";
                                break;  

                            case 21:
                                generoSelecionado = "Mystery";
                                break;  

                            case 22:
                                generoSelecionado = "Sport";
                                break;

                            case 23:
                                generoSelecionado = "Fantasy";
                                break;  
                            
                            case 24:
                                generoSelecionado = "Romance";
                                break;

                            case 25:
                                generoSelecionado = "Adventure";
                                break;

                            case 26:
                                generoSelecionado = "Musical";
                                break;

                            case 27:
                                generoSelecionado = "Western";
                                break;

                            default:
                                cout << "OPCAO INVALIDA"<< endl;
                                i--; 
                                continue; // Volta para o início do loop se a opção for inválida
                        }

                        generoBusca.push_back(generoSelecionado);
                        
                    }
                    system("clear");
                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                system("clear");
                        
            auto Cronometro_de_Filtro_Filmes = chrono::high_resolution_clock::now();

            //FILTRO DE FILMES
            Filtro::FiltroFilmes(filmes, FiltroFilmes, tipoBusca, anoInicio, anoFim, duracaoMinima, duracaoMaxima, generoBusca);

            auto Termina_Cronometro_Filtro_Filmes = chrono::high_resolution_clock::now();
            auto tempoDecorridoFiltro = Termina_Cronometro_Filtro_Filmes - Cronometro_de_Filtro_Filmes;
            cout << "- Tempo de execução do filtro: " << chrono::duration_cast<chrono::seconds>(tempoDecorridoFiltro).count() << " segundos" << endl;
            cout << "- Tempo de execução do filtro: " << chrono::duration_cast<chrono::milliseconds>(tempoDecorridoFiltro).count() << " milisegundos" << endl;

            //EXIBICAO DOS FILMES FILTRADOS
            cout << "______________________________________________________________________"<< endl;
            cout << "|>> O que deseja fazer com o resultado do filtro?                    |" << endl;
            cout << "|                                                                    |" << endl;
            cout << "|  1 - SALVAR EM ARQUIVO                                             |" << endl;
            cout << "|  2 - IMPRIMIR NO TERMINAL                                          |" << endl;
            cout << "______________________________________________________________________"<< endl;
            cout << "Digite a opção desejada: ";
            cin >> resposta;

            if(resposta == 1)
                salvaFiltroFilmes(FiltroFilmes);
            else{
                imprimirFiltroFilmes(FiltroFilmes);
            }
                break;
            }

            //BUSCA DE CINEMA
            case 2:{
                vector<Cinema> cinemasFiltrados;
                vector<string> tipoBuscaCinema;
                vector<string> generoBuscaCinema;
                vector<int> limiteDuracao = {-2, -2}; // -2 significa que não foi selecionado
                int distancia = -2;
                float preco = -2; 
                vector<int> limiteano = {-2, -2}; 
                tipoBuscaCinema.clear();
                generoBuscaCinema.clear();
                int pontoX = 0, pontoY = 0;
                int resposta, qntGenero, qntAux;

                //PESQUISAR FILTRO
                //BUSCA POR TIPO
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum tipo?                                    |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Quantos tipos deseja incluir no filtro?                          |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite a quantidade desejada:                                     |" << endl;   
                    cin >> qntAux;
                    cout << "______________________________________________________________________"<< endl;

                    for (int i = 0; i < qntAux; i++){
                        int escolhaTipo;
                        string tipoSelecionado;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "|                         Escolha o tipo                             |" << endl;
                        cout << "|  1 - MOVIE (FILME)                                                 |" << endl;
                        cout << "|  2 - SHORT (CURTA-METRAGEM)                                        |" << endl;
                        cout << "|  3 - TV SERIES (SERIES DE TV)                                      |" << endl;
                        cout << "|  4 - TV EPISODE (TELEFILME)                                        |" << endl;
                        cout << "|  5 - VIDEO                                                         |" << endl;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "Digite o tipo " << i + 1 << " que deseja: ";
                        cin >> escolhaTipo;

                        switch (escolhaTipo){
                            case 1:
                                tipoSelecionado = "movie";
                                break;
                            
                            case 2:
                                tipoSelecionado = "short";
                                break;

                            case 3:
                                tipoSelecionado = "tv series";
                                break;

                            case 4:
                                tipoSelecionado = "tvEpisode";
                                break;

                            case 5:
                                tipoSelecionado = "video";
                                break;

                            default:
                                cout << "OPCAO INVALIDA"<< endl;
                                i--; 
                                continue; 
                        }
                        
                        tipoBuscaCinema.push_back(tipoSelecionado);
                        
                    }
                    system("clear");
                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;

                system("clear");

                //BUSCA POR ANO
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Deseja filtrar por ano?                                          |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  1 - SIM                                                           |" << endl;
                    cout << "|  2 - NAO                                                           |" << endl;
                    cout << "______________________________________________________________________"<< endl;
                    cout << "Digite a opção desejada: ";
                    cin >> resposta;

                    if(resposta == 1){
                        int modo;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "|>> Escolha o modo de filtro de ano.                                 |" << endl;
                        cout << "|                                                                    |" << endl;
                        cout << "|  1 - ANO ESPECIFICO                                                |" << endl;
                        cout << "|  2 - INTERVALO DE ANOS                                             |" << endl;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "Digite a opção desejada: ";
                        cin >> modo;

                        switch (modo){
                            case 1:{
                                int anoEspecifico;
                                cout << "______________________________________________________________________"<< endl;
                                cout << "|>> Digite o ano especifico:                                         |" << endl;
                                cout << "|                                                                    |" << endl;
                                cout << "|  Digite o ano especifico:                                          |" << endl;
                                cin >> anoEspecifico;
                                cout << "______________________________________________________________________"<< endl;
                                limiteano[0] = anoEspecifico;
                                limiteano[1] = anoEspecifico; 
                                system("clear");
                                break;
                            }
                            case 2:{
                                cout << "______________________________________________________________________"<< endl;
                                cout << "|>> Digite o ano inicial:                                            |" << endl;
                                cout << "|                                                                    |" << endl;
                                cout << "|  Digite o ano inicial:                                             |" << endl;   
                                cin >> limiteano[0];
                                cout << "______________________________________________________________________"<< endl;
                                do{
                                    cout << "______________________________________________________________________"<< endl;
                                    cout << "|>> Digite o ano final:                                              |" << endl;
                                    cout << "|                                                                    |" << endl;
                                    cout << "|  Digite o ano final:                                               |" << endl;   
                                    cin >> limiteano[1];
                                    cout << "______________________________________________________________________"<< endl;

                                    if(limiteano[0] > limiteano[1]){
                                        cout << "Ano inicial maior que o final, tente novamente!" << endl;
                                    }
                                } while(limiteano[0] > limiteano[1]);
                                    system("clear");
                            }    
                            default:{
                                cout << "OPCAO INVALIDA"<< endl;
                                break;
                            }
                        }system("clear");
                    }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                    system("clear");

                //BUSCA POR DURACAO ESPECIFICA
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum filme com alguma duracao especifica?     |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Digite a duracao minima do filme:                                |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite a duracao minima:                                          |" << endl;   
                    cin >> limiteDuracao[0];
                    cout << "______________________________________________________________________"<< endl;

                    do{
                        cout << "______________________________________________________________________"<< endl;
                        cout << "|>> Digite a duracao maxima do filme:                                |" << endl;
                        cout << "|                                                                    |" << endl;
                        cout << "|  Digite a duracao maxima:                                          |" << endl;   
                        cin >> limiteDuracao[1];
                        cout << "______________________________________________________________________"<< endl;
                        
                        if(limiteDuracao[0] > limiteDuracao[1]){
                            cout << "Duracao minima maior que a maxima, tente novamente!" << endl;
                        }
                    } while(limiteDuracao[0] > limiteDuracao[1]);
                    system("clear");

                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                system("clear");

                //BUSCAR GENERO
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum genero?                                  |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Quantos generos deseja incluir no filtro?                        |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite a quantidade desejada:                                     |" << endl;   
                    cin >> qntGenero;
                    cout << "______________________________________________________________________"<< endl;

                    for(int i = 0; i < qntGenero; i++){
                        int escolhaGenero;
                        string generoSelecionado;

                        cout << "______________________________________________________________________"<< endl;
                        cout << "|                         Escolha o Genero                           |" << endl;
                        cout << "|  1 - ACTION                                                        |" << endl;
                        cout << "|  2 - ANIMATION                                                     |" << endl;
                        cout << "|  3 - COMEDY                                                        |" << endl;
                        cout << "|  4 - DRAMA                                                         |" << endl;
                        cout << "|  5 - HISTORY                                                       |" << endl;
                        cout << "|  6 - MUSIC                                                         |" << endl;
                        cout << "|  7 - SHORT                                                         |" << endl;
                        cout << "|  8 - TALK-SHOW                                                     |" << endl;
                        cout << "|  9 - BIOGRAPHY                                                     |" << endl;
                        cout << "|  10 - DOCUMENTARY                                                  |" << endl;
                        cout << "|  11 - NEWS                                                         |" << endl;
                        cout << "|  12 - SCI-FI                                                       |" << endl;
                        cout << "|  13 - REALITY-TV                                                   |" << endl;
                        cout << "|  14 - FAMILY                                                       |" << endl;
                        cout << "|  15 - ADULT                                                        |" << endl;
                        cout << "|  16 - GAME-SHOW                                                    |" << endl;
                        cout << "|  17 - HORROR                                                       |" << endl;
                        cout << "|  18 - THRILLER                                                     |" << endl;
                        cout << "|  19 - WAR                                                          |" << endl;
                        cout << "|  20 - CRIME                                                        |" << endl;
                        cout << "|  21 - MYSTERY                                                      |" << endl;
                        cout << "|  22 - SPORT                                                        |" << endl;
                        cout << "|  23 - FANTASY                                                      |" << endl;
                        cout << "|  24 - ROMANCE                                                      |" << endl;
                        cout << "|  25 - ADVENTURE                                                    |" << endl;
                        cout << "|  26 - MUSICAL                                                      |" << endl;
                        cout << "|  27 - WESTERN                                                      |" << endl;
                        cout << "______________________________________________________________________"<< endl;
                        cout << "Digite o genero " << i + 1 << " que deseja: ";
                        cin >> escolhaGenero;

                        switch (escolhaGenero){
                            case 1:
                                generoSelecionado = "Action";
                                break;
                            
                            case 2:
                                generoSelecionado = "Animation";
                                break;

                            case 3:
                                generoSelecionado = "Comedy";
                                break;

                            case 4:
                                generoSelecionado = "Drama";
                                break;

                            case 5:
                                generoSelecionado = "History";
                                break;

                            case 6:
                                generoSelecionado = "Music";
                                break;

                            case 7:
                                generoSelecionado = "Short";
                                break;

                            case 8:
                                generoSelecionado = "Talk-Show";
                                break;

                            case 9:
                                generoSelecionado = "Biography";
                                break;

                            case 10:
                                generoSelecionado = "Documentary";
                                break;

                            case 11:
                                generoSelecionado = "News";
                                break;

                            case 12:
                                generoSelecionado = "Sci-Fi";
                                break;

                            case 13:
                                generoSelecionado = "Reality-TV";
                                break;
                        
                            case 14:
                                generoSelecionado = "Family";
                                break;

                            case 15:
                                generoSelecionado = "Adult";
                                break;

                            case 16:
                                generoSelecionado = "Game-Show";
                                break;

                            case 17:
                                generoSelecionado = "Horror";
                                break;

                            case 18:
                                generoSelecionado = "Thriller";
                                break;
                            
                            case 19:
                                generoSelecionado = "War";
                                break;

                            case 20:
                                generoSelecionado = "Crime";
                                break;  

                            case 21:
                                generoSelecionado = "Mystery";
                                break;  

                            case 22:
                                generoSelecionado = "Sport";
                                break;

                            case 23:
                                generoSelecionado = "Fantasy";
                                break;  
                            
                            case 24:
                                generoSelecionado = "Romance";
                                break;

                            case 25:
                                generoSelecionado = "Adventure";
                                break;

                            case 26:
                                generoSelecionado = "Musical";
                                break;

                            case 27:
                                generoSelecionado = "Western";
                                break;

                            default:
                                cout << "OPCAO INVALIDA"<< endl;
                                i--; 
                                continue; 
                        }

                        generoBuscaCinema.push_back(generoSelecionado);
                        
                    }
                    system("clear");
                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                system("clear");


                //BUSCA POR DISTANCIA
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum cinema em uma distancia especifica?      |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){

                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Digite a distancia maxima:                                       |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite a distancia maxima:                                        |" << endl;   
                    cin >> distancia;
                    cout << "|>> Digite o ponto X:                                                |" << endl;
                    cin >> pontoX;
                    cout << "|>> Digite o ponto Y:                                                |" << endl;
                    cin >> pontoY;
                    cout << "|                                                                    |" << endl;
                    cout << "______________________________________________________________________"<< endl;
                    system("clear");
                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                system("clear");

                //BUSCA POR PRECO
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Deseja Buscar por algum cinema com um preco especifico?          |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SIM                                                           |" << endl;
                cout << "|  2 - NAO                                                           |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;

                if(resposta == 1){
                    cout << "______________________________________________________________________"<< endl;
                    cout << "|>> Digite o preco maximo:                                           |" << endl;
                    cout << "|                                                                    |" << endl;
                    cout << "|  Digite o preco maximo:                                            |" << endl;   
                    cin >> preco;
                    cout << "______________________________________________________________________"<< endl;
                    system("clear");
                }if(resposta != 1 && resposta != 2)
                        cout << " - OPÇÃO INCORRETA!!!" << endl << endl;
                    system("clear");

                auto Cronometro_de_Filtro_Cinema = chrono::high_resolution_clock::now();

                //FILTRO DE CINEMAS
                Filtro::FiltraCinema(cinemas, cinemasFiltrados, tipoBuscaCinema, generoBuscaCinema, limiteDuracao, distancia, preco, limiteano, pontoX, pontoY);

                auto Termina_Cronometro_Filtro_Cinema = chrono::high_resolution_clock::now();
                auto tempoDecorridoFiltroCinema = Termina_Cronometro_Filtro_Cinema - Cronometro_de_Filtro_Cinema;
                cout << "- Tempo de execução do filtro: " << chrono::duration_cast<chrono::seconds>(tempoDecorridoFiltroCinema).count() << " segundos" << endl;
                cout << "- Tempo de execução do filtro: " << chrono::duration_cast<chrono::milliseconds>(tempoDecorridoFiltroCinema).count() << " milisegundos" << endl;    

                //EXIBICAO DOS CINEMAS FILTRADOS
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> O que deseja fazer com o resultado do filtro?                    |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  1 - SALVAR EM ARQUIVO                                             |" << endl;
                cout << "|  2 - IMPRIMIR NO TERMINAL                                          |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << "Digite a opção desejada: ";
                cin >> resposta;
                if(resposta == 1)
                    salvaFiltroCinemas(cinemasFiltrados);
                else{
                    imprimirFiltroCinemas(cinemasFiltrados);
                }
                break;
            }

            //SAINDO DO PROGRAMA
            case 3:{
                cout << "______________________________________________________________________"<< endl;
                cout << "|>> Obrigado por utilizar o programa!                                |" << endl;
                cout << "|                                                                    |" << endl;
                cout << "|  Volte sempre!                                                     |" << endl;
                cout << "______________________________________________________________________"<< endl;
                cout << endl;

                break;
            }
        
            default:{
                cout << "OPCAO INVALIDA"<< endl; 
                break;
            }
        }
    }while(op != 3);

    auto terminoCronometro = chrono::high_resolution_clock::now();
    auto tempo_execucao_programa = terminoCronometro - cronometro;
    cout << "- Tempo de execução do Programa: " << chrono::duration_cast<chrono::seconds>(tempo_execucao_programa).count() << " segundos" << endl;
    cout << "- Tempo de execução do Programa: " << chrono::duration_cast<chrono::milliseconds>(tempo_execucao_programa).count() << " milisegundos" << endl;

    return 0;
}
