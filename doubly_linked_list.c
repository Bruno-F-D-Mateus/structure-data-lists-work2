#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

struct Station
{
    char *name;
    int qty;
};

struct Stations
{
    struct Station st;
    struct Stations *prev;
    struct Stations *next;
};

struct Route
{
    int code;
    struct Stations *sts;
};

struct Routes
{
    struct Route rt;
    struct Routes *prev;
    struct Routes *next;
};

routes *initRoutes()
{
    routes *newRoutes = (routes *)malloc(sizeof(routes));
    newRoutes = NULL;
    return newRoutes;
}

// Código é criado de forma automática
routes *createRouteBegin(routes *headRoute)
{
    routes *newRoute = (routes *)malloc(sizeof(routes));

    if (newRoute)
    {

        newRoute->rt.code = 1 + countRts(headRoute);
        newRoute->rt.sts = NULL;
        newRoute->prev = NULL;

        if (!headRoute)
            newRoute->next = NULL;
        else
        {
            headRoute->prev = newRoute;
            newRoute->next = headRoute;
        }

        return newRoute;
    }
    else
        printf("Erro ao criar Rota\n");

    return NULL;
}
// Imprime todas as paragens de uma determinada rota
void printStation(routes *myRoute)
{
    stations *auxStation = myRoute->rt.sts;

    if (!myRoute || !auxStation)
        printf("Lista Vazia!\n\n");
    else
    {

        printf("Rota %d\n", myRoute->rt.code);

        while (auxStation->next != NULL)
        {
            printf("Paragem: %s - Qtd: %d\n", auxStation->st.name, auxStation->st.qty);
            auxStation = auxStation->next;
        }
        printf("Paragem: %s - Qtd: %d\n\n", auxStation->st.name, auxStation->st.qty);
    }
}
// Imprime todas as rotas existentes
void printRoutes(routes *headRoute)
{
    routes *aux = headRoute;

    if (!headRoute)
        printf("Lista Vazia!\n\n");
    else
    {
        while (aux->next != NULL)
        {
            printf("rota: %d\n", aux->rt.code);
            aux = aux->next;
        }
        printf("rota: %d\n\n", aux->rt.code);
    }
}
// Cria paragens numa determinada rota
void createStationEnd(int code, char *name, int qty, routes *headRoute)
{
    routes *auxRoute = getRouteByCode(code, headRoute);

    if (auxRoute == NULL)
        printf("Rota nao existe!\n\n");
    else
    {

        if (auxRoute->rt.sts && !verifyStation(auxRoute->rt.sts, name))
            printf("Nao pode haver paragens repetidas\n\n");
        else
        {

            stations *newStation = (stations *)malloc(sizeof(stations));

            newStation->st.name = name;
            newStation->st.qty = qty;
            newStation->next = NULL;
            if (!newStation)
                printf("Erro na alocação\n");
            else if (!auxRoute->rt.sts)
            { // primeiro elemento
                newStation->prev = NULL;
                auxRoute->rt.sts = newStation;

                printf("Paragem adicionada com sucesso!\n");
            }
            else
            { // outros elementos
                stations *auxStations = auxRoute->rt.sts;

                while (auxStations->next != NULL)
                    auxStations = auxStations->next;

                auxStations->next = newStation;
                newStation->prev = auxStations;

                printf("Paragem adicionada com sucesso!\n");
            }
        }
    }
}
// Mostra a Paragem mais lucrativa
void printMaxStation(int code, routes *headRoute)
{
    routes *auxRoute = getRouteByCode(code, headRoute);
    if (!auxRoute)
        printf("Rota nao Existe!\n\n");
    else
    {
        stations *auxStation = auxRoute->rt.sts;
        stations *maxStation = (stations *)malloc(sizeof(stations));

        if (!auxStation)
            printf("Nao existem paragens nessa Rota!\n\n");
        else
        {
            // pegando os primeiros elementos
            char *name = auxStation->st.name;
            int qty = auxStation->st.qty;

            while (auxStation->next != NULL)
            {
                if (qty < auxStation->st.qty)
                {
                    name = auxStation->st.name;
                    qty = auxStation->st.qty;
                }
                auxStation = auxStation->next;
            }
            if (qty < auxStation->st.qty)
            {
                name = auxStation->st.name;
                qty = auxStation->st.qty;
            }
            printf("Rota %d\nParagem mais Lucrativa %s com %d passageiros\n\n", auxRoute->rt.code, name, qty);
        }
    }
}
// remove uma paragem
void removeStation(int routeCode, routes *headRoute, char *stationName)
{
    routes *auxRoute = getRouteByCode(routeCode, headRoute);
    if (!auxRoute)
        printf("\nRota nao Existe!\n\n");
    else
    {
        if (!auxRoute->rt.sts)
            printf("Nao existe paragens nessa Rota\n\n");
        else
        {
            stations *auxStation = auxRoute->rt.sts;
            if (strcmp(auxStation->st.name, stationName) == 0)
            { // encontrou no início
                auxRoute->rt.sts = auxRoute->rt.sts->next;
                free(auxStation);
                printf("Paragem eliminada com sucesso!\n\n");
            }
            else
            {
                while (auxStation->next != NULL) // meio
                {
                    if (strcmp(auxStation->st.name, stationName) == 0)
                    {
                        auxStation->prev->next = auxStation->next;
                        auxStation->next->prev = auxStation->prev;
                        free(auxStation);
                        printf("Paragem eliminada com sucesso!\n\n");

                        return;
                    }
                    auxStation = auxStation->next;
                }
                // último elemento
                if (strcmp(auxStation->st.name, stationName) == 0)
                {
                    auxStation->prev->next = NULL;
                    free(auxStation);
                    printf("Paragem eliminada com sucesso!\n\n");
                }
                else
                    printf("Paragem não Encontrada\n\n");
            }
        }
    }
}
// elimina uma rota e todas suas paragens
routes *removeRoute(int routeCode, routes *headRoute)
{
    routes *auxRoute = getRouteByCode(routeCode, headRoute);

    if (!auxRoute)
        printf("\nRota nao Existe\n\n");
    else if (!auxRoute->next && !auxRoute->prev)
    {
        free(auxRoute);

        printf("\nRota eliminado com sucesso\n\n");

        return NULL;
    }
    else
    {
        if (!auxRoute->prev) // encontrou no início
            headRoute = auxRoute->next;
        else if (!auxRoute->next) // encontrou no fim
            auxRoute->prev->next = auxRoute->next;
        else
        { // no meio
            auxRoute->prev->next = auxRoute->next;
            auxRoute->next->prev = auxRoute->prev;
        }
        free(auxRoute);
        printf("\nRota eliminado com sucesso\n\n");
    }
    return headRoute;
}
// pesquisa uma determinada rota pelo código
routes *getRouteByCode(int code, routes *headRoute)
{
    routes *aux = headRoute;

    if (aux == NULL)
        return NULL;

    if (aux->rt.code == code)
        return aux;

    return getRouteByCode(code, aux->next);
}

int countRts(routes *headRoute)
{
    int cont = 0;
    routes *aux = headRoute;

    return aux == NULL ? 0 : 1 + countRts(aux->next);
}

int verifyStation(stations *head, char *name)
{
    stations *auxStation = head;
    while (auxStation->next != NULL)
    {
        if (strcmp(auxStation->st.name, name) == 0)
            return 0;
        auxStation = auxStation->next;
    }

    return strcmp(head->st.name, name);
}

