#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_SIZE 1024

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t* insert(node_t *head, int new_data) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    if(new_node == NULL) {
        printf("Erro de alocação.\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = head;
    
    return new_node;
}

node_t* order_insert(node_t *head, int new_data) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));
    if(new_node == NULL) {
        printf("Erro de alocação.\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    
    if(head == NULL)
        head = new_node;
    else {
        node_t *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = new_node;
    }
    
    return head;
}

node_t* removeAllEvenNumbers(node_t *head) {
    node_t *ant = NULL;
    node_t *aux = NULL;
    node_t *p = head;
    
    while(p != NULL) {
        if(p->data % 2 == 0) {
            if(ant == NULL)
                head = p->next;
            else
                ant->next = p->next;
            aux = p;
            p = p->next;
            free(aux);
        }
        else {
            ant = p;
            p = p->next;
        }
    }
    free(p);
    return head;
}

void createLinkedList(node_t **head) {
    *head = order_insert(*head, 23);
    *head = order_insert(*head, 45);
    *head = order_insert(*head, 56);
    *head = order_insert(*head, 78);
}


void printl(node_t *head) {
    node_t *p;
    for(p = head; p != NULL; p = p->next)
        printf("info = %d, end = %x \n", p->data, p);
}

void freemem(node_t *head) {
    node_t *p = head, *t;
    while (p != NULL) {
        t = p->next;
        free(p);
        p = t;
    }    
}

int main() {
    node_t *head = NULL;

    setlocale(LC_ALL, "Portuguese");

    createLinkedList(&head);
    printl(head);

    printf("\n");

    removeAllEvenNumbers(head);
    printl(head);

    freemem(head);
    return 0;
}
