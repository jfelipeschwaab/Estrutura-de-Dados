#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int data;
    struct Node* next_node;

} Node;


/*
Aqui, eu tenho uma função que irá me retornar um ponteiro para a struct do tipo Nó. Dentro dessa função
eu crio um novo nó, que é um ponteiro que aponta para a memória reservada pelo malloc, o malloc reserva memória
suficiente para a struct Node, em seguida, faço uma verificação se o ponteiro foi certamente alocado, se sim, passa-se na verificação
e o ponteiro é criado, o conteúdo do ponteiro vai ser o mesmo que será passado como parâmetro da função, e o seu próximo, é nulo, pois ele
será o primeiro, o Head.
*/
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Erro ao alocar na memória\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next_node = NULL;

    return newNode;

}

/*
Aqui, eu tenho uma função que não me retorna nada, nela eu recebo dois parâmetros, um ponteiro para head, logo se eu recebo um ponteiro
para head, eu preciso apontar para o ponteiro de head, logo, é um ponteiro que aponta para um ponteiro que aponta para a head da lista,
e também, recebo o conteúdo do Node

Dentro da função, eu Crio um ponteiro para a struct Node, chamado newNode, e o atribuo como a função createNode(data) e passo o conteúdo
para a função create node, para o Node ser criado, logo após, eu referencio o próximo Node do meu novo Node, como o Atual Head Node, e 
defino o Head Node, como o meu Novo Node Criado.
*/
void alocarNoComeco(Node** head, int data){
    Node* newNode = createNode(data);
    newNode->next_node = *head;
    *head =newNode;
}


/*
Aqui, eu tenho uma função que retorna nada, nela eu recebo dois parâmetros, um ponteiro que aponta para o ponteiro que aponta para o nó
cabeça, e recebo também o conteúdo desse Node, Dentro da função, eu crio um novo Node, que é um ponteiro para a Struct Node, e crio
o Node baseado na função createNode

Eu verifico se a Head está vazia, se sim, A head será definida como meu novo Node

Se a Head não estiver vazia eu crio um Node temporario, que irá armazenar o Head Node, logo após, eu itero sobre os nós, até achar um
nó que não tenha um próximo nó, quando essa condição é estabelecida eu saio do loop e o próximo Nó será o meu New Node, logo, o meu New
Node será o último nó
*/
void alocarNoFinal(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next_node != NULL) {
        temp = temp->next_node;
    }
    temp->next_node = newNode;
}


/*
Aqui, eu tenho uma função que não retorna nada, ela recebe dois parâmetros, um ponteiro que aponta para um ponteiro que aponta para o 
nó cabeça, e o valor a ser removido, dentro da função eu Crio um nó temporário e o defino como o head, que é um ponteiro que aponta para
o nó cabeça, e crio também um nó prev, que aponta para o nó anterior

Eu faço a primeira verificação, se o nó cabeça for diferente de nulo e o valor a ser removido é ele, eu defino o nó cabeça como o próximo 
desse nó, e libero o espaço alocado dele

Se não, eu itero, até achar o nó que corresponda ao valor chave

eu faço mais uma verificação, se temp for apenas Nulo, aquele valor não existe

quando eu finalmente achar, o previous Node apontará para o próximo do meu nó temporário, logo após,
eu retiro o espaço alocado pelo temporário, que é um ponteiro que aponta para o nó que será retirado.
*/
void removeNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;


    //Se o nó a ser removido for o primeiro
    if(temp != NULL && temp->data == key){
        *head = temp->next_node;
        free(temp);
        return 0;
    }

    //Procura o nó a ser removido:
    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next_node;
    }

    if(temp == NULL) {
        printf("Elemento não encontrado!\n");
        return;
    }

    prev->next_node = temp->next_node;
    free(temp);
}

void displayList(Node* head) {
    Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next_node;
    }
    printf("NULL\n");
}


int main() {
    Node* head = NULL;

    alocarNoComeco(&head, 10);
    alocarNoFinal(&head, 20);
    alocarNoComeco(&head, 5);
    alocarNoFinal(&head, 30);

    printf("Lista ligada: ");
    displayList(head);


    printf("Removendo o elemento 20...\n");
    removeNode(&head, 20);

    printf("Lista ligada após remoção: ");
    displayList(head);

    return 0;
}
