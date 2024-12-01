#include <stdio.h>                                                                            /**Aluno: Estevão Florencio**/
#include <stdlib.h>
#include <time.h>

/**Estrutura do nó da árvore**/
typedef struct No {
    int chave;
    struct No *esquerda, *direita;
} No;

/**Função para criar um novo nó**/
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

/**Inserção na BST**/
No* inserirBST(No* raiz, int chave) {
    if (raiz == NULL)
        return criarNo(chave);

    if (chave < raiz->chave)
        raiz->esquerda = inserirBST(raiz->esquerda, chave);
    else if (chave > raiz->chave)
        raiz->direita = inserirBST(raiz->direita, chave);

    return raiz;
}

/**Mostra a estrutura da árvore**/
void exibirArvore(No* raiz, int nivel) {
    if (raiz != NULL) {
        exibirArvore(raiz->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) 
            printf("   "); /**Recuo para indicar o nível**/
        printf("%d\n", raiz->chave);
        exibirArvore(raiz->esquerda, nivel + 1);
    }
}

int main() {
    No* raizBST = NULL;
    int numeros[50];

    /**Inicializa o gerador de números aleatórios**/
    srand(time(NULL));

    printf("Números gerados: ");
    for (int i = 0; i < 50; i++) {
        numeros[i] = rand() % 100;
        printf("%d ", numeros[i]);
        raizBST = inserirBST(raizBST, numeros[i]);
    }
    printf("\n\nEstrutura da BST:\n");
    exibirArvore(raizBST, 0);

    return 0;
}

