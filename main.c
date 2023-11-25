#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include "circular_list.h"

void displayInitialMenu();

void displayChallenge1Menu(circular_list *myList);
void backOrLeaveMenu1(circular_list *myList);

void displayChallenge2Menu(routes *myRoutes);
void backOrLeaveMenu2(routes *myRoutes);

int main(int argc, char const *argv[])
{

    displayInitialMenu();

    return 0;
}

void displayInitialMenu()
{
    fflush(stdin);
    char menu;
    printf("\n\nBem-Vindo aos Desafios Tudo ou Nada\n");
    printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("|1 - Primeiro Desafio                          |\n");
    printf("|2 - Segundo Desafio                           |\n");
    printf("|0 - Sair                                      |\n");
    printf("00000000000000000000000000000000000000000oo00000\n\nOpcao: ");
    scanf("%c", &menu);

    switch (menu)
    {
    case '1':
        system("cls");
        circular_list *myList = init();
        displayChallenge1Menu(myList);
        break;
    case '2':
        system("cls");
        routes *myRoutes = initRoutes();
        displayChallenge2Menu(myRoutes);
        break;
    case '0':
        break;
    default:
        system("cls");
        displayInitialMenu();
        break;
    }
}

void displayChallenge1Menu(circular_list *myList)
{

    fflush(stdin);
    int menu;
    char character;

    printf("\n\nBem-Vindo ao desafio 1\n\n");
    printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("|1 - Inserir No                                |\n");
    printf("|2 - Remover No                                |\n");
    printf("|3 - Imprimir Lista                            |\n");
    printf("|4 - Pesquisar No                              |\n");
    printf("|5 - Dividir Lista                             |\n");
    printf("|6 - Remover Lista                             |\n");
    printf("|0 - Sair                                      |\n");
    printf("00000000000000000000000000000000000000000oo00000\n\nOpcao: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:

        printf("Insira o Caracter: ");
        fflush(stdin);
        scanf("%c", &character);

        myList = insertNodeBegin(myList, character);

        (!myList) ? printf("Falha ao Inserir No\n") : printf("No Inserido com Sucesso!\n");

        backOrLeaveMenu1(myList);

        break;
    case 2:

        printf("Remover No com Caracter: ");
        fflush(stdin);

        scanf("%c", &character);

        myList = removeNode(myList, character);

        (!myList) ? printf("Falha ao Remover No\n") : printf("No Removido com Sucesso!\n");
        backOrLeaveMenu1(myList);
        break;
    case 3:
        printf("Impressao: \n-----------------\n");
        printList(myList);
        backOrLeaveMenu1(myList);
        break;
    case 4:
        printf("Caracter a Pesquisar: ");
        fflush(stdin);
        scanf("%c", &character);

        searchNode(myList, character);

        backOrLeaveMenu1(myList);

        break;
    case 5:
        myList = divideList(myList);

        backOrLeaveMenu1(myList);

        break;
    case 6:

        myList = removeList(myList);

        backOrLeaveMenu1(myList);

        break;
    default:
        system("cls");
        displayInitialMenu();
        break;
    }
}

