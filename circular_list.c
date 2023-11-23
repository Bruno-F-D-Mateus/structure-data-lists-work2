#include <stdlib.h>
#include <stdio.h>
#include "circular_list.h"
#include <ctype.h>

struct Circular_List
{
    char character;
    struct Circular_List *next;
};

circular_list *init()
{
    circular_list *new_list = (circular_list *)malloc(sizeof(circular_list));
    new_list = NULL;
    return new_list;
}

circular_list *insertNodeBegin(circular_list *head, char character)
{
    circular_list *new_node = (circular_list *)malloc(sizeof(circular_list));
    if (new_node)
    {
        new_node->character = character;
        if (!head) // se não possui nenhum elemento
            new_node->next = new_node;
        else
        { // se já possui elementos
            new_node->next = head;
            circular_list *aux = head;
            while (aux->next != head)
                aux = aux->next;
            aux->next = new_node;
        }
        return new_node;
    }
    return NULL;
}

circular_list *removeNode(circular_list *head, char character)
{
    circular_list *aux = head, *ant = NULL;

    if (!head)
        return head;

    while (aux->character != character)
    {
        ant = aux;
        aux = aux->next;
        if (aux->next == head && aux->character != character)
            return head; // deu a volta completa e não encontrou. RETORNE
    }
    // Encontrou o Elemento Procurado
    if (aux->next == aux)
        head = NULL; // se possui um unico elemento head = NULL
    if (!ant)
    { // eliminar no início
        ant = aux;
        while (ant->next != head)
            ant = ant->next;    // último elemento
        head = ant->next->next; // head recebe o elemento depois do 1º
        ant->next = head;
    }
    else
        ant->next = aux->next;

    free(aux);
    return head;
}

void printList(circular_list *head)
{
    circular_list *aux = head;
    while (head && aux->next != head)
    {
        printf("%c\n", aux->character);
        aux = aux->next;
    }
    if (head && aux->next == head)
        printf("%c\n", aux->character);
}

void searchNode(circular_list *head, char character)
{
    circular_list *aux = head;

    if (!head)
        printf("Lista Vazia!\n");
    else
    {
        while (aux->next != head && aux->character != character)
        {
            aux = aux->next;
        }
        if (aux->character == character)
            printf("Elemento \'%c\' Encontrado na Lista\n", aux->character);
        else
            printf("Elemento Inexistente!\n");
    }
}

void divideList(circular_list *head)
{
    circular_list *vowel_list = NULL, *consonant_list = NULL, *aux = head;
    if (!head)
        printf("Lista Vazia\n");
    else
    {
        do
        {
            if (tolower(aux->character) == 'a' || tolower(aux->character) == 'e' || tolower(aux->character) == 'i' || tolower(aux->character) == 'o' || tolower(aux->character) == 'u')
            {
                if (!vowel_list)
                { // primeiro elemento aponta para ele mesmo
                    vowel_list = aux;
                    aux = aux->next;
                    vowel_list->next = vowel_list;
                }
                else
                {
                    circular_list *vowel = aux;
                    circular_list *aux_vowel = vowel_list;
                    aux = aux->next;
                    while (aux_vowel->next != vowel_list)
                        aux_vowel = aux_vowel->next;
                    aux_vowel->next = vowel;  // último liga com o novo
                    vowel->next = vowel_list; // novo aponta para o primeiro
                    vowel_list = vowel;       // novo passa a ser o primeiro agora
                }
            }
            else
            {
                if (!consonant_list)
                { // primeiro elemento aponta para ele mesmo
                    consonant_list = aux;
                    aux = aux->next;
                    consonant_list->next = consonant_list;
                }
                else
                {
                    circular_list *consonant = aux;
                    circular_list *aux_consonant = consonant_list;
                    aux = aux->next;
                    while (aux_consonant->next != consonant_list)
                        aux_consonant = aux_consonant->next;
                    aux_consonant->next = consonant;  // último liga com o novo
                    consonant->next = consonant_list; // novo aponta para o primeiro
                    consonant_list = consonant;       // novo passa a ser o primeiro agora
                }
            }
        } while (aux != head); // aux é o primeiro elemento
    }

    printf("Lista de Vogais: \n");
    printList(vowel_list); //imprime vogais

    printf("Lista de Consoantes: \n");
    printList(consonant_list); //imprime consoantes
}

void removeList(circular_list *head)
{
    
    int count = 0;
        
/*
        circular_list *aux = *head;
        printf("%c\n",aux->character);
        free(aux);
        if(!aux) printf("Vazio");
        else printf("Preenchido!");
        printf("\n%c\n",aux->character);
        aux = aux-
        if(head->next==head) free(head);
        else{

        }
*/
}