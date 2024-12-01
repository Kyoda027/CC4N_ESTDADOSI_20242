#include <stdio.h>                                                                      /*Estevão Florencio*/
#include <stdlib.h>
#include <time.h>

/* Estrutura do nó da árvore AVL */
typedef struct No {
    int chave;
    struct No *esquerda, *direita;
    int altura;
} No;

/* Função para criar um novo nó */
No* criarNo(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = novoNo->direita = NULL;
    novoNo->altura = 1; // Altura inicial
    return novoNo;
}

/* Função auxiliar para obter a altura de um nó */
int obterAltura(No* no) {
    return no ? no->altura : 0;
}

/* Função para obter o maior valor entre dois números */
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Função para obter o fator de balanceamento de um nó */
int obterBalanceamento(No* no) {
    return no ? obterAltura(no->esquerda) - obterAltura(no->direita) : 0;
}

/* Rotação à direita */
No* rotacaoDireita(No* y) {
    No* x = y->esquerda;
    No* T2 = x->direita;

    /* Executa a rotação */
    x->direita = y;
    y->esquerda = T2;

    /* Atualiza as alturas */
    y->altura = max(obterAltura(y->esquerda), obterAltura(y->direita)) + 1;
    x->altura = max(obterAltura(x->esquerda), obterAltura(x->direita)) + 1;

    return x; // Novo nó raiz após a rotação
}

/* Rotação à esquerda */
No* rotacaoEsquerda(No* x) {
    No* y = x->direita;
    No* T2 = y->esquerda;

    /* Executa a rotação */
    y->esquerda = x;
    x->direita = T2;

    /* Atualiza as alturas */
    x->altura = max(obterAltura(x->esquerda), obterAltura(x->direita)) + 1;
    y->altura = max(obterAltura(y->esquerda), obterAltura(y->direita)) + 1;

    return y; // Novo nó raiz após a rotação
}

/* Inserção na AVL com balanceamento */
No* inserirAVL(No* raiz, int chave) {
    /* Passo 1: Inserção normal em árvore binária */
    if (raiz == NULL)
        return criarNo(chave);

    if (chave < raiz->chave)
        raiz->esquerda = inserirAVL(raiz->esquerda, chave);
    else if (chave > raiz->chave)
        raiz->direita = inserirAVL(raiz->direita, chave);
    else
        return raiz; /* Chaves duplicadas não são permitidas */

    /* Passo 2: Atualizar altura do nó */
    raiz->altura = 1 + max(obterAltura(raiz->esquerda), obterAltura(raiz->direita));

    /* Passo 3: Verificar o fator de balanceamento */
    int balanceamento = obterBalanceamento(raiz);

    /* Caso 1: Desbalanceamento para a esquerda (Rotação à direita) */
    if (balanceamento > 1 && chave < raiz->esquerda->chave)
        return rotacaoDireita(raiz);

    /* Caso 2: Desbalanceamento para a direita (Rotação à esquerda) */
    if (balanceamento < -1 && chave > raiz->direita->chave)
        return rotacaoEsquerda(raiz);

    /* Caso 3: Desbalanceamento esquerda-direita (Rotação esquerda-direita) */
    if (balanceamento > 1 && chave > raiz->esquerda->chave) {
        raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
        return rotacaoDireita(raiz);
    }

    /* Caso 4: Desbalanceamento direita-esquerda (Rotação direita-esquerda) */
    if (balanceamento < -1 && chave < raiz->direita->chave) {
        raiz->direita = rotacaoDireita(raiz->direita);
        return rotacaoEsquerda(raiz);
    }

    return raiz; /* Retorna o nó raiz atualizado */
}

/* Função para exibir a árvore AVL */
void exibirArvore(No* raiz, int nivel) {
    if (raiz != NULL) {
        exibirArvore(raiz->direita, nivel + 1);
        for (int i = 0; i < nivel; i++) 
            printf("   "); // Recuo para indicar o nível
        printf("%d\n", raiz->chave);
        exibirArvore(raiz->esquerda, nivel + 1);
    }
}

int main() {
    No* raizAVL = NULL;
    int numeros[10];

    srand(time(NULL));

    printf("Números gerados: ");
    for (int i = 0; i < 10; i++) {
        numeros[i] = rand() % 100;
        printf("%d ", numeros[i]);
        raizAVL = inserirAVL(raizAVL, numeros[i]);
    }
    printf("\n\nEstrutura da AVL:\n");
    exibirArvore(raizAVL, 0);

    return 0;
}
