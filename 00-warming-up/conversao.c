#include <stdio.h>
#include <stdlib.h>

/*
    Em C, as diretivas de pré-processamento são comandos especiais 
    que o pré-processador interpreta antes da compilação do código. 
    Elas são identificadas pelo símbolo "#" no início da linha. 
    O pré-processador é um programa que examina o código-fonte e 
    realiza transformações textuais antes que o compilador gere o 
    código executável.
*/

#ifdef _WIN32
    #define LIMPAR_TELA "cls"
#else
    #define LIMPAR_TELA "clear"
#endif

/*
    O loop continua a ler e descartar caracteres até encontrar 
    o marcador de fim de arquivo (EOF) ou um caractere de 
    nova linha ('\n'). O marcador EOF indica que não há mais 
    caracteres para ler, enquanto o caractere de nova linha 
    normalmente significa o fim de uma linha de entrada.
*/
void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){

    int opcao = -1;
    float valor_real, cotacao_dolar, valor_dolar;
    
    printf("------------OBJETIVO-------------------\n");
    printf("Este algoritmo tem como objetivo converter um valor monetário de reais (BRL) para dólares (USD). \n");
    
    do{
        printf("\n--------- Menu ----------\n");
        printf("1 - Conversão de real para dólar\n");
        printf("0 - Sair do programa\n");
        printf("---------------------------\n");
        printf("Digite a opção desejada: ");
        int validar_valor_opcao = scanf("%d", &opcao);
        
        if (validar_valor_opcao == 1){
            
            if(opcao == 1){
                printf("Digite o valor em reais (ATENÇÃO: O valor informado deve ser um número (Ex.: 500; 923.43)): ");
                int validar_valor_real = scanf("%f", &valor_real);
                
                if (validar_valor_real == 1){
                    printf("Digite a cotação do dólar: (ATENÇÃO: O valor informado deve ser um número positivo (Ex.: 5.50).): ");
                    int validar_cotacao_dolar = scanf("%f", &cotacao_dolar);
                    
                    if (validar_cotacao_dolar == 1 && cotacao_dolar > 0){
                        valor_dolar = valor_real / cotacao_dolar;
                        printf("------------------------------\n");
                        printf("Valor em real: %.2f\n", valor_real);
                        printf("Cotação do dólar: %.2f\n", cotacao_dolar);
                        printf("O valor em dólares é: %.2f\n", valor_dolar);
                        printf("------------------------------\n");
                        //break;
                        opcao = 0;
                    }
                    else{
                        limpar_buffer();
                        system(LIMPAR_TELA);
                        printf("A cotacao informada não é válida.\nAperte <ENTER> para voltar ao menu inicial.\n");   
                        getchar();
                    }
                }
                else{
                    limpar_buffer();
                    system(LIMPAR_TELA);
                    printf("O valor informado não é válido.\nAperte <ENTER> para voltar ao menu inicial.\n");
                    getchar();
                }
            }
            else if(opcao == 0){
                system(LIMPAR_TELA);
                printf("Programa finalizado.\n");
            }
            else{
                limpar_buffer();
                system(LIMPAR_TELA);
                printf("A opcao informada não é válida.\nAperte <ENTER> para voltar ao menu inicial.");
                getchar();
            }
        }
        else{
            limpar_buffer(); // Limpa o buffer para não entrar em loop
            system(LIMPAR_TELA);
            printf("A opcao informada não é válida.\nAperte <ENTER> para voltar ao menu inicial.");
            getchar();
        }
    } while(opcao != 0);
    
    return 0;
}
