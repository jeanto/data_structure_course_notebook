#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main() {
    
    int opcao = -1;
    float salario_atual, novo_salario;
    
    printf("\n----------------𝐎𝐛𝐣𝐞𝐭𝐢𝐯𝐨------------------------------");
    printf("\nEste algoritmo tem como objetivo calcular e \nimprimir o valor do novo salário, sabendo \nque o funcionário recebeu um aumento de 25%%. \n");
    
    do{
        printf("\n----------------𝐄𝐧𝐭𝐫𝐚𝐝𝐚------------------------------\n");
        printf("1 - Calcular aumento de salário. \n");
        printf("0 - Sair. \n");
        printf("----------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
            float salario_minimo = 1509.00;
            printf("Digite o salário do funcionário (ATENÇÃO: O valor informado deve ser um número maior que %.2f): ", salario_minimo);
            int valida_salario = scanf("%f", &salario_atual);
            
            if(valida_salario == 1 && salario_atual > salario_minimo){
                novo_salario = salario_atual * 1.25;
                printf("----------------𝐒𝐚𝐢𝐝𝐚------------------------------\n");
                printf("Salário atual: R$ %.2f \n", salario_atual);
                printf("Novo salário: R$ %.2f \n", novo_salario);
                printf("----------------------------------------------------\n");
                //break;
                opcao = 0;
            }
            else{
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
    }while(opcao != 0);
        
    return 0;
}    
