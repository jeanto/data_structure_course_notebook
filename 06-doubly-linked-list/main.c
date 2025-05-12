#include "ListaDinEncadeadaDupla.c"

void info_lista(int t, int v){
    printf("Tamanho: \t%d \nLista Vazia: \t%d\n", t, v);
}

Aluno* carrega_dados() {
    // Aloca memória para 10 estruturas do tipo Aluno
    Aluno* dados_alunos = (Aluno*)malloc(10 * sizeof(Aluno));
    if (dados_alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Inicializa o array
    dados_alunos[0] = (Aluno){11, "Andre Santos", 9.5, 7.8, 5.6, 0.0};
    dados_alunos[1] = (Aluno){22, "Maria Silva", 8.0, 7.5, 4.5, 0.0};
    dados_alunos[2] = (Aluno){33, "Joao Pereira", 6.5, 8.2, 6.0, 0.0};
    dados_alunos[3] = (Aluno){44, "Ana Costa", 9.0, 9.1, 7.1, 0.0};
    dados_alunos[4] = (Aluno){55, "Carlos Oliveira", 7.5, 6.8, 4.5, 0.0};
    dados_alunos[5] = (Aluno){66, "Fernanda Lima", 8.8, 9.0, 6.7, 0.0};
    dados_alunos[6] = (Aluno){77, "Paulo Souza", 7.0, 7.3, 7.6, 0.0};
    dados_alunos[7] = (Aluno){88, "Juliana Mendes", 8.5, 8.7, 3.4, 0.0};
    dados_alunos[8] = (Aluno){90, "Ricardo Alves", 6.9, 7.4, 5.0, 0.0};
    dados_alunos[9] = (Aluno){91, "Beatriz Rocha", 9.2, 8.6, 6.0, 0.0};

    return dados_alunos;
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
        printf("3 - Consultar Aluno. \n");
        printf("4 - Trocar Alunos. \n");
        printf("5 - Imprimir Alunos. \n");
        printf("6 - Carregar dados. \n");
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
                    printf("\n----------------Tipos de Inserção------------------\n");
                    printf("1 - Inserir no início da lista. \n");
                    printf("2 - Inserir no final da lista. \n");
                    printf("3 - Inserir ordenado por matrícula. \n");
                    printf("0 - Voltar. \n");
                    printf("----------------------------------------------------\n");
                    printf("Digite a opção desejada: ");
                    scanf("%d", &opcao_inserir);

                    // Inserção na Lista
                    info_lista(tamanho_lista(li), lista_vazia(li));

                    int retorno = 0;
                    if (opcao_inserir == 1){
                        retorno = insere_lista_inicio(li, al);
                    }
                    else if (opcao_inserir == 2){
                        retorno = insere_lista_final(li, al);
                    }
                    else if (opcao_inserir == 3){
                        retorno = insere_lista_ordenada(li, al);
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

            system(LIMPAR_TELA);

            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));

            int opcao_remover = -1;
            printf("\n----------------Tipos de Remoção------------------\n");
            printf("1 - Remover no início da lista. \n");
            printf("2 - Remover no final da lista. \n");
            printf("3 - Remover por matrícula. \n");
            printf("0 - Voltar. \n");
            printf("----------------------------------------------------\n");
            printf("Digite a opção desejada: ");
            scanf("%d", &opcao_remover);

            int retorno = 0;
            if (opcao_remover == 1){
                retorno = remove_lista_inicio(li);
            }
            else if (opcao_remover == 2){
                retorno = remove_lista_final(li);
            }
            else if (opcao_remover == 3){

                int matricula;
                printf("Digite a matrícula do aluno: ");
                int valida_matricula = scanf("%d", &matricula);

                if (valida_matricula){
                    if (matricula >= 0){     
                        retorno = remove_lista_mat(li, matricula);
                    } else {
                        msg_erro("Matrícula inválida. Deve ser maior que 0. \n");
                    }
                }
            }
            else if (opcao_remover == 0){
                system(LIMPAR_TELA);
                printf("Voltando ao menu inicial.\n");   
            }                     
            else{
                msg_erro("Opção inválida. \n");
            }

            system(LIMPAR_TELA);

            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));
        }
        else if(opcao == 3){

            Elemento *elemento_encontrado;

            system(LIMPAR_TELA);

            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));

            int opcao_buscar = -1;
            printf("\n----------------Buscar Aluno------------------\n");
            printf("1 - Buscar pela matrícula. \n");
            printf("2 - Buscar pela posição. \n");
            printf("0 - Voltar. \n");
            printf("----------------------------------------------------\n");
            printf("Digite a opção desejada: ");
            scanf("%d", &opcao_buscar);

            if (opcao_buscar == 1){
                int matricula;
                printf("Digite a matrícula do aluno: ");
                int valida_matricula = scanf("%d", &matricula);

                if (valida_matricula){
                    if (matricula >= 0){     
                        if (busca_lista_mat(li, matricula, &aluno_encontrado)){
                            system(LIMPAR_TELA);
                            imprime_aluno(&elemento_encontrado->dados);
                        } else {
                            msg_erro("Matrícula não encontrada. \n");
                        }
                    } else {
                        msg_erro("Matrícula inválida. Deve ser maior que 0. \n");
                    }
                }
            }
            else if (opcao_buscar == 2){
                int posicao;
                printf("Digite a posicao do aluno: ");
                int valida_posicao = scanf("%d", &posicao);

                if (valida_posicao){
                    if (posicao >= 0){     
                        if (busca_lista_pos(li, posicao, &aluno_encontrado)){
                            system(LIMPAR_TELA);
                            imprime_aluno(&elemento_encontrado->dados);
                        } else {
                            msg_erro("Posição não encontrada. \n");
                        }
                    } else {
                        msg_erro("Posição inválida. Deve ser maior que 0. \n");
                    }
                }
            }
            else if (opcao_buscar == 0){
                system(LIMPAR_TELA);
                printf("Voltando ao menu inicial.\n");   
            }                     
            else{
                msg_erro("Opção inválida. \n");
            }
        }
        else if(opcao == 4){

            system(LIMPAR_TELA);

            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));

            int retorno = 0;
            int matricula1, matricula2;
            printf("Digite a matrícula do primeiro aluno: ");
            int valida_matricula1 = scanf("%d", &matricula1);
            printf("Digite a matrícula do segundo aluno: ");
            int valida_matricula2 = scanf("%d", &matricula2);
            if (valida_matricula1 == 1 && valida_matricula2 == 1){
                if (matricula1 >= 0 && matricula2 >= 0){     
                    retorno = troca_elementos_lista(li, matricula1, matricula2);
                } else {
                    msg_erro("Matrícula inválida. Deve ser maior que 0. \n");
                }
            } else {
                msg_erro("Valor inválido. Os valores precisam ser números.\n");
            }

            system(LIMPAR_TELA);

            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));
        }
        else if(opcao == 5){
            system(LIMPAR_TELA);
            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));
        }
        else if(opcao == 6){

            int total_alunos = 10; // Número fixo de alunos carregados em carrega_dados()
            Aluno* dados_alunos = carrega_dados();

            for (int i = 0; i < total_alunos; i++) {
                calcular_media(&dados_alunos[i]);
                insere_lista_final(li, dados_alunos[i]);
            }

            system(LIMPAR_TELA);
            if (lista_vazia(li)) 
                printf("Dados não carregados.\n");
            else
                printf("Dados carregados e inseridos na lista com sucesso.\n");
            imprime_lista(li);
            info_lista(tamanho_lista(li), lista_vazia(li));
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
