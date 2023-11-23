#include <stdlib.h>
#include <stdio.h>
#include "circular_list.h"
#include <ctype.h>

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
    if(new_node){
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
    return NULL;
}

circular_list *removeNode(circular_list *head, char character){
    circular_list *aux = head, *ant = NULL;

    if(!head) return head;

    while(aux->character != character) {
        ant = aux;
        aux = aux->next;
        if(aux->next == head && aux->character != character) 
            return head; //deu a volta completa e não encontrou. RETORNE
    } 
    //Encontrou o Elemento Procurado
    if(aux->next == aux) head = NULL; // se possui um unico elemento head = NULL
    if(!ant){ //eliminar no início
        ant = aux;
        while(ant->next != head) ant = ant->next; //último elemento
        head = ant->next->next; //head recebe o elemento depois do 1º
        ant->next = head; 
    }else
        ant->next = aux->next;

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

void searchNode(circular_list *head, char character){
    circular_list *aux = head;
    
    if(!head) printf("Lista Vazia!\n");
    else{
        while(aux->next != head && aux->character != character) {
            aux = aux->next;
        } 
        if(aux->character == character) 
            printf("Elemento \'%c\' Encontrado na Lista\n",aux->character);
        else
            printf("Elemento Inexistente!\n");
    }
}

void divideList(circular_list *head){
    circular_list *vowel_list = NULL, *consonant_list = NULL, *aux = head;
    if(!head) printf("Lista Vazia\n");
    else{
        do{
            if(tolower(aux->character) == 'a' || tolower(aux->character) == 'e' || tolower(aux->character) == 'i' || tolower(aux->character) == 'o' || tolower(aux->character) == 'u'){
                printf("Sim\n");
                 if(!vowel_list){ //primeiro elemento aponta para ele mesmo
                    vowel_list = aux;
                    aux = aux->next;
                    vowel_list->next = vowel_list;                    
                 }else{
                    //vowel_list
                 }
                 break;
            }
        }while(aux != head); //aux é o primeiro elemento
    }
}

circular_list *removeList(circular_list *head){
    free(head);
    return NULL;
}