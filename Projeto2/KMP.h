#ifndef KMP_H
#define KMP_H

#include <vector>

extern int acessouuuuu; // Variável global para contar a quantidade de acessos ao arquivo

void kmp(const char* textoAchado, const char* padroes, int linha);
void imprimi(const char* texto, int inicio, int fim, int linha);


#endif