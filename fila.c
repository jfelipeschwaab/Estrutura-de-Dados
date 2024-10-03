#include <stdio.h>
#include <stdlib.h>


#define MAX 50

typedef struct {
    int itens[MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

void iniciarFIla(Fila *f){
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}


int filaEstaCheia(Fila *f) {
    return f->tamanho == MAX;
}

int filaEstaVazia(Fila *f) {
    return f->tamanho == 0;
}

void enqueue(Fila *f, int elemento){
    if(filaEstaCheia(f)){
        printf("Erro: Fila Cheia!");
        return -1;
    }

    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = elemento;
    f->tamanho++;
    printf("Elemento %d inserido na fila.\n", elemento);
}


int dequeue(Fila *f) {
    if(filaEstaVazia(f)) {
        printf("Erro: Fila vazia!");
        return -1;
    }

    int elementoRemovido = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho --;
    printf("Elemento %d removido da fila. \n", elementoRemovido);
    return elementoRemovido;
    
}

int frente(Fila *f) {
    if (filaEstaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->itens[f->frente];
}

int main() {
    Fila f;
    iniciarFIla(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);
    enqueue(&f, 40);
    printf("Elemento da frente: %d\n", frente(&f));
    printf("Retirando o primeiro da fila, seguindo os padroes FIFO(First in, First Out)\n");
    dequeue(&f);
    printf("Novo Elemento da frente: %d\n", frente(&f));
    printf("Retirando o primeiro da fila, seguindo os padroes FIFO(First in, First Out)\n");
    dequeue(&f);
    printf("Retirando o primeiro da fila, seguindo os padroes FIFO(First in, First Out)\n");
    printf("Novo Elemento da frente: %d", frente(&f));



    

    
}