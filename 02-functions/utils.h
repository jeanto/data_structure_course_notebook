#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

typedef struct {
  int matricula;
  float nota1, nota2, nota3;
  float media;
} aluno;

void limpar_buffer();
void msg_erro(char *msg);
float media(float n1, float n2, float n3);
float media_struct(aluno al);
void media_ponteiro_notas(float *n1, float *n2, float *n3, float *media);
void media_ponteiro_struct(aluno *aluno1);

#endif // UTILS_H
