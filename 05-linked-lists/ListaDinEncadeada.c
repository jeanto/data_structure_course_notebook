#include "ListaDinEncadeada.h" //inclui os Prototipos

// Definição de macros para limpar a tela
void limpar_buffer(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
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


/**
 * @brief Cria e inicializa uma nova lista encadeada.
 * 
 * Esta função aloca dinamicamente memória para uma estrutura do tipo Lista
 * e inicializa o ponteiro interno da lista como NULL, indicando que a lista
 * está vazia no momento da criação.
 * 
 * @return Lista* Retorna um ponteiro para a nova lista criada. Caso a alocação
 * de memória falhe, retorna NULL.
 */
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

/**
 * @brief Calcula a média de um aluno e define seu status de aprovação.
 *
 * Esta função realiza a validação das notas do aluno, garantindo que
 * valores negativos sejam ajustados para zero. Em seguida, calcula a
 * média aritmética das duas notas e define o status de aprovação do
 * aluno com base na média calculada.
 *
 * @param aluno Ponteiro para a estrutura do tipo Aluno, que contém
 *              as notas, a média e o status de aprovação.
 *
 * @details
 * - Se a média for maior ou igual a 6.0, o status será definido como 1 (Aprovado).
 * - Caso contrário, o status será definido como 0 (Reprovado).
 */
 void calcular_media(Aluno *aluno) {
    // Validação das notas
    aluno->n1 = aluno->n1 < 0 ? 0 : aluno->n1;
    aluno->n2 = aluno->n2 < 0 ? 0 : aluno->n2;
    aluno->n3 = aluno->n3 < 0 ? 0 : aluno->n3;

    aluno->media = (aluno->n1 + aluno->n2 + aluno->n3) / 3.0;

    if (aluno->media >= 6.0) {
        aluno->status = 1; // Aprovado
    } else {
        aluno->status = 0; // Reprovado
    }
}


/**
 * @brief Insere um aluno no final da lista encadeada.
 * 
 * @param li Ponteiro para a lista encadeada.
 * @param al Estrutura do tipo Aluno contendo os dados do aluno a ser inserido.
 * @return int Retorna 1 se a inserção for bem-sucedida, ou 0 em caso de falha 
 * (como lista não inicializada ou falta de memória).
 */
int insere_lista_final(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;

    // Copia os dados do aluno para o novo nó
    no->dados = al;

    // Define o próximo nó como NULL, já que será o último da lista
    no->prox = NULL;

    // Verifica se a lista está vazia
    if((*li) == NULL){ // Caso a lista esteja vazia, insere o nó no início
        *li = no;
    } else {
        // Caso contrário, percorre a lista até encontrar o último nó
        Elemento *aux;
        aux = *li;

        // Itera até que o próximo nó seja NULL (último nó da lista)
        while(aux->prox != NULL){
            aux = aux->prox;
        }

        // Atualiza o próximo do último nó para apontar para o novo nó
        aux->prox = no;
    }
    return 1;
}

/**
 * @brief Insere um novo elemento no início de uma lista encadeada.
 * 
 * @param li Ponteiro para a lista encadeada onde o elemento será inserido.
 * @param al Estrutura do tipo Aluno contendo os dados a serem inseridos.
 * 
 * @return Retorna 1 se a inserção for bem-sucedida, ou 0 em caso de falha 
 *         (como ponteiro nulo ou falha na alocação de memória).
 */
int insere_lista_inicio(Lista* li, Aluno al){
    if(li == NULL) return 0;
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    // Verifica se a alocação de memória para o novo elemento falhou
    if(no == NULL) return 0;
    // Copia os dados do aluno para o novo elemento
    no->dados = al;       // Faz o novo elemento apontar para o primeiro elemento atual da lista
    no->prox = (*li);     // Atualiza o ponteiro da lista para que o novo elemento seja o primeiro
    *li = no;
    return 1;
}

/**
 * @brief Insere um elemento na lista encadeada de forma ordenada.
 * 
 * Esta função insere um novo elemento na lista encadeada de forma que 
 * a lista permaneça ordenada com base no campo `matricula` do tipo `Aluno`.
 * 
 * @param li Ponteiro para a lista encadeada (do tipo `Lista`).
 * @param al Estrutura do tipo `Aluno` contendo os dados a serem inseridos.
 * 
 * @return 
 * - 1: Caso a inserção seja bem-sucedida.
 * - 0: Caso ocorra algum erro (ex.: lista não inicializada ou falha na alocação de memória).
 * 
 * @note 
 * - Se a lista estiver vazia, o elemento será inserido no início.
 * - Se a lista já contiver elementos, o novo elemento será inserido na posição correta
 *   para manter a ordenação.
 */
int insere_lista_ordenada(Lista* li, Aluno al){
    return 0;
}



/**
 * @brief Calcula o tamanho de uma lista encadeada.
 * 
 * Esta função percorre uma lista encadeada simples e conta o número de 
 * elementos que ela contém. Se a lista estiver vazia ou o ponteiro para 
 * a lista for NULL, a função retorna 0.
 * 
 * @param li Ponteiro para a lista encadeada.
 *           Espera-se que seja um ponteiro para o início da lista.
 * 
 * @return int O número de elementos na lista encadeada.
 *             Retorna 0 se a lista for NULL ou estiver vazia.
 */
int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

/**
 * @brief Verifica se uma lista encadeada está vazia.
 *
 * Esta função verifica se a lista encadeada está vazia, retornando 1 (verdadeiro)
 * caso a lista esteja vazia ou seja nula, e 0 (falso) caso contrário.
 *
 * @param li Ponteiro para a lista encadeada a ser verificada.
 * 
 * @return int Retorna 1 se a lista estiver vazia ou nula, e 0 caso contrário.
 */
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}


