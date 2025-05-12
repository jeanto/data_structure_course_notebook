#ifndef LISTADINENCADEADADUPLA_H
#define LISTADINENCADEADADUPLA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Códigos de cor terminal
#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

typedef struct Aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3, media;
    int status;
} Aluno;

//Definicao do tipo lista
typedef struct Elemento{
    struct Elemento *ant;
    Aluno dados;
    struct Elemento *prox;
} Elemento;

typedef Elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);

int insere_lista_inicio(Lista* li, Aluno al);
int insere_lista_final(Lista *li, Aluno al);
int insere_lista_ordenada(Lista* li, Aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int remove_lista_mat(Lista* li, int mat);
int busca_lista_mat(Lista* li, int mat, Elemento **elem);
int busca_lista_pos(Lista* li, int pos, Elemento **elem);
int troca_elementos_lista(Lista* li, int mat1, int mat2);

int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
void imprime_aluno(Aluno *al);

void limpar_buffer();
void msg_erro(char *msg);
void calcular_media(Aluno *aluno);

#endif
