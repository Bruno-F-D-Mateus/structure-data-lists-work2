#include <stdio.h>
#include <stdlib.h>

void displayInitialMenu();
void displayChallenge1Menu();
void displayChallenge2Menu();
void backOrLeaveMenu2();

int main(int argc, char const *argv[])
{
    displayInitialMenu();
    return 0;
}

void displayInitialMenu()
{
    fflush(stdin);

    char menu;

    void displayChallenge1Menu();
    void displayChallenge2Menu();

    printf("_____________________________________\n\n");
    printf("Desafio 1: 1\nDesafio 2: 2\nSair: 3\n\n");
    printf("_____________________________________\n\n");
    printf("Escolha o desafio: ");
    scanf("%c", &menu);

    switch (menu)
    {
    case '1':
        system("cls");

        displayChallenge1Menu();
        break;
    case '2':
        system("cls");

        displayChallenge2Menu();
        break;
    case '3':
        break;
    default:
        system("cls");
        displayInitialMenu();
        break;
    }
}

void displayChallenge1Menu()
{

    fflush(stdin);

    char menu;

    printf("_____________________________________\n\n");
    printf("Desafio 1: 1\nDesafio 2: 2\nSair 3: 3\n\n");
    printf("_____________________________________\n\n");
    printf("Escolha o desafio: ");
    scanf("%c", &menu);

    switch (menu)
    {
    case '1':
        // chama o menu do primeiro desafio
        break;
    case '2':
        // chama o menu do segundo desafio
        break;
    case '3':
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
