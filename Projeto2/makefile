##############################################################################
# Makefile para o Projeto 2 - Algoritmos de Busca de Padrões
##############################################################################

# Arquivo principal
MAIN := main

# Lista de objetos
OBJECTS := $(MAIN).o KMP.o aho_Corasick.o

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
main.o: main.cpp KMP.h aho_Corasick.h
	$(CC) $(FLAGS) $(DEBUG) -c main.cpp

KMP.o: KMP.cpp KMP.h
	$(CC) $(FLAGS) $(DEBUG) -c KMP.cpp

aho_Corasick.o: aho_Corasick.cpp aho_Corasick.h
	$(CC) $(FLAGS) $(DEBUG) -c aho_Corasick.cpp

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

# Garante que as regras 'all', 'clean' e 'run' funcionem mesmo que existam
# arquivos com esses nomes
.PHONY: all clean run