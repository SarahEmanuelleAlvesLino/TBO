##############################################################################
# Makefile adaptado para projeto com diferentes implementações de listas
##############################################################################

# Arquivo principal
MAIN := main

# Lista de objetos
OBJECTS := $(MAIN).o ListaContigua.o ListaEncadeadaSimples.o ListaEncadeadaDupla.o

# Flags de compilação
FLAGS := -Wall -Wextra -std=c++17 -pedantic-errors
DEBUG := -g

# Compilador
CC := g++

# Definindo o nome do executável conforme o sistema operacional
ifeq ($(OS), Windows_NT)
OUTPUTMAIN := $(MAIN).exe
else
OUTPUTMAIN := $(MAIN).out
endif

# Regra padrão
all: $(OUTPUTMAIN)
	@echo Compilação concluída com sucesso!

# Regra de linkagem do executável
$(OUTPUTMAIN): $(OBJECTS)
	$(CC) $(FLAGS) $(DEBUG) $(OBJECTS) -o $(OUTPUTMAIN)

# Regras de compilação para cada arquivo
main.o: main.cpp ListaContigua.h ListaEncadeadaSimples.h ListaEncadeadaDupla.h
	$(CC) $(FLAGS) $(DEBUG) -c main.cpp

ListaContigua.o: ListaContigua.cpp ListaContigua.h
	$(CC) $(FLAGS) $(DEBUG) -c ListaContigua.cpp

ListaEncadeadaSimples.o: ListaEncadeadaSimples.cpp ListaEncadeadaSimples.h
	$(CC) $(FLAGS) $(DEBUG) -c ListaEncadeadaSimples.cpp

ListaEncadeadaDupla.o: ListaEncadeadaDupla.cpp ListaEncadeadaDupla.h
	$(CC) $(FLAGS) $(DEBUG) -c ListaEncadeadaDupla.cpp

# Limpeza dos arquivos objetos e executável
clean:
ifeq ($(OS), Windows_NT)
	del /Q *.o
	del /Q $(OUTPUTMAIN)
else
	rm -f *.o
	rm -f $(OUTPUTMAIN)
endif
	@echo Limpeza concluída!

# Regra para rodar o programa
run: all
	./$(OUTPUTMAIN)
