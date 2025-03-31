#include "utils.h"

void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

float media(float n1, float n2, float n3){
    float med = (n1 + n2 + n3) / 3.0;
    return med;
    //return (n1 + n2 + n3) / 3.0;
}

float media_struct(aluno al){
    return (al.nota1 + al.nota2 + al.nota3) / 3.0;
}

void media_ponteiro_notas(float *n1, float *n2, float *n3, float *media){
    *media = (*n1 + *n2 + *n3) / 3.0;
}

void media_ponteiro_struct(aluno *aluno1){
    aluno1->media = (aluno1->nota1 + aluno1->nota2 + aluno1->nota3) / 3.0;
}

void msg_erro(char *msg){
    limpar_buffer();
    system(LIMPAR_TELA);
    printf("\n----------------Erro------------------------------\n");
    printf("%s", msg);
    printf("----------------------------------------------------\n");
    printf("\nAperte <ENTER> para voltar ao menu principal.");
    getchar();
}