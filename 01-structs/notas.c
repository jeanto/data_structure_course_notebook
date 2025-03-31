#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

struct aluno {
    int matricula;
    float nota1, nota2, nota3;
    float media;
};

void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    
    int opcao = -1;
    
    printf("\n----------------𝐎𝐛𝐣𝐞𝐭𝐢𝐯𝐨------------------------------");
    printf("O objetivo deste programa é armazenar \na matrícula e 3 notas para um dado aluno e, \nem seguida, calcular e armazenar a média.\n");

    do{
        printf("\n----------------𝐄𝐧𝐭𝐫𝐚𝐝𝐚------------------------------\n");
        printf("1 - Calcular aumento de salário. \n");
        printf("0 - Sair. \n");
        printf("----------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
            struct aluno aluno1;
            printf("Digite a matrícula do aluno: ");
            int valida_matricula = scanf("%d", &aluno1.matricula);
            printf("Digite a primeira nota do aluno: ");
            int valida_nota1 = scanf("%f", &aluno1.nota1);
            printf("Digite a segunda nota do aluno: ");
            int valida_nota2 = scanf("%f", &aluno1.nota2);
            printf("Digite a terceira nota do aluno: ");
            int valida_nota3 = scanf("%f", &aluno1.nota3);
            
            if (valida_matricula == 1 && valida_nota1 == 1 && valida_nota2 == 1 && valida_nota3 == 1){
                if (aluno1.matricula >= 0 && aluno1.nota1 >= 0 && aluno1.nota1 <= 10 && aluno1.nota2 >= 0 && aluno1.nota2 <= 10 && aluno1.nota3 >= 0 && aluno1.nota3 <= 10){
                    system(LIMPAR_TELA);
                    aluno1.media = (aluno1.nota1 + aluno1.nota2 + aluno1.nota3) / 3.0;
                    printf("----------------𝐒𝐚𝐢𝐝𝐚------------------------------\n");
                    printf("Matricula: %d\n", aluno1.matricula);
                    printf("Nota 1: %.2f\n", aluno1.nota1);
                    printf("Nota 2: %.2f\n", aluno1.nota2);
                    printf("Nota 3: %.2f\n", aluno1.nota3);
                    printf("Media: %.2f\n", aluno1.media);
                    printf("----------------------------------------------------\n");
                    opcao = 0;
                } else {
                    limpar_buffer();
                    system(LIMPAR_TELA);
                    printf("\n----------------𝐄𝐫𝐫𝐨-----------------------------\n");
                    printf("Valor inválido. As notas devem ser entre 0 e 10. \n");
                    printf("------------------------------------------------\n");
                    printf("\nAperte <ENTER> para voltar ao menu principal.");
                    getchar();
                }
            } else {
                limpar_buffer();
                system(LIMPAR_TELA);
                printf("\n----------------𝐄𝐫𝐫𝐨-----------------------------\n");
                printf("Valor inválido. \n");
                printf("------------------------------------------------\n");
                printf("\nAperte <ENTER> para voltar ao menu principal.");
                getchar();
            }
        }
        else if(opcao == 0){
            system(LIMPAR_TELA);
            printf("Programa finalizado.\n");
        }        
        else {
            limpar_buffer();
            system(LIMPAR_TELA);
            printf("\n----------------𝐄𝐫𝐫𝐨-----------------------------\n");
            printf("Opção inválida. \n");
            printf("------------------------------------------------\n");
            printf("\nAperte <ENTER> para voltar ao menu principal.");
            getchar();
        }
    } while(opcao != 0);

    return 0;
}
