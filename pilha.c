#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef struct {
    int topo;
    int elementos[MAX];
} Pilha;


void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return (p->topo == -1); //Se o topo for igual a -1, retorna True
}

int pilhaCheia(Pilha *p) {
    return (p->topo == MAX - 1); //Se o topo for igual a 99, então a pilha está cheia
}

void push(Pilha *p, int elemento) {
    if(pilhaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }

    p->topo++;
    p->elementos[p->topo] = elemento;
}


int pop(Pilha *p) {
    if(pilhaVazia(p)) {
        printf("Erro: Pilha vazia!");
        return;
    }

    int elementoRemovido = p->elementos[p->topo];
    p->topo--;
    return elementoRemovido;
}

int topo(Pilha *p) {
    if(pilhaVazia(p)){
        printf("Erro: Pilha vazia!");
        return;
    }

    return p->elementos[p->topo];
}


int main() {
    Pilha pilhaTeste;
    inicializarPilha(&pilhaTeste);

    push(&pilhaTeste, 8);
    printf("Elemento do topo: %d\n", topo(&pilhaTeste));
    printf("Adicionando o elemento 10 ao topo\n");
    push(&pilhaTeste, 10);
    printf("Novo Elemento do topo: %d\n", topo(&pilhaTeste));
    printf("Tirando o elemento do topo: %d\n", topo(&pilhaTeste));
    pop(&pilhaTeste);
    printf("Novo Elemento do topo: %d\n", topo(&pilhaTeste));

}