/**
 * @brief Libera toda a memória alocada para a lista encadeada.
 * 
 * Esta função percorre a lista encadeada e libera a memória de cada nó,
 * garantindo que todos os recursos alocados sejam devidamente liberados.
 * 
 * @param li Ponteiro para a lista que será liberada.
 */
void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}


/**
 * @brief Imprime todos os elementos de uma lista encadeada.
 * 
 * Esta função percorre a lista encadeada e imprime os dados armazenados
 * em cada nó da lista. É necessário que a lista tenha sido previamente
 * inicializada e que os elementos estejam corretamente inseridos.
 * 
 * @param li Ponteiro para a lista encadeada que será impressa.
 */
void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;

    printf("\n");
    printf("%-10s | %-8s | %-8s | %-8s | %-8s | %-10s \n",
           " Matrícula", "N1", "N2", "N3", "MEDIA", "Status");
    printf("-----------|----------|----------|----------|----------|------------\n");

    /*
    printf("%-10s | %-30s | %-8s | %-8s | %-8s | %-8s | %-10s \n",
        " Matrícula", "Nome", "N1", "N2", "N3", "MEDIA", "Status");
    printf("-----------|--------------------------------|----------|----------|----------|------------\n");
    */

    while(no != NULL){

        if (no->dados.status == 0) { // Reprovado
            printf(RED_TEXT);
        }

        //printf("%-10d | %-30s | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10s",
        printf("%-10d | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10s",
            no->dados.matricula,
            no->dados.n1,
            no->dados.n2,
            no->dados.n3,
            no->dados.media,
            no->dados.status == 1 ? "Aprovado" : "Reprovado");
        if (no->dados.status == 0) {
            printf(RESET_TEXT);
        }
        printf("\n");

        no = no->prox;
    }
    printf("\n");
}


/**
 * @brief Remove um elemento da lista encadeada com base na matrícula fornecida.
 * 
 * Esta função busca um elemento na lista encadeada que possui a matrícula
 * especificada e o remove, ajustando os ponteiros para manter a integridade
 * da lista. Caso a lista esteja vazia ou o elemento não seja encontrado, 
 * a função retorna 0. Caso a remoção seja bem-sucedida, retorna 1.
 * 
 * @param li Ponteiro para a lista encadeada.
 * @param mat Matrícula do elemento a ser removido.
 * 
 * @return int Retorna 1 se o elemento foi removido com sucesso, ou 0 caso
 * a lista esteja vazia ou o elemento não seja encontrado.
 */
int remove_lista_mat(Lista* li, int mat){
    return 0;
}


/**
 * @brief Remove o primeiro elemento de uma lista encadeada.
 * 
 * Esta função remove o elemento que está no início de uma lista encadeada,
 * liberando a memória associada a ele e ajustando o ponteiro da lista para
 * apontar para o próximo elemento.
 * 
 * @param li Ponteiro para a lista encadeada.
 * 
 * @return Retorna 1 se o elemento foi removido com sucesso, ou 0 se a lista
 *         estiver vazia ou se o ponteiro da lista for nulo.
 */
int remove_lista_inicio(Lista* li){
    return 0;
}


/**
 * @brief Remove o último elemento de uma lista encadeada.
 * 
 * Esta função remove o último elemento de uma lista encadeada
 * alocada dinamicamente. Ela lida com casos em que a lista está
 * vazia ou possui apenas um elemento.
 * 
 * @param li Ponteiro para o ponteiro do início da lista.
 *           - Se a lista estiver vazia, *li deve ser NULL.
 * 
 * @return int 
 *         - 1 se o último elemento foi removido com sucesso.
 *         - 0 se a lista for NULL ou estiver vazia.
 * 
 * @note A função libera a memória alocada para o elemento removido.
 */
int remove_lista_final(Lista* li){
    return 0;
}



/**
 * @brief Consulta um elemento da lista encadeada com base na posição.
 * 
 * Esta função busca um elemento na lista encadeada a partir de sua posição
 * e armazena as informações do elemento encontrado na estrutura fornecida.
 * 
 * @param li Ponteiro para a lista encadeada.
 * @param pos Posição do elemento a ser consultado (iniciando em 1).
 * @param al Ponteiro para a estrutura onde os dados do elemento serão armazenados.
 * 
 * @return Retorna 1 se a consulta for bem-sucedida, 0 caso contrário.
 */
int consulta_lista_pos(Lista* li, int pos, Aluno *al){
    return 0;
}


/**
 * @brief Consulta um aluno na lista encadeada com base na matrícula.
 * 
 * @param li Ponteiro para a lista encadeada.
 * @param mat Número de matrícula do aluno a ser consultado.
 * @param al Ponteiro para a estrutura onde os dados do aluno serão armazenados, caso encontrado.
 * 
 * @return Retorna 1 se o aluno for encontrado, 0 caso contrário.
 */
int consulta_lista_mat(Lista* li, int mat, Aluno *al){
    return 0;
}
