#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

void displayInitialMenu();
void displayChallenge1Menu(circular_list *myList);
void displayChallenge2Menu();
void backOrLeaveMenu2();

int main(int argc, char const *argv[])
{
    displayInitialMenu();
    return 0;
}

void displayInitialMenu(){
    fflush(stdin);
    char menu;
     printf("Bem-Vindo aos Desafios Tudo ou Nada\n");
     printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
	 printf("|1 - Primeiro Desafio                          |\n");
     printf("|2 - Segundo Desafio                           |\n");
     printf("|0 - Sair                                      |\n");
	 printf("00000000000000000000000000000000000000000oo00000\n\nOpção: ");
     scanf("%c", &menu);

    switch (menu){
    case '1':
        system("cls");
        circular_list * myList = init();
        displayChallenge1Menu(myList);
        break;
    case '2':
        system("cls");
        displayChallenge2Menu();
        break;
    case '0':
        break;
    default:
        system("cls");
        displayInitialMenu();
        break;
    }
}

void displayChallenge1Menu(circular_list *myList){
    
    fflush(stdin);
    int menu;
    char character;

     printf("Bem-Vindo ao 1º Desafio\n");
     printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
	 printf("|1 - Inserir Nó                                |\n");
     printf("|2 - Remover Nó                                |\n");
     printf("|3 - Imprimir Lista                            |\n");
     printf("|4 - Pesquisar Nó                              |\n");
     printf("|5 - Dividir Lista                             |\n");
     printf("|6 - Remover Lista                             |\n");
     printf("|0 - Sair                                      |\n");
	 printf("00000000000000000000000000000000000000000oo00000\n\nOpção: ");
     scanf("%d", &menu);

    switch (menu){
    case 1:
        printf("Insira o Caracter: ");
        scanf("%c",&character); //eliminar um
        scanf("%c",&character);

        myList = insertNodeBegin(myList,character);
        (!myList) ? printf("Falha ao Inserir Nó\n") : printf("Nó Inserido com Sucesso!\n");
        displayChallenge1Menu(myList);
        break;
    case 2:
        printf("Remover Nó com Caracter: ");
        scanf("%c",&character); //eliminar um
        scanf("%c",&character);
        myList = removeNode(myList, character);
        (!myList) ? printf("Falha ao Remover Nó\n") : printf("Nó Removido com Sucesso!\n");
        displayChallenge1Menu(myList);
        break;
    case 3:
            printf("Impressão: \n-----------------\n");
            printList(myList);
            displayChallenge1Menu(myList);
        break;
    case 4:
        printf("Caracter a Pesquisar: ");
        scanf("%c",&character); //eliminar um
        scanf("%c",&character);
        searchNode(myList, character);
        displayChallenge1Menu(myList);
    break;
    case 5:
        myList = divideList(myList);
        displayChallenge1Menu(myList);
    break;
    case 6:
        myList = removeList(myList);
        displayChallenge1Menu(myList);
    break;
    default:
        system("cls");
        displayInitialMenu();
        break;
    }
}

void displayChallenge2Menu()
{

    fflush(stdin);

    char menu;
    void backOrLeaveMenu2();

    printf("____BEM___VINDO___AO___DESAFIO___2___\n\n");
    printf("Criar Rota: 1\nRemover Rota: 2\nAdd Paragem: 3\nRemover Paragem: 4\nVer Rotas: 5\nVer Paragens: 6\nVer Paragem com mais Passageiros: 7\nVer Rotas e suas Paragens: 8\nSair: 9\n\n");
    printf("_____________________________________\n\n");
    printf("Escolha a opcao: ");
    scanf("%c", &menu);

    switch (menu)
    {
    case '1':
        // chama a função para criar rota
        system("cls");

        backOrLeaveMenu2();
        break;
    case '2':
        // chama a função para remover rota
        system("cls");

        backOrLeaveMenu2();
        break;
    case '3':
        // chama a função para add paragem a uma rota
        system("cls");

        backOrLeaveMenu2();

        break;
    case '4':
        // chama a função para remover paragem de uma rota
        system("cls");

        backOrLeaveMenu2();

        break;
    case '5':
        // chama a função para ver rotas
        system("cls");

        backOrLeaveMenu2();

        break;
    case '6':
        // chama a função para ver paragens
        system("cls");

        backOrLeaveMenu2();

        break;
    case '7':
        // chama a função para ver paragem com mais passageiros de uma rota
        system("cls");

        backOrLeaveMenu2();

        break;
    case '8':
        // chama a função para ver rotas e suas paragens
        system("cls");

        backOrLeaveMenu2();
        break;
    case '9':
        system("cls");
        displayInitialMenu();
        break;
    default:
        system("cls");
        displayChallenge2Menu();
        break;
    }
}

void backOrLeaveMenu2()
{

    fflush(stdin);

    char menu;

    printf("_____________________________________\n\n");
    printf("Voltar: 1\nSair: 2\n");
    printf("_____________________________________\n\n");
    printf("Escolha a opcao: ");
    scanf("%c", &menu);

    switch (menu)
    {
    case '1':
        system("cls");
        displayChallenge2Menu();
        break;
    case '2':
        system("cls");
        displayInitialMenu();
        break;
    case '3':
        break;
    default:
        system("cls");
        displayChallenge2Menu();
        break;
    }
}
