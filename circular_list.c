#include <stdlib.h>
#include <stdio.h>
#include "circular_list.h"

struct Circular_List{
    char character;
    struct Circular_List *next;
};

circular_list *init(){
    circular_list *new_list = (circular_list*)malloc(sizeof(circular_list));
    new_list = NULL;
    return new_list;
}

circular_list *insertNodeBegin(circular_list *head, char character){
    circular_list *new_node = (circular_list*)malloc(sizeof(circular_list));
    new_node->character = character;
    if(!head) //se não possui nenhum elemento
        new_node->next = new_node;
    else{ //se já possui elementos
        new_node->next = head;
        circular_list *aux = head;
        while(aux->next != head) aux = aux->next;
        aux->next = new_node;
    }
    return new_node;
}

circular_list *removeNode(circular_list *head, char character){
    circular_list *aux = head;

    //2 nós
    while(aux->next != head && aux->character != character) {
        if(aux->next->character == character)
            break;
        aux = aux->next;
    } 
    if(aux->character == character) head = aux->next;

    free(aux);
    return head;
}

void printList(circular_list *head){
    circular_list *aux = head;
    while(head && aux->next != head){
        printf("%c\n", aux->character);
        aux = aux->next;
    }
    if(head && aux->next == head) printf("%c\n", aux->character);
}
/*

void searchNode(circular_list *head, char character);

void divideList(circular_list *head);

*/
circular_list *removeList(circular_list *head){
    free(head);
    return NULL;
}