# Define o compilador C++
CXX = g++

# Define as flags de compilação
# -std=c++11: Usa o padrão C++11 (importante para recursos modernos de C++)
# -Wall: Habilita todos os avisos do compilador (recomendado para boas práticas)
# -g: Inclui informações de depuração no executável
CXXFLAGS = -std=c++11 -Wall -g

# Define o nome do executável final
EXECUTABLE = meu_programa

# Lista todos os arquivos-fonte (.cpp)
SOURCES = main.cpp Filmes.cpp Filtro.cpp Cinema.cpp

# Gera automaticamente a lista de arquivos de objeto (.o) a partir dos fontes
OBJECTS = $(SOURCES:.cpp=.o)

#
# Regras do Makefile
#

# A regra padrão (executada quando você digita apenas "make")
# Depende do executável
all: $(EXECUTABLE)

# Regra para linkar os arquivos de objeto e criar o executável final
# $@ representa o nome do alvo (nesse caso, $(EXECUTABLE))
# $^ representa a lista de todas as dependências (nesse caso, $(OBJECTS))
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra genérica para compilar arquivos .cpp em arquivos .o
# $< representa a primeira dependência (o arquivo .cpp correspondente)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#
# Dependências dos arquivos de objeto
# Isso garante que um arquivo .o seja recompilado se um dos cabeçalhos (.h) que ele inclui for modificado.
#
main.o: main.cpp Filtro.h Filmes.h Cinema.h
Cinema.o: Cinema.cpp Cinema.h Filmes.h Filtro.h
Filmes.o: Filmes.cpp Filmes.h
Filtro.o: Filtro.cpp Filtro.h Filmes.h 

#
# Regras "Phony" (não representam arquivos)
#

# Regra para limpar os arquivos compilados (objetos e executável)
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Declara as regras que não geram arquivos com o mesmo nome
.PHONY: all clean