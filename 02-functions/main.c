#include "utils.h"

int main() {
    
    int opcao = -1;
    
    printf("\n----------------𝐎𝐛𝐣𝐞𝐭𝐢𝐯𝐨------------------------------\n");
    printf("O objetivo deste programa é armazenar \na matrícula e 3 notas para um dado aluno e, \nem seguida, calcular e armazenar a média.\n");

    do{
        printf("\n----------------𝐄𝐧𝐭𝐫𝐚𝐝𝐚------------------------------\n");
        printf("1 - Calcular a média do aluno Alef. \n");
        printf("0 - Sair. \n");
        printf("----------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
            aluno aluno1;
            printf("Digite a matrícula do aluno: ");
            int valida_matricula = scanf("%d", &aluno1.matricula);
            printf("Digite a primeira nota do aluno: ");
            int valida_nota1 = scanf("%f", &aluno1.nota1);
            printf("Digite a segunda nota do aluno: ");
            int valida_nota2 = scanf("%f", &aluno1.nota2);
            printf("Digite a terceira nota do aluno: ");
            int valida_nota3 = scanf("%f", &aluno1.nota3);
            aluno1.media = 0;
            
            if (valida_matricula == 1 && valida_nota1 == 1 && valida_nota2 == 1 && valida_nota3 == 1){
                if (aluno1.matricula >= 0 && aluno1.nota1 >= 0 && aluno1.nota1 <= 10 && aluno1.nota2 >= 0 && aluno1.nota2 <= 10 && aluno1.nota3 >= 0 && aluno1.nota3 <= 10){
                    system(LIMPAR_TELA);

                    // Criar função para calcular a média do aluno usando passagem por valor e por referência
                    //aluno1.media = media(aluno1.nota1, aluno1.nota2, aluno1.nota3);
                    //printf("%f\n", aluno1.media);
                    //aluno1.media = media_struct(aluno1); 
                    //media_ponteiro_notas(&aluno1.nota1, &aluno1.nota2, &aluno1.nota3, &aluno1.media);
                    //printf("%f\n", aluno1.media);

                    media_ponteiro_struct(&aluno1);
                    printf("%f\n", aluno1.media);

                    //printf("%ld", sizeof(aluno1));

                    // Criar função para imprimir os dados do aluno (relatório)	
                    printf("----------------𝐒𝐚𝐢𝐝𝐚------------------------------\n");
                    printf("Matricula: \t %d\n", aluno1.matricula);
                    printf("Nota 1: \t %.2f\n", aluno1.nota1);
                    printf("Nota 2: \t %.2f\n", aluno1.nota2);
                    printf("Nota 3: \t %.2f\n", aluno1.nota3);
                    printf("Media:  \t %.2f\n", aluno1.media);
                    printf("----------------------------------------------------\n");
                    opcao = 0;
                } else {
                    msg_erro("Valor inválido. As notas devem ser entre 0 e 10. \n");
                }
            } else {
                msg_erro("Valor inválido. Os valores precisam ser números.\n");
            }
        }
        else if(opcao == 0){
            system(LIMPAR_TELA);
            printf("Programa finalizado.\n");
        }        
        else {
            msg_erro("Opção inválida. \n");
        }
    } while(opcao != 0);

    return 0;
}