void displayChallenge2Menu(routes *myRoutes)
{

    fflush(stdin);

    int menu;
    char *stationName = NULL;

    int codeRoute;
    int stationNameSize = 20;

    printf("Bem-Vindo ao desafio 1\n\n");
    printf("oooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("|1 - Criar Rota                                |\n");
    printf("|2 - Remover Rota                              |\n");
    printf("|3 - Adicionar Paragem                         |\n");
    printf("|4 - Remover Paragem                           |\n");
    printf("|5 - Ver Rotas                                 |\n");
    printf("|6 - Ver Paragens                              |\n");
    printf("|7 - Ver Paragens com mais Passageiros         |\n");
    printf("|0 - Sair                                      |\n");
    printf("00000000000000000000000000000000000000000oo00000\n\nOpcao: ");
    scanf("%d", &menu);

    switch (menu)
    {

    case 1:
        // chama a função para criar rota
        system("cls");

        myRoutes = createRouteBegin(myRoutes);

        if (!myRoutes)
            printf("Erro ao criar\n");
        else
            printf("Rota criada com sucesso\n");

        backOrLeaveMenu2(myRoutes);
        break;
    case 2:
        // chama a função para remover rota
        system("cls");

        printf("Insira o codigo da rota que pretende eliminar: ");
        scanf("%d", &codeRoute);

        myRoutes = removeRoute(codeRoute, myRoutes);

        backOrLeaveMenu2(myRoutes);

        break;
    case 3:
        // chama a função para add paragem a uma rota
        system("cls");

        int qty = 0;

        stationName = (char *)malloc(sizeof(char) * stationNameSize);

        printf("Insira o codigo da rota que pretende adicionar paragem: ");
        scanf("%d", &codeRoute);

        fflush(stdin);

        printf("Insira o nome da paragem: ");
        scanf("%s", stationName);

        printf("Insira a quantidade de passageiros: ");
        scanf("%d", &qty);

        createStationEnd(codeRoute, stationName, qty, myRoutes);

        backOrLeaveMenu2(myRoutes);

        break;
    case 4:
        // chama a função para remover paragem de uma rota
        system("cls");

        printf("Insira o codigo da rota que pretende remover paragem: ");
        scanf("%d", &codeRoute);

        if (getRouteByCode(codeRoute, myRoutes))
        {

            stationName = (char *)malloc(sizeof(char) * stationNameSize);

            fflush(stdin);

            printf("Insira o nome da paragem: ");
            scanf("%s", stationName);

            removeStation(codeRoute, myRoutes, stationName);
        }
        else
            printf("Rota nao existe\n\n");

        backOrLeaveMenu2(myRoutes);

        break;
    case 5:
        // chama a função para ver rotas
        system("cls");
        printRoutes(myRoutes);
        backOrLeaveMenu2(myRoutes);

        break;
    case 6:
        // chama a função para ver paragens
        system("cls");

        printf("Insira o código da Rota: ");
        scanf("%d", &codeRoute);

        getRouteByCode(codeRoute, myRoutes) ? printStation(getRouteByCode(codeRoute, myRoutes)) : printf("Rota nao existe\n");

        backOrLeaveMenu2(myRoutes);

        break;
    case 7:
        // chama a função para ver paragem com mais passageiros de uma rota
        system("cls");

        printf("Insira o codigo da rota que pretende ver a paragem com mais passageiros: ");
        scanf("%d", &codeRoute);

        printMaxStation(codeRoute, myRoutes);

        backOrLeaveMenu2(myRoutes);

        break;
    case '8':
        // chama a função para ver rotas e suas paragens
        system("cls");

        backOrLeaveMenu2(myRoutes);
        break;
    case '9':
        system("cls");
        displayInitialMenu();
        break;
    default:
        system("cls");
        displayChallenge2Menu(myRoutes);
        break;
    }
}

void backOrLeaveMenu1(circular_list *myList)
{

    fflush(stdin);

    int menu;
    printf("\n\noooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("|1 - Voltar                                    |\n");
    printf("|2 - Sair                                      |\n");
    printf("000000000000000000000000000000000000000000000000\n\nOpcao: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        system("cls");
        displayChallenge1Menu(myList);
        break;
    case 2:
        system("cls");
        displayInitialMenu();
        break;
    case 3:
        break;
    default:
        system("cls");
        displayChallenge1Menu(myList);
        break;
    }
}

void backOrLeaveMenu2(routes *myRoutes)
{

    fflush(stdin);

    int menu;
    printf("\n\noooooooooooooooooooooooooooooooooooooooooooooooo\n");
    printf("|1 - Voltar                                    |\n");
    printf("|2 - Sair                                      |\n");
    printf("000000000000000000000000000000000000000000000000\n\nOpcao: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        system("cls");
        displayChallenge2Menu(myRoutes);
        break;
    case 2:
        system("cls");
        displayInitialMenu();
        break;
    case 3:
        break;
    default:
        system("cls");
        displayChallenge2Menu(myRoutes);
        break;
    }
}
