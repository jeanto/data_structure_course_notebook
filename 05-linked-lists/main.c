#include "ListaDinEncadeada.c"

void info_lista(int t, int v){
    printf("Tamanho: \t%d \nLista Vazia: \t%d\n", t, v);
}

int main() {

    Lista* li = cria_lista();

    int opcao = -1;

    printf("\n----------------𝐎𝐛𝐣𝐞𝐭𝐢𝐯𝐨------------------------------\n");
    printf("O objetivo deste programa é armazenar \na matrícula e 2 notas para um dado aluno e, \nem seguida, calcular e armazenar a média.\n");

    do{
        printf("\n----------------𝐄𝐧𝐭𝐫𝐚𝐝𝐚------------------------------\n");
        printf("1 - Inserir Aluno. \n");
        printf("2 - Remover Aluno. \n");
        printf("3 - Carregar dados. \n");
        printf("0 - Sair. \n");
        printf("----------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        if(opcao == 1){       

            Aluno al;

            printf("Digite a matrícula do aluno: ");
            int valida_matricula = scanf("%d", &al.matricula);
            printf("Digite a primeira nota do aluno: ");
            int valida_nota1 = scanf("%f", &al.n1);
            printf("Digite a segunda nota do aluno: ");
            int valida_nota2 = scanf("%f", &al.n2);
            printf("Digite a terceira nota do aluno: ");
            int valida_nota3 = scanf("%f", &al.n3);

            if (valida_matricula == 1 && 
                valida_nota1 == 1 && 
                valida_nota2 == 1 &&
                valida_nota3 == 1 ){

                if (al.matricula >= 0 && 
                    al.n1 >= 0 && 
                    al.n1 <= 10 && 
                    al.n2 >= 0 && 
                    al.n2 <= 10 &&
                    al.n3 >= 0 && 
                    al.n3 <= 10){

                    // Calcula a média
                    calcular_media(&al);

                    int opcao_inserir = -1;
                    printf("\n----------------Tipo de Inserção------------------\n");
                    printf("1 - Inserir no início da lista. \n");
                    printf("2 - Inserir no final da lista. \n");
                    printf("3 - Inserir ordenado por matrícula. \n");
                    printf("0 - Voltar. \n");
                    printf("----------------------------------------------------\n");
                    printf("Digite a opção desejada: ");
                    scanf("%d", &opcao_inserir);

                    // Inserção na Lista
                    info_lista(tamanho_lista(li), lista_vazia(li));

                    if (opcao_inserir == 1){
                        insere_lista_inicio(li, al);
                    }
                    else if (opcao_inserir == 2){
                        insere_lista_final(li, al);
                    }
                    else if (opcao_inserir == 3){
                        insere_lista_ordenada(li, al);
                    }
                    else if (opcao_inserir == 0){
                        system(LIMPAR_TELA);
                        printf("Voltando ao menu inicial.\n");   
                    }                     
                    else{
                        msg_erro("Opção inválida. \n");
                    }

                    system(LIMPAR_TELA);

                    imprime_lista(li);
                    info_lista(tamanho_lista(li), lista_vazia(li));

                } else {
                    msg_erro("Valor inválido. As notas devem ser entre 0 e 10. \n");
                }
            } else {
                msg_erro("Valor inválido. Os valores precisam ser números.\n");
            }
        }
        else if(opcao == 2){
            return 0;
        }
        else if(opcao == 3){
            return 0;
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